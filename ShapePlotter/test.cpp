#include "ShapePlotter.cpp"

void test()
{
  vector <string> Names;
  Names.push_back("/storage/a/ishvetso/CMSSW_6_2_8/src/output.root");
  vector <string> VarNames;
  VarNames.push_back("mass_GENjet");
  ShapePlotter Plotter(Names);
  Plotter.SetVarNames(VarNames);
  Plotter.Draw();
}