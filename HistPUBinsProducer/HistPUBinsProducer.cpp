#include "HistPUBinsProducer.hpp"

HistPUBinsProducer::HistPUBinsProducer()
{}

void HistPUBinsProducer::SetInputFiles(string inputFile)
{
  FileNames.push_back(inputFile);
}

void HistPUBinsProducer::SetPUBinsParameters(Int_t nPUmin_, Int_t nPUmax_, Int_t interval_)
{
  nPUmax = nPUmax_;
  nPUmin = nPUmin_;
  interval = interval_;
  float x1 = (float)(nPUmax - nPUmin)/interval;
  int x2 = (nPUmax - nPUmin)/interval;
  if ((x1-x2) != 0  ) 
  {
    cerr << "interval cannot be divided. The program supports the case when PU interval can be divided by integer. Please change the interval. Program closing.."<< endl;
    exit(EXIT_FAILURE);
  }
}

void HistPUBinsProducer::SetBinParameters(Int_t Nbins_, Float_t xmin_, Float_t xmax_)
{
  Nbins = Nbins_;
  xmin = xmin_;
  xmax = xmax_;
}

vector <TH1F*> HistPUBinsProducer::ProduceHists()
{
    TChain *chain = new TChain("pf");
  
    for( unsigned int iFile = 0; iFile < FileNames.size(); ++iFile)
    {
      chain -> Add(FileNames.at(iFile).c_str());
    
    }
    
     vector <float>* tmp = new std::vector<float>();
    Int_t nPU;
    chain -> SetBranchAddress(VarName.c_str(), &tmp);
    chain -> SetBranchAddress("npu", &nPU);
    
    int nPUBins = (nPUmax- nPUmin)/interval;
    hists.reserve(nPUBins);
    hists.resize(nPUBins);
    
    for (unsigned int iHist = 0; iHist < nPUBins; iHist++)
    {
      hists.at(iHist) = new TH1F( "", "", Nbins, xmin, xmax);
    }
    
    for (unsigned int iEntry =0;  iEntry < chain -> GetEntriesFast(); ++iEntry)
    {
      chain -> GetEntry(iEntry);
      if (nPU > nPUmax || nPU < nPUmin) continue;
      int BinNumber;
      BinNumber = ((nPU - nPUmin)/interval ) + 1;
      if (nPU == nPUmax) BinNumber--;
      //cout << nPU << "  "<< BinNumber <<  endl;
    //  cout << hists -> size() << endl;
      for (unsigned int iE =0; iE < tmp -> size(); ++iE)
      {
	hists.at(BinNumber -1 ) -> Fill(tmp -> at(iE));
	
      }
    }
     
     return hists;
}
    