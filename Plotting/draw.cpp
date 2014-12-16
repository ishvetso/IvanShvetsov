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
	
	var.VarName = "mt_W_lep";
	var.SetRange(0., 2500.);
	variables.push_back(var);
	
	Plotter p;
	p.withData = false;
	vector <Sample> samples;
	p.SetVar(variables);
	p.SetNbins(300);
	
	string MCSelection = "";
	string DataSelection = "";
	string Prefix = "/afs/cern.ch/work/i/ishvetso/RunII_preparation/CMSSW_7_2_2_patch1/src/WW-analysis/Common/test/crab_projects/crab_RSGravitonToWW_kMpl01_M_2000_Tune4C_13TeV_pythia8/results/";
	
	/*
	 * Colors
	 * kWhite =0,   kBlack =1,   kGray=920,  kRed   =632, kGreen =416, kBlue=600, 
	 * kYellow=400, kMagenta=616, kCyan=432, kOrange=800, kSpring=820, kTeal=840,
	 * kAzure =860, kViolet =880, kPink=900
	 */
	
	Sample s;
	
	
	
	s.SetParameters("RSGraviton", MCSelection, kGreen);
	s.SetFileNames(Prefix + "tree_1.root");
	samples.push_back(s);
	s.ReSet();
	
	
	p.SetSamples(samples);
 	p.Plotting();
}
