#include "ShapePlotter.cpp"

void test()
{
  
  string prefix = "/storage/a/ishvetso/JetSubstructureStudies/Trees/WW/";
  
  
  ShapePlotter Plotter;
  Plotter.xmin = 50.;
  Plotter.xmax = 200.;
  Plotter.Nbins = 20;
  
  Plotter.SetInputFiles(prefix + "WWtree_AK8.root");
  Plotter.SetTitle("WW AK8");
  Plotter.AddVariable("m", "pf", kRed);
  Plotter.AddVariable("mraw", "pf", kGreen);
  Plotter.Draw("WW_AK8/");
  
  
  Plotter.xmin = 0.;
  Plotter.xmax = 40.;
  Plotter.ClearVariables();
  Plotter.AddVariable("mpruned", "pf", kRed);
  Plotter.AddVariable("mprunedsafe", "pf", kGreen);
  Plotter.Draw("WW_AK8/");
  
  Plotter.xmin = 50.;
  Plotter.xmax = 200.;
  Plotter.ClearVariables();
  Plotter.AddVariable("msoftdrop", "pf", kRed);
  Plotter.AddVariable("msoftdropsafe", "pf", kGreen);
  Plotter.Draw("WW_AK8/");
  
  Plotter.ClearInputFiles();
  Plotter.ClearVariables();
  Plotter.SetInputFiles(prefix + "WWtree_AK12.root");
  Plotter.xmin = 50.;
  Plotter.xmax = 200.;
  Plotter.SetTitle("WW AK12");
  Plotter.AddVariable("m", "pf", kRed);
  Plotter.AddVariable("mraw", "pf", kGreen);
  Plotter.Draw("WW_AK12/");
  
  
  Plotter.xmin = 0.;
  Plotter.xmax = 40.;
  Plotter.ClearVariables();
  Plotter.AddVariable("mpruned", "pf", kRed);
  Plotter.AddVariable("mprunedsafe", "pf", kGreen);
  Plotter.Draw("WW_AK12/");
  
  Plotter.xmin = 50.;
  Plotter.xmax = 200.;
  Plotter.ClearVariables();
  Plotter.AddVariable("msoftdrop", "pf", kRed);
  Plotter.AddVariable("msoftdropsafe", "pf", kGreen);
  Plotter.Draw("WW_AK12/");

}
