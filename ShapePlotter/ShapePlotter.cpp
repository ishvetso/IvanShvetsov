#include "ShapePlotter.hpp"

ShapePlotter::ShapePlotter(vector <string> FileNames_)
{
    chain = new TChain("GEN");

   for (unsigned int i =0; i < FileNames_.size(); ++i)
   {
     chain -> Add(FileNames_.at(i).c_str());
   } 
}

void ShapePlotter::SetVarNames(vector <string> VarNames_)
{
  VarNames = VarNames_;
}
void ShapePlotter::Draw()
{
  for (unsigned int i = 0; i < VarNames.size(); ++i )
  {
    Vars.push_back(-100.);
    chain -> SetBranchAddress(VarNames.at(i).c_str(), &Vars.at(i));
  }
  
  for (unsigned iEntry = 0; iEntry < chain -> GetEntries(); ++iEntry)
  {
    chain -> GetEntry(iEntry);
  }
}