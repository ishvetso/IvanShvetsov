#include <TFile.h>
#include <TTree.h>
#include <TTreeFormula.h>
#include <TH1.h>
#include <TH2.h>
#include <THStack.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TRandom3.h>
#include <TAxis.h>
#include <iostream>
#include <iostream>
#include <sstream>
#include <map>
#include <Math/Random.h>
#include <Math/GSLRndmEngines.h>
#include <time.h> 
void rv_draw()
{
  gStyle->SetCanvasColor(kWhite);
  //gStyle->SetTitleFillColor(kWhite);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  Int_t Nbins =100;
  double RV_min =0., RV_max=0.8;
  
  TRandom3 R;
  time_t timer;
  R.SetSeed(time(&timer));
  double x;
 
  //getting from the tree
  TFile f(" /afs/cern.ch/work/i/ishvetso/Single_limit_RV/ANOM.root");
  TTree *t = (TTree*)f.Get("chain_1");
  Double_t  RV;
  Int_t weight;
  t -> SetBranchAddress("RV", &RV);
  t -> SetBranchAddress("weight", &weight);
  TH1D *hist = new TH1D("Anom", "Anom", Nbins, RV_min, RV_max);
  TH1D *hist_68 = new TH1D("Anom_68", "Anom_68", Nbins, RV_min, RV_max);
  TH1D *hist_95 = new TH1D("Anom_95", "Anom_95", Nbins, RV_min, RV_max);
  
  for  (int l = 0; l < (int)t -> GetEntries();++l)
  {
      t -> GetEntry(l);
//Below is the line to change total uncertainty
      x = R.Gaus(0., 0.114);
      if ((RV+x) > 0.)hist -> Fill(RV+x,weight);
      else hist -> Fill(-RV-x,weight);
   
  }
   
   double tot = hist -> Integral();
   double sum = 0.0;
   double v;
   int down=1, up=1;
   for (int i=1; i <=Nbins; ++i)
   {
      sum = sum + (hist -> GetBinContent(i));
      cout << sum/tot << endl;
      if (((sum/tot)<0.68)) hist_68 -> SetBinContent(i,(hist -> GetBinContent(i)));
      if (((sum/tot)<0.95)) hist_95 -> SetBinContent(i,(hist -> GetBinContent(i)));
      if (((sum/tot)<0.95)) up =i;
      
     
   }
   
   TLegend *leg;
   leg = new TLegend(0.7,0.6,0.9,0.9);
   leg -> SetTextFont(4111);
   leg ->  SetFillColor(kWhite);
   leg->AddEntry(hist_95,"95\% C.L.","f");
   leg->AddEntry(hist_68,"68\% C.L.","f");
   
   //drawing
   
   hist->GetXaxis()->SetTitle("RV");
   hist -> SetLineColor(kWhite);
   hist -> SetFillColor(kOrange);
   hist_68 -> SetFillColor(kBlue);
   hist_95 -> SetFillColor(kRed);
   TCanvas *c1=  new TCanvas("c1","canvas",1300,800);
   hist -> Draw();
   hist_95 -> Draw("SAME");
   hist_68 -> Draw("SAME");
   leg-> Draw("SAME");
   cout  <<  " ---------------------"<< endl;
   cout << hist ->  GetBinLowEdge(up) + (RV_max - RV_min)/Nbins << endl;
 //  cout << hist ->  GetBinLowEdge(down) << endl;
  
  c1 -> SaveAs("RV.png");
   
  
}
