#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLine.h"
#include "TH1F.h"
#include "TPad.h"
#include <TStyle.h>
#include <TFolder.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Variable.hpp"

using namespace std;

class ShapePlotter
{
    vector <TFile> Files;
    vector <Variable> Variables;
    vector <TH1F*> hists;
    vector <string> FileNames;
    string title;

 
public:
  Float_t xmin, xmax;
  Int_t Nbins;
  ShapePlotter();
  void AddVariable(string VarName_, string TreeName_, Color_t color_);
  void SetTitle(string title_);
  void ClearVariables();
  void SetInputFiles(string inputFile);
  void ClearInputFiles();
  void Draw(string outprefix);

};  

