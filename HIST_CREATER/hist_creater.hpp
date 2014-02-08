#ifndef  HIST_CREATER
#define HIST_CREATER

#include <TFile.h>
#include <TTree.h>
#include <TTreeFormula.h>
#include <TH1.h>
#include <TH2.h>
#include <THStack.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <iostream>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm> 

using namespace std;
	
class hist_creater
{
	int Nxbins, Nybins, dim;
	string selection, prefix, prefix_QCD, prefix_output, var1, var2, selectionQCD, selectionMC, OutFileName;
	map<string,vector <string> > hist_map;
	float QCD_weight, xmin, xmax, ymin, ymax;
	bool convert;
	double *edges1, *edges2;
		
public:
	hist_creater();
	void SetNbins(int Nxbins_, int Nybins_);
	void SetNbins(int Nxbins_);
	void SetRange(float xmin_, float xmax_);
	void SetRange(float xmin_, float xmax_, float ymin_, float ymax_);
	void SetRange(double * edges1_);
	void SetRange(double * edges1_, double * edges2_);
	void SetVar(string var1_);
	void SetVar(string var1_,string var2_ );
	void SetMap(map<string,vector <string> > hist_map_);
	void SetDimension(int dim_);
	void SetCommonSelection(string selection_);
	void SetMCSelection(string selectionMC_);
	void SetQCDSelection(string selectionQCD_);
	void SetInDirectory( string prefix_);
	void SetInDirectoryQCD( string prefix_QCD_);
	void SetOutDirectory( string prefix_output_);
	void SetOutFileName(string OutFileName_);
	void SetConvertOption(bool convert_);
	TH1F* ConvertHist(TH2F* hist_2dim_, string name_);
	void CreateHists();
	
};

#endif