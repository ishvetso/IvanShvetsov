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
#include <fstream>
#include <map>
#include <vector>
#include <getopt.h>
#include <math.h>
#include <ctime>

using namespace std;

//Compile with 
// g++ -o getting_results getting_results.C --std=c++11 `root-config --cflags --libs` -O2 -I./

void getting_quantiles(ofstream & res_, string WORK_DIR_);
void getting_stat_unc(ofstream & res_, string WORK_DIR_);
Double_t getting_t_ch(string WORK_DIR_, string generator_);
void getting_gen_unc(ofstream & res_, string WORK_DIR_, string generator_);
void getting_pdf_unc(ofstream & res_, string WORK_DIR_, string generator_);
void getting_matching_unc(ofstream & res_, string WORK_DIR_, string generator_);
void getting_scale_unc(ofstream & res_, string WORK_DIR_, string generator_);
void getting_trig_unc(ofstream & res_, string WORK_DIR_, string generator_);

int main(int argc, char *argv[])
{
  ofstream res("stat_treatment.txt");	
  
  res.precision(2);
  res.setf(ios::fixed,ios::floatfield);
  
  res << "##############################################################################" << endl;
  res << "####This is text file containing the results of the statistical_inference#####" << endl;
  res << "##############################################################################" << endl;
  
  // current date/time based on current system
  time_t now = time(0);
   
  // convert now to string form
  char* dt = ctime(&now);

   res << endl << "File was generated on  " << dt << endl;
  
  int c;
  
  string WORK_DIR;
  string generator;
  
 while ( (c = getopt(argc, argv, "g:m:")) != -1)
 {
    switch (c)
    {
      case 'g' : 
	  if (string(optarg) == "pw" or string(optarg) == "ch") {
	    generator = optarg;
	    cout << generator << endl;
	  }
	  else {
	    cerr << "Error: incorrect generator" << endl;
	    return 0;
	  }
	  break;   
      case 'm' : 
	  WORK_DIR = optarg;
	  cout << WORK_DIR << endl;
	  break;  
    }
 }
  
  
  getting_quantiles(res, WORK_DIR);
//   getting_stat_unc(res, WORK_DIR);
  getting_gen_unc(res, WORK_DIR, generator);
  getting_pdf_unc(res, WORK_DIR, generator);
  getting_matching_unc(res, WORK_DIR, generator);
  getting_scale_unc(res, WORK_DIR, generator);
  getting_trig_unc(res, WORK_DIR, generator);



}

void getting_quantiles(ofstream & res_,string WORK_DIR_)

