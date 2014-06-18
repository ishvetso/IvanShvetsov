#include "HistPUBinsProducer.cpp"
#include "TGraph.h"
#include "TCanvas.h"
#include "TLatex.h"
#include <sstream>
void test()
{
  
  HistPUBinsProducer Producer;
  string prefix = "/storage/a/ishvetso/CMSSW_6_2_8/src/SubstrAna/Summer14/bin/";
  Producer.SetInputFiles(prefix + "WW_AK8.root");
  
  Float_t PUmin = 20., PUmax = 60.;
  Int_t interval =10;
  Producer.SetPUBinsParameters(PUmin, PUmax, interval);
  Producer.SetBinParameters(20, 60.,120.);
 vector <TH1F*> hists;
  
  
  vector <string> VarNames;
  vector <Color_t> Colors;
  
  VarNames.push_back("m");
  VarNames.push_back("mtrim");
  VarNames.push_back("msoftdrop");
  VarNames.push_back("mpruned");
  
  
  Colors.push_back(kBlue);
  Colors.push_back(kRed);
  Colors.push_back(kGreen);
  Colors.push_back(kOrange);
 
  
  TFile file("resolution.root", "RECREATE");
  file.cd();
  
  TCanvas *c1=  new TCanvas("c1","canvas",1200,800);
  TMultiGraph *mg = new TMultiGraph("", "");
  
  TLegend  *leg = new TLegend(0.8,0.6,0.9,0.9);
  leg ->  SetFillColor(kWhite);
  
  
  for (unsigned iVar = 0; iVar < VarNames.size(); ++iVar)
  {
     Producer.VarName = VarNames[iVar];  
     hists.clear();
     hists = Producer.ProduceHists();
     
     Int_t Npoints = hists.size();
     Float_t masses[Npoints], RMSmasses[Npoints];
     string PUNumberLow[Npoints], PUNumberUp[Npoints];
          
     for (unsigned int i = 0; i < Npoints; ++ i )
     {
	masses[i] = (hists.at(i) -> GetBinCenter(hists.at(i) -> GetMaximumBin())) - 80.;
	// masses[i] = (hists.at(i) -> GetMean()) - 80.;
	RMSmasses[i] = hists.at(i) -> GetRMS();
     }
     
      TGraph *gr = new TGraph (Npoints, masses, RMSmasses);
    
    for (unsigned int i =0; i< Npoints;++i)
    {
      ostringstream Number;   
      Number<< PUmin + interval*i;
      PUNumberLow[i] = Number.str();
      Number.str("");
      
      Number<< PUmin + interval*(i + 1);
      PUNumberUp[i] = Number.str();
      TLatex *latex = new TLatex(gr->GetX()[i], gr->GetY()[i],("[" + PUNumberLow[i] + ", "  + PUNumberUp[i] + "]"  ).c_str());
      latex -> SetTextSize(0.03);
      gr->GetListOfFunctions()->Add(latex);
      
      hists.at(i) -> SetName(("[" + PUNumberLow[i] + ", "  + PUNumberUp[i] + "]" + VarNames.at(iVar) ).c_str());
      hists.at(i) -> Write();
    }
    
    
   gr -> SetMarkerColor(Colors.at(iVar));
   gr -> SetMarkerStyle(21);
   gr -> SetLineWidth(4.);
    gr->SetMarkerSize(1.);
   
   
   gr -> GetYaxis() -> SetRangeUser(gr -> GetYaxis() -> GetXmin(), (gr -> GetYaxis() -> GetXmax())*1.02);
   gr -> GetXaxis() -> SetLimits(gr -> GetXaxis() -> GetXmin(), (gr -> GetXaxis() -> GetXmax())*100.92);
   gr -> GetYaxis() -> SetTitle("Resolution");
   gr -> GetXaxis() -> SetTitle((Producer.VarName + " - mass_W").c_str());
   mg -> Add(gr);
   
   leg->AddEntry(gr,VarNames.at(iVar).c_str(),"p");
   
  }
  
  mg -> Draw("AP");
  mg -> GetXaxis() -> SetLimits(mg -> GetXaxis() -> GetXmin(), (mg -> GetXaxis() -> GetXmax())*1.5);
  mg -> GetXaxis() -> SetTitle("mass - mass_W");
  mg -> GetYaxis() -> SetTitle("resolution");
  leg -> Draw("SAME");
  c1 -> SaveAs("resolution_vs_mass.png");
}
