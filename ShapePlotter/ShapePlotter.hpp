#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include <iostream>
#include <fstream>
#include <vector>

class ShapePlotter
{
    vector <TFile> File;
    TChain *chain;
    vector <string> VarNames;
    vector <Float_t> Vars;

public:
  ShapePlotter(vector <string> FileNames_);
  void SetVarNames(vector <string> VarNames_);
  void Draw();

};  