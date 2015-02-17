#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Candidate/interface/CandidateFwd.h"

#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/EgammaCandidates/interface/PhotonFwd.h"

#include "DataFormats/PatCandidates/interface/Photon.h"

#include "DataFormats/Common/interface/ValueMap.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"

#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"

#include "PhysicsTools/IsolationAlgos/interface/IsoDepositVetoFactory.h"
#include "DataFormats/RecoCandidate/interface/IsoDepositVetos.h"

#include "PhysicsTools/IsolationAlgos/interface/CITKIsolationConeDefinitionBase.h"
#include "DataFormats/Math/interface/deltaR.h"

#include "DataFormats/EcalDetId/interface/EcalSubdetector.h"


#include <unordered_map>

namespace reco {
  typedef edm::Ptr<reco::Photon> recoPhotonPtr;
}

namespace pat {
  typedef edm::Ptr<pat::Photon> patPhotonPtr;
  typedef edm::Ptr<pat::PackedCandidate> PackedCandidatePtr;
}

// This template function finds whether theCandidate is in thefootprint
// collection. It is templated to be able to handle both reco and pat
// photons (from AOD and miniAOD, respectively).
template <class T, class U>
bool isInFootprint(const T& thefootprint, const U& theCandidate) {
for ( auto itr = thefootprint.begin(); itr != thefootprint.end(); ++itr ) {
if( itr->key() == theCandidate.key() ) return true;
}
return false;
}


class PhotonPFIsolationWithMapBasedVeto : public citk::IsolationConeDefinitionBase {
public:
  PhotonPFIsolationWithMapBasedVeto(const edm::ParameterSet& c) :
    citk::IsolationConeDefinitionBase(c),
    _isolateAgainst(c.getParameter<std::string>("isolateAgainst")),
    _vertexCollection(c.getParameter<std::string>("vertexCollection")),
    _dzMax(c.getParameter<double>("dzMax")),
    _dxyMax(c.getParameter<double>("dxyMax")){}
    
  PhotonPFIsolationWithMapBasedVeto(const PhotonPFIsolationWithMapBasedVeto&) = delete;
  PhotonPFIsolationWithMapBasedVeto& operator=(const PhotonPFIsolationWithMapBasedVeto&) =delete;

  bool isInIsolationCone(const reco::CandidatePtr& physob,
			 const reco::CandidatePtr& other) const override final;
  

  edm::Handle<reco::VertexCollection> vertices;			 
   
  // this is needed for reco case
 edm::Handle< edm::ValueMap<std::vector<reco::PFCandidateRef > > > particleBasedIsolationMap;			 
 edm::EDGetTokenT<edm::ValueMap<std::vector<reco::PFCandidateRef > > > particleBasedIsolationToken_;
 
 virtual void getEventInfo(const edm::Event& iEvent)
  {
      iEvent.getByToken(particleBasedIsolationToken_, particleBasedIsolationMap); 
      iEvent.getByToken(_vtxToken, vertices);
  };			 
  
  
  //As far as I understand now, the object particleBasedIsolationMap should be fixed, so we don't configure the name
  void setConsumes(edm::ConsumesCollector iC)
  {
      particleBasedIsolationToken_ = iC.consumes<edm::ValueMap<std::vector<reco::PFCandidateRef > > >(edm::InputTag("particleBasedIsolation", "gedPhotons"));
      _vtxToken = iC.consumes<reco::VertexCollection>(edm::InputTag(_vertexCollection));
     
  }

  //! Destructor
  virtual ~PhotonPFIsolationWithMapBasedVeto(){};
  
  
private:    
  const std::string _isolateAgainst, _vertexCollection;
  const float _dzMax, _dxyMax;
  edm::EDGetTokenT<reco::VertexCollection> _vtxToken; 

  
};

DEFINE_EDM_PLUGIN(CITKIsolationConeDefinitionFactory,
		  PhotonPFIsolationWithMapBasedVeto,
		  "PhotonPFIsolationWithMapBasedVeto");


bool PhotonPFIsolationWithMapBasedVeto::
isInIsolationCone(const reco::CandidatePtr& physob,
		  const reco::CandidatePtr& iso_obj  ) const {
 
  reco::recoPhotonPtr asreco_photonptr(physob);
  pat::patPhotonPtr aspat_photonptr(physob);
  
  pat::PackedCandidatePtr aspacked(iso_obj);
  reco::PFCandidatePtr aspf(iso_obj);
  
  if (vertices->empty()) return false; // return false if there are no PV found
  const reco::Vertex &pv = vertices->front();
  
  bool inFootprint = false;
  bool result = true;
  
  // dealing here with patObjects
  if ( aspat_photonptr.get())    
  {
    inFootprint = isInFootprint(aspat_photonptr ->associatedPackedPFCandidates(),aspacked);
    
    // the neutral hadrons and charged hadrons can be of pdgId types
    // only 130 (K0L) and +-211 (pi+-) in packed candidates
    if ( abs(aspacked -> pdgId()) == 211)
    { 
      float dxy = -999, dz = -999;      
      dz = aspacked -> pseudoTrack().dz(pv.position());
      dxy = aspacked -> pseudoTrack().dxy(pv.position()); 
      
      if (fabs(dz) > _dzMax) result = false;
      if (fabs(dxy) > _dxyMax) result = false;
    }
    
     
  }
  
  // dealing here with recoObjects
  else if ( asreco_photonptr.get())
  {
    inFootprint = isInFootprint((*particleBasedIsolationMap)[physob], iso_obj); 
    reco::PFCandidate::ParticleType thisCandidateType = reco::PFCandidate::X;
     thisCandidateType = aspf -> particleId();
     
     if( thisCandidateType == reco::PFCandidate::h ){
     
       float dxy = -999., dz = -999.;
       dz = ( aspf -> trackRef()->dz(pv.position()));
       dxy =( aspf -> trackRef()->dxy(pv.position()));
       
       if (fabs(dz) > _dzMax) result = false;
       if (fabs(dxy) > _dxyMax) result = false;
     }
  }
  
  // throw exception if it is not a patObject or recoObject
  else {
    throw cms::Exception("InvalidIsolationInput")
      << "The supplied candidate to be used as isolation "
      << "was neither a reco::Photon nor a pat::Photon!";
  }
  
  const float deltar2 = reco::deltaR2(*physob,*iso_obj); 
  
  
  if (deltar2 > _coneSize2) result = false;
  if (inFootprint) result = false;
  
  return result;
}
