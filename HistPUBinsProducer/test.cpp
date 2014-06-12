#include "HistPUBinsProducer.cpp"

void test()
{
  
  HistPUBinsProducer Producer;
  string prefix = "/storage/a/ishvetso/JetSubstructureStudies/Trees/WW/";
  Producer.SetInputFiles(prefix + "WWtree_AK12.root");
  Producer.VarName = "m";
  Producer.SetPUBinsParameters(25, 60, 5);
  Producer.SetBinParameters(20, 40.,200.);
  vector <TH1F*> hists;
  hists = Producer.ProduceHists();
  cout << hists.at(0) -> GetMean() << endl;
}
