#include <TFile.h>
#include <TTree.h>
#include <TTreeFormula.h>
#include <TH1.h>
#include <THStack.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TAxis.h>
#include <iostream>
#include <iostream>
#include <sstream>
#include <map>
#include "Plotter.cpp"

void draw()
{
	vector <Var> variables;
	Var var;
	
	var.VarName = "NBtag";
	var.SetRange(0., 6.);
	variables.push_back(var);

	
	var.VarName = "pt_W_lep";
	var.SetRange(0., 1500.);
	variables.push_back(var);
	
	var.VarName = "pt_W_had";
	var.SetRange(0., 1500.);
	variables.push_back(var);
	
	var.VarName = "eta_W_lep";
	var.SetRange(-3., 3.);
	variables.push_back(var);
	
	var.VarName = "eta_W_had";
	var.SetRange(-3., 3.);
	variables.push_back(var);
	
	var.VarName = "phi_W_lep";
	var.SetRange(-3.2, 3.2);
	variables.push_back(var);
	
	var.VarName = "phi_W_had";
	var.SetRange(-3.2, 3.2);
	variables.push_back(var);
	
	var.VarName = "mass_W_lep";
	var.SetRange(40., 200.);
	variables.push_back(var);
	
	var.VarName = "mass_W_had";
	var.SetRange(40., 200.);
	variables.push_back(var);
	
	var.VarName = "mass_W_pruned";
	var.SetRange(50., 110.);
	variables.push_back(var);
	
	var.VarName = "mt_W_lep";
	var.SetRange(0., 1500.);
	variables.push_back(var);
	
	var.VarName = "mt_W_had";
	var.SetRange(0., 1500.);
	variables.push_back(var);
	
	var.VarName = "charge_W_lep";
	var.SetRange(-2., 2.);
	variables.push_back(var);
	
	var.VarName = "N_had_W";
	var.SetRange(0., 4.);
	variables.push_back(var);
	
	var.VarName = "N_lep_W";
	var.SetRange(0., 4.);
	variables.push_back(var);
	
	var.VarName = "WDecayClass";
	var.SetRange(0., 4.);
	variables.push_back(var);
	
	var.VarName = "N_had_W_gen";
	var.SetRange(0., 4.);
	variables.push_back(var);
	
	var.VarName = "N_lep_W_gen";
	var.SetRange(0., 4.);
	variables.push_back(var);
	
	var.VarName = "tau1";
	var.SetRange(0., 0.8);
	variables.push_back(var);
	
	var.VarName = "tau2";
	var.SetRange(0., 0.4);
	variables.push_back(var);
	
	var.VarName = "tau3";
	var.SetRange(0., 0.25);
	variables.push_back(var);
	
	var.VarName = "tau21";
	var.SetRange(0., 1.);
	variables.push_back(var);
	
	var.VarName = "MET";
	var.SetRange(0., 1400.);
	variables.push_back(var);
	
	var.VarName = "MET_phi";
	var.SetRange(-3.2, 3.2);
	variables.push_back(var);
	
	var.VarName = "MET_mass";
	var.SetRange(-1., 1.);
	variables.push_back(var);
	
	var.VarName = "MET_mt";
	var.SetRange(0., 1200.);
	variables.push_back(var);
	
	
	var.VarName = "pt_ele";
	var.SetRange(0., 1000.);
	variables.push_back(var);
	
	var.VarName = "eta_ele";
	var.SetRange(-4., 4.);
	variables.push_back(var);
	
	var.VarName = "phi_ele";
	var.SetRange(-3.2, 3.2);
	variables.push_back(var);
	
	var.VarName = "charge_ele";
	var.SetRange(-2., 2.);
	variables.push_back(var);
	
	var.VarName = "relIso_ele";
	var.SetRange(0., 1.);
	variables.push_back(var);
	
	var.VarName = "pt_mu";
	var.SetRange(0., 1000.);
	variables.push_back(var);
	
	var.VarName = "eta_mu";
	var.SetRange(-4., 4.);
	variables.push_back(var);
	
	var.VarName = "phi_mu";
	var.SetRange(-3.2, 3.2);
	variables.push_back(var);
	
	var.VarName = "charge_mu";
	var.SetRange(-2., 2.);
	variables.push_back(var);
	
	var.VarName = "relIso_muon";
	var.SetRange(0., 20.);
	variables.push_back(var);
	
	var.VarName = "pt_lep";
	var.SetRange(0., 1000.);
	variables.push_back(var);
	
	var.VarName = "eta_lep";
	var.SetRange(-3., 3.);
	variables.push_back(var);
	
	var.VarName = "phi_lep";
	var.SetRange(-3.2, 3.2);
	variables.push_back(var);
	
	var.VarName = "deltaR_LepWJet";
	var.SetRange(0.0, 6.0);
	variables.push_back(var);
	
	var.VarName = "deltaPhi_LepMet";
	var.SetRange(-3.2, 3.2);
	variables.push_back(var);
	
	var.VarName = "deltaPhi_WJetMet";
	var.SetRange(-3.2, 3.2);
	variables.push_back(var);

	
	
	Plotter p;
	p.withData = false;
	vector <Sample> samples;
	p.SetVar(variables);
	p.SetNbins(30);
	
	string MCSelection = "weight";
	string DataSelection = "";
		
	/*
	 * Colors
	 * kWhite =0,   kBlack =1,   kGray=920,  kRed   =632, kGreen =416, kBlue=600, 
	 * kYellow=400, kMagenta=616, kCyan=432, kOrange=800, kSpring=820, kTeal=840,
	 * kAzure =860, kViolet =880, kPink=900
	 */
	
	Sample s;
	
	string Prefix = "/afs/cern.ch/work/i/ishvetso/samples_PHYS14/";
		  
	
	
	s.SetParameters("t#bar{t}", MCSelection, kOrange);
 	s.SetFileNames("/afs/cern.ch/work/i/ishvetso/RunII_preparation/CMSSW_7_2_2_patch1/src/WW-analysis/Common/test/crab_projects_Phys14_btag/crab_TT_Tune4C_13TeV-pythia8-tauola/results/ttbar.root");
	samples.push_back(s);
	s.ReSet();
		
	s.SetParameters("W+jets", MCSelection, kGreen);
 	s.SetFileNames("/afs/cern.ch/work/i/ishvetso/RunII_preparation/CMSSW_7_2_2_patch1/src/WW-analysis/Common/test/crab_projects_Phys14_btag/crab_WJetsToLNu_13TeV-madgraph-pythia8-tauola/results/Wjets.root");
	samples.push_back(s);
	s.ReSet();
	
	p.SetSamples(samples);
 	p.Plotting("plots/PHYS14/");
	
	
}
