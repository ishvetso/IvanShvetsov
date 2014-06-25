#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TCanvas.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TLine.h"
#include "TH1F.h"
#include "TPad.h"
#include <TStyle.h>
#include <TFolder.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

void response()
{
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  
  TFile file("/storage/a/ishvetso/JetSubstructureStudies/Trees/WW/WWtree_AK8.root", "READ");
  
  TTree *tr = (TTree*)file.Get("pf");
  
 vector< vector <float>*> mass;
 vector <float>* mass_gen = new std::vector<float>();
 vector <int> * imatch = new std::vector<int>();
    
 tr -> SetBranchAddress("imatch", &imatch);
 tr -> SetBranchAddress("mgen", &mass_gen);
 
  
  vector <TH1F*> hists;
  vector <string> VarName;
  VarName.push_back("m");
  VarName.push_back("mtrim");
  VarName.push_back("mtrimsafe");
  VarName.push_back("msoftdrop");
  VarName.push_back("mpruned");
  VarName.push_back("mraw");
  
  vector <Color_t> colors;
  colors.push_back(kBlue);
  colors.push_back(kRed);
  colors.push_back(kRed+2);
  colors.push_back(kOrange);
  colors.push_back(kGreen);
   colors.push_back(kYellow);
  
  mass.reserve(VarName.size());
 
  
  for (unsigned int iVar = 0; iVar < VarName.size(); iVar++)
  {
    vector <float>* tmp = new std::vector<float>();
    mass.push_back(tmp);
    TH1F *hist_tmp = new TH1F((VarName.at(iVar)).c_str(), (VarName.at(iVar)).c_str(), 30, -100., 100.);
    hists.push_back(hist_tmp);
   
  }
  
  for (unsigned int iVar = 0; iVar < VarName.size(); iVar++)
  {
    (mass.at(iVar)) -> clear();
     tr -> SetBranchAddress((VarName.at(iVar)).c_str(), &mass.at(iVar));
  }
  
  for (unsigned int i = 0; i < tr -> GetEntries(); ++i)
  {
    tr -> GetEntry(i);
   
  //  if ((mass_gen -> size()) != ( mass -> size() )) cerr << "Smth is wrong" << endl;
    for (unsigned int iVar = 0; iVar < VarName.size(); ++iVar )
    {
      for (unsigned int iE = 0; iE < (mass.at(iVar)) -> size(); ++iE )
      {
	if( (imatch -> at(iE)) != -1) hists.at(iVar) -> Fill( (((mass.at(iVar)) -> at((imatch ->at(iE)))) - (mass_gen -> at(iE))));
	
      }
       (mass.at(iVar)) -> clear();
    }

  }
  
   TCanvas *c1=  new TCanvas("c1","canvas",1200,800);
   TLegend *leg = new TLegend(0.8,0.6,0.9,0.9);
   
    (hists.at(0) ) -> GetYaxis() -> SetRangeUser( (hists.at(0) ) -> GetYaxis() -> GetXmin(), ( (hists.at(0) ) -> GetMaximum())*2.2 );
   for (unsigned int iHist = 0; iHist < VarName.size(); ++iHist)
   {
     (hists.at(iHist) ) -> SetLineColor(colors.at(iHist));
     (hists.at(iHist) ) -> SetLineWidth(3.);
     leg->AddEntry(hists.at(iHist), (VarName.at(iHist)).c_str(), "l");
   
     (hists.at(iHist) )-> Draw("HISTSAME");
   }
   
    leg -> Draw();
    c1 -> SaveAs("WW_response_test.png");
  
}