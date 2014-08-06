#include "HistPUBinsProducer.cpp"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TLatex.h"
#include <sstream>
#include "TGaxis.h"

/*
 * Plotting PU-dependence plots for different groomers:
 * Mean mass, RMS mass, Mean response, RMS response by fitting gaussian and calculating mean and RMS
 * 
 * for JME-14-001
 * 
 * Compile with
 * g++ -o PUBinPlotter  PUBinPlotter.cpp --std=c++11 `root-config --cflags --libs` -O2 -I./
 * 
 */

void WritePUBins()
{

  HistPUBinsProducer Producer;
  
  string inputFileList = "/storage/1/ishvetso/git/IvanShvetsov/scripts/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14.txt";
  std::ifstream ifs(inputFileList);
  std::string line;
  
  int counter = 0;
  
  while(std::getline(ifs, line))
  {
    Producer.SetInputFiles("root://eoscms.cern.ch/" + line);
    counter ++;
    std::cout << line << std::endl;
    //if (counter > 1) break;
  }

  Float_t PUmin = 15., PUmax = 50.; //PUmax not included --> [20,21), [21, 22).... [49,50)
  Int_t interval =5;
  Producer.SetPUBinsParameters(PUmin, PUmax, interval);
  Producer.SetBinParameters(100, 0.,200.);
  Producer.SetResponseParameters(-100., 100.);
  vector <TH1F*> hists;
  vector <TH1F*> hists_response;
  
  
  vector <string> VarNames;
  vector <string> treeNames;
  
  treeNames.push_back("pf");
  treeNames.push_back("chs");
  treeNames.push_back("puppi");
  
  TFile file("PileUpBins.root", "RECREATE");  
  
  for (unsigned int iTree = 0; iTree < treeNames.size(); ++iTree)
  {
  

    if (  (treeNames.at(iTree) == "pf" ) ||  (treeNames.at(iTree) == "chs" ) )
    {
        VarNames.push_back("m");
	VarNames.push_back("mraw");
	VarNames.push_back("mprunedsafe_zcut_010_R_cut_050");
	VarNames.push_back("mprunedsafe_zcut_005_R_cut_050");
	VarNames.push_back("mprunedsafe_zcut_005_R_cut_075");
	VarNames.push_back("mprunedsafe_zcut_010_R_cut_075");
	VarNames.push_back("mtrimsafe_Rtrim_020_Ptfrac_005");
	VarNames.push_back("mtrimsafe_Rtrim_010_Ptfrac_003");
	VarNames.push_back("mtrimsafe_Rtrim_020_Ptfrac_003");
	VarNames.push_back("mtrimsafe_Rtrim_030_Ptfrac_003");
	VarNames.push_back("msoftdropsafe_beta10");
	VarNames.push_back("msoftdropsafe_beta00");
	VarNames.push_back("msoftdropsafe_beta20");
      
    }
    
    else if ( treeNames.at(iTree) == "puppi"  )
    {
        VarNames.push_back("m");
	VarNames.push_back("mraw");
	VarNames.push_back("mpruned_zcut_010_R_cut_050");
	VarNames.push_back("mpruned_zcut_005_R_cut_050");
	VarNames.push_back("mpruned_zcut_005_R_cut_075");
	VarNames.push_back("mpruned_zcut_010_R_cut_075");
	VarNames.push_back("mtrim_Rtrim_020_Ptfrac_005");
	VarNames.push_back("mtrim_Rtrim_010_Ptfrac_003");
	VarNames.push_back("mtrim_Rtrim_020_Ptfrac_003");
	VarNames.push_back("mtrim_Rtrim_030_Ptfrac_003");
	VarNames.push_back("msoftdrop_beta10");
	VarNames.push_back("msoftdrop_beta00");
	VarNames.push_back("msoftdrop_beta20");
    }

  

  file.cd();

  
  for (unsigned iVar = 0; iVar < VarNames.size(); ++iVar)
  {
     Producer.VarName = VarNames[iVar];  
     hists.clear();
     hists_response.clear();
     hists = Producer.ProduceHists(treeNames.at(iTree));
     hists_response = Producer.hists_response;     
     Int_t Npoints = hists.size();
     string PUNumberLow[Npoints], PUNumberUp[Npoints];
    
     cout << VarNames[iVar] << endl;
     
     for (unsigned int i =0; i< Npoints;++i)
     {
	ostringstream Number;   
	Number<< PUmin + interval*i;
	PUNumberLow[i] = Number.str();
	Number.str("");
	
	Number<< PUmin + interval*(i + 1);
	PUNumberUp[i] = Number.str();
	    
	hists.at(i) -> SetName((treeNames.at(iTree) + "_"  + VarNames.at(iVar) +  "_[" + PUNumberLow[i] + ", "  + PUNumberUp[i] + "]"  ).c_str());
	hists_response.at(i) -> SetName(( "response_" +  treeNames.at(iTree) + "_"  + VarNames.at(iVar) +  "_[" +  PUNumberLow[i] + ", "  + PUNumberUp[i] + "]" ).c_str());
	
	hists.at(i) -> Write();
	hists_response.at(i) -> Write();
    }
  }
  
  VarNames.clear();
 }
}

int main(int argc, char** argv)
{
    WritePUBins(); 
}