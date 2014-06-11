#include "ShapePlotter.cpp"

void test()
{
  
  string prefix = "/storage/a/ishvetso/JetSubstructureStudies/RSGraviton_JMET_samples/";
  
  
  ShapePlotter Plotter;
  Plotter.AddVariable("m", "pf", kRed);
  Plotter.AddVariable("mraw", "pf", kGreen);
  Plotter.SetTitle("WW AK8");
  Plotter.xmin = 0.;
  Plotter.xmax = 200.;
  Plotter.Nbins = 20;
  Plotter.SetInputFiles(prefix + "WWtree_AK8.root");
  Plotter.Draw();
  Plotter.ClearVariables();
  Plotter.AddVariable("mtrim", "pf", kRed);
  Plotter.AddVariable("mtrimsafe", "pf", kGreen);
  Plotter.Draw();
  
}
