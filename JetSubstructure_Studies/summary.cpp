#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
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

#include "/storage/1/ishvetso/git/IvanShvetsov/CMS_stylistics/tdrstyle.C"
#include "/storage/1/ishvetso/git/IvanShvetsov/CMS_stylistics/CMS_lumi.cpp"
/*
 * 
 * g++ -o summary summary.cpp --std=c++11 `root-config --cflags --libs` -O2 -I./
 * 
*/
using namespace std;

typedef vector <string> vstring;

void summary(vstring treeNames, string outFileName)
{
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  
  vector <Color_t> Colors;
  Colors.push_back(kBlue);
  Colors.push_back(kGreen);
  Colors.push_back(kRed);

  
  vector <string> TreeLabels;
  
  system("mkdir -p summary_plots");
  system("mkdir -p summary_plots/C");
  system("mkdir -p summary_plots/png");
  system("mkdir -p summary_plots/pdf");
  
  TFile file("summary.root", "READ");
  vector <string> LabelsAxis;
  
  vector <TH1F *> HISTS_Fit, HISTS_RMS, HISTS_Fit_response, HISTS_RMS_response;
  
  vector <string> VarName;
   
  for (unsigned int iTree = 0; iTree < treeNames.size(); ++iTree )
  {
    
    if (  (treeNames.at(iTree) == "pf" ) ||  (treeNames.at(iTree) == "chs" ) )
    {
        VarName.push_back("m");
	VarName.push_back("mraw");
	VarName.push_back("mtrimsafe_Rtrim_020_Ptfrac_005");
	VarName.push_back("mtrimsafe_Rtrim_010_Ptfrac_003");
	VarName.push_back("mtrimsafe_Rtrim_020_Ptfrac_003");
	VarName.push_back("mtrimsafe_Rtrim_030_Ptfrac_003");
	VarName.push_back("mprunedsafe_zcut_010_R_cut_050");
	VarName.push_back("mprunedsafe_zcut_005_R_cut_050");
	VarName.push_back("mprunedsafe_zcut_005_R_cut_075");
	VarName.push_back("mprunedsafe_zcut_010_R_cut_075");
	VarName.push_back("msoftdropsafe_beta10");
	VarName.push_back("msoftdropsafe_beta00");
	VarName.push_back("msoftdropsafe_beta20");
      
    }
    
    else if ( treeNames.at(iTree) == "puppi"  )
    {
        VarName.push_back("m");
	VarName.push_back("mraw");
	VarName.push_back("mtrim_Rtrim_020_Ptfrac_005");
	VarName.push_back("mtrim_Rtrim_010_Ptfrac_003");
	VarName.push_back("mtrim_Rtrim_020_Ptfrac_003");
	VarName.push_back("mtrim_Rtrim_030_Ptfrac_003");
	VarName.push_back("mpruned_zcut_010_R_cut_050");
	VarName.push_back("mpruned_zcut_005_R_cut_050");
	VarName.push_back("mpruned_zcut_005_R_cut_075");
	VarName.push_back("mpruned_zcut_010_R_cut_075");
	VarName.push_back("msoftdrop_beta10");
	VarName.push_back("msoftdrop_beta00");
	VarName.push_back("msoftdrop_beta20");
    }
    
    else cerr << "tree name is not supported" << endl;

    for (unsigned int iVar = 0; iVar < VarName.size(); iVar++)
    {
         
      if (iTree == 0)
      {
	if (VarName.at(iVar) == "m") LabelsAxis.push_back("m");
	else if (VarName.at(iVar) == "mraw") LabelsAxis.push_back("m_{raw}");
	else if ((VarName.at(iVar) == "mpruned_zcut_010_R_cut_050") || (VarName.at(iVar) == "mprunedsafe_zcut_010_R_cut_050") ) LabelsAxis.push_back("z_{cut}=0.1 R_{cut}=0.5");
	else if ((VarName.at(iVar) == "mpruned_zcut_005_R_cut_050") || (VarName.at(iVar) == "mprunedsafe_zcut_005_R_cut_050")) LabelsAxis.push_back("z_{cut}=0.05 R_{cut}=0.5");
	else if ((VarName.at(iVar) == "mpruned_zcut_005_R_cut_075") || (VarName.at(iVar) == "mprunedsafe_zcut_005_R_cut_075")) LabelsAxis.push_back("z_{cut}=0.05 R_{cut}=0.75");
	else if ((VarName.at(iVar) == "mpruned_zcut_010_R_cut_075") || (VarName.at(iVar) == "mprunedsafe_zcut_010_R_cut_075")) LabelsAxis.push_back("z_{cut}=0.1 R_{cut}=0.75");
	else if ((VarName.at(iVar) == "mtrim_Rtrim_020_Ptfrac_005") || (VarName.at(iVar) == "mtrimsafe_Rtrim_020_Ptfrac_005")) LabelsAxis.push_back("r_{sub}=0.2 pT_{frac}=0.05");
	else if ((VarName.at(iVar) == "mtrim_Rtrim_010_Ptfrac_003") || (VarName.at(iVar) == "mtrimsafe_Rtrim_010_Ptfrac_003")) LabelsAxis.push_back("r_{sub}=0.1 pT_{frac}=0.03");
	else if ((VarName.at(iVar) == "mtrim_Rtrim_020_Ptfrac_003") || (VarName.at(iVar) == "mtrimsafe_Rtrim_020_Ptfrac_003")) LabelsAxis.push_back("r_{sub}=0.2 pT_{frac}=0.03");
	else if ((VarName.at(iVar) == "mtrim_Rtrim_030_Ptfrac_003") || (VarName.at(iVar) == "mtrimsafe_Rtrim_030_Ptfrac_003")) LabelsAxis.push_back("r_{sub}=0.3 pT_{frac}=0.03");
	else if ((VarName.at(iVar) == "msoftdrop_beta10") || (VarName.at(iVar) == "msoftdropsafe_beta10")) LabelsAxis.push_back("#beta=1");
	else if ((VarName.at(iVar) == "msoftdrop_beta00") || (VarName.at(iVar) == "msoftdropsafe_beta00")) LabelsAxis.push_back("#beta=0");
	else if ((VarName.at(iVar) == "msoftdrop_beta20") || (VarName.at(iVar) == "msoftdropsafe_beta20")) LabelsAxis.push_back("#beta=2");
	else cout << "Not supported label " << endl;	
      }
    }
    

    file.cd();
    TH1F *hist_RMS = new TH1F(("RMS_" + treeNames.at(iTree)).c_str(), ( "RMS_" + treeNames.at(iTree)).c_str(), VarName.size(), 0.+ (iTree/8.), VarName.size()  + (iTree/8.));
    TH1F *hist_Fit  = new TH1F(( "Fit_" + treeNames.at(iTree)).c_str(), ("Fit_" + treeNames.at(iTree)).c_str(), VarName.size(), 0. + (iTree/8.), VarName.size()  + (iTree/8.));
    
    TH1F *hist_RMS_response = new TH1F(("RMS_response_" + treeNames.at(iTree)).c_str(), ( "RMS_response_" + treeNames.at(iTree)).c_str(), VarName.size(), 0.+ (iTree/8.) , VarName.size() + (iTree/8.) );
    TH1F *hist_Fit_response  = new TH1F(( "Fit_response_" + treeNames.at(iTree)).c_str(), ("Fit_response_" + treeNames.at(iTree)).c_str(), VarName.size(), 0.+ (iTree/8.) , VarName.size() + (iTree/8.) );
    
    HISTS_Fit.push_back(hist_Fit);
    HISTS_RMS.push_back(hist_RMS);
    
    HISTS_Fit_response.push_back(hist_Fit_response);
    HISTS_RMS_response.push_back(hist_RMS_response);
    
    
    for (unsigned int  iVar = 0; iVar < VarName.size(); iVar++ )
    {
      TH1F *hist = (TH1F*)file.Get((VarName.at(iVar) + "_" + treeNames.at(iTree)).c_str());
      TH1F *hist_response = (TH1F*)file.Get(("response_" +  VarName.at(iVar) + "_" + treeNames.at(iTree)).c_str());
     
      Int_t N_RMS = 3.;
      float minf = ((hist -> GetMean()) - (hist -> GetRMS()));
      float maxf = ((hist -> GetMean()) + (hist -> GetRMS()));
      
      TF1 *gfit = new TF1("Gaussian","gaus",minf,maxf);
      hist -> Fit("Gaussian", "RQ");
      TF1 * mass = (TF1*) hist -> GetFunction("Gaussian");
      
      TF1 *gfit_response = new TF1("Gaussian_response","gaus", -100., 100.);
      hist_response -> Fit("Gaussian_response", "RQ");
      TF1 * mass_response = (TF1*) hist_response -> GetFunction("Gaussian_response");
      
      Float_t Mu = mass -> GetParameter(1);
           
      Float_t Sigma = mass -> GetParameter(2);
      
      
      Float_t UpMass = Mu + N_RMS*Sigma;
      Float_t DownMass = Mu - N_RMS*Sigma;
      
      
      hist -> GetXaxis() -> SetRangeUser(DownMass, UpMass);

      HISTS_RMS.at(iTree) -> SetBinContent(iVar + 1, hist -> GetRMS());
      HISTS_RMS.at(iTree) -> SetBinError(iVar + 1, hist -> GetRMSError());
      HISTS_RMS.at(iTree)  -> LabelsOption("v");
      HISTS_RMS.at(iTree)  -> GetXaxis() -> SetBinLabel(iVar + 1, (LabelsAxis.at(iVar)).c_str());
      
      HISTS_Fit.at(iTree) -> SetBinContent(iVar + 1, mass -> GetParameter(2));
      HISTS_Fit.at(iTree) -> SetBinError(iVar + 1, mass -> GetParError(2));
      HISTS_Fit.at(iTree) -> GetXaxis() -> SetBinLabel(iVar + 1, (LabelsAxis.at(iVar)).c_str());

      HISTS_RMS_response.at(iTree) -> SetBinContent(iVar + 1, hist_response -> GetRMS());
      HISTS_RMS_response.at(iTree) -> SetBinError(iVar + 1, hist_response -> GetRMSError());
      HISTS_RMS_response.at(iTree)  -> GetXaxis() -> SetBinLabel(iVar + 1, (LabelsAxis.at(iVar)).c_str());
      
      HISTS_Fit_response.at(iTree) -> SetBinContent(iVar + 1, mass_response -> GetParameter(2));
      HISTS_Fit_response.at(iTree) -> SetBinError(iVar + 1, mass_response -> GetParError(2));
      HISTS_Fit_response.at(iTree) -> GetXaxis() -> SetBinLabel(iVar + 1, (LabelsAxis.at(iVar)).c_str());
      
    
      if ( (100*(( hist -> GetRMSError())/(hist -> GetRMS() ))) > 1.0 ) cerr << "@@@@@@@ Uncertainty is > 1 %: " << (100*(( hist -> GetRMSError())/(hist -> GetRMS() ))) << endl;
      if ( (100*(( mass -> GetParError(2))/(mass -> GetParameter(2) ))) > 1.0 ) cerr << "@@@@@@@ Uncertainty is > 1 %: " <<  (100*(( mass -> GetParError(2))/(mass -> GetParameter(2) ))) << endl;            
      
      if ( (100*(( hist_response -> GetRMSError())/(hist_response -> GetRMS() ))) > 1.0 ) cerr << "@@@@@@@ Uncertainty is > 1 %: " << (100*(( hist_response -> GetRMSError())/(hist_response -> GetRMS() ))) << endl;
      if ( (100*(( mass_response -> GetParError(2))/(mass_response -> GetParameter(2) ))) > 1.0 ) cerr << "@@@@@@@ Uncertainty is > 1 %: " << (100*(( mass_response -> GetParError(2))/(mass_response -> GetParameter(2) )))<< endl;         
    
      
    }
    
    HISTS_RMS.at(iTree) -> GetXaxis() -> SetLabelSize(0.035);
    HISTS_RMS.at(iTree) -> SetMarkerStyle(21);
    HISTS_RMS.at(iTree) -> SetMarkerSize(2.0);
    HISTS_RMS.at(iTree) -> SetMarkerColor(Colors.at(iTree));
    HISTS_RMS.at(iTree) -> SetLineColor(Colors.at(iTree));
    HISTS_RMS.at(iTree) -> SetLineWidth(2.);
    
    HISTS_Fit.at(iTree) -> GetXaxis() -> SetLabelSize(0.035);
    HISTS_Fit.at(iTree) -> SetMarkerStyle(22);
    HISTS_Fit.at(iTree) -> SetMarkerSize(2.0);
    HISTS_Fit.at(iTree) -> SetMarkerColor(Colors.at(iTree));
    HISTS_Fit.at(iTree) -> SetLineColor(Colors.at(iTree));
    HISTS_Fit.at(iTree) -> SetLineWidth(5.);

    
    HISTS_RMS_response.at(iTree) -> GetXaxis() -> SetLabelSize(0.035);
    HISTS_RMS_response.at(iTree) -> SetMarkerStyle(21);
    HISTS_RMS_response.at(iTree) -> SetMarkerSize(2.0);
    HISTS_RMS_response.at(iTree) -> SetMarkerColor(Colors.at(iTree));
    HISTS_RMS_response.at(iTree) -> SetLineColor(Colors.at(iTree));
    HISTS_RMS_response.at(iTree) -> SetLineWidth(2.);
    
    HISTS_Fit_response.at(iTree) -> GetXaxis() -> SetLabelSize(0.035);
    HISTS_Fit_response.at(iTree) -> SetMarkerStyle(22);
    HISTS_Fit_response.at(iTree) -> SetMarkerSize(2.0);
    HISTS_Fit_response.at(iTree) -> SetMarkerColor(Colors.at(iTree));
    HISTS_Fit_response.at(iTree) -> SetLineColor(Colors.at(iTree));
    HISTS_Fit_response.at(iTree) -> SetLineWidth(5.);
   
    if (treeNames.at(iTree) == "pf") TreeLabels.push_back("PF");
    else if (treeNames.at(iTree) == "chs") TreeLabels.push_back("PF + CHS");
    else if (treeNames.at(iTree) == "puppi") TreeLabels.push_back("PF + PUPPI");
    
    VarName.clear();
  }
  
  setTDRStyle();
  TCanvas *c1=  new TCanvas("c2","canvas",1000,800);
  setTDRStyle();
  c1 -> SetTickx(1);
  c1 -> SetTicky(1);
  c1 -> SetBottomMargin(0.15);
  c1 -> SetRightMargin(0.08); 
  
  TPaveText descriptionPave(0.2,0.7,0.4,0.9, "NDC");
  descriptionPave.SetTextAlign(11);
  descriptionPave.SetFillStyle(0);  // transparent
  descriptionPave.SetBorderSize(0);
  descriptionPave.SetTextSize(0.035);
  descriptionPave.AddText("RS Graviton #rightarrow WW, Anti-kT (R=0.8) ");
  descriptionPave.AddText("<n_{PU}>=40");
  descriptionPave.AddText("p_{T} > 300 GeV");
  descriptionPave.AddText("|#eta| < 2.5");
  
  TPaveText descriptionPavePruned(0.58,0.6,0.68,0.7, "NDC");
  descriptionPavePruned.SetTextAlign(11);
  descriptionPavePruned.SetFillStyle(0);  // transparent
  descriptionPavePruned.SetBorderSize(0);
  descriptionPavePruned.SetTextSize(0.035);
  descriptionPavePruned.AddText("Pruning");
  
  TPaveText descriptionPaveTrimmed(0.35,0.6,0.45,0.7, "NDC");
  descriptionPaveTrimmed.SetTextAlign(11);
  descriptionPaveTrimmed.SetFillStyle(0);  // transparent
  descriptionPaveTrimmed.SetBorderSize(0);
  descriptionPaveTrimmed.SetTextSize(0.035);
  descriptionPaveTrimmed.AddText("Trimming");
  
  TPaveText descriptionPaveSoftDrop(0.78,0.6,0.88,0.7, "NDC");
  descriptionPaveSoftDrop.SetTextAlign(11);
  descriptionPaveSoftDrop.SetFillStyle(0);  // transparent
  descriptionPaveSoftDrop.SetBorderSize(0);
  descriptionPaveSoftDrop.SetTextSize(0.035);
  descriptionPaveSoftDrop.AddText("Soft Drop");
  
  
  TLegend  *leg = new TLegend(0.7,0.75,0.9,0.9);
  leg ->  SetTextSize(0.03);
  leg ->  SetFillStyle(0.);
  leg -> SetLineWidth(0.);
  leg -> SetLineColor(kWhite);
  leg -> SetBorderSize(0.);
  
  for (unsigned int iTree = 0; iTree < treeNames.size(); iTree++)
  {
    HISTS_Fit.at(iTree) -> GetYaxis() -> SetRangeUser(0., 55.);
    HISTS_Fit.at(iTree) -> GetYaxis() -> SetTitle("Resolution (GeV)");
    HISTS_Fit.at(iTree) -> Draw("HISTPSAME");
    HISTS_RMS.at(iTree) -> Draw("HISTPSAME");
    
    leg->AddEntry(HISTS_Fit.at(iTree),(TreeLabels.at(iTree)).c_str(),"l");
    
  }
  
  TLegend  *leg2 = new TLegend(0.4,0.69,0.7,0.89);
  leg2 ->  SetTextSize(0.04);
  leg2 ->  SetFillStyle(0.);
  leg2 -> SetLineColor(kWhite);
  leg2 -> SetBorderSize(0.);
  leg2 -> SetNColumns(2);
    
  TGraph *gr1 = new TGraph();
  TGraph *gr2 = new TGraph();

  gr2 -> SetMarkerStyle(21);
  gr1 -> SetMarkerStyle(22);

  gr2 -> SetMarkerSize(2);
  gr1 -> SetMarkerSize(2.);
  
  

  leg2->AddEntry(gr1,"fitted #sigma","p");
  leg2->AddEntry(gr2,"RMS","p");

  
  descriptionPave.Draw();
  descriptionPavePruned.Draw();
  descriptionPaveTrimmed.Draw();
  descriptionPaveSoftDrop.Draw();
  leg -> Draw();
  leg2 -> Draw();
  CMS_lumi( c1, 4, 0 );
  
 TLine *l1 = new TLine(2.,0.0,2.,38.);
 TLine *l2 = new TLine(6.,0.0,6.,38.);
 TLine *l3 = new TLine(10.,0.0,10.,38.);
 
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
  c1->Update();
  c1 -> SaveAs(("summary_plots/png/"+ outFileName + ".png").c_str() );
  c1 -> SaveAs(("summary_plots/pdf/" + outFileName +  ".pdf").c_str());
  c1 -> SaveAs(("summary_plots/C/" + outFileName +  ".C").c_str());
  
 c1 -> Delete();
  
  setTDRStyle();
  c1=  new TCanvas("c2","canvas",1000,800);
  
  c1 -> SetTickx(1);
  c1 -> SetTicky(1);
  c1 -> SetBottomMargin(0.15);
  c1 -> SetRightMargin(0.08);
   
  for (unsigned int iTree = 0; iTree < treeNames.size(); iTree++)
  {
    setTDRStyle();
    HISTS_Fit_response.at(iTree) -> GetYaxis() -> SetRangeUser(0., 55.);
    HISTS_Fit_response.at(iTree) -> GetYaxis() -> SetTitle("Resolution (GeV)");
    HISTS_Fit_response.at(iTree) -> Draw("PHISTSAME");
    HISTS_RMS_response.at(iTree) -> Draw("PHISTSAME");
      
  }
    
   l1 -> Draw("SAME");
   l2 -> Draw("SAME");
   l3 -> Draw("SAME"); 
   
   descriptionPave.Draw();
   descriptionPavePruned.Draw();
   descriptionPaveTrimmed.Draw();
   descriptionPaveSoftDrop.Draw();
      
   leg -> Draw();
   leg2 -> Draw();
   CMS_lumi( c1, 4, 0 );

   c1 -> SaveAs(("summary_plots/png/" + outFileName +  "_response.png").c_str());
   c1 -> SaveAs(("summary_plots/pdf/" + outFileName +  "_response.pdf").c_str());
   c1 -> SaveAs(("summary_plots/C/" + outFileName +  "_response.C").c_str());
}

int main(int argc, char** argv)
{
    vstring treeNames;
    
    treeNames.push_back("pf");
    treeNames.push_back("chs");
    
    summary( treeNames, "summary_plot_PF_CHS");
    summary( treeNames, "summary_plot_PF_CHS");
    treeNames.push_back("puppi");
    summary( treeNames, "summary_plot");
        
    
  
}
