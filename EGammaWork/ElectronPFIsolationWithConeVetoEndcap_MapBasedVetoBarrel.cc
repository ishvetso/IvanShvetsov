#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Candidate/interface/CandidateFwd.h"

#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"

#include "FWCore/Framework/interface/ConsumesCollector.h"

#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"

#include "PhysicsTools/IsolationAlgos/interface/IsoDepositVetoFactory.h"
#include "DataFormats/RecoCandidate/interface/IsoDepositVetos.h"

#include "PhysicsTools/IsolationAlgos/interface/CITKIsolationConeDefinitionBase.h"
#include "DataFormats/Math/interface/deltaR.h"

#include "DataFormats/EcalDetId/interface/EcalSubdetector.h"

#include "DataFormats/PatCandidates/interface/Electron.h"


#include <unordered_map>

namespace reco {
  typedef edm::Ptr<reco::GsfElectron> GsfElectronPtr;
}

namespace pat {
  typedef edm::Ptr<pat::PackedCandidate> PackedCandidatePtr;
  typedef edm::Ptr<pat::Electron> PatElectronPtr;
}	

template <class T, class U>
bool isInFootprint(const T& thefootprint, const U& theCandidate) {
for ( auto itr = thefootprint.begin(); itr != thefootprint.end(); ++itr ) {
if( itr->key() == theCandidate.key() ) return true;
}
return false;
}

class ElectronPFIsolationWithConeVetoEndcap_MapBasedVetoBarrel : public citk::IsolationConeDefinitionBase {
public:
  ElectronPFIsolationWithConeVetoEndcap_MapBasedVetoBarrel(const edm::ParameterSet& c) :
    citk::IsolationConeDefinitionBase(c),
    _vetoConeSize2EE(std::pow(c.getParameter<double>("VetoConeSizeEndcaps"),2.0)),
    _miniAODVertexCodes(c.getParameter<std::vector<unsigned> >("miniAODVertexCodes")),
    _isolateAgainst(c.getParameter<std::string>("isolateAgainst")) {
    char buf[50];
    sprintf(buf,"BarMapBasedVeto-EndVeto%.2f",
    std::sqrt(_vetoConeSize2EE));
    _additionalCode = std::string(buf);
    auto decimal = _additionalCode.find('.');
    while( decimal != std::string::npos ) {
      _additionalCode.erase(decimal,1);
      decimal = _additionalCode.find('.');
    }    
  }
  ElectronPFIsolationWithConeVetoEndcap_MapBasedVetoBarrel(const ElectronPFIsolationWithConeVetoEndcap_MapBasedVetoBarrel&) = delete;
  ElectronPFIsolationWithConeVetoEndcap_MapBasedVetoBarrel& operator=(const ElectronPFIsolationWithConeVetoEndcap_MapBasedVetoBarrel&) =delete;
  
  edm::Handle< edm::ValueMap<std::vector<reco::PFCandidateRef > > > particleBasedIsolationMap;
  edm::EDGetTokenT<edm::ValueMap<std::vector<reco::PFCandidateRef > > > particleBasedIsolationToken_;
  
   virtual void getEventInfo(const edm::Event& iEvent)
   {
      iEvent.getByToken(particleBasedIsolationToken_, particleBasedIsolationMap);      
   };
    
   //As far as I understand now, the object particleBasedIsolationMap should be fixed, so we don't configure the name
   void setConsumes(edm::ConsumesCollector iC)
   {
     particleBasedIsolationToken_ = iC.consumes<edm::ValueMap<std::vector<reco::PFCandidateRef > > >(edm::InputTag("particleBasedIsolation", "gedGsfElectrons"));      
   }

  bool isInIsolationCone(const reco::CandidatePtr& physob,
			 const reco::CandidatePtr& other) const override final;
  
  //! Destructor
  virtual ~ElectronPFIsolationWithConeVetoEndcap_MapBasedVetoBarrel(){};
  
private:    
  const float _vetoConeSize2EE;  
  const std::vector<unsigned> _miniAODVertexCodes;
  const std::string _isolateAgainst;  
};

DEFINE_EDM_PLUGIN(CITKIsolationConeDefinitionFactory,
		  ElectronPFIsolationWithConeVetoEndcap_MapBasedVetoBarrel,
		  "ElectronPFIsolationWithConeVetoEndcap_MapBasedVetoBarrel");

bool ElectronPFIsolationWithConeVetoEndcap_MapBasedVetoBarrel::
isInIsolationCone(const reco::CandidatePtr& physob,
		  const reco::CandidatePtr& iso_obj  ) const {
		    
  reco::GsfElectronPtr asreco_electronptr(physob);
  pat::PatElectronPtr aspat_electronptr(physob);
  
  pat::PackedCandidatePtr aspacked(iso_obj);
  reco::PFCandidatePtr aspf(iso_obj);
  
  const reco::CaloClusterPtr& seed = asreco_electronptr->superCluster()->seed();
  bool isEB = ( seed->seed().subdetId() == EcalBarrel );
  
  const float deltar2 = reco::deltaR2(*physob,*iso_obj);  
  
  
  bool result = true;
  bool inFootprint = false;
  
  //dealing with pat objects
  if( aspacked.isNonnull() && aspacked.get() ) 
  {  
     if( aspacked->charge() != 0 ) {
      bool is_vertex_allowed = false;
      for( const unsigned vtxtype : _miniAODVertexCodes ) {
	if( vtxtype == aspacked->fromPV() ) {
	  is_vertex_allowed = true;
	  break;
	}
      }      
      result *= ( is_vertex_allowed );
    }
    if (!isEB) result *= deltar2 > _vetoConeSize2EE && deltar2 < _coneSize2 ;
    else 
    {
       inFootprint = isInFootprint(aspat_electronptr ->associatedPackedPFCandidates(),aspacked);
       result *= (!inFootprint) && deltar2 < _coneSize2 ;      
    }
    
  }
  
  //dealing with reco objects
  else if ( aspf.isNonnull() && aspf.get() ) 
  {    
    
    if (!isEB) result *= deltar2 > _vetoConeSize2EE && deltar2 < _coneSize2;
    else 
    {
      inFootprint = isInFootprint((*particleBasedIsolationMap)[physob], iso_obj); 
      result *= (!inFootprint) && deltar2 < _coneSize2 ;
    }
  }
  
  else {
    throw cms::Exception("InvalidIsolationInput")
      << "The supplied candidate to be used as isolation "
      << "was neither a reco::PFCandidate nor a pat::PackedCandidate!";
  }
  return result;
}
