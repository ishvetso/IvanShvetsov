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
#include "TPaveText.h"
using namespace std;
void summary(string inputFileList, string treeName)
{
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  
  TChain chain(treeName.c_str());
  vector <TH1F*> hists;

  std::ifstream ifs(inputFileList);
  
  std::string line;

  string prefix = "root://eoscms.cern.ch/";
  string filenname;
  
  while(std::getline(ifs, line))
  {
      filenname = prefix + line;
      cout << filenname << endl;
      chain.Add(filenname.c_str());
      
  }
  vector <string> VarName;
  VarName.push_back("m");
  VarName.push_back("mraw");
  VarName.push_back("mpruned_zcut_010_R_cut_050");
  VarName.push_back("mpruned_zcut_005_R_cut_050");
  VarName.push_back("mpruned_zcut_005_R_cut_075");
  VarName.push_back("mpruned_zcut_010_R_cut_075");
  VarName.push_back("mtrim_Rtrim_020_Ptfrac_005");
  VarName.push_back("mtrim_Rtrim_010_Ptfrac_003");
  VarName.push_back("mtrim_Rtrim_020_Ptfrac_003");
  VarName.push_back("mtrim_Rtrim_030_Ptfrac_003");
  VarName.push_back("msoftdrop_beta10");
  VarName.push_back("msoftdrop_beta-10");
  VarName.push_back("msoftdrop_beta00");
  VarName.push_back("msoftdrop_beta20");
  vector< vector <float>*> tmp;
  vector <int> * imatch_tmp = new std::vector<int>();
  vector <float>* pt = new std::vector<float>();
  vector <bool> * isMatchedToBoson_tmp = new std::vector<bool>();
     
  TFile file_out(("summary_"+ treeName + ".root").c_str(), "RECREATE");
  tmp.reserve(VarName.size());
  
  for (unsigned int iVar = 0; iVar < VarName.size(); iVar++)
  {
    vector <float>* a = new std::vector<float>();
    tmp.push_back(a);
    TH1F *hist_tmp ;
    hist_tmp = new TH1F((VarName.at(iVar) + "_" + treeName).c_str(), (VarName.at(iVar) + "_" + treeName).c_str(), 30, 60., 120.);
//    else if (iVar == 0) hist_tmp = new TH1F((VarName.at(iVar) + "_" + treeName).c_str(), (VarName.at(iVar) + "_" + treeName).c_str(), 30, 70., 140.);
    if (iVar == 1) hist_tmp = new TH1F((VarName.at(iVar) + "_" + treeName).c_str(), (VarName.at(iVar) + "_" + treeName).c_str(), 30, 60., 160.);
    hists.push_back(hist_tmp);   
  }
  
  chain.SetBranchAddress("imatch", &imatch_tmp);
  chain.SetBranchAddress("pt", &pt);
  chain.SetBranchAddress("is_MatchedToBoson", &isMatchedToBoson_tmp);
  
  for (unsigned int iVar = 0; iVar < tmp.size(); iVar++)
  {
    (tmp.at(iVar)) -> clear();
    chain.SetBranchAddress((VarName.at(iVar)).c_str(), &tmp.at(iVar));
  
  }

  cout << chain.GetEntries() << endl;  

   for (unsigned int i = 0; i < chain.GetEntries(); ++i)
  {
    
    chain.GetEntry(i);
  
    
    for (unsigned int iVar = 0; iVar < VarName.size(); ++iVar )
    {
      for (unsigned int iE = 0; iE < (tmp.at(iVar)) -> size(); ++iE )
      {
	if((isMatchedToBoson_tmp -> at(iE)) && ((pt -> at(iE))> 300.) &&  imatch_tmp -> at(iE) != -1) 
	{  
	  hists.at(iVar) -> Fill( ((tmp.at(iVar)) -> at(iE)) );
	}
      }
	
      (tmp.at(iVar)) -> clear();
    }
   }
   
  TH1F * hist_Summary = new TH1F ("Summary", "Summary", VarName.size(), 0., 10.);
  file_out.cd();
  for (unsigned int  iVar = 0; iVar < VarName.size(); iVar++ )
  {
    hist_Summary -> SetBinContent(iVar + 1, ( hists.at(iVar) )-> GetRMS());
    hist_Summary -> GetXaxis() -> SetBinLabel(iVar + 1, (VarName.at(iVar)).c_str());
    hists.at(iVar)  -> Write();
  }
  hist_Summary -> GetXaxis() -> SetLabelSize(0.023);
  
  TPaveText descriptionPave(0.75,0.75,0.9,0.9, "NDC");
  descriptionPave.AddText(treeName.c_str());
 
  TCanvas *c1=  new TCanvas("c1","canvas",1200,1000);
  hist_Summary -> SetMarkerStyle(22);
  hist_Summary -> SetMarkerSize(2.);
  hist_Summary -> SetMarkerColor(kBlue);
  hist_Summary -> Draw("P");
  descriptionPave.Draw();
  c1 -> SaveAs(("summary_grooming_algos_" + treeName + ".png").c_str());
   
}

int main(int argc, char** argv)
{
    string treeName = argv[1];
        
    summary("/storage/a/ishvetso/git_repository/IvanShvetsov/scripts/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14.txt", treeName);
  
}
