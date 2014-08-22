#ifndef PU_BIN_PLOTTER
#define PU_BIN_PLOTTER

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
#include <math.h> 

using namespace std;

class HistPUBinsProducer
{
   vector <TFile> Files;
   vector <string> FileNames;
   Int_t nPUmax, nPUmin, interval, Nbins;
   Float_t xmin, xmax, xmin_response, xmax_response;
   vector <TH1F*> hists;
  

public:
  string VarName;
  vector <TH1F*> hists_response;
  HistPUBinsProducer();
   void SetInputFiles(string inputFile);
   void SetPUBinsParameters(Int_t nPUmin_, Int_t nPUmax_, Int_t interval_);
   void SetResponseParameters(Float_t xmin_response_, Float_t xmax_response_);
   void SetBinParameters(Int_t Nbins_, Float_t xmin_, Float_t xmax_);
   vector <TH1F*>  ProduceHists(string treename);
};  
#endif