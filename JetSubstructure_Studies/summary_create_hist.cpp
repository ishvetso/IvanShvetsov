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
#include <math.h> 
/*
 * g++ -o summary_create_hist summary_create_hist.cpp --std=c++11 `root-config --cflags --libs` -O2 -I./
*/

using namespace std;

void summary(string inputFileList, vector <string> treeNames)
{
  TFile file_out("summary.root", "RECREATE");
    
  vector <string> VarName;

  for (unsigned int iTree = 0; iTree < treeNames.size(); ++iTree )
  {
    TChain chain((treeNames.at(iTree)).c_str());
    TChain chain_gen("gen");
    
    vector <TH1F*> hists;
    vector <TH1F*> hists_response;
   
    if (  (treeNames.at(iTree) == "pf" ) ||  (treeNames.at(iTree) == "chs" ) )
    {
        VarName.push_back("m");
	VarName.push_back("mraw");
	VarName.push_back("mprunedsafe_zcut_010_R_cut_050");
	VarName.push_back("mprunedsafe_zcut_005_R_cut_050");
	VarName.push_back("mprunedsafe_zcut_005_R_cut_075");
	VarName.push_back("mprunedsafe_zcut_010_R_cut_075");
	VarName.push_back("mtrimsafe_Rtrim_020_Ptfrac_005");
	VarName.push_back("mtrimsafe_Rtrim_010_Ptfrac_003");
	VarName.push_back("mtrimsafe_Rtrim_020_Ptfrac_003");
	VarName.push_back("mtrimsafe_Rtrim_030_Ptfrac_003");
	VarName.push_back("msoftdropsafe_beta10");
	VarName.push_back("msoftdropsafe_beta00");
	VarName.push_back("msoftdropsafe_beta20");
      
    }
    
    else if ( treeNames.at(iTree) == "puppi"  )
    {
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
	VarName.push_back("msoftdrop_beta00");
	VarName.push_back("msoftdrop_beta20");
    }
    
    else cerr << "tree name is not supported" << endl;
    
    std::ifstream ifs(inputFileList);
    
    std::string line;

    string prefix = "root://eoscms.cern.ch/";
    string filename;
    
    int counter = 0;
    while(std::getline(ifs, line))
    {
	filename = prefix + line;
	cout << filename << endl;
	chain.Add(filename.c_str());
	chain_gen.Add(filename.c_str());
	counter ++;
	//if (counter > 10) break;
	
    }
        
    vector< vector <float>*> tmp;
    vector< vector <float>*> tmp_gen;
    vector <int> * imatch_tmp = new std::vector<int>();
    vector <float>* pt = new std::vector<float>();
    vector <float>* eta = new std::vector<float>();
    vector <bool> * isMatchedToBoson_tmp = new std::vector<bool>();
      
    
    tmp.reserve(VarName.size());
    tmp_gen.reserve(VarName.size());
     
    vector <string> LabelsAxis;
    
    for (unsigned int iVar = 0; iVar < VarName.size(); iVar++)
    {
      vector <float>* a = new std::vector<float>();
      vector <float>* b = new std::vector<float>();
      tmp.push_back(a);
      tmp_gen.push_back(b);
      
      TH1F *hist_tmp = new TH1F((VarName.at(iVar) + "_" + treeNames.at(iTree)).c_str(), (VarName.at(iVar) + "_" + treeNames.at(iTree)).c_str(), 100, 0., 200.);
      TH1F *hist_tmp_response = new TH1F(( "response_" + VarName.at(iVar) + "_" + treeNames.at(iTree)).c_str(), ("response_" + VarName.at(iVar) + "_" + treeNames.at(iTree)).c_str(), 100, -100., 100.);
      
      hists.push_back(hist_tmp);
      hists_response.push_back(hist_tmp_response); 
      
     
    }
    
    chain.SetBranchAddress("imatch", &imatch_tmp);
    chain.SetBranchAddress("ptcorrphil", &pt);
    chain.SetBranchAddress("eta", &eta);
    chain.SetBranchAddress("is_MatchedToBoson", &isMatchedToBoson_tmp);
    
    for (unsigned int iVar = 0; iVar < tmp.size(); iVar++)
    {
      (tmp.at(iVar)) -> clear();
      (tmp_gen.at(iVar)) -> clear();
      
      chain.SetBranchAddress((VarName.at(iVar)).c_str(), &tmp.at(iVar));
      chain_gen.SetBranchAddress((VarName.at(iVar)).c_str(), &tmp_gen.at(iVar));
    
    }

    cout << chain.GetEntries() << " "  << chain_gen.GetEntries() << endl;  

    for (unsigned int i = 0; i < chain.GetEntries(); ++i)
    {
      
      chain.GetEntry(i);
      chain_gen.GetEntry(i);
    
      
      for (unsigned int iVar = 0; iVar < VarName.size(); ++iVar )
      {
	for (unsigned int iE = 0; iE < (tmp.at(iVar)) -> size(); ++iE )
	{
	  cout << eta -> size() << " " << pt -> size() << endl; 
	  if((isMatchedToBoson_tmp -> at(iE) == true) && ((pt -> at(iE))> 300.)  && ((fabs((eta -> at(iE)))) < 2.5 )  && ( imatch_tmp -> at(iE) != -1 )) 
	  {  
	    hists.at(iVar) -> Fill( (((tmp.at(iVar)) -> at(iE))) );
	    hists_response.at(iVar) -> Fill( ((((tmp.at(iVar)) -> at(iE))) - (((tmp_gen.at(iVar)) -> at(iE)))) );
	  }
	}
	  
	(tmp.at(iVar)) -> clear();
	(tmp_gen.at(iVar)) -> clear();
      }
    }
    
        
    file_out.cd();
    
    for (unsigned int  iVar = 0; iVar < VarName.size(); iVar++ )
    {
       hists.at(iVar)  -> Write();
       hists_response.at(iVar)  -> Write();      
    }
  
        
    hists.clear();
    hists_response.clear();
    VarName.clear();
  }
  

   
}

int main(int argc, char** argv)
{
    vector <string> treeNames;
    treeNames.push_back("pf");
    treeNames.push_back("chs");
    treeNames.push_back("puppi");
        
    summary("/storage/1/ishvetso/git/IvanShvetsov/scripts/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14.txt", treeNames);
  
}