{
	res_<< endl << endl << endl ;
	res_ << "Quantiles for model parameters"<< endl << endl << endl ;
	res_ << "Please note, that up- and down- uncertainties for shape-changing parameters are included here only"<< endl << "technically, actually there is not much sense in them. This information shouldn't be included in any reports, analysis note." << endl << " One should take attention to the value of quantiles for shape-changing parameters." << endl << " Remember that up (84\%-quantile) and down( 16\% -quantile) are more likely to be close to their prior values 1 and -1 correspondingly."<< endl << endl << endl << endl ;
	res_ << "\\begin{table}[h]" << endl;
	res_ << "\\center{" << endl;
	res_ << "\\begin{tabular}{|c|c|c|c|c|c|}" << endl;
	res_ << "\\hline" << endl;
	res_ << "parameter name" << " &  16 \\% " << " &  50 \\% "<< " &  84 \\% "<< " &  up uncertainty "<< " & down uncertainty "<<  "\\\\" <<endl;
	res_ << "\\hline" << endl;
	vector <string> par;

	string quan[3];
	quan[0] = "quant__quant01600";
	quan[1] = "quant__quant05000";
	quan[2] = "quant__quant08400";

	Double_t quant_value[3];
	Double_t sum[3];
	sum[0] = 0.0;
	sum[1] = 0.0;
	sum[2] = 0.0;
		

	par.push_back("RV");
	par.push_back("LV");
	par.push_back("sigmaTtbar");
	par.push_back("sigmaDY");
	par.push_back("sigmaDiboson");
	par.push_back("sigma_s_ch");
	par.push_back("sigma_tw_ch");
	par.push_back("sigmaWjets_WQQ");
	par.push_back("sigmaWjets_W_light");
	par.push_back("sigmaWjets_W_other");
	par.push_back("sigmaWjets_Wc");
	par.push_back("Tag");
	par.push_back("Mistag");
	par.push_back("pile_up");
	par.push_back("JEC");
	par.push_back("JER");
	par.push_back("METUncl");
	par.push_back("sigmaQCD");
	par.push_back("trig");
	
	for (int i = 0; i< par.size(); i++ )
	{
		TFile *f = new TFile((WORK_DIR_ + "results/quantiles/quant_" + par.at(i) + ".root").c_str(), "READ");
		TTree *t = (TTree*) f -> Get("products");
		
		for (Int_t j=0; j< 3; j++)		

		{
			t -> SetBranchAddress(quan[j].c_str(), &quant_value[j]);
		}
		
		
		for (Int_t k = 0;  k < (Int_t)t -> GetEntries(); k++) 					
					{			
						t -> GetEntry(k);						 
						for (Int_t mm = 0; mm < 3; mm++)
						{
						  sum[mm] = sum[mm]+quant_value[mm];
						  
						  
						}
						

					}	
		Int_t Nentries = (Int_t)t -> GetEntries();
		res_ << par[i] << " & " << sum[0]/Nentries << " & " << sum[1]/Nentries << " & " << sum[2]/Nentries  << " & " << 100*(sum[2]-sum[1])/sum[1]<< "\\%"<< " & " << 100.*(sum[1]-sum[0])/sum[1]<< "\\%"<< "\\\\" << endl;
		res_ <<"\\hline" << endl;
		
		for (Int_t kk = 0; kk < 3; kk++)
		{
		  
		  sum[kk] = 0.0;
		  
		}
	}
	
	res_ << "\\end{tabular}" << endl;
	res_ << "}" << endl;
	res_ << "\\end{table}" << endl;
}

void getting_stat_unc(ofstream & res_, string WORK_DIR_)

{

  
  res_<< endl << endl << endl ;
  res_ << "Statistical uncertainty"<< endl << endl << endl ;
  res_ << "\\begin{table}[h]" << endl;
  res_ << "\\center{" << endl;
  res_ << "\\begin{tabular}{|c|c|c|}" << endl;
  res_ << "\\hline" << endl;
  res_  << "  16 \\% " << " &  50 \\% "<< " &  84 \\% "<<  "\\\\" <<endl;
  res_ << "\\hline" << endl;
  
  string quan[3];
  quan[0] = "quant__quant01590";
  quan[1] = "quant__quant05000";
  quan[2] = "quant__quant08410";

  Double_t quant_value[3];
  Double_t sum[3];
  sum[0] = 0.0;
  sum[1] = 0.0;
  sum[2] = 0.0;


   TFile *f;
   TTree *t;
   f  = new TFile((WORK_DIR_ + "results/stat_uncertainty/stat_uncertainty.root").c_str(), "READ");
   t = (TTree*) f-> Get("products");
   
   for (Int_t j=0; j< 3; j++)		

   {
      t -> SetBranchAddress(quan[j].c_str(), &quant_value[j]);
   }
		
  for (Int_t k = 0;  k < (Int_t)t -> GetEntries(); k++) 					
  {			
	  t -> GetEntry(k);						 
	  for (Int_t mm = 0; mm < 3; mm++)
	  {
	    sum[mm] = sum[mm]+quant_value[mm];
	  }
	  

  }

  Int_t Nentries = (Int_t)t -> GetEntries();
  res_  << sum[0]/Nentries << " & " << sum[1]/Nentries << " & " << sum[2]/Nentries  << "\\\\" << endl;
  
  double x =-(sum[1]-sum[0])/sum[1] ;
  double y =(sum[2]-sum[1])/sum[1];
  
  res_ << "\\hline"<<endl;
  
  res_ << 100*x << "\\%" << " & "<< "0.0\\%  &  ";
  res_ <<  100*y << "\\%"<< "\\\\" <<endl;
   res_ << "\\hline"<<endl;
  res_ << "\\end{tabular}" << endl;
  res_ << "}" << endl;
  res_ << "\\end{table}" << endl;
}

