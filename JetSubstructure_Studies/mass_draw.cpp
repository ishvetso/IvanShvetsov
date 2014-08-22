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
#include <sstream>
#include <iomanip>
#include "/storage/1/ishvetso/git/IvanShvetsov/CMS_stylistics/tdrstyle.C"
#include "/storage/1/ishvetso/git/IvanShvetsov/CMS_stylistics/CMS_lumi.cpp"

/*
 * 
 * g++ -o mass_draw mass_draw.cpp --std=c++11 `root-config --cflags --libs` -O2 -I./
 * 
*/

using namespace std;
typedef vector <string> vstring;

void mass_draw( vstring treeNames, string Tag)
{
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

  
  vector <Color_t> Colors;

  
  vector <string> Labels;
  
   TFile file_out("summary.root", "READ");
   vector <string> VarNames;
   
   for (unsigned int iTree =0; iTree < treeNames.size(); ++iTree)
   {
     
      
      
      if (  ((treeNames.at(iTree) == "pf" ) ||  (treeNames.at(iTree) == "chs" ) ) && Tag == "pruned")
      {
	VarNames.push_back("mprunedsafe_zcut_010_R_cut_050");
	VarNames.push_back("mprunedsafe_zcut_005_R_cut_050");
	VarNames.push_back("mprunedsafe_zcut_005_R_cut_075");
	VarNames.push_back("mprunedsafe_zcut_010_R_cut_075");

    
      }
    
      else if ( (treeNames.at(iTree) == "puppi" ) &&  Tag == "pruned" )
      {
	  VarNames.push_back("mpruned_zcut_010_R_cut_050");
	  VarNames.push_back("mpruned_zcut_005_R_cut_050");
	  VarNames.push_back("mpruned_zcut_005_R_cut_075");
	  VarNames.push_back("mpruned_zcut_010_R_cut_075");
	  
      }
      
      else  if (  ((treeNames.at(iTree) == "pf" ) ||  (treeNames.at(iTree) == "chs" ) ) && Tag == "trimmed")
      {
	VarNames.push_back("mtrimsafe_Rtrim_020_Ptfrac_005");
	VarNames.push_back("mtrimsafe_Rtrim_010_Ptfrac_003");
	VarNames.push_back("mtrimsafe_Rtrim_020_Ptfrac_003");
	VarNames.push_back("mtrimsafe_Rtrim_030_Ptfrac_003");

    
      }
    
      else if ( (treeNames.at(iTree) == "puppi" ) &&  Tag == "trimmed" )
      {
	VarNames.push_back("mtrim_Rtrim_020_Ptfrac_005");
	VarNames.push_back("mtrim_Rtrim_010_Ptfrac_003");
	VarNames.push_back("mtrim_Rtrim_020_Ptfrac_003");
	VarNames.push_back("mtrim_Rtrim_030_Ptfrac_003");
	  
      }
      
       else  if (  ((treeNames.at(iTree) == "pf" ) ||  (treeNames.at(iTree) == "chs" ) ) && Tag == "softdrop")
      {
	VarNames.push_back("msoftdropsafe_beta10");
	VarNames.push_back("msoftdropsafe_beta00");
	VarNames.push_back("msoftdropsafe_beta20");    
      }
    
      else if ( (treeNames.at(iTree) == "puppi" ) &&  Tag == "softdrop" )
      {
	VarNames.push_back("msoftdrop_beta10");
	VarNames.push_back("msoftdrop_beta00");
	VarNames.push_back("msoftdrop_beta20");
	  
      }
      
          
      else if ( Tag == "raw" )
      {
	VarNames.push_back("mraw");
		  
      }
      
      
      else cerr << "not supported tag or var name" << endl;
      
      VarNames.push_back("m");
      
      if (Tag == "pruned" || Tag == "trimmed")
      {
	Colors.push_back(kBlack);
	Colors.push_back(kBlue);
	Colors.push_back(kRed);
	Colors.push_back(kGreen);
	Colors.push_back(6);
      }
      
      else if (Tag == "softdrop") 
      {
	Colors.push_back(kBlack);
	Colors.push_back(kRed);
	Colors.push_back(kGreen);
	Colors.push_back(6);
      }
      
      else if (Tag == "raw") 
      {
	Colors.push_back(kRed);
	Colors.push_back(6);
      }
      
      for (unsigned int iVar = 0; iVar < VarNames.size(); iVar++)
      {
	
	
	if (VarNames.at(iVar) == "m") Labels.push_back("Ungroomed");
	else if (VarNames.at(iVar) == "mraw") Labels.push_back("m_{raw}");
	else if ((VarNames.at(iVar) == "mpruned_zcut_010_R_cut_050") || (VarNames.at(iVar) == "mprunedsafe_zcut_010_R_cut_050") ) Labels.push_back("z_{cut}=0.1 R_{cut}=0.5");
	else if ((VarNames.at(iVar) == "mpruned_zcut_005_R_cut_050") || (VarNames.at(iVar) == "mprunedsafe_zcut_005_R_cut_050")) Labels.push_back("z_{cut}=0.05 R_{cut}=0.5");
	else if ((VarNames.at(iVar) == "mpruned_zcut_005_R_cut_075") || (VarNames.at(iVar) == "mprunedsafe_zcut_005_R_cut_075")) Labels.push_back("z_{cut}=0.05 R_{cut}=0.75");
	else if ((VarNames.at(iVar) == "mpruned_zcut_010_R_cut_075") || (VarNames.at(iVar) == "mprunedsafe_zcut_010_R_cut_075")) Labels.push_back("z_{cut}=0.1 R_{cut}=0.75");
	else if ((VarNames.at(iVar) == "mtrim_Rtrim_020_Ptfrac_005") || (VarNames.at(iVar) == "mtrimsafe_Rtrim_020_Ptfrac_005")) Labels.push_back("r_{sub}=0.2 pT_{frac}=0.05");
	else if ((VarNames.at(iVar) == "mtrim_Rtrim_010_Ptfrac_003") || (VarNames.at(iVar) == "mtrimsafe_Rtrim_010_Ptfrac_003")) Labels.push_back("r_{sub}=0.1 pT_{frac}=0.03");
	else if ((VarNames.at(iVar) == "mtrim_Rtrim_020_Ptfrac_003") || (VarNames.at(iVar) == "mtrimsafe_Rtrim_020_Ptfrac_003")) Labels.push_back("r_{sub}=0.2 pT_{frac}=0.03");
	else if ((VarNames.at(iVar) == "mtrim_Rtrim_030_Ptfrac_003") || (VarNames.at(iVar) == "mtrimsafe_Rtrim_030_Ptfrac_003")) Labels.push_back("r_{sub}=0.3 pT_{frac}=0.03");
	else if ((VarNames.at(iVar) == "msoftdrop_beta10") || (VarNames.at(iVar) == "msoftdropsafe_beta10")) Labels.push_back("#beta=1");
	else if ((VarNames.at(iVar) == "msoftdrop_beta00") || (VarNames.at(iVar) == "msoftdropsafe_beta00")) Labels.push_back("#beta=0");
	else if ((VarNames.at(iVar) == "msoftdrop_beta20") || (VarNames.at(iVar) == "msoftdropsafe_beta20")) Labels.push_back("#beta=2");
	else cout << "Not supported label " << endl;	

      
      }
 
      file_out.cd();
      
      setTDRStyle();
      
      TCanvas *c1=  new TCanvas("c2","canvas",1000,800);
      c1->SetTickx(1);
      c1->SetTicky(1); 
           
      TLegend  *leg ;
      if (Tag != "raw") leg = new TLegend(0.65,0.3,0.95,0.9);
      else if (Tag == "raw") leg = new TLegend(0.7,0.6,0.9,0.9);
      leg ->  SetTextSize(0.03);
      leg ->  SetFillStyle(0.);
      leg -> SetLineWidth(0.);
      leg -> SetLineColor(kWhite);
      leg -> SetBorderSize(0.);
      
  
      for (unsigned int iVar = 0; iVar < VarNames.size(); iVar++)
      {
	TH1F *hist_tmp = (TH1F*)file_out.Get((  VarNames.at(iVar) + "_" + treeNames.at(iTree)).c_str());
	cout << VarNames.at(iVar) << "  " << treeNames.at(iTree) << "  "<< hist_tmp -> GetRMS() << endl;
	hist_tmp  -> SetLineColor(Colors.at(iVar));
	hist_tmp  -> GetYaxis() -> SetTitleOffset(1.6);
	hist_tmp  -> GetXaxis() -> SetTitle("m_{reco} (GeV)");
	hist_tmp  -> GetYaxis() -> SetTitle("arbitrary units");
	hist_tmp  -> SetLineWidth(2.);
	hist_tmp  -> GetYaxis() -> SetRangeUser(0., 1.8*(hist_tmp -> GetBinContent(hist_tmp -> GetMaximumBin())));
	hist_tmp  -> Draw("HISTSAME");
	leg->AddEntry(hist_tmp,(Labels.at(iVar)).c_str(),"l");
	  
	ostringstream stream;   
	stream.precision(3);
	string RMS;
	stream <<((float)( hist_tmp -> GetRMS()));
	RMS = stream.str();
	stream.str("");
	
	string mean;
	stream.precision(2);
	stream << ((float) (hist_tmp -> GetMean()));
	mean = stream.str();
	stream.str("");
	
	leg->AddEntry((TObject*)0,"","");
	leg->AddEntry((TObject*)0,("RMS = " + RMS + " GeV").c_str(),"");
	leg->AddEntry((TObject*)0,"","");
	leg->AddEntry((TObject*)0,("mean = " + mean + " GeV").c_str(),"");
	leg->AddEntry((TObject*)0,"","");
	leg->AddEntry((TObject*)0,"","");
      }
  
      TPaveText descriptionPave(0.2,0.6,0.4,0.9, "NDC");
      TPaveText descriptionPaveCMS(0.12,0.85,0.3,0.98, "NDC");
      descriptionPave.SetFillStyle(0);  // transparent
      descriptionPave.SetBorderSize(0);
      descriptionPave.SetTextAlign(11);
      descriptionPave.SetTextSize(0.03);
      descriptionPave.AddText("RSGraviton #rightarrow WW, Anti-kT (R=0.8) ");
      descriptionPave.AddText("<n_{PU}>=40");
      descriptionPave.AddText("p_{T} > 300 GeV");
      descriptionPave.AddText("|#eta| < 2.5");
      
      string CollectionLabel, AlgoLabel;
      
      if (treeNames.at(iTree) == "pf") CollectionLabel = "PF";
      else if (treeNames.at(iTree) == "chs")CollectionLabel = "PF + CHS";
      else if (treeNames.at(iTree) == "puppi") CollectionLabel = "PF + PUPPI";
      else cerr << "Tree Name is not supported " << endl;
    
      if (Tag == "pruned") AlgoLabel = "pruning";
      else if (Tag == "trimmed") AlgoLabel = "trimming";
      else if (Tag == "softdrop") AlgoLabel = "softdrop";
      else cerr << "algo not supported" << endl;
      
      if (Tag != "raw") descriptionPave.AddText((CollectionLabel + " with " + AlgoLabel ).c_str());
      else if (Tag == "raw") descriptionPave.AddText((CollectionLabel).c_str());
      descriptionPave.Draw();
      CMS_lumi( c1, 4, 0 );
      leg -> Draw();
      
    
      system("mkdir -p plots_mass");
      system("mkdir -p plots_mass/C");
      system("mkdir -p plots_mass/png");
      system("mkdir -p plots_mass/pdf");
      
      c1 -> SaveAs( ("plots_mass/png/mass_" + treeNames.at(iTree) + "_"+ Tag + ".png").c_str());
      c1 -> SaveAs( ("plots_mass/pdf/mass_" + treeNames.at(iTree) + "_"+ Tag + ".pdf").c_str());
      c1 -> SaveAs( ("plots_mass/C/mass_" + treeNames.at(iTree) + "_"+ Tag + ".C").c_str());
      delete c1;
      
      VarNames.clear();
      Colors.clear();
   }   
   
}

int main(int argc, char** argv)
{
   vstring treeNames;
   treeNames.push_back("pf");
   treeNames.push_back("chs");
   treeNames.push_back("puppi");

    mass_draw(treeNames, "pruned");
    mass_draw(treeNames, "trimmed");
    mass_draw(treeNames, "softdrop");
    mass_draw(treeNames, "raw");
    
   
}

