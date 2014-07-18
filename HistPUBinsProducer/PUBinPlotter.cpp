#include "HistPUBinsProducer.cpp"
#include "TGraph.h"
#include "TCanvas.h"
#include "TLatex.h"
#include <sstream>



void PUPlotter( string var1, string var2, string var3, string var4, string tag, string treeName)
{
  
  HistPUBinsProducer Producer;

Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_0.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_1.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_10.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_11.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_12.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_13.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_14.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_15.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_16.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_17.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_18.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_19.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_2.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_20.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_21.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_22.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_23.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_24.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_25.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_26.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_27.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_28.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_29.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_3.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_30.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_31.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_32.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_33.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_34.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_35.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_36.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_37.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_38.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_39.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_4.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_40.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_41.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_42.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_43.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_44.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_45.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_46.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_47.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_48.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_49.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_50.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_51.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_6.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_7.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_8.root");
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_9.root");
  
  Float_t PUmin = 20., PUmax = 60.; //PUmax not included --> [20,21), [21, 22).... [49,50)
  Int_t interval =5;
  Producer.SetPUBinsParameters(PUmin, PUmax, interval);
  Producer.SetBinParameters(20, 60.,150.);
  Producer.SetResponseParameters(-20., 20.);
  vector <TH1F*> hists;
  vector <TH1F*> hists_response;
  
  
  vector <string> VarNames;
  vector <Color_t> Colors;
  
  //VarNames.push_back("m");
  VarNames.push_back(var1);
  VarNames.push_back(var2);
  VarNames.push_back(var3);
  VarNames.push_back(var4);
  
  
  Colors.push_back(kBlue);
  Colors.push_back(kRed);
  Colors.push_back(kGreen);
  Colors.push_back(kOrange);
 
  system(("mkdir -p " + treeName).c_str());
  
  TFile file(( treeName + "/resolution_" + tag + "_" + treeName + ".root").c_str(), "RECREATE");
  file.cd();
  
  TCanvas *c1=  new TCanvas("c1","canvas",1500,1000);

  TMultiGraph *mg_Masses = new TMultiGraph("", "");
  TMultiGraph *mg_MassRMS = new TMultiGraph("", "");
  TMultiGraph *mg_ResponseMass = new TMultiGraph("", "");
  TMultiGraph *mg_RMSResponse = new TMultiGraph("", "");
    
  TLegend  *leg = new TLegend(0.1,0.7,0.48,0.9);
  leg ->  SetFillColor(kWhite);
  
  
  for (unsigned iVar = 0; iVar < VarNames.size(); ++iVar)
  {
     Producer.VarName = VarNames[iVar];  
     hists.clear();
     hists_response.clear();
     hists = Producer.ProduceHists(treeName);
     hists_response = Producer.hists_response;     
     
     Int_t Npoints = hists.size();
    // cout << Npoints << endl;
     Float_t masses[Npoints], RMSmasses[Npoints], RMSResponse[Npoints], MassResponse[Npoints], PileUp[Npoints];
     string PUNumberLow[Npoints], PUNumberUp[Npoints];
          
     for (unsigned int i = 0; i < Npoints; ++ i )
     {
	//masses[i] = (hists.at(i) -> GetBinCenter(hists.at(i) -> GetMaximumBin())) ;
	PileUp[i] = PUmin + interval*0.5 + i*interval;
       
	masses[i] = (hists.at(i) -> GetMean());
	MassResponse[i] = (hists_response.at(i) -> GetMean());
	
	RMSmasses[i] = hists.at(i) -> GetRMS();
	RMSResponse[i] = hists_response.at(i) -> GetRMS();
		
     }
     
     TGraph *gr_masses = new TGraph (Npoints, PileUp, masses);
     TGraph *gr_massResponse = new TGraph (Npoints, PileUp, MassResponse);
     TGraph *gr_massRMS = new TGraph (Npoints, PileUp, RMSmasses);
     TGraph *gr_RMSResponse = new TGraph (Npoints, PileUp, RMSResponse);
    
    for (unsigned int i =0; i< Npoints;++i)
    {
      ostringstream Number;   
      Number<< PUmin + interval*i;
      PUNumberLow[i] = Number.str();
      Number.str("");
      
      Number<< PUmin + interval*(i + 1);
      PUNumberUp[i] = Number.str();
      
      //TLatex *latex = new TLatex(gr->GetX()[i], gr->GetY()[i],("[" + PUNumberLow[i] + ", "  + PUNumberUp[i] + "]"  ).c_str());
      //latex -> SetTextSize(0.03);
      //gr->GetListOfFunctions()->Add(latex);
      
      hists.at(i) -> SetName(("[" + PUNumberLow[i] + ", "  + PUNumberUp[i] + "]" + VarNames.at(iVar) ).c_str());
      hists_response.at(i) -> SetName(("Response_[" + PUNumberLow[i] + ", "  + PUNumberUp[i] + "]" + VarNames.at(iVar) ).c_str());
      hists.at(i) -> Write();
      hists_response.at(i) -> Write();
    }
    
    
   gr_masses -> SetMarkerColor(Colors.at(iVar));
   gr_masses -> SetMarkerStyle(21);
   gr_masses -> SetLineWidth(4.);
   gr_masses -> SetMarkerSize(1.);
   
   gr_massResponse -> SetMarkerColor(Colors.at(iVar));
   gr_massResponse -> SetMarkerStyle(21);
   gr_massResponse -> SetLineWidth(4.);
   gr_massResponse -> SetMarkerSize(1.);
   
   gr_massRMS -> SetMarkerColor(Colors.at(iVar));
   gr_massRMS -> SetMarkerStyle(21);
   gr_massRMS -> SetLineWidth(4.);
   gr_massRMS -> SetMarkerSize(1.);
   
   gr_RMSResponse -> SetMarkerColor(Colors.at(iVar));
   gr_RMSResponse -> SetMarkerStyle(21);
   gr_RMSResponse -> SetLineWidth(4.);
   gr_RMSResponse -> SetMarkerSize(1.);

   mg_Masses -> Add(gr_masses);
   mg_ResponseMass -> Add(gr_massResponse);
   mg_MassRMS -> Add(gr_massRMS);
   mg_RMSResponse -> Add(gr_RMSResponse);
   
   leg->AddEntry(gr_masses,VarNames.at(iVar).c_str(),"p");
   
  }

  
  
  TPaveText descriptionPave(0.8,0.8,0.9,0.9, "NDC");
   //  descriptionPave.SetTextAlign(11);
   //descriptionPave.SetFillStyle(0);  // transparent
   //descriptionPave.SetBorderSize(0);
   descriptionPave.AddText(treeName.c_str());
  
  //Mean mass
  mg_Masses -> Draw("AP");
  mg_Masses -> GetXaxis() -> SetTitle("nPU");
  mg_Masses -> GetYaxis() -> SetTitle("Mean Mass");
  mg_Masses -> GetYaxis() -> SetRangeUser(60., 110.);
  leg -> Draw("SAME");
  descriptionPave.Draw();
  c1 -> SaveAs((treeName + "/mass_vs_nPU_" + tag + ".png").c_str());
  c1 -> Clear();
  
  // Mass Response
  mg_ResponseMass -> Draw("AP");
  mg_ResponseMass -> GetXaxis() -> SetTitle("nPU");
  mg_ResponseMass -> GetYaxis() -> SetTitle("Mean Mass Response");
  mg_ResponseMass -> GetYaxis() -> SetRangeUser(-10., 15.);
  leg -> Draw("SAME");
  descriptionPave.Draw();
  c1 -> SaveAs((treeName + "/massResponse_" + tag + ".png").c_str());
  c1 -> Clear();

  //Mass RMS
  mg_MassRMS -> Draw("AP");
  mg_MassRMS -> GetXaxis() -> SetTitle("nPU");
  mg_MassRMS -> GetYaxis() -> SetTitle("Mass Resolution");
  mg_MassRMS -> GetYaxis() -> SetRangeUser(0., 30.);
  leg -> Draw("SAME");
  descriptionPave.Draw();
  c1 -> SaveAs((treeName + "/mass_resolution_vs_nPU_" + tag + ".png").c_str());
  c1 -> Clear();
  
  //RMS Response
  mg_RMSResponse -> Draw("AP");
  mg_RMSResponse -> GetXaxis() -> SetTitle("nPU");
  mg_RMSResponse -> GetYaxis() -> SetTitle("RMS(Mass - GenMass)");
  mg_RMSResponse -> GetYaxis() -> SetRangeUser(0., 15. );
  leg -> Draw("SAME");
  descriptionPave.Draw();
  c1 -> SaveAs((treeName + "/RMSResponse_vs_nPU_" + tag + ".png").c_str());
  c1 -> Clear();

}