Double_t getting_t_ch(string WORK_DIR_, string generator_)
{

    Double_t value50;
    Double_t  sum50 = 0.0;
    string gen;
    if (generator_ == "pw") gen = "powheg";
    if (generator_ == "ch") gen = "comphep";
    TFile f((WORK_DIR_ + "results/nominal_pseudodata_" + gen +".root").c_str(), "READ");
    TTree *t = (TTree*) f.Get("products");
    t ->  SetBranchAddress("quant__quant05000", &value50);
    Int_t Nentries = (Int_t)t -> GetEntries();
    for (Int_t k = 0;  k < (Int_t)t -> GetEntries(); k++) 					
    {			
      t -> GetEntry(k);						 
      sum50 = sum50 + value50;
    }
    
  return sum50/Nentries ;
}

void getting_gen_unc(ofstream & res_, string WORK_DIR_, string generator_)
{
  
  string antigenerator, antigen, gen; //;)
  if (generator_ == "ch") antigenerator ="pw";
  if (generator_ == "pw") antigenerator ="ch";
  
  if (generator_ == "ch") gen ="comphep";
  if (generator_ == "pw") gen ="powheg";
  
   if (antigenerator == "ch") antigen ="comphep";
  if (antigenerator == "pw") antigen ="powheg";
  
  res_<< endl << endl << endl ;
  res_ << "Generator uncertainty"<< endl << "Default generator is "<< gen<< endl << endl ;
  res_ << "\\begin{table}[h]" << endl;
  res_ << "\\center{" << endl;
  res_ << "\\begin{tabular}{|c|c|}" << endl;
  res_ << "\\hline" << endl;
  res_  << " generator" << " &  Xsection 50 \\% -quantile"<<   "\\\\" <<endl;
  res_ << "\\hline" << endl;
  res_ << gen<<" & " << getting_t_ch(WORK_DIR_, generator_)<<   "\\\\" <<endl;
  res_ << "\\hline" << endl;
  res_ << antigen<<" & " << getting_t_ch(WORK_DIR_, antigenerator)<<   "\\\\" <<endl;
  res_ << "\\hline" << endl;
  res_ << "\\end{tabular}" << endl;
  res_ << "}" << endl;
  res_ << "\\end{table}" << endl;
  
  res_  << endl << endl << endl;
  res_  << "Generator uncertainty is "<<100*0.5*( getting_t_ch(WORK_DIR_, antigenerator) - getting_t_ch(WORK_DIR_, generator_))/(getting_t_ch(WORK_DIR_, generator_))<<  "\\%"<<endl;
  res_  << "Uncertainty is divided by factor 2"<< endl;
  
}

void getting_pdf_unc(ofstream & res_, string WORK_DIR_, string generator_)

{
  
      res_<< endl << endl << endl ;
      res_ << "PDF uncertainty"<< endl;
      res_ << "\\begin{table}[h]" << endl;
      res_ << "\\center{" << endl;
      res_ << "\\begin{tabular}{|c|c|c|}" << endl;
      res_ << "\\hline" << endl;
      res_ << "type of variation" << " &  " << "Xsection (50\\%-quantile)" << " &  " << "shift from nominal" << "  \\\\" << endl;
      res_ << "\\hline" << endl;
      
      Double_t value, nom, UP, DOWN;
      Double_t quadsum = 0.0; 
      Double_t sum  = 0.0; 
      nom = getting_t_ch( WORK_DIR_, generator_);
      
      stringstream wow;
      string num[20];
      string DIR[2];
      DIR[0] = "Up";
      DIR[1] = "Down";
      
      string fname[40], Outname[40];


      for (int ee = 0; ee < 20; ee ++ )
      {
	wow  << ee;
	num[ee] = wow.str();
	wow.str("");
      }
      
      
      for (int i=0; i < 20; i++)
      {
	  fname[i] = "PDF_"+DIR[0]  + num[i] + ".root";
	  fname[20 + i] = "PDF_"+DIR[1] + num[i] + ".root";

	  Outname[i] =  "PDF-"+DIR[0] + "-" + num[i] ;
	  Outname[20 + i] =  "PDF-"+DIR[1] + "-" + num[i] ;
      }

      for (int j = 0; j < 40; j ++)
      {

	TFile *f = new TFile((WORK_DIR_ + "results/PDF_uncertainty/" + fname[j] ).c_str(), "READ");
	TTree  *t = (TTree*) f -> Get("products");
	t ->  SetBranchAddress("quant__quant05000", &value);
	
	for (Int_t k = 0;  k < (Int_t)t -> GetEntries(); k++) 
	{			

		t -> GetEntry(k);						 
		sum = sum + value;					

	}
	
	
	Int_t Nentries = (Int_t)t -> GetEntries();
	res_ << Outname[j] << "  &  " <<sum/Nentries << "  &  " << ((sum/Nentries) - nom)/nom <<"  \\\\" <<endl;
	res_ << "\\hline" <<endl;
	
	if (j == 20) quadsum = 0.0;
	quadsum = quadsum + 10000.*pow((((sum/Nentries) -nom)/nom),2);
	if (j==19) UP = (1/1.6)*sqrt(quadsum); 
	if (j==39) DOWN = (1/1.6)*sqrt(quadsum); 
	sum = 0.0;
	      
      }
      
    res_ << "\\end{tabular}" << endl;
    res_ << "}" << endl;
    res_ << "\\end{table}" << endl;
    res_ << "PDF uncertainty is $^{+"<< UP<<"\\%}_{-" << DOWN <<"\\%}$"<< endl;
}

