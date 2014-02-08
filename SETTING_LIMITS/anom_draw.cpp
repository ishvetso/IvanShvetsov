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
void anom_draw()
{
  gStyle->SetCanvasColor(kWhite);
  //gStyle->SetTitleFillColor(kWhite);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  Int_t Nbins =70;
  double RV_min = 0.0, RV_max=1.0, LV_min = 0.5, LV_max=1.2;
  
  //getting from the tree
  TFile f("/afs/cern.ch/work/i/ishvetso/THETA/ANOM.root");
  TTree *t = (TTree*)f.Get("chain_1");
  Double_t LV, RV;
  Int_t weight;
  t -> SetBranchAddress("LV", &LV);
  t -> SetBranchAddress("RV", &RV);
  t -> SetBranchAddress("weight", &weight);
  TH2D *hist = new TH2D("Anom", "Anom", Nbins, RV_min, RV_max, Nbins, LV_min, LV_max);
  Double_t X,Y;
  ROOT::Math::Random <ROOT::Math::GSLRngMT> g;
  time_t timer;
  g.SetSeed(time(&timer));
  
  for  (int l = 0; l < (int)t -> GetEntries();++l)
  {
      t -> GetEntry(l);
//this a place in put information from studying unmarginalized systematics
      g.Gaussian2D( 0.0445473, 0.159421, 0.879385, X,  Y);
      if ((RV+Y)>0.) hist -> Fill(RV+Y, LV+X,weight);
      else hist -> Fill(-RV-Y, LV+X,weight);
   
  }
   
   //drawing
   hist->GetYaxis()->SetTitle("LV");
   hist->GetXaxis()->SetTitle("RV");
   TCanvas *c1=  new TCanvas("c1","canvas",1300,800);
  // hist -> Draw("COLZ");
//    c1 -> SaveAs("anom_NN_oneNet_ch.png");
   
   //Next 95% contour is drawed
	double L = 900.0;
  double tot = hist -> Integral();
  double part =0.;
  TH2D *hist_68 = new TH2D("Part", "Part", Nbins, RV_min, RV_max, Nbins, LV_min, LV_max);
  TH2D *hist_95 = new TH2D("Part", "Part", Nbins, RV_min, RV_max, Nbins, LV_min, LV_max);
	
 
  L =900.;
  while ((part/tot) < 0.68)
  {
    for (int i =1; i<=Nbins; ++i)
    for (int j =1; j <= Nbins; ++j)
    {
      {
	double v = hist -> GetBinContent(i,j);
	if (v > L) hist_68 -> SetBinContent(i, j, v);
	
      }
    }
   part = hist_68 -> Integral();
   cout << part/tot << endl;
    L = L-1.;
  }
  
  L =900.;
  part =0.0;
  while ((part/tot) < 0.95)
  {
    for (int i =1; i<=Nbins; ++i)
    for (int j =1; j <= Nbins; ++j)
    {
      {
	 
	double v = hist -> GetBinContent(i,j);
	if (v > L) hist_95 -> SetBinContent(i, j, v);
	
      }
    }
    
    part = hist_95 -> Integral();
    cout << part/tot << endl;
    L = L-1.;
  }
  
  for (int i =1; i<=Nbins; ++i)
    for (int j =1; j <= Nbins; ++j)
    {
      {
	 
	if ((hist_68 -> GetBinContent(i, j))!=0.) hist_95 -> SetBinContent(i, j, 0);
	
      }
    }
 
   hist_68 -> SetFillColor(kRed);
   hist_68 -> SetMarkerColor(kRed);
   hist_68 -> SetLineColor(kRed);
   hist_68 -> GetYaxis()->SetTitle("LV");
   hist_68 -> GetXaxis()->SetTitle("RV");
   
   hist_95 -> SetFillColor(kOrange);
   hist_95 -> SetMarkerColor(kOrange);
   hist_95 -> SetLineColor(kOrange);
   hist_95 -> GetYaxis()->SetTitle("LV");
   hist_95 -> GetXaxis()->SetTitle("RV");
   
   TLegend *leg;
   leg = new TLegend(0.7,0.6,0.9,0.9);
   leg -> SetTextFont(4111);
   leg ->  SetFillColor(kWhite);
   leg->AddEntry(hist_95,"95\% C.L.","f");
   leg->AddEntry(hist_68,"68\% C.L.","f");
   gPad -> Update();
   hist_95 -> Draw();
  hist_68 -> Draw("SAME");
  leg->Draw("SAME");
  c1 -> SaveAs("LVRV.png");
  
}
