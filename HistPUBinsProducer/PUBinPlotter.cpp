#include "HistPUBinsProducer.cpp"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TLatex.h"
#include <sstream>
#include "TGaxis.h"



void PUPlotter( string var1, string var2, string var3, string var4, string tag, string treeName)
{
  
  HistPUBinsProducer Producer;
  
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/caf/user/rgerosa/MiniNtuples_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_0.root");
/*Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_1.root");
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
Producer.SetInputFiles("root://eoscms.cern.ch//eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/outtree_9.root");*/
  
  Float_t PUmin = 25., PUmax = 55.; //PUmax not included --> [20,21), [21, 22).... [49,50)
  Int_t interval =5;
  Producer.SetPUBinsParameters(PUmin, PUmax, interval);
  Producer.SetBinParameters(50, 0.,200.);
  Producer.SetResponseParameters(-100., 100.);
  vector <TH1F*> hists;
  vector <TH1F*> hists_response;
  
  
  vector <string> VarNames;
  vector <string> VarLabels;
  vector <Color_t> Colors;
  string TagLabel;
  if (tag == "pf") TagLabel = "PF";
  else if (tag == "chs") TagLabel = "PF + CHS";
  else if (tag == "puppi") TagLabel = "PF + PUPPI"; 
  
  //VarNames.push_back("m");
  VarNames.push_back(var1);
  VarNames.push_back(var2);
  VarNames.push_back(var3);
  VarNames.push_back(var4);
  
  for ( unsigned int iLabel = 0; iLabel < VarNames.size(); iLabel++)
  {
    //pruning
    if ((VarNames.at(iLabel) == "mpruned_zcut_010_R_cut_050") || ( VarNames.at(iLabel) == "mprunedsafe_zcut_010_R_cut_050" )) VarLabels.push_back("Pruned (z_{cut} = 0.1, r_{cut} = 0.5)");
    else if ((VarNames.at(iLabel) == "mpruned_zcut_005_R_cut_050") || (VarNames.at(iLabel) == "mprunedsafe_zcut_005_R_cut_050" ) ) VarLabels.push_back("Pruned (z_{cut} = 0.05, r_{cut} = 0.5)");
    else if ( (VarNames.at(iLabel) == "mpruned_zcut_005_R_cut_075" ) || ( VarNames.at(iLabel) == "mprunedsafe_zcut_005_R_cut_075")) VarLabels.push_back("Pruned (z_{cut} = 0.05, r_{cut} = 0.75)");
    else if ((VarNames.at(iLabel) == "mpruned_zcut_010_R_cut_075") || (VarNames.at(iLabel) == "mprunedsafe_zcut_010_R_cut_075") ) VarLabels.push_back("Pruned (z_{cut} = 0.1, r_{cut} = 0.75)");
    
    //trimming
    else if ((VarNames.at(iLabel) == "mtrim_Rtrim_020_Ptfrac_005" ) || (VarNames.at(iLabel) == "mtrimsafe_Rtrim_020_Ptfrac_005" )  ) VarLabels.push_back("Trimmed (R_{filt} = 0.2, pT_{frac} = 0.05)");
    else if ( (VarNames.at(iLabel) == "mtrim_Rtrim_010_Ptfrac_003" ) || (VarNames.at(iLabel) == "mtrimsafe_Rtrim_010_Ptfrac_003" )) VarLabels.push_back("Trimmed (R_{filt} = 0.1, pT_{frac} = 0.03)");
    else if ( (VarNames.at(iLabel) == "mtrim_Rtrim_020_Ptfrac_003") || (VarNames.at(iLabel) == "mtrimsafe_Rtrim_020_Ptfrac_003")) VarLabels.push_back("Trimmed (R_{filt} = 0.2, pT_{frac} = 0.03)");
    else if ((VarNames.at(iLabel) == "mtrim_Rtrim_030_Ptfrac_003") || (VarNames.at(iLabel) == "mtrimsafe_Rtrim_030_Ptfrac_003") ) VarLabels.push_back("Trimmed (R_{filt} = 0.3, pT_{frac} = 0.03)");
    
    //softdrop
    else if ((VarNames.at(iLabel) == "msoftdrop_beta20" ) || (VarNames.at(iLabel) == "msoftdropsafe_beta20" )  ) VarLabels.push_back("Softdrop #beta = 2");
    else if ((VarNames.at(iLabel) == "msoftdrop_beta00" ) || (VarNames.at(iLabel) == "msoftdropsafe_beta00" )  ) VarLabels.push_back("Softdrop #beta = 0");
    else if ((VarNames.at(iLabel) == "msoftdrop_beta10" ) || (VarNames.at(iLabel) == "msoftdropsafe_beta10" )  ) VarLabels.push_back("Softdrop #beta = 1");
    else if ((VarNames.at(iLabel) == "msoftdrop_beta-10" ) || (VarNames.at(iLabel) == "msoftdropsafe_beta-10" )  ) VarLabels.push_back("Softdrop #beta = -1");
    
    else cerr << "Label " << VarNames.at(iLabel) << " is not correct" << endl; 
  }
  
  
  Colors.push_back(kBlue);
  Colors.push_back(kRed);
  Colors.push_back(kGreen);
  Colors.push_back(kOrange);
 
  system(("mkdir -p " + treeName).c_str());
  
  TFile file(( treeName + "/resolution_" + tag + "_" + treeName + ".root").c_str(), "RECREATE");
  file.cd();
  
  TCanvas *c1=  new TCanvas("c1","canvas",1000,800);

  TMultiGraph *mg_Masses = new TMultiGraph("", "");
  TMultiGraph *mg_MassRMS = new TMultiGraph("", "");
  TMultiGraph *mg_ResponseMass = new TMultiGraph("", "");
  TMultiGraph *mg_RMSResponse = new TMultiGraph("", "");
    
  TLegend  *leg = new TLegend(0.6,0.7,0.89,0.83);
  //leg ->  SetFillColor(kWhite);
  leg ->  SetFillStyle(0.);
  
  
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
     Float_t massesErrors[Npoints], RMSmassesErrors[Npoints], RMSResponseErrors[Npoints], MassResponseErrors[Npoints], PileUpErrors[Npoints];
         
     Float_t massesEstimated[Npoints], RMSmassesEstimated[Npoints], RMSResponseEstimated[Npoints], MassResponseEstimated[Npoints];
     Float_t massesErrorsEstimated[Npoints], RMSmassesErrorsEstimated[Npoints], RMSResponseErrorsEstimated[Npoints], MassResponseErrorsEstimated[Npoints];
     string PUNumberLow[Npoints], PUNumberUp[Npoints];
          
     for (unsigned int i = 0; i < Npoints; ++ i )
     {
	//masses[i] = (hists.at(i) -> GetBinCenter(hists.at(i) -> GetMaximumBin())) ;
	PileUp[i] = PUmin + interval*0.5 + i*interval;
	PileUpErrors[i] = 0.0;
	
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
      
      //TLatex *latex = new TLatex(gr->GetX()[i], gr->GetY()[i],("[" + PUNumberLow[i] + ", "  + PUNumberUp[i] + "]"  ).c_str());
      //latex -> SetTextSize(0.03);
      //gr->GetListOfFunctions()->Add(latex);
      
      hists.at(i) -> SetName(("[" + PUNumberLow[i] + ", "  + PUNumberUp[i] + "]" + VarNames.at(iVar) ).c_str());
      hists_response.at(i) -> SetName(("Response_[" + PUNumberLow[i] + ", "  + PUNumberUp[i] + "]" + VarNames.at(iVar) ).c_str());
      
     //TF1 *f1 = new TF1("mass","[0]*exp(-0.5*((x-[1])/[2])^2)",0.,200.);
     //f1 -> SetParameters(1., hists.at(i) ->  GetMean(), hists.at(i) ->  GetRMS());
     
     //cout << "Mean " << f1 -> GetParameter(2) << endl;	      
      
      hists.at(i) -> Write();
      hists_response.at(i) -> Write();
    }
    
    
   gr_masses -> SetMarkerColor(Colors.at(iVar));
   gr_masses -> SetFillColor(Colors.at(iVar));
   gr_masses -> SetLineColor(Colors.at(iVar));
   gr_masses -> SetMarkerStyle(21);
   gr_masses -> SetLineWidth(4.);
   gr_masses -> SetMarkerSize(2.);
   
   gr_massResponse -> SetMarkerColor(Colors.at(iVar));
   gr_massResponse -> SetFillColor(Colors.at(iVar));
   gr_massResponse -> SetLineColor(Colors.at(iVar));
   gr_massResponse -> SetMarkerStyle(21);
   gr_massResponse -> SetLineWidth(4.);
   gr_massResponse -> SetMarkerSize(2.);
   
   gr_massRMS -> SetMarkerColor(Colors.at(iVar));
   gr_massRMS -> SetFillColor(Colors.at(iVar));
   gr_massRMS -> SetLineColor(Colors.at(iVar));
   gr_massRMS -> SetMarkerStyle(21);
   gr_massRMS -> SetLineWidth(4.);
   gr_massRMS -> SetMarkerSize(2.);
   
   gr_RMSResponse -> SetMarkerColor(Colors.at(iVar));
   gr_RMSResponse -> SetFillColor(Colors.at(iVar));
   gr_RMSResponse -> SetLineColor(Colors.at(iVar));
   gr_RMSResponse -> SetMarkerStyle(21);
   gr_RMSResponse -> SetLineWidth(4.);
   gr_RMSResponse -> SetMarkerSize(2.);
   
   
   //graphs with mean and RMS 
   gr_masses_Estimated -> SetMarkerColor(Colors.at(iVar));
   gr_masses_Estimated -> SetFillColor(Colors.at(iVar));
   gr_masses_Estimated -> SetLineColor(Colors.at(iVar));
   gr_masses_Estimated -> SetMarkerStyle(22);
   gr_masses_Estimated -> SetLineWidth(4.);
   gr_masses_Estimated -> SetMarkerSize(2.);
   
   gr_massResponse_Estimated -> SetMarkerColor(Colors.at(iVar));
   gr_massResponse_Estimated -> SetFillColor(Colors.at(iVar));
   gr_massResponse_Estimated -> SetLineColor(Colors.at(iVar));
   gr_massResponse_Estimated -> SetMarkerStyle(22);
   gr_massResponse_Estimated -> SetLineWidth(4.);
   gr_massResponse_Estimated -> SetMarkerSize(2.);
   
   gr_massRMS_Estimated -> SetMarkerColor(Colors.at(iVar));
   gr_massRMS_Estimated -> SetFillColor(Colors.at(iVar));
   gr_massRMS_Estimated -> SetLineColor(Colors.at(iVar));
   gr_massRMS_Estimated -> SetMarkerStyle(22);
   gr_massRMS_Estimated -> SetLineWidth(4.);
   gr_massRMS_Estimated -> SetMarkerSize(2.);
   
   gr_RMSResponse_Estimated -> SetMarkerColor(Colors.at(iVar));
   gr_RMSResponse_Estimated -> SetFillColor(Colors.at(iVar));
   gr_RMSResponse_Estimated -> SetLineColor(Colors.at(iVar));
   gr_RMSResponse_Estimated -> SetMarkerStyle(22);
   gr_RMSResponse_Estimated -> SetLineWidth(4.);
   gr_RMSResponse_Estimated -> SetMarkerSize(2.);

   mg_Masses -> Add(gr_masses);
   mg_Masses -> Add(gr_masses_Estimated);
   mg_ResponseMass -> Add(gr_massResponse);
   mg_ResponseMass -> Add(gr_massResponse_Estimated);
   mg_MassRMS -> Add(gr_massRMS);
   mg_MassRMS -> Add(gr_massRMS_Estimated);
   mg_RMSResponse -> Add(gr_RMSResponse);
   mg_RMSResponse -> Add(gr_RMSResponse_Estimated);
   
   leg->AddEntry(gr_masses,VarLabels.at(iVar).c_str(),"pl");
   
  }

  
  
  TPaveText descriptionPave(0.12,0.8,0.3,0.9, "NDC");
  TPaveText descriptionPaveCMS(0.12,0.9,0.3,1.0, "NDC");
  descriptionPave.SetTextAlign(11);
  descriptionPave.SetFillStyle(0);  // transparent
  descriptionPave.SetBorderSize(0);
  descriptionPave.SetTextSize(0.03);
  descriptionPave.AddText("WW, Antikt jets with R = 0.8");// \\ p_{T}^{jet} > 300 GeV");
  descriptionPave.AddText("p_{T}^{jet} > 300 GeV" );
  descriptionPave.AddText(TagLabel.c_str());
  
  descriptionPaveCMS.SetTextAlign(11);
  descriptionPaveCMS.SetFillStyle(0);  // transparent
  descriptionPaveCMS.SetBorderSize(0);
  descriptionPaveCMS.SetTextSize(0.03);
  descriptionPaveCMS.AddText("CMS Simulation Preliminary #sqrt{s} = 13 TeV");
 //  descriptionPave.AddText("#splitline{CMS Simulation Preliminary, #sqrt{s} = 13 TeV}{WW, Antikt jets with R = 0.8  p_{T}^{jet} > 300 GeV}");
  
  leg -> SetLineWidth(0.);
  leg -> SetLineColor(kWhite);
  

  c1->SetTickx(1);
  c1->SetTicky(1);  
  
  //Mean mass
  mg_Masses -> Draw("AP");
  mg_Masses -> GetXaxis() -> SetTitle("n_{PV}");
  mg_Masses -> GetYaxis() -> SetTitle(("<m_{" + tag + "}> (GeV)").c_str());
  Float_t YMIN = 60.;
  Float_t YMAX = 110.;
  mg_Masses -> GetYaxis() -> SetRangeUser(YMIN, YMAX);
  leg -> Draw("SAME");
  descriptionPave.Draw();
  descriptionPaveCMS.Draw();

  
  c1 -> SaveAs((treeName + "/mass_vs_nPU_" + tag + ".png").c_str());
  c1 -> Clear();
  
  // Mass Response
  mg_ResponseMass -> Draw("AP");
  mg_ResponseMass -> GetXaxis() -> SetTitle("n_{PV}");
  mg_ResponseMass -> GetYaxis() -> SetTitle("<m_{Recojet}  - m_{GenJet} (GeV)>");
  mg_ResponseMass -> GetYaxis() -> SetRangeUser(-10., 15.);
  leg -> Draw("SAME");
  descriptionPave.Draw();
  descriptionPaveCMS.Draw();
  c1 -> SaveAs((treeName + "/massResponse_" + tag + ".png").c_str());
  c1 -> Clear();

  //Mass RMS
  mg_MassRMS -> Draw("AP");
  mg_MassRMS -> GetXaxis() -> SetTitle("n_{PV}");
  mg_MassRMS -> GetYaxis() -> SetTitle(("RMS(m_{" + tag + "} ) (GeV)").c_str());
  mg_MassRMS -> GetYaxis() -> SetRangeUser(0., 30.);
  leg -> Draw("SAME");
  descriptionPave.Draw();
  descriptionPaveCMS.Draw();
  c1 -> SaveAs((treeName + "/mass_resolution_vs_nPU_" + tag + ".png").c_str());
  c1 -> Clear();
  
  //RMS Response
  mg_RMSResponse -> Draw("AP");
  mg_RMSResponse -> GetXaxis() -> SetTitle("n_{PV}");
  mg_RMSResponse -> GetYaxis() -> SetTitle("RMS[m_{Recojet}  - m_{GenJet}]> (GeV)");
  mg_RMSResponse -> GetYaxis() -> SetRangeUser(0., 15. );
  leg -> Draw("SAME");
  descriptionPave.Draw();
  descriptionPaveCMS.Draw();

  
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
   
  PUPlotter(VAR1, VAR2, VAR3, VAR4, tag, treeName);
  
}