int main(int argc, char** argv)
{
  for (int i = 0; i < argc; ++i) {
        //std::  << argv[i] << std::endl;
    }
    if (argc != 7) 
    {
      cout << "Not correct number of parameters" << endl;
      exit(EXIT_FAILURE);
    }
    std::string VAR1 = argv[1];
    std::string VAR2 = argv[2];  
    std::string VAR3 = argv[3];  
    std::string VAR4 = argv[4];
    std::string tag = argv[5];
    std::string treeName = argv[6];  
    
    
  //PUPlotter("mprunedsafe_zcut_010_R_cut_050", "mprunedsafe_zcut_005_R_cut_050", "mprunedsafe_zcut_005_R_cut_075", "mprunedsafe_zcut_010_R_cut_075", "pruned");
  PUPlotter(VAR1, VAR2, VAR3, VAR4, tag, treeName);
  //PUPlotter("mtrimsafe_Rtrim_020_Ptfrac_005", "mtrimsafe_Rtrim_010_Ptfrac_003", "mtrimsafe_Rtrim_020_Ptfrac_003", "mtrimsafe_Rtrim_030_Ptfrac_003", "trimmed");
  //PUPlotter("msoftdropsafe_beta10", "msoftdropsafe_beta-10", "msoftdropsafe_beta00", "msoftdropsafe_beta20", "softdrop");
}