void getting_matching_unc(ofstream & res_, string WORK_DIR_, string generator_)

{
       res_<< endl << endl << endl ;
      res_ << "Matching uncertainty"<< endl;
      res_ << "\\begin{table}[h]" << endl;
      res_ << "\\center{" << endl;
      res_ << "\\begin{tabular}{|c|c|c|}" << endl;
      res_ << "\\hline" << endl;
      res_ << "type of variation" << " &  " << "Xsection (50\\%-quantile)" << " &  " << "shift from nominal" << "  \\\\" << endl;
      res_ << "\\hline" << endl;
      vector<string> name;
      
      name.push_back("ttbar_matchingUp");
      name.push_back("ttbar_matchingDown");
      name.push_back("Wjets_matchingUp");
      name.push_back("Wjets_matchingDown");
     
      
      vector<string> Outname;
      Outname.push_back("ttbar-up");
      Outname.push_back("ttbar-down");
      Outname.push_back("Wjets-up");
      Outname.push_back("Wjets-down");
  
      Double_t value, nom; 
      Double_t sum  = 0.0;
      nom = getting_t_ch( WORK_DIR_, generator_);
      
      for (int i=0; i < name.size(); i++)
      {
	TFile *f = new TFile((WORK_DIR_ + "results/matching/" + name[i] + ".root" ).c_str());
	
	TTree *t = (TTree*) f -> Get("products");
	t ->  SetBranchAddress("quant__quant05000", &value);
	
	for (Int_t k = 0;  k < (Int_t)t -> GetEntries(); k++) 					
	{			
	  t -> GetEntry(k);						 
	  sum = sum + value;
	}
	
	
	Int_t Nentries = t -> GetEntries();
	res_ << Outname[i] << "  &  " << sum/Nentries <<"  &  " << 100*((sum/Nentries)-nom)/(sum/Nentries) <<"\\%"<<"  \\\\" <<endl;
	res_ << "\\hline" <<endl;
	sum = 0.0;
      }
      
      res_ << "\\end{tabular}" << endl;
      res_ << "}" << endl;
      res_ << "\\end{table}" << endl;

}


void getting_scale_unc(ofstream & res_, string WORK_DIR_, string generator_)

