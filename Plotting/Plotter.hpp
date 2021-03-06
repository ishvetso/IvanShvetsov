#ifndef  PLOTTER
#define PLOTTER

#include <TFile.h>
#include <TTree.h>
#include <TTreeFormula.h>
#include <TH1.h>
#include <TH2.h>
#include <THStack.h>
#include <TPad.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <iostream>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <Sample.hpp>
#include <var.hpp>

/*
 * Class to make data-MC comparison plots
 */

typedef unsigned int uint;

class Plotter
{
        int Nbins;
	vector <Sample> samples;
	Sample DataSample;
	vector <Var> variables;

	public:
	Plotter();
	bool withData;
	void SetNbins(int Nbins_);
	void SetVar(vector <Var> variables_);
	void SetSamples(vector <Sample> samples_);	
	void SetDataSample(Sample sample_);
	void Plotting();

};

#endif
