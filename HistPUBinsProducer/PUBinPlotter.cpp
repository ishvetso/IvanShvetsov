#include "HistPUBinsProducer.cpp"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TLatex.h"
#include <sstream>
#include "TGaxis.h"
#include <stdio.h>
#include "/storage/1/ishvetso/git/IvanShvetsov/CMS_stylistics/tdrstyle.C"
#include "/storage/1/ishvetso/git/IvanShvetsov/CMS_stylistics/CMS_lumi.cpp"
/*
 * Plotting PU-dependence plots for different groomers:
 * Mean mass, RMS mass, Mean response, RMS response by fitting gaussian and calculating mean and RMS
 * 
 * for JME-14-001
 * 
 * Compile with
 * g++ -o PUBinPlotter  PUBinPlotter.cpp --std=c++11 `root-config --cflags --libs` -O2 -I./ -lASImage
 * 
 */

void PUPlotter( string tag, string treeName, vector <string> var )
{
  HistPUBinsProducer Producer;
  
  string inputFileList = "/storage/1/ishvetso/git/IvanShvetsov/scripts/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14.txt";
  std::ifstream ifs(inputFileList);
  std::string line;
  
  int counter = 0;
  
  while(std::getline(ifs, line))
  {
    Producer.SetInputFiles(line);
    counter ++;
    std::cout << line << std::endl;
  // if (counter > 1) break;
  }

  Float_t PUmin = 15., PUmax = 50.; //PUmax not included --> [20,21), [21, 22).... [49,50)
  Int_t interval = 5;
  Producer.SetPUBinsParameters(PUmin, PUmax, interval);
  Producer.SetBinParameters(100, 0.,200.);
  Producer.SetResponseParameters(-100., 100.);
  vector <TH1F*> hists;
  vector <TH1F*> hists_response;
  
  
  vector <string> VarNames;
  vector <string> VarLabels;
  vector <Color_t> Colors;
  string TagLabel;
  if (treeName == "pf") TagLabel = "PF";
  else if (treeName == "chs") TagLabel = "PF + CHS";
  else if (treeName == "puppi") TagLabel = "PF + PUPPI"; 
  else cerr << "tree name is not supported " << endl;
  
  //VarNames.push_back("m");
  for (unsigned int i = 0; i< var.size(); ++i)
  {
    VarNames.push_back(var.at(i));
  }
  for ( unsigned int iLabel = 0; iLabel < VarNames.size(); iLabel++)
  {
    //pruning
    if ((VarNames.at(iLabel) == "mpruned_zcut_010_R_cut_050") || ( VarNames.at(iLabel) == "mprunedsafe_zcut_010_R_cut_050" )) VarLabels.push_back("z_{cut} = 0.1, r_{cut} = 0.5");
    else if ((VarNames.at(iLabel) == "mpruned_zcut_005_R_cut_050") || (VarNames.at(iLabel) == "mprunedsafe_zcut_005_R_cut_050" ) ) VarLabels.push_back("z_{cut} = 0.05, r_{cut} = 0.5");
    else if ( (VarNames.at(iLabel) == "mpruned_zcut_005_R_cut_075" ) || ( VarNames.at(iLabel) == "mprunedsafe_zcut_005_R_cut_075")) VarLabels.push_back("z_{cut} = 0.05, r_{cut} = 0.75");
    else if ((VarNames.at(iLabel) == "mpruned_zcut_010_R_cut_075") || (VarNames.at(iLabel) == "mprunedsafe_zcut_010_R_cut_075") ) VarLabels.push_back("z_{cut} = 0.1, r_{cut} = 0.75");
    
    //trimming
    else if ((VarNames.at(iLabel) == "mtrim_Rtrim_020_Ptfrac_005" ) || (VarNames.at(iLabel) == "mtrimsafe_Rtrim_020_Ptfrac_005" )  ) VarLabels.push_back("r_{sub} = 0.2, pT_{frac} = 0.05");
    else if ( (VarNames.at(iLabel) == "mtrim_Rtrim_010_Ptfrac_003" ) || (VarNames.at(iLabel) == "mtrimsafe_Rtrim_010_Ptfrac_003" )) VarLabels.push_back("r_{sub} = 0.1, pT_{frac} = 0.03");
    else if ( (VarNames.at(iLabel) == "mtrim_Rtrim_020_Ptfrac_003") || (VarNames.at(iLabel) == "mtrimsafe_Rtrim_020_Ptfrac_003")) VarLabels.push_back("r_{sub} = 0.2, pT_{frac} = 0.03");
    else if ((VarNames.at(iLabel) == "mtrim_Rtrim_030_Ptfrac_003") || (VarNames.at(iLabel) == "mtrimsafe_Rtrim_030_Ptfrac_003") ) VarLabels.push_back("r_{sub} = 0.3, pT_{frac} = 0.03");
    
    //softdrop
    else if ((VarNames.at(iLabel) == "msoftdrop_beta20" ) || (VarNames.at(iLabel) == "msoftdropsafe_beta20" )  ) VarLabels.push_back("#beta = 2");
    else if ((VarNames.at(iLabel) == "msoftdrop_beta00" ) || (VarNames.at(iLabel) == "msoftdropsafe_beta00" )  ) VarLabels.push_back("#beta = 0");
    else if ((VarNames.at(iLabel) == "msoftdrop_beta10" ) || (VarNames.at(iLabel) == "msoftdropsafe_beta10" )  ) VarLabels.push_back("#beta = 1");
    else if ((VarNames.at(iLabel) == "msoftdrop_beta-10" ) || (VarNames.at(iLabel) == "msoftdropsafe_beta-10" )  ) VarLabels.push_back("#beta = -1");
  
    
    else cerr << "Label " << VarNames.at(iLabel) << " is not correct" << endl; 
  }

  Colors.push_back(kBlack);
  Colors.push_back(kRed);
  Colors.push_back(kGreen);
  Colors.push_back(kBlue);
 
  system(("mkdir -p " + treeName).c_str());
  system(("mkdir -p " + treeName + "/png").c_str());
  system(("mkdir -p " + treeName + "/pdf").c_str());
  system(("mkdir -p " + treeName + "/C").c_str());
  
  TFile file(( treeName + "/resolution_" + tag + "_" + treeName + ".root").c_str(), "RECREATE");
  file.cd();

  TMultiGraph *mg_Masses = new TMultiGraph("", "");
  TMultiGraph *mg_MassRMS = new TMultiGraph("", "");
  TMultiGraph *mg_ResponseMass = new TMultiGraph("", "");
  TMultiGraph *mg_RMSResponse = new TMultiGraph("", "");
  
  setTDRStyle();
  TLegend  *leg ;
  if (tag!="softdrop")leg = new TLegend(0.88,0.7,0.68,0.9);
  else if (tag =="softdrop")leg = new TLegend(1.04,0.7,0.8,0.9);
  TLegend  *leg2 = new TLegend(0.55,0.15,0.9,0.25);
  leg ->  SetTextSize(0.03);
  leg ->  SetFillStyle(0.);
  leg2 ->  SetFillStyle(0.);
  leg2 ->  SetTextSize(0.05);
    
  for (unsigned iVar = 0; iVar < VarNames.size(); ++iVar)
  {
     Producer.VarName = VarNames[iVar];  
     hists.clear();
     hists_response.clear();
     hists = Producer.ProduceHists(treeName);
     hists_response = Producer.hists_response; 
     
     cout << VarNames[iVar] << endl;  
     
     Int_t Npoints = hists.size();
    
     Float_t masses[Npoints], RMSmasses[Npoints], RMSResponse[Npoints], MassResponse[Npoints], PileUp[Npoints];
     Float_t massesErrors[Npoints], RMSmassesErrors[Npoints], RMSResponseErrors[Npoints], MassResponseErrors[Npoints], PileUpErrors[Npoints];
         
     Float_t massesEstimated[Npoints], RMSmassesEstimated[Npoints], RMSResponseEstimated[Npoints], MassResponseEstimated[Npoints];
     Float_t massesErrorsEstimated[Npoints], RMSmassesErrorsEstimated[Npoints], RMSResponseErrorsEstimated[Npoints], MassResponseErrorsEstimated[Npoints];
     string PUNumberLow[Npoints], PUNumberUp[Npoints];
          
     for (unsigned int i = 0; i < Npoints; ++ i )
     {
	PileUp[i] = PUmin + interval*0.5 + i*interval;
	PileUpErrors[i] = 2.5;

	hists.at(i) -> Fit("gaus");
	TF1 * mass = (TF1*) hists.at(i) -> GetFunction("gaus");
	hists_response.at(i) -> Fit("gaus");
	TF1 * mass_response = (TF1*) hists_response.at(i) -> GetFunction("gaus");
       
	massesEstimated[i] = (hists.at(i) -> GetMean());
	massesErrorsEstimated[i]  = (hists.at(i) -> GetMeanError());

	masses[i] = mass -> GetParameter(1);
	massesErrors[i]  = mass -> GetParError(1);

	MassResponseEstimated[i] = (hists_response.at(i) -> GetMean());
	MassResponseErrorsEstimated[i] = (hists_response.at(i) -> GetMeanError());

	MassResponse[i] = mass_response -> GetParameter(1);
	MassResponseErrors[i] = mass_response-> GetParError(1);


	RMSmassesEstimated[i] = hists.at(i) -> GetRMS();
	RMSmassesErrorsEstimated[i] = hists.at(i) -> GetRMSError();

	RMSmasses[i] = mass -> GetParameter(2);
	RMSmassesErrors[i] = mass -> GetParError(2);

	RMSResponseEstimated[i] = hists_response.at(i) -> GetRMS();
	RMSResponseErrorsEstimated[i] = hists_response.at(i) -> GetRMSError();

	RMSResponse[i] = mass_response -> GetParameter(2);
	RMSResponseErrors[i] = mass_response -> GetParError(2);

     }
     
     TGraphErrors *gr_masses = new TGraphErrors(Npoints, PileUp, masses, PileUpErrors, massesErrors);
     TGraphErrors *gr_massResponse = new TGraphErrors(Npoints, PileUp, MassResponse, PileUpErrors, MassResponseErrors);
     TGraphErrors *gr_massRMS = new TGraphErrors(Npoints, PileUp, RMSmasses, PileUpErrors, RMSmassesErrors);
     TGraphErrors *gr_RMSResponse = new TGraphErrors(Npoints, PileUp, RMSResponse, PileUpErrors, RMSResponseErrors);
     
     TGraphErrors *gr_masses_Estimated = new TGraphErrors(Npoints, PileUp, massesEstimated, PileUpErrors, massesErrorsEstimated);
     TGraphErrors *gr_massResponse_Estimated = new TGraphErrors(Npoints, PileUp, MassResponseEstimated, PileUpErrors, MassResponseErrorsEstimated);
     TGraphErrors *gr_massRMS_Estimated = new TGraphErrors(Npoints, PileUp, RMSmassesEstimated, PileUpErrors, RMSmassesErrorsEstimated);
     TGraphErrors *gr_RMSResponse_Estimated = new TGraphErrors(Npoints, PileUp, RMSResponseEstimated, PileUpErrors, RMSResponseErrorsEstimated);
    
    for (unsigned int i =0; i< Npoints;++i)
    {
      ostringstream Number;   
      Number<< PUmin + interval*i;
      PUNumberLow[i] = Number.str();
      Number.str("");
      
      Number<< PUmin + interval*(i + 1);
      PUNumberUp[i] = Number.str();
           
      hists.at(i) -> SetName(("[" + PUNumberLow[i] + ", "  + PUNumberUp[i] + "]" + VarNames.at(iVar) ).c_str());
      hists_response.at(i) -> SetName(("Response_[" + PUNumberLow[i] + ", "  + PUNumberUp[i] + "]" + VarNames.at(iVar) ).c_str());
      
      hists.at(i) -> Write();
      hists_response.at(i) -> Write();
    }
    
    
   gr_masses -> SetMarkerColor(Colors.at(iVar));
   gr_masses -> SetFillColor(Colors.at(iVar));
   gr_masses -> SetLineColor(Colors.at(iVar));
   gr_masses -> SetMarkerStyle(22);
   gr_masses -> SetLineWidth(2.);
   gr_masses -> SetMarkerSize(1.5);   
   
   gr_massResponse -> SetMarkerColor(Colors.at(iVar));
   gr_massResponse -> SetFillColor(Colors.at(iVar));
   gr_massResponse -> SetLineColor(Colors.at(iVar));
   gr_massResponse -> SetMarkerStyle(22);
   gr_massResponse -> SetLineWidth(2.);
   gr_massResponse -> SetMarkerSize(1.5);
   
   
   gr_massRMS -> SetMarkerColor(Colors.at(iVar));
   gr_massRMS -> SetFillColor(Colors.at(iVar));
   gr_massRMS -> SetLineColor(Colors.at(iVar));
   gr_massRMS -> SetMarkerStyle(22);
   gr_massRMS -> SetLineWidth(2.);
   gr_massRMS -> SetMarkerSize(1.5);   
      
   gr_RMSResponse -> SetMarkerColor(Colors.at(iVar));
   gr_RMSResponse -> SetFillColor(Colors.at(iVar));
   gr_RMSResponse -> SetLineColor(Colors.at(iVar));
   gr_RMSResponse -> SetMarkerStyle(22);
   gr_RMSResponse -> SetLineWidth(2.);
   gr_RMSResponse -> SetMarkerSize(1.5);   
   
   //graphs with mean and RMS 
   gr_masses_Estimated -> SetMarkerColor(Colors.at(iVar));
   gr_masses_Estimated -> SetFillColor(Colors.at(iVar));
   gr_masses_Estimated -> SetLineColor(Colors.at(iVar));
   gr_masses_Estimated -> SetMarkerStyle(21);
   gr_masses_Estimated -> SetLineWidth(2.);
   gr_masses_Estimated -> SetMarkerSize(1.5);   
   
   gr_massResponse_Estimated -> SetMarkerColor(Colors.at(iVar));
   gr_massResponse_Estimated -> SetFillColor(Colors.at(iVar));
   gr_massResponse_Estimated -> SetLineColor(Colors.at(iVar));
   gr_massResponse_Estimated -> SetMarkerStyle(21);
   gr_massResponse_Estimated -> SetLineWidth(2.);
   gr_massResponse_Estimated -> SetMarkerSize(1.5);
   
   
   gr_massRMS_Estimated -> SetMarkerColor(Colors.at(iVar));
   gr_massRMS_Estimated -> SetFillColor(Colors.at(iVar));
   gr_massRMS_Estimated -> SetLineColor(Colors.at(iVar));
   gr_massRMS_Estimated -> SetMarkerStyle(21);
   gr_massRMS_Estimated -> SetLineWidth(2.);
   gr_massRMS_Estimated -> SetMarkerSize(1.5);   
   
   gr_RMSResponse_Estimated -> SetMarkerColor(Colors.at(iVar));
   gr_RMSResponse_Estimated -> SetFillColor(Colors.at(iVar));
   gr_RMSResponse_Estimated -> SetLineColor(Colors.at(iVar));
   gr_RMSResponse_Estimated -> SetMarkerStyle(21);
   gr_RMSResponse_Estimated -> SetLineWidth(2.);
   gr_RMSResponse_Estimated -> SetMarkerSize(1.5);

   mg_Masses -> Add(gr_masses);
   mg_Masses -> Add(gr_masses_Estimated);
   
   mg_ResponseMass -> Add(gr_massResponse);
   mg_ResponseMass -> Add(gr_massResponse_Estimated);
   
   mg_MassRMS -> Add(gr_massRMS);
   mg_MassRMS -> Add(gr_massRMS_Estimated);
   
   mg_RMSResponse -> Add(gr_RMSResponse);
   mg_RMSResponse -> Add(gr_RMSResponse_Estimated);
   
   
   
   leg->AddEntry(gr_masses,(VarLabels.at(iVar) ).c_str(),"l");
   leg2 -> SetNColumns(2);
   if  (iVar == 0)
   {
      TGraph *gr1 = new TGraph();
      TGraph *gr2 = new TGraph();
      
      gr2 -> SetMarkerStyle(21);
      gr1 -> SetMarkerStyle(22);
      
      gr2 -> SetMarkerSize(2);
      gr1 -> SetMarkerSize(2.);
      
      leg2->AddEntry(gr1,"fitted #sigma","p");
      leg2->AddEntry(gr2,"RMS","p");
   }

   
  }

  
  leg -> SetLineWidth(0.);
  leg -> SetLineColor(kWhite);
  leg2 -> SetLineWidth(0.);
  leg2 -> SetLineColor(kWhite);

  setTDRStyle();
  
  TCanvas *c1=  new TCanvas("c1","canvas",1000,800);
  
  c1->SetTickx(1);
  c1->SetTicky(1);  
  
  TPaveText descriptionPave(0.2,0.6,0.4,0.9, "NDC");
  TPaveText descriptionPaveCMS(0.12,0.85,0.3,0.98, "NDC");
  descriptionPave.SetFillStyle(0);  // transparent
  descriptionPave.SetBorderSize(0);
  descriptionPave.SetTextAlign(11);
  descriptionPave.SetTextSize(0.04);
  descriptionPave.AddText("RSGraviton #rightarrow WW, Anti-kT (R=0.8) ");
  descriptionPave.AddText("<n_{PU}>=40");
  descriptionPave.AddText("p_{T} > 300 GeV");
  descriptionPave.AddText("|#eta| < 2.5");
  
  string CollectionLabel, AlgoLabel;
  
  if (treeName == "pf") CollectionLabel = "PF";
  else if (treeName == "chs")CollectionLabel = "PF + CHS";
  else if (treeName == "puppi") CollectionLabel = "PF + PUPPI";
  else cerr << "Tree Name is not supported " << endl;

  if (tag == "pruned") AlgoLabel = "pruning";
  else if (tag == "trimmed") AlgoLabel = "trimming";
  else if (tag == "softdrop") AlgoLabel = "softdrop";
  else cerr << "algo not supported" << endl;
  
  descriptionPave.AddText((CollectionLabel + " with " + AlgoLabel ).c_str());
  
      
  //Mean mass
  //c1 -> Clear();
  mg_Masses -> Draw("AP");
  mg_Masses -> GetXaxis() -> SetTitle("n_{PV}");
  mg_Masses -> GetYaxis() -> SetTitle(("<m_{" + tag + "}> (GeV)").c_str());
  mg_Masses -> GetYaxis() -> SetRangeUser(50., 130.);
  leg -> Draw("SAME");
  leg2 -> Draw("SAME");
  CMS_lumi( c1, 4, 0 );
  descriptionPave.Draw();
  c1 -> SaveAs((treeName + "/png/mass_vs_nPU_" + tag + ".png").c_str());
  c1 -> SaveAs((treeName + "/pdf/mass_vs_nPU_" + tag + ".pdf").c_str());
  c1 -> SaveAs((treeName + "/C/mass_vs_nPU_" + tag + ".C").c_str());
  c1 -> Clear();
    
  // Mass Response
  mg_ResponseMass -> Draw("AP");
  mg_ResponseMass -> GetXaxis() -> SetTitle("n_{PV}");
  mg_ResponseMass -> GetYaxis() -> SetTitle("<m_{reco}-m_{gen}> (GeV)");
  mg_ResponseMass -> GetYaxis() -> SetRangeUser(-20., 30.);
  leg -> Draw("SAME");
  leg2 -> Draw("SAME");
  CMS_lumi( c1, 4, 0 );
  descriptionPave.Draw();
  c1 -> SaveAs((treeName + "/png/massResponse_" + tag + ".png").c_str());
  c1 -> SaveAs((treeName + "/pdf/massResponse_" + tag + ".pdf").c_str());
  c1 -> SaveAs((treeName + "/C/massResponse_" + tag + ".C").c_str());
  c1 -> Clear();

  //Mass RMS
  mg_MassRMS -> Draw("AP");
  mg_MassRMS -> GetXaxis() -> SetTitle("n_{PV}");
  mg_MassRMS -> GetYaxis() -> SetTitle(("Resolution(m_{" + tag + "} ) [GeV]").c_str());
  mg_MassRMS -> GetYaxis() -> SetRangeUser(0., 60.);
  leg -> Draw("SAME");
  leg2 -> Draw("SAME");
  CMS_lumi( c1, 4, 0 );
  descriptionPave.Draw();
  c1 -> SaveAs((treeName + "/png/mass_resolution_vs_nPU_" + tag + ".png").c_str());
  c1 -> SaveAs((treeName + "/pdf/mass_resolution_vs_nPU_" + tag + ".pdf").c_str());
  c1 -> SaveAs((treeName + "/C/mass_resolution_vs_nPU_" + tag + ".C").c_str());
  c1 -> Clear();
  
  //RMS Response
  mg_RMSResponse -> Draw("AP");
  mg_RMSResponse -> GetXaxis() -> SetTitle("n_{PV}");
  mg_RMSResponse -> GetYaxis() -> SetTitle("Resolution(m_{reco}-m_{gen}) [GeV]");
  mg_RMSResponse -> GetYaxis() -> SetRangeUser(0., 30. );
  leg -> Draw("SAME");
  leg2 -> Draw("SAME");
  CMS_lumi( c1, 4, 0 );
  descriptionPave.Draw();
  c1 -> SaveAs((treeName + "/png/RMSResponse_vs_nPU_" + tag + ".png").c_str());
  c1 -> SaveAs((treeName + "/pdf/RMSResponse_vs_nPU_" + tag + ".pdf").c_str());
  c1 -> SaveAs((treeName + "/C/RMSResponse_vs_nPU_" + tag + ".C").c_str());
  c1 -> Clear();

}

int main(int argc, char** argv)
{

    vector <string> VarNames;
    for (unsigned int i = 3; i < argc; ++i)
    {
      VarNames.push_back(argv[i]);
    }
    std::string tag = argv[1];
    std::string treeName = argv[2];  
   
    PUPlotter(tag, treeName, VarNames);
  
}
