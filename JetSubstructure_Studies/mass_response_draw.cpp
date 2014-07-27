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

void mass_response_draw(string inputFileList, string treeName, string Tag , vector <string> VarNames)
{
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  
  vector <Color_t> Colors;
  Colors.push_back(kBlue);
  Colors.push_back(kGreen);
  Colors.push_back(kRed);
  Colors.push_back(kOrange);
  
  vector <string> Labels;
    
  TChain chain(treeName.c_str());
  TChain chain_gen("gen");
  vector <TH1F*> hists;
  
   TFile file_out(("mass_response_" + Tag + "_" + treeName + ".root").c_str(), "RECREATE");
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
     // if (counter > 1) break;
      
  }
      
  vector< vector <float>*> tmp;
  vector< vector <float>*> tmp_gen;
  vector <int> * imatch_tmp = new std::vector<int>();
  vector <float>* pt = new std::vector<float>();
  vector <bool> * isMatchedToBoson_tmp = new std::vector<bool>();
    
  
  tmp.reserve(VarNames.size());
  tmp_gen.reserve(VarNames.size());

  
  for (unsigned int iVar = 0; iVar < VarNames.size(); iVar++)
  {
    vector <float>* a = new std::vector<float>();
    vector <float>* b = new std::vector<float>();
    tmp.push_back(a);
    tmp_gen.push_back(b);
    TH1F *hist_tmp ;
    hist_tmp = new TH1F((VarNames.at(iVar) + "_" + treeName).c_str(), (VarNames.at(iVar) + "_" + treeName).c_str(), 100, -150., 150.);
    hists.push_back(hist_tmp); 
	
  }
  
  chain.SetBranchAddress("imatch", &imatch_tmp);
  chain.SetBranchAddress("pt", &pt);
  chain.SetBranchAddress("is_MatchedToBoson", &isMatchedToBoson_tmp);
  
  for (unsigned int iVar = 0; iVar < tmp.size(); iVar++)
  {
    (tmp.at(iVar)) -> clear();
    (tmp_gen.at(iVar)) -> clear();
    chain.SetBranchAddress((VarNames.at(iVar)).c_str(), &tmp.at(iVar));
    chain_gen.SetBranchAddress((VarNames.at(iVar)).c_str(), &tmp_gen.at(iVar));
    
    if (VarNames.at(iVar) == "m") Labels.push_back("m");
    else if (VarNames.at(iVar) == "mraw") Labels.push_back("m_{raw}");
    else if ((VarNames.at(iVar) == "mpruned_zcut_010_R_cut_050") || (VarNames.at(iVar) == "mprunedsafe_zcut_010_R_cut_050") ) Labels.push_back("m_{pruned} z_{cut}=0.1 R_{cut}=0.5");
    else if ((VarNames.at(iVar) == "mpruned_zcut_005_R_cut_050") || (VarNames.at(iVar) == "mprunedsafe_zcut_005_R_cut_050")) Labels.push_back("m_{pruned} z_{cut}=0.05 R_{cut}=0.5");
    else if ((VarNames.at(iVar) == "mpruned_zcut_005_R_cut_075") || (VarNames.at(iVar) == "mprunedsafe_zcut_005_R_cut_075")) Labels.push_back("m_{pruned} z_{cut}=0.05 R_{cut}=0.75");
    else if ((VarNames.at(iVar) == "mpruned_zcut_010_R_cut_075") || (VarNames.at(iVar) == "mprunedsafe_zcut_010_R_cut_075")) Labels.push_back("m_{pruned} z_{cut}=0.1 R_{cut}=0.75");
    else if ((VarNames.at(iVar) == "mtrim_Rtrim_020_Ptfrac_005") || (VarNames.at(iVar) == "mtrimsafe_Rtrim_020_Ptfrac_005")) Labels.push_back("m_{trim} R_{trim}=0.2 pT_{frac}=0.05");
    else if ((VarNames.at(iVar) == "mtrim_Rtrim_010_Ptfrac_003") || (VarNames.at(iVar) == "mtrimsafe_Rtrim_010_Ptfrac_003")) Labels.push_back("m_{trim} R_{trim}=0.1 pT_{frac}=0.03");
    else if ((VarNames.at(iVar) == "mtrim_Rtrim_020_Ptfrac_003") || (VarNames.at(iVar) == "mtrimsafe_Rtrim_020_Ptfrac_003")) Labels.push_back("m_{trim} R_{trim}=0.2 pT_{frac}=0.03");
    else if ((VarNames.at(iVar) == "mtrim_Rtrim_030_Ptfrac_003") || (VarNames.at(iVar) == "mtrimsafe_Rtrim_030_Ptfrac_003")) Labels.push_back("m_{trim} R_{trim}=0.3 pT_{frac}=0.03");
    else if ((VarNames.at(iVar) == "msoftdrop_beta10") || (VarNames.at(iVar) == "msoftdropsafe_beta10")) Labels.push_back("m_{softdrop} #beta=1");
    else if ((VarNames.at(iVar) == "msoftdrop_beta00") || (VarNames.at(iVar) == "msoftdropsafe_beta00")) Labels.push_back("m_{softdrop} #beta=0");
    else if ((VarNames.at(iVar) == "msoftdrop_beta20") || (VarNames.at(iVar) == "msoftdropsafe_beta20")) Labels.push_back("m_{softdrop} #beta=2");
    else cout << "Not supported label " << endl;	

  
  }

  cout << chain.GetEntries() << " "  << chain_gen.GetEntries() << endl;  

  for (unsigned int i = 0; i < chain.GetEntries(); ++i)
  {
    
    chain.GetEntry(i);
    chain_gen.GetEntry(i);
  
    
    for (unsigned int iVar = 0; iVar < VarNames.size(); ++iVar )
    {
      for (unsigned int iE = 0; iE < (tmp.at(iVar)) -> size(); ++iE )
      {
	if((isMatchedToBoson_tmp -> at(iE) == true) && ((pt -> at(iE))> 300.) &&  imatch_tmp -> at(iE) != -1) 
	{  
	  hists.at(iVar) -> Fill( (((tmp.at(iVar)) -> at(iE)) - ((tmp_gen.at(iVar)) -> at(imatch_tmp -> at(iE)))) );
	}
      }
	
      (tmp.at(iVar)) -> clear();
      (tmp_gen.at(iVar)) -> clear();
    }
  }

  
  file_out.cd();
  TCanvas *c1=  new TCanvas("c1","canvas",1000,800);
  c1->SetTickx(1);
  c1->SetTicky(1); 
  
  TLegend  *leg = new TLegend(0.6,0.6,0.95,0.85);
  leg ->  SetTextSize(0.023);
  leg ->  SetFillStyle(0.);
  leg -> SetLineWidth(0.);
  leg -> SetLineColor(kWhite);
  
  for (unsigned int  iVar = 0; iVar < VarNames.size(); iVar++ )
  {

    hists.at(iVar)  -> Write();
    hists.at(iVar)  -> SetLineColor(Colors.at(iVar));
    hists.at(iVar)  -> SetLineWidth(2.);
    hists.at(iVar)  -> Draw("HISTSAME");
    leg->AddEntry(hists.at(iVar),(Labels.at(iVar)).c_str(),"l");
    
  }
 
  
  TPaveText descriptionPave(0.12,0.75,0.3,0.85, "NDC");
  TPaveText descriptionPaveCMS(0.12,0.9,0.3,1.0, "NDC");
  descriptionPave.SetTextAlign(11);
  descriptionPave.SetFillStyle(0);  // transparent
  descriptionPave.SetBorderSize(0);
  descriptionPave.SetTextSize(0.03);
  descriptionPave.AddText("WW, Antikt jets with R = 0.8");// \\ p_{T}^{jet} > 300 GeV");
  descriptionPave.AddText("p_{T}^{jet} > 300 GeV" );
  if (treeName == "pf") descriptionPave.AddText("PF Jets");
  else if (treeName == "chs") descriptionPave.AddText("PF + CHS Jets");
  else if (treeName == "puppi") descriptionPave.AddText("PUPPI Jets");
  else cerr << "Tree Name is not supported " << endl;
  descriptionPave.SetTextSize(0.025);
  
  descriptionPaveCMS.SetTextAlign(11);
  descriptionPaveCMS.SetFillStyle(0);  // transparent
  descriptionPaveCMS.SetBorderSize(0);
  descriptionPaveCMS.SetTextSize(0.03);
  descriptionPaveCMS.AddText("CMS Simulation Preliminary #sqrt{s} = 13 TeV");
  
  
  

  
  descriptionPave.Draw();
  descriptionPaveCMS.Draw();
  leg -> Draw();
 
  system("mkdir -p plots_mass_response");
  
  c1 -> SaveAs( ("plots_mass_response/mass_response_" + treeName + "_"+ Tag + ".png").c_str());
   
}