{
       res_<< endl << endl << endl ;
      res_ << "Scale uncertainty"<< endl;
      res_ << "\\begin{table}[h]" << endl;
      res_ << "\\center{" << endl;
      res_ << "\\begin{tabular}{|c|c|c|}" << endl;
      res_ << "\\hline" << endl;
      res_ << "type of variation" << " &  " << "Xsection (50\\%-quantile)" << " &  " << "shift from nominal" << "  \\\\" << endl;
      res_ << "\\hline" << endl;
      vector<string> name;
      
      name.push_back("ttbar_Q2Up");
      name.push_back("ttbar_Q2Down");
      name.push_back("Wjets_Q2Up");
      name.push_back("Wjets_Q2Down");
      name.push_back("t_ch_Q2Up");
      name.push_back("t_ch_Q2Down");
      name.push_back("tW_ch_Q2Up");
      name.push_back("tW_ch_Q2Down");
     
      
      vector<string> Outname;
      Outname.push_back("ttbar-up");
      Outname.push_back("ttbar-down");
      Outname.push_back("Wjets-up");
      Outname.push_back("Wjets-down");
      Outname.push_back("t-ch-up");
      Outname.push_back("t-ch-down");
      Outname.push_back("tW-ch-up");
      Outname.push_back("tW-ch-down");
  
      Double_t value, nom, nom_pw; 
      Double_t sum  = 0.0;
      nom = getting_t_ch( WORK_DIR_, generator_);
      nom_pw = getting_t_ch( WORK_DIR_, "pw");//t-ch for POWHEG only
      
      for (int i=0; i < name.size(); i++)
      {
	TFile *f = new TFile((WORK_DIR_ + "results/scale/" + name[i] + ".root" ).c_str());
	
	TTree *t = (TTree*) f -> Get("products");
	t ->  SetBranchAddress("quant__quant05000", &value);
	
	for (Int_t k = 0;  k < (Int_t)t -> GetEntries(); k++) 					
	{			
	  t -> GetEntry(k);						 
	  sum = sum + value;
	}
	
	
	Int_t Nentries = t -> GetEntries();
	if ((Outname[i]).find("t-ch") == string::npos)res_ << Outname[i] << "  &  " << sum/Nentries <<"  &  " << 100*((sum/Nentries)-nom)/(sum/Nentries) <<"\\%"<<"  \\\\" <<endl;
	if ((Outname[i]).find("t-ch") != string::npos)res_ << Outname[i] << "  &  " << sum/Nentries <<"  &  " << 100*((sum/Nentries)-nom_pw)/(sum/Nentries) <<"\\%"<<"  \\\\" <<endl;
	res_ << "\\hline" <<endl;
	sum = 0.0;
      }
      
      res_ << "\\end{tabular}" << endl;
      res_ << "}" << endl;
      res_ << "\\end{table}" << endl;

}


void getting_trig_unc(ofstream & res_, string WORK_DIR_, string generator_)

{
       res_<< endl << endl << endl ;
      res_ << "Trigger uncertainty"<< endl;
      res_ << "\\begin{table}[h]" << endl;
      res_ << "\\center{" << endl;
      res_ << "\\begin{tabular}{|c|c|c|}" << endl;
      res_ << "\\hline" << endl;
      res_ << "type of variation" << " &  " << "Xsection (50\\%-quantile)" << " &  " << "shift from nominal" << "  \\\\" << endl;
      res_ << "\\hline" << endl;
     
      Double_t value, nom; 
      Double_t sum  = 0.0;
      nom = getting_t_ch( WORK_DIR_, generator_);
      
      vector<string> name;
      
      name.push_back("trig_Up");
      name.push_back("trig_Down");
      
      vector<string> Outname;
      
      Outname.push_back("trig-Up");
      Outname.push_back("trig-Down");
     
      
      for (int i=0; i < name.size(); i++)
      {
	TFile *f = new TFile((WORK_DIR_ + "results/trig/" + name[i] + ".root" ).c_str());
	
	TTree *t = (TTree*) f -> Get("products");
	t ->  SetBranchAddress("quant__quant05000", &value);
	
	for (Int_t k = 0;  k < (Int_t)t -> GetEntries(); k++) 					
	{			
	  t -> GetEntry(k);						 
	  sum = sum + value;
	}
	
	
	Int_t Nentries = t -> GetEntries();
	res_ << Outname[i] << "  &  " << sum/Nentries <<"  &  " << 100*((sum/Nentries)-nom)/(sum/Nentries) <<"\\%"<<"  \\\\" <<endl;
	res_ << "\\hline" <<endl;
	sum = 0.0;
      }
      
      res_ << "\\end{tabular}" << endl;
      res_ << "}" << endl;
      res_ << "\\end{table}" << endl;

}