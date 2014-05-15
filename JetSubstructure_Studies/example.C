#include <vector>
#include "fastjet/Selector.hh"
#include "fastjet/PseudoJet.hh"
#include "fastjet/ClusterSequence.hh"
#include <fastjet/GhostedAreaSpec.hh>
#include "fastjet/GhostedAreaSpec.hh"
#include "fastjet/tools/Filter.hh"
#include "fastjet/tools/Pruner.hh"
#include "fastjet/tools/MassDropTagger.hh"
//#include "fastjet/tools/JetMedianBackgroundEstimator.hh"
#include "fastjet/tools/GridMedianBackgroundEstimator.hh"
#include "fastjet/tools/Subtractor.hh"
#include "fastjet/Selector.hh"
#include "fastjet/Selector.hh"
#include <fastjet/tools/Pruner.hh>
#include <fastjet/tools/Filter.hh>

//#include "JetMETCorrections/Objects/interface/JetCorrector.h"
//#include "JetSubstructure/SubstructureTools/interface/JetSubstructureTools.h"
 #include "JetSubstructure/SubstructureTools/interface/PseudoJetUserInfo.h"
#include "TFile.h"
#include "TTree.h"
#include "TClonesArray.h"
#include "TPFPart.hh"
#include "../interface/TGenEventInfo.hh"
//#include "../interface/TEventInfo.hh"
#include "../interface/TGenParticle.hh"
#include <TMath.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <string>
#include <fstream>
#include "TBranch.h"
#include "TLorentzVector.h"


using namespace std;
using namespace fastjet;

using namespace baconhep;

void readBacon()
{
        TFile* fIn = new TFile("/storage/a/ishvetso/JetSubstructureStudies/ntuple_1_1_VQC.root");
        TTree* tree = (TTree*) fIn->Get("Events");
        TClonesArray *fPFPart = new TClonesArray("baconhep::TPFPart");
	tree->SetBranchAddress("PFPart", &fPFPart);
	
	
	TFile OutputFile ("output.root", "RECREATE");
	
	Float_t mass_jet, mass_Filtered_jet, mass_Pruned_jet, mass_Trimmed_jet;
	
	
	TTree *out_tree = new TTree("Variables", "Variables");
        out_tree -> Branch("mass_jet",&mass_jet,"mass_jet/F");
	out_tree -> Branch("mass_Pruned_jet",&mass_Pruned_jet,"mass_Pruned_jet/F");
	out_tree -> Branch("mass_Trimmed_jet",&mass_Trimmed_jet,"mass_Trimmed_jet/F");
	out_tree -> Branch("mass_Filtered_jet",&mass_Filtered_jet,"mass_Filtered_jet/F");
        
	
      

	for(int i0 = 0; i0 <tree->GetEntriesFast(); i0++) 
	{ //1, event loop

	  tree->GetEntry(i0);

	std::vector<fastjet::PseudoJet> particles; particles.clear();
        for( int i1 = 0; i1 < fPFPart->GetEntriesFast(); i1++)
	{
	  //2,entries loop,fill the vector particles with PF particles
          baconhep::TPFPart *pPartTmp = (baconhep::TPFPart*)((*fPFPart)[i1]);

	  double Px=pPartTmp->pt*cos(pPartTmp->phi);
	  double Py= pPartTmp->pt*sin(pPartTmp->phi);
	  double theta = 2*atan(exp(-pPartTmp->eta)); //eta = -ln(tan(theta/2))
	  double Pz = pPartTmp->pt/tan(theta);
	  double E = pPartTmp->e;
	  double pdgId = pPartTmp->pfType;
	  int charge = pPartTmp->q;
	  fastjet::PseudoJet tmp_psjet(Px, Py, Pz, E);
	  particles.push_back(tmp_psjet);
  
        }//2,entries loop ,fill the vector particles with PFparticles

	fastjet::Selector selected_eta = fastjet::SelectorAbsEtaMax(5.4);
        double R=0.8;//define the jet cone radius to use 
        std::string JetAlgorithm = "AK"; //choose which jet algo to use , write AK for antikt, CA for Cambridge/Achen, KT for kt algo
        
        JetDefinition jet_def(antikt_algorithm,R);


	if (JetAlgorithm == "AK")jet_def.set_jet_algorithm( fastjet::antikt_algorithm );
	else if (JetAlgorithm == "CA")jet_def.set_jet_algorithm( fastjet::cambridge_algorithm );
	else if (JetAlgorithm == "KT")jet_def.set_jet_algorithm( fastjet::kt_algorithm );
	//else throw << " unknown jet algorithm " << std::endl;


        fastjet::ClusterSequence thisClustering_basic(particles, jet_def);
       
        std::vector<fastjet::PseudoJet> out_jets_basic = sorted_by_pt( selected_eta(thisClustering_basic.inclusive_jets(20.0)) );
	 
	
        for(int j=0;j<out_jets_basic.size();j++)
	{
	  double RCut= 0.5;
	  Pruner pruner(jet_def, 0.1,RCut);
	  PseudoJet pruned_jet = pruner(out_jets_basic.at(j));
	  
	  Filter trimmer(JetDefinition(antikt_algorithm, 0.3) ,SelectorPtFractionMin(0.1) );
	  PseudoJet trimmed_jet = (PseudoJet) trimmer.result(out_jets_basic.at(j));
	  
	  Filter filter(JetDefinition(antikt_algorithm, 0.3) , SelectorNHardest(3) );
	  PseudoJet filtered_jet = (PseudoJet) filter.result(out_jets_basic.at(j));
	  
	  mass_jet = out_jets_basic.at(j).m();
	  mass_Pruned_jet = pruned_jet.m();
	  mass_Filtered_jet = filtered_jet.m();
	  mass_Trimmed_jet = trimmed_jet.m();
	  out_tree -> Fill();
	 
        }
       
    }//1 event loop
    
    OutputFile.cd();
    out_tree -> Write();
    OutputFile.Close();
}
