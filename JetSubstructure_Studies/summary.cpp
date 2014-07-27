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

void summary(string inputFileList, vector <string> treeNames)
{
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  
  vector <Color_t> Colors;
  Colors.push_back(kBlue);
  Colors.push_back(kGreen);
  Colors.push_back(kRed);
  
  vector <string> Labels;
  
  
  TFile file_out("summary.root", "RECREATE");
 
  vector <TH1F * > hists_summary_Fit;
  vector <TH1F * > hists_summary_Estimation;
  
  hists_summary_Fit.reserve(treeNames.size());
  hists_summary_Estimation.reserve(treeNames.size());
  
  vector <string> VarName;

  
  
  for (unsigned int iTree = 0; iTree < treeNames.size(); ++iTree )
  {
    TChain chain((treeNames.at(iTree)).c_str());
    TChain chain_gen("gen");
    vector <TH1F*> hists;
   
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
	//if (counter > 1) break;
	
    }
        
    vector< vector <float>*> tmp;
    vector< vector <float>*> tmp_gen;
    vector <int> * imatch_tmp = new std::vector<int>();
    vector <float>* pt = new std::vector<float>();
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
      TH1F *hist_tmp ;
      hist_tmp = new TH1F((VarName.at(iVar) + "_" + treeNames.at(iTree)).c_str(), (VarName.at(iVar) + "_" + treeNames.at(iTree)).c_str(), 100, -150., 150.);
      hists.push_back(hist_tmp); 
      
      if (VarName.at(iVar) == "m") LabelsAxis.push_back("m");
      else if (VarName.at(iVar) == "mraw") LabelsAxis.push_back("m_{raw}");
      else if ((VarName.at(iVar) == "mpruned_zcut_010_R_cut_050") || (VarName.at(iVar) == "mprunedsafe_zcut_010_R_cut_050") ) LabelsAxis.push_back("m_{pruned} z_{cut}=0.1 R_{cut}=0.5");
      else if ((VarName.at(iVar) == "mpruned_zcut_005_R_cut_050") || (VarName.at(iVar) == "mprunedsafe_zcut_005_R_cut_050")) LabelsAxis.push_back("m_{pruned} z_{cut}=0.05 R_{cut}=0.5");
      else if ((VarName.at(iVar) == "mpruned_zcut_005_R_cut_075") || (VarName.at(iVar) == "mprunedsafe_zcut_005_R_cut_075")) LabelsAxis.push_back("m_{pruned} z_{cut}=0.05 R_{cut}=0.75");
      else if ((VarName.at(iVar) == "mpruned_zcut_010_R_cut_075") || (VarName.at(iVar) == "mprunedsafe_zcut_010_R_cut_075")) LabelsAxis.push_back("m_{pruned} z_{cut}=0.1 R_{cut}=0.75");
      else if ((VarName.at(iVar) == "mtrim_Rtrim_020_Ptfrac_005") || (VarName.at(iVar) == "mtrimsafe_Rtrim_020_Ptfrac_005")) LabelsAxis.push_back("m_{trim} R_{trim}=0.2 pT_{frac}=0.05");
      else if ((VarName.at(iVar) == "mtrim_Rtrim_010_Ptfrac_003") || (VarName.at(iVar) == "mtrimsafe_Rtrim_010_Ptfrac_003")) LabelsAxis.push_back("m_{trim} R_{trim}=0.1 pT_{frac}=0.03");
      else if ((VarName.at(iVar) == "mtrim_Rtrim_020_Ptfrac_003") || (VarName.at(iVar) == "mtrimsafe_Rtrim_020_Ptfrac_003")) LabelsAxis.push_back("m_{trim} R_{trim}=0.2 pT_{frac}=0.03");
      else if ((VarName.at(iVar) == "mtrim_Rtrim_030_Ptfrac_003") || (VarName.at(iVar) == "mtrimsafe_Rtrim_030_Ptfrac_003")) LabelsAxis.push_back("m_{trim} R_{trim}=0.3 pT_{frac}=0.03");
      else if ((VarName.at(iVar) == "msoftdrop_beta10") || (VarName.at(iVar) == "msoftdropsafe_beta10")) LabelsAxis.push_back("m_{softdrop} #beta=1");
      else if ((VarName.at(iVar) == "msoftdrop_beta00") || (VarName.at(iVar) == "msoftdropsafe_beta00")) LabelsAxis.push_back("m_{softdrop} #beta=0");
      else if ((VarName.at(iVar) == "msoftdrop_beta20") || (VarName.at(iVar) == "msoftdropsafe_beta20")) LabelsAxis.push_back("m_{softdrop} #beta=2");
      else cout << "Not supported label " << endl;	
    }
    
    chain.SetBranchAddress("imatch", &imatch_tmp);
    chain.SetBranchAddress("pt", &pt);
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
	  if((isMatchedToBoson_tmp -> at(iE) == true) && ((pt -> at(iE))> 300.) &&  imatch_tmp -> at(iE) != -1) 
	  {  
	    hists.at(iVar) -> Fill( (((tmp.at(iVar)) -> at(iE)) - ((tmp_gen.at(iVar)) -> at(imatch_tmp -> at(iE)))) );
	  }
	}
	  
	(tmp.at(iVar)) -> clear();
	(tmp_gen.at(iVar)) -> clear();
      }
    }
    
    TH1F * hist_Summary_Fit = new TH1F (("Summary_Fit" + treeNames.at(iTree)).c_str(), ("Summary_Fit" + treeNames.at(iTree)).c_str(), VarName.size(), 0., VarName.size());
    TH1F * hist_Summary_Estimation = new TH1F (("Summary_Estimation" + treeNames.at(iTree)).c_str(), ("Summary_Estimation" + treeNames.at(iTree)).c_str(), VarName.size(), 0., VarName.size());
    
    hists_summary_Fit.push_back(hist_Summary_Fit);
    hists_summary_Estimation.push_back(hist_Summary_Estimation);
    
    file_out.cd();
    
    for (unsigned int  iVar = 0; iVar < VarName.size(); iVar++ )
    {
      hists.at(iVar) -> Fit("gaus");
      TF1 * mass = (TF1*) hists.at(iVar) -> GetFunction("gaus");
      
      hists_summary_Fit.at(iTree) -> SetBinContent(iVar + 1, mass -> GetParameter(2));
      hists_summary_Estimation.at(iTree) -> SetBinContent(iVar + 1, hists.at(iVar) -> GetRMS());
      
      hists_summary_Fit.at(iTree) -> GetXaxis() -> SetBinLabel(iVar + 1, (LabelsAxis.at(iVar)).c_str());
      hists.at(iVar)  -> Write();
      
    }
    
    hists_summary_Fit.at(iTree) -> GetXaxis() -> SetLabelSize(0.03);
    hists_summary_Fit.at(iTree) -> SetMarkerStyle(22);
    hists_summary_Fit.at(iTree) -> SetMarkerSize(2.);
    hists_summary_Fit.at(iTree) -> SetMarkerColor(Colors.at(iTree));
    
    hists_summary_Estimation.at(iTree) -> GetXaxis() -> SetLabelSize(0.05);
    hists_summary_Estimation.at(iTree) -> SetMarkerStyle(21);
    hists_summary_Estimation.at(iTree) -> SetMarkerSize(2.);
    hists_summary_Estimation.at(iTree) -> SetMarkerColor(Colors.at(iTree));
   
        
    hists.clear();
    LabelsAxis.clear();
    
    if (treeNames.at(iTree) == "pf") Labels.push_back("PF Jets");
    else if (treeNames.at(iTree) == "chs") Labels.push_back("PF + CHS Jets");
    else if (treeNames.at(iTree) == "puppi") Labels.push_back("PUPPI Jets");
   
   
    VarName.clear();
  }
  
  TCanvas *c1=  new TCanvas("c1","canvas",1000,800);
  c1->SetTickx(1);
  c1->SetTicky(1); 
  
  TPaveText descriptionPave(0.12,0.75,0.3,0.85, "NDC");
  TPaveText descriptionPaveCMS(0.12,0.9,0.3,1.0, "NDC");
  descriptionPave.SetTextAlign(11);
  descriptionPave.SetFillStyle(0);  // transparent
  descriptionPave.SetBorderSize(0);
  descriptionPave.SetTextSize(0.03);
  descriptionPave.AddText("WW, Antikt jets with R = 0.8");// \\ p_{T}^{jet} > 300 GeV");
  descriptionPave.AddText("p_{T}^{jet} > 300 GeV" );
  descriptionPave.SetTextSize(0.025);
  
  descriptionPaveCMS.SetTextAlign(11);
  descriptionPaveCMS.SetFillStyle(0);  // transparent
  descriptionPaveCMS.SetBorderSize(0);
  descriptionPaveCMS.SetTextSize(0.03);
  descriptionPaveCMS.AddText("CMS Simulation Preliminary #sqrt{s} = 13 TeV");
  
  TLegend  *leg = new TLegend(0.4,0.65,0.89,0.85);
  leg ->  SetTextSize(0.023);
  leg ->  SetFillStyle(0.);
  leg -> SetLineWidth(0.);
  leg -> SetLineColor(kWhite);
  leg-> SetNColumns(2);

  for (unsigned int iTree = 0; iTree < treeNames.size(); iTree++)
  {
    hists_summary_Fit.at(iTree) -> GetYaxis() -> SetRangeUser(0., 65.);
    hists_summary_Fit.at(iTree) -> Draw("PSAME");
    hists_summary_Estimation.at(iTree) -> Draw("PSAME");
    
     leg->AddEntry(hists_summary_Estimation.at(iTree),(Labels.at(iTree) + " Estimation" ).c_str(),"p");
     leg->AddEntry(hists_summary_Fit.at(iTree),(Labels.at(iTree) + " Fit Result " ).c_str(),"p");
  }
  
  descriptionPave.Draw();
  descriptionPaveCMS.Draw();
  leg -> Draw();
  
 TLine *l1 = new TLine(2.,0.0,2.,44.0);
 TLine *l2 = new TLine(6.,0.0,6.,44.0);
 TLine *l3 = new TLine(10.,0.0,10.,44.0);
 
 l1 -> SetLineColor(kYellow);
 l1 -> SetLineWidth(3.);
 l1 -> SetLineStyle(9);
 
 l2 -> SetLineColor(kYellow);
 l2 -> SetLineWidth(3.);
 l2 -> SetLineStyle(9);
 
 l3 -> SetLineColor(kYellow);
 l3 -> SetLineWidth(3.);
 l3 -> SetLineStyle(9);
 
 l1 -> Draw("SAME");
 l2 -> Draw("SAME");
 l3 -> Draw("SAME");
  
  c1 -> SaveAs("summary_grooming_algos.png");
   
}

int main(int argc, char** argv)
{
    vector <string> treeNames;
    treeNames.push_back("pf");
    treeNames.push_back("chs");
    treeNames.push_back("puppi");
        
    summary("/storage/a/ishvetso/git_repository/IvanShvetsov/scripts/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14.txt", treeNames);
  
}