int main(int argc, char** argv)
{
  vector <string> VarNamesPruning, VarNamesTrimmed, VarNamesSoftDrop;
  VarNamesPruning.push_back("mpruned_zcut_010_R_cut_050");
  VarNamesPruning.push_back("mpruned_zcut_005_R_cut_050");
  VarNamesPruning.push_back("mpruned_zcut_005_R_cut_075");
  VarNamesPruning.push_back("mpruned_zcut_010_R_cut_075");
  
  VarNamesTrimmed.push_back("mtrim_Rtrim_020_Ptfrac_005");
  VarNamesTrimmed.push_back("mtrim_Rtrim_010_Ptfrac_003");
  VarNamesTrimmed.push_back("mtrim_Rtrim_020_Ptfrac_003");
  VarNamesTrimmed.push_back("mtrim_Rtrim_030_Ptfrac_003");
  
  VarNamesSoftDrop.push_back("msoftdrop_beta20");
  VarNamesSoftDrop.push_back("msoftdrop_beta10");
  VarNamesSoftDrop.push_back("msoftdrop_beta00");
  VarNamesSoftDrop.push_back("msoftdrop_beta-10");
    
   string TreeName = argv[1];
   string Tag = argv[2];
   
   vector <string> Vars;
   
   for (unsigned int i = 3; i < argc; i++)
   {
      Vars.push_back(argv[i]);
   }
     
        
    mass_response_draw("/storage/a/ishvetso/git_repository/IvanShvetsov/scripts/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14.txt", TreeName, Tag, Vars);
    
   
}

