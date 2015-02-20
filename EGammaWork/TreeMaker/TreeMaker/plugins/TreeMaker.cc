// -*- C++ -*-
//
// Package:    TreeMaker/TreeMaker
// Class:      TreeMaker
// 
/**\class TreeMaker TreeMaker.cc TreeMaker/TreeMaker/plugins/TreeMaker.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Ivan Shvetsov
//         Created:  Thu, 19 Feb 2015 12:15:26 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/PatCandidates/interface/Electron.h"

#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "TTree.h"
//
// class declaration
//

class TreeMaker : public edm::EDAnalyzer {
   public:
      explicit TreeMaker(const edm::ParameterSet&);
      ~TreeMaker();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;
      
      edm::EDGetTokenT<edm::ValueMap<float> > ValueMaps_ChargedHadrons_, ValueMaps_NeutralHadrons_, ValueMaps_Photons_;
      edm::EDGetTokenT<edm::View<pat::Electron> > Electrons_;
       TTree* Tree;
       
       double sumChargedHadronPt_PF, sumChargedHadronPt_CITK, sumNeutralHadronEt_PF, sumNeutralHadronEt_CITK, sumPhotonEt_PF, sumPhotonEt_CITK;

      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
TreeMaker::TreeMaker(const edm::ParameterSet& iConfig):
  ValueMaps_ChargedHadrons_(consumes<edm::ValueMap<float> > (iConfig.getParameter<edm::InputTag>( "ValueMaps_ChargedHadrons_src" ) ) ),
  ValueMaps_NeutralHadrons_(consumes<edm::ValueMap<float> > (iConfig.getParameter<edm::InputTag>( "ValueMaps_NeutralHadrons_src" ) ) ),
  ValueMaps_Photons_(consumes<edm::ValueMap<float> > (iConfig.getParameter<edm::InputTag>( "ValueMaps_Photons_src" ) ) ),
  Electrons_(consumes<edm::View<pat::Electron> > (iConfig.getParameter<edm::InputTag>( "electron_src" ) ) )

{
   //now do what ever initialization is needed
  edm::Service<TFileService> fs;
  Tree = fs->make<TTree>("Iso","Iso");
  
  
  Tree -> Branch("sumChargedHadronPt_PF", &sumChargedHadronPt_PF, "sumChargedHadronPt_PF/D");
  Tree -> Branch("sumChargedHadronPt_CITK", &sumChargedHadronPt_CITK, "sumChargedHadronPt_CITK/D");
  
  Tree -> Branch("sumNeutralHadronEt_PF", &sumNeutralHadronEt_PF, "sumNeutralHadronEt_PF/D");
  Tree -> Branch("sumNeutralHadronEt_CITK", &sumNeutralHadronEt_CITK, "sumNeutralHadronEt_CITK/D");
  
  Tree -> Branch("sumPhotonEt_PF", &sumPhotonEt_PF, "sumPhotonEt_PF/D");
  Tree -> Branch("sumPhotonEt_CITK", &sumPhotonEt_CITK, "sumPhotonEt_CITK/D");
  

}


TreeMaker::~TreeMaker()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
TreeMaker::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   
   Handle <edm::ValueMap <float> > ValueMaps_ChargedHadrons, ValueMaps_NeutralHadrons, ValueMaps_Photons;
   Handle<edm::View<pat::Electron> > Electrons;
   
   iEvent.getByToken( ValueMaps_ChargedHadrons_ , ValueMaps_ChargedHadrons);
   iEvent.getByToken( ValueMaps_NeutralHadrons_ , ValueMaps_NeutralHadrons);
   iEvent.getByToken( ValueMaps_Photons_ , ValueMaps_Photons);
   iEvent.getByToken(Electrons_, Electrons);

   
   for (unsigned int iElectron = 0; iElectron < Electrons -> size(); iElectron ++)
   {
       sumChargedHadronPt_CITK =  (*ValueMaps_ChargedHadrons)[Electrons -> ptrAt(iElectron)];
       sumNeutralHadronEt_CITK =  (*ValueMaps_NeutralHadrons)[Electrons -> ptrAt(iElectron)];
       sumPhotonEt_CITK        =  (*ValueMaps_Photons)[Electrons -> ptrAt(iElectron)];
       
       reco::GsfElectron::PflowIsolationVariables pfIso = (Electrons -> at(iElectron)).pfIsolationVariables();
       
       sumChargedHadronPt_PF = pfIso.sumChargedHadronPt;
       sumNeutralHadronEt_PF = pfIso.sumNeutralHadronEt;
       sumPhotonEt_PF = pfIso.sumPhotonEt;
       
       Tree -> Fill();
   }

#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
TreeMaker::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
TreeMaker::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
void 
TreeMaker::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
TreeMaker::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
TreeMaker::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
TreeMaker::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
TreeMaker::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(TreeMaker);
