#include "HistPUBinsProducer.hpp"

typedef vector<bool> vbool;

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
  int x2 = (nPUmax  - nPUmin)/interval;
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

void HistPUBinsProducer::SetResponseParameters(Float_t xmin_response_, Float_t xmax_response_)
{
  xmin_response = xmin_response_;
  xmax_response = xmax_response_;
  
}
vector <TH1F*> HistPUBinsProducer::ProduceHists(string treename)
{
    TChain *chain = new TChain(treename.c_str());
    TChain *chain_gen = new TChain("gen");
  
    for( unsigned int iFile = 0; iFile < FileNames.size(); ++iFile)
    {
      chain -> Add(FileNames.at(iFile).c_str());
      chain_gen -> Add(FileNames.at(iFile).c_str());
    
    }
    
    vector <float>* tmp = new std::vector<float>();
    vector <float>* tmp_gen = new std::vector<float>();
    vector <float>* pt = new std::vector<float>();
    vector <float>* eta = new std::vector<float>();
    vector <int> * imatch_tmp = new std::vector<int>();
    vector <bool> * isMatchedToBoson_tmp = new std::vector<bool>();
    
    Int_t nPU;
    
    chain -> SetBranchAddress(VarName.c_str(), &tmp);
    chain_gen -> SetBranchAddress(VarName.c_str(), &tmp_gen); //corresponding gen info
    chain -> SetBranchAddress("npv", &nPU);
    chain -> SetBranchAddress("imatch", &imatch_tmp);
    chain -> SetBranchAddress("is_MatchedToBoson", &isMatchedToBoson_tmp);
    chain -> SetBranchAddress("ptcorrphil", &pt);
    chain -> SetBranchAddress("eta", &eta);
    
    int nPUBins = (nPUmax- nPUmin)/interval;
    hists.reserve(nPUBins);
    hists.resize(nPUBins);
    
    hists_response.reserve(nPUBins);
    hists_response.resize(nPUBins);
    
    //cout << nPUBins << endl;
    for (unsigned int iHist = 0; iHist < nPUBins; iHist++)
    {
      hists.at(iHist) = new TH1F( "", "", Nbins, xmin, xmax);
      hists_response.at(iHist) = new TH1F( "", "", Nbins, xmin_response, xmax_response);
    }
    
    
    if ((chain -> GetEntriesFast())!= (chain_gen -> GetEntriesFast())) 
    {
      cout <<  "the number of entries in the gen tree is not equal to the number of entries in the " << treename << " tree " << endl;
      exit(EXIT_FAILURE);
    }
    for (unsigned int iEntry =0;  iEntry < chain -> GetEntriesFast(); ++iEntry)
    {
      chain -> GetEntry(iEntry);
      chain_gen -> GetEntry(iEntry);

      if (nPU >= nPUmax || nPU < nPUmin) continue;
      int BinNumber;
      BinNumber = ((nPU - nPUmin)/interval ) + 1;

      cout <<  isMatchedToBoson_tmp -> size() << " " << pt -> size() << "  " << eta -> size() << endl;
      
      for (unsigned int iE =0; iE < tmp -> size(); ++iE)
      {
	//cout << BinNumber -1 << endl;
	if ((isMatchedToBoson_tmp -> at(iE)) && ((pt -> at(iE))> 300.)  && ((fabs((eta -> at(iE)))) < 2.5 )  && ( imatch_tmp -> at(iE) != -1)) 
	{
	  //cout << "imatch    "<< imatch_tmp -> at(iE) << endl;
	  //if (imatch_tmp -> at(iE) == -1) cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	  hists.at(BinNumber -1 ) -> Fill(tmp -> at(iE));
	  hists_response.at(BinNumber -1 ) -> Fill(((tmp -> at(iE)) - (tmp_gen -> at(imatch_tmp -> at(iE)))) );
	  
	  
	}
	//cout << isMatchedToBoson_tmp -> at(iE) << endl;
	//cout << "BinNumber = " << BinNumber <<  "  nPU = " <<  nPU << endl;
		
      }
      
      tmp -> clear();
      isMatchedToBoson_tmp -> clear();
      tmp_gen -> clear();
      pt -> clear();
    }
     
     return hists;
}
    