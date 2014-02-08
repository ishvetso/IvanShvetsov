#include "hist_creater.hpp"

hist_creater::hist_creater()
{

	convert = false;
	xmin = -37.;
	ymin = -37.;
	xmax = -37.;
	ymax = -37.;
	

}

void hist_creater::SetNbins(int Nxbins_, int Nybins_)
{
	
	if (dim == 1) cout << "Error: Please check the dimension you use" << endl;
	
	Nxbins = Nxbins_;
	Nybins = Nybins_;
	
}


void hist_creater::SetNbins(int Nxbins_)
{
	if (dim == 2) cout << " Error: Please check the dimension you use" << endl;
	
	Nxbins = Nxbins_;
	
	
}

void hist_creater::SetRange(float xmin_, float xmax_, float ymin_, float ymax_)
{
	if (dim == 1) cout << "Error: Range is set incorrectly. Please check the dimension you use" << endl;
	
	xmin = xmin_;
	xmax = xmax_;
	
	ymin = ymin_;
	ymax = ymax_;
			
}

void hist_creater::SetRange(float xmin_, float xmax_)
{
	if (dim == 2) cout << "Error: Range is set incorrectly. Please check the dimension you use" << endl;
	xmin = xmin_;
	xmax = xmax_;
				
}

//for 1 dimensional adaptive binning
void hist_creater::SetRange(double *edges1_)
{
	if (dim == 2) cout << "Error: Range is set incorrectly. Please check the dimension you use" << endl;
	edges1 = edges1_;
				
}
//for 1 dimensional adaptive binning 
void hist_creater::SetRange(double *edges1_, double *edges2_)
{
	if (dim == 1) cout << "Error: Range is set incorrectly. Please check the dimension you use" << endl;
	edges1 = edges1_;
	edges2 = edges2_;		
				
}


void hist_creater::SetVar(string  var1_)
{

	var1 = var1_;
	
}

void hist_creater::SetVar(string  var1_,string  var2_)
{

	var1 = var1_;
	var2 = var2_;
	
}

void hist_creater::SetCommonSelection(string selection_)
{

	selection = selection_;
	
}

void hist_creater::SetMCSelection(string selectionMC_)
{

	selectionMC = selectionMC_;
	
}

void hist_creater::SetQCDSelection(string selectionQCD_)
{

	selectionQCD = selectionQCD_;
	
}

void hist_creater::SetMap(map<string,vector <string> > hist_map_)
{
	hist_map = hist_map_;

}

void hist_creater::SetInDirectory( string prefix_)
{

	prefix = prefix_;
	
}

void hist_creater::SetInDirectoryQCD( string prefix_QCD_)
{

	prefix_QCD = prefix_QCD_;
	
}

void hist_creater::SetOutDirectory( string prefix_output_)
{

	prefix_output = prefix_output_;
	
}
void hist_creater::SetDimension(int dim_)
{
	dim = dim_;
	
}

void hist_creater::SetConvertOption(bool convert_)
{
	
	convert = convert_;
	
}
void hist_creater::SetOutFileName(string OutFileName_)
{
	
	OutFileName = OutFileName_;
	
}

TH1F* hist_creater::ConvertHist(TH2F *hist_2dim_, string name_)
{
	int Nxbins_, Nybins_;
	Nxbins_ = hist_2dim_ -> GetXaxis() -> GetNbins();
	Nybins_ = hist_2dim_ -> GetYaxis() -> GetNbins();
	TH1F *hist_1dim_ = new TH1F((name_).c_str(),(name_).c_str(), Nxbins_*Nybins_, 0., Nxbins_*Nybins_);
	hist_1dim_ -> Sumw2();
	
    float binContent_, binError_;
    for ( int m = 1; m <= Nybins_; m++)
    {
    	for (int n = 1; n <= Nxbins_; n++)
    	{
	
    		binContent_ = hist_2dim_->GetBinContent(n,m);
    		binError_ = hist_2dim_->GetBinError(n,m);
	  
    		hist_1dim_ -> SetBinContent(Nxbins_*(m-1)+n, binContent_);
    		hist_1dim_ -> SetBinError(Nxbins_*(m-1)+n, binError_);
	  
    	}
    }
    
    return hist_1dim_;
	
}

void hist_creater::CreateHists()
{

	std::map<string,vector <string> >::iterator it;
	bool nominal_flag, THROW_TS;
	double wqq=0., wother =0., wlight = 0., wc = 0.;//nominal integral for wjets
	string pdfUp[20], pdfDown[20], unc_PDFUp[20], unc_PDFDown[20];
  	stringstream wow;
	vector <ULong64_t> lumi_TS, event_TS, run_TS;
	TFile file((prefix_output +OutFileName).c_str(), "RECREATE");
	
	TH1F *hist_1dim, *hist_1dim_pile_up_Up, *hist_1dim_pile_up_Down, *hist_1dim_pdfUp[20], *hist_1dim_pdfDown[20], *Wjets_1dim_Q2Up, *Wjets_1dim_Q2Down;
     
	
      
	TH2F *hist_2dim, *hist_2dim_pile_up_Up, *hist_2dim_pile_up_Down, *hist_2dim_pdfUp[20],*hist_2dim_pdfDown[20], *Wjets_2dim_Q2Up, *Wjets_2dim_Q2Down;

	
	      
   	for (unsigned int ee = 0; ee < 20; ee++)
    	{
		wow << "_PDFUp" << ee;
		pdfUp[ee] = wow.str();
		wow.str("");
		wow << "_PDFDown" << ee ;
		pdfDown[ee] = wow.str();
		wow.str("");
		
		wow << "_PDFUp[" << ee << "]";
		unc_PDFUp[ee] = wow.str();
		wow.str("");
		wow << "_PDFDown[" << ee <<"]";
		unc_PDFDown[ee] = wow.str();
		wow.str("");
		
    	}

	THROW_TS = false;
	 for (it = hist_map.begin(); it!=hist_map.end(); ++it)
	 {
		
		if ((it-> first) == "Drell-Yan" || (it-> first) == "Diboson" || (it-> first) == "t-ch"|| (it-> first) == "t-ch_ch"||(it-> first) == "t-ch_pw"||(it-> first) == "s-ch" || (it-> first) == "tW-ch"|| (it-> first) == "ttbar"|| (it-> first) == "Wjets_WQQ"|| (it-> first) == "Wjets_Wc"|| (it-> first) == "Wjets_W_light"|| (it-> first) == "Wjets_W_other" || (it-> first) == "Wjets"|| (it-> first) == "unphys_ch"|| (it-> first) == "right_ch" || (it-> first) == "tensor_ch" || (it-> first) == "unphys_LVLT_ch") nominal_flag = true;
		else nominal_flag = false;
		
		
		//Allocating the histograms necessary for current dimension and iteration
		if (dim == 1 )
		{
	
		 hist_1dim = new TH1F();
		 hist_1dim -> Sumw2();
	
		  if (nominal_flag == true) 
		  { 
			hist_1dim_pile_up_Up = new TH1F();
			hist_1dim_pile_up_Down = new TH1F();
		      
			hist_1dim_pile_up_Up -> Sumw2();
			hist_1dim_pile_up_Down -> Sumw2();
		      
			for (Int_t ii = 0; ii < 20;++ii)
			{
				hist_1dim_pdfUp[ii] = new TH1F();
				hist_1dim_pdfDown[ii] = new TH1F();
				hist_1dim_pdfUp[ii] -> Sumw2();
				hist_1dim_pdfDown[ii] -> Sumw2();
			}
		    
			if ((it-> first).find("Wjets") !=string::npos) 
			{
			    Wjets_1dim_Q2Up = new TH1F();
			    Wjets_1dim_Q2Down = new TH1F();
			    Wjets_1dim_Q2Up -> Sumw2();
			    Wjets_1dim_Q2Down -> Sumw2();
			}
		  }
		}

		if (dim == 2)
		{
		    hist_2dim = new TH2F();
		    hist_2dim -> Sumw2();
		  
		    if (nominal_flag == true)
		    {
			hist_2dim_pile_up_Up = new TH2F();
			hist_2dim_pile_up_Down = new TH2F();
			hist_2dim_pile_up_Up -> Sumw2();
			hist_2dim_pile_up_Down -> Sumw2();
			
			for (Int_t ii = 0; ii < 20;++ii)
			{
				hist_2dim_pdfUp[ii] = new TH2F();
				hist_2dim_pdfDown[ii] = new TH2F();
				hist_2dim_pdfUp[ii] -> Sumw2();
				hist_2dim_pdfDown[ii] -> Sumw2();
			}		

			if ((it-> first).find("Wjets") !=string::npos) 
			{
			    Wjets_2dim_Q2Up = new TH2F();
			    Wjets_2dim_Q2Down = new TH2F();
			    Wjets_2dim_Q2Up -> Sumw2();
			    Wjets_2dim_Q2Down -> Sumw2();

			}
		    }  
		}
		
		
		//looping through the files
		for (unsigned int j =0; j <(it->second).size();++j  ) 
		{
			string fname;
			if ((it-> first)!= "QCD") fname = prefix +  (it->second).at(j); 
			if ((it-> first) == "QCD") fname = prefix_QCD +  (it->second).at(j);

			//cout << fname  << endl;

			TFile f(fname.c_str(), "READ");
			
			unsigned pos = ((it -> second).at(j)).find(".root");
			string PrincipalFileName = ((it -> second).at(j)).substr(0,pos);
			
			//get the information of the train set
			TFile EventList("/afs/cern.ch/work/i/ishvetso/THETA/NN_ttbar_NN_wjets/hist_creation/eventID_full.root", "OPEN");
			if (EventList.Get(PrincipalFileName.c_str()) != NULL) {
			  
			THROW_TS = true;  
			}
			
			else THROW_TS = false;
			
			if (THROW_TS == true)
			{
			    TTree *TrainSetTree = (TTree*)EventList.Get(PrincipalFileName.c_str());
			    ULong64_t run, event, lumi;
			    TrainSetTree -> SetBranchAddress("lumi", &lumi);
			    TrainSetTree -> SetBranchAddress("run", &run);
			    TrainSetTree -> SetBranchAddress("event", &event);
			    cout << PrincipalFileName << endl;
			      
			    for (int l = 0; l < (int) TrainSetTree -> GetEntries();++l)
			      {
				TrainSetTree -> GetEntry(l);
				lumi_TS.push_back(lumi);
				event_TS.push_back(event);
				run_TS.push_back(run);
			      }
			      lumi_TS.push_back(0);
			      event_TS.push_back(0);
			      run_TS.push_back(0);
			    cout << run_TS.size() << endl;
			     cout << TrainSetTree -> GetEntries() << endl;  
			      
			}
			
			
			/*
			 *1 dimension 
			 */
			if (dim == 1)
			{
				// adding component of the map to the histogramm
				TH1F *temp = new TH1F("temp","temp",Nxbins, xmin, xmax);
				temp -> Sumw2();
				
				if (THROW_TS == true)
				{
				    TTree *Tree =  ((TTree*)f.Get("Vars"));
				    ULong64_t run, event, lumi;
				    Tree -> SetBranchAddress("lumi", &lumi);
				    Tree -> SetBranchAddress("run", &run);
				    Tree -> SetBranchAddress("event", &event);
				     int counter =0;
				    
				    for (int l = 0; l < (int) Tree -> GetEntries();++l)
				    {
				      Tree -> GetEntry(l);
				      vector<ULong64_t>::iterator iter_lumi, iter_event, iter_run;
				      iter_lumi = std::find(lumi_TS.begin(), lumi_TS.end() , lumi);
				      iter_event = std::find(event_TS.begin(), event_TS.end(), event);
				      iter_run = std::find(run_TS.begin(), run_TS.end(), run);
				      
 				      if (iter_run!=run_TS.end() && iter_lumi!=lumi_TS.end() && iter_event!= event_TS.end() ) {
					//cout  << "l="<<l << " "<< *iter_run << " "<< run << " "<< *iter_lumi << " "<< lumi << " " << *iter_event << "  " << event << endl;
					counter+=1;
				      }
				      
				      
				    }
				    cout << counter << endl;
				    counter =0;
				    lumi_TS.clear();
				    event_TS.clear();
				    run_TS.clear();
				}
			
				if (xmin == xmax)temp -> SetBins(Nxbins, edges1);
				
				if ((it-> first).find("Wjets_WQQ") != string::npos) ((TTree*)f.Get("Vars"))->Project("temp",var1.c_str(),("(" + selectionMC +")*(" +selection + "&& WHFClass == 0)").c_str());
				else if ((it-> first).find("Wjets_Wc")  != string::npos) ((TTree*)f.Get("Vars"))->Project("temp",var1.c_str(),("(" + selectionMC +")*(" +selection + "&& WHFClass == 1)").c_str());
				else if ((it-> first).find("Wjets_W_light") != string::npos) ((TTree*)f.Get("Vars"))->Project("temp", var1.c_str(),("(" + selectionMC +")*(" +selection + "&& WHFClass == 3)").c_str());
				else if ((it-> first).find("Wjets_W_other") != string::npos) ((TTree*)f.Get("Vars"))->Project("temp",var1.c_str(),("(" + selectionMC +")*(" +selection + "&& (WHFClass == 2 || WHFClass == 4))").c_str());
				else if ((it-> first) =="data")  ((TTree*)f.Get("Vars"))->Project("temp",var1.c_str(),selection.c_str());
				else if ((it-> first) =="QCD")  ((TTree*)f.Get("Vars"))->Project("temp",var1.c_str(),("(" + selectionQCD +")*(" +selection + ")").c_str());
				else ((TTree*)f.Get("Vars"))->Project("temp",var1.c_str(),("(" + selectionMC +")*(" + selection + ")").c_str());
				
				hist_1dim -> SetName((it-> first).c_str());
				hist_1dim -> SetTitle((it-> first).c_str());
				if (xmin!=xmax) hist_1dim -> SetBins(Nxbins, xmin, xmax);
				if (xmin == xmax) hist_1dim -> SetBins(Nxbins, edges1);
				hist_1dim -> Add(temp);
			
				
				delete temp;			
				
				
				if ( nominal_flag == true) 
				{
					TH1F *temp_pile_up_Up = new TH1F("temp_pile_upUp","temp_pile_upUp",Nxbins, xmin, xmax);
					TH1F *temp_pile_up_Down = new TH1F("temp_pile_upDown","temp_pile_upDown",Nxbins, xmin, xmax);
					temp_pile_up_Up -> Sumw2();
					temp_pile_up_Down -> Sumw2();
					TH1F * temp_pdfUp[20];
					TH1F * temp_pdfDown[20];
					
					TH1F * temp_Q2Up;
					TH1F * temp_Q2Down;
					
					
					for (Int_t l =0; l < 20; ++l)
					{
						temp_pdfUp[l] = new TH1F(("temp" + pdfUp[l]).c_str(),("temp" + pdfUp[l]).c_str(),Nxbins, xmin, xmax);
						temp_pdfDown[l] = new TH1F(("temp" + pdfDown[l]).c_str(),("temp" + pdfDown[l]).c_str(),Nxbins, xmin, xmax);
	
						temp_pdfUp[l] -> Sumw2();
						temp_pdfDown[l] -> Sumw2();	

					}
					
					if (xmin == xmax)
					{
						temp_pile_up_Up -> SetBins(Nxbins, edges1);
						temp_pile_up_Down -> SetBins(Nxbins, edges1);
					}
				
					
					//allocating Q2 for Wjets nominal
					if ((it-> first).find("Wjets") != string::npos) 
					{

					    temp_Q2Up = new TH1F("temp_Q2Up","temp_Q2Up", Nxbins, xmin, xmax );
					    temp_Q2Down = new TH1F("temp_Q2Down","temp_Q2Down", Nxbins, xmin, xmax );
					    
					    temp_Q2Up -> Sumw2();
					    temp_Q2Down-> Sumw2();
					  
					}
					
					//Wjets components 
					if ((it-> first).find("Wjets_WQQ") != string::npos) 
					{
						//pile-up
						((TTree*)f.Get("Vars"))->Project("temp_pile_upUp",var1.c_str(),("weight_PUUp* (" +selection + "&& WHFClass == 0)").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_pile_upDown",var1.c_str(),("weight_PUDown* (" +selection + "&& WHFClass == 0)").c_str());
						hist_1dim_pile_up_Up -> SetBins(Nxbins, xmin, xmax);

						//PDF
						for (Int_t tt =0; tt < 20; ++tt)
						{

							((TTree*)f.Get("Vars"))->Project(("temp" + pdfUp[tt]).c_str(),var1.c_str(),("weight"+unc_PDFUp[tt]+ "* (" +selection + "&& WHFClass == 0)").c_str());
							
							((TTree*)f.Get("Vars"))->Project(("temp" + pdfDown[tt]).c_str(),var1.c_str(),("weight"+unc_PDFDown[tt]+ "* (" +selection + "&& WHFClass == 0)").c_str());

						}
						
						//Q2
						((TTree*)f.Get("Vars"))->Project("temp_Q2Up",var1.c_str(),("weight_Q2Up* (" +selection + "&& WHFClass == 0)").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_Q2Down",var1.c_str(),("weight_Q2Down*(" +selection + "&& WHFClass == 0)").c_str());

						
		
					}
			
					else if ((it-> first).find("Wjets_Wc") != string::npos )
					{
						((TTree*)f.Get("Vars"))->Project("temp_pile_upUp",var1.c_str(),("weight_PUUp* (" +selection + "&& WHFClass == 1)").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_pile_upDown",var1.c_str(),("weight_PUDown* (" +selection + "&& WHFClass == 1)").c_str());

						for (Int_t tt =0; tt < 20; ++tt)
						{

							((TTree*)f.Get("Vars"))->Project(("temp" + pdfUp[tt]).c_str(),var1.c_str(),("weight"+unc_PDFUp[tt]+ "* (" +selection + "&& WHFClass == 1)").c_str());
							
							((TTree*)f.Get("Vars"))->Project(("temp" + pdfDown[tt]).c_str(),var1.c_str(),("weight"+unc_PDFDown[tt]+ "* (" +selection + "&& WHFClass == 1)").c_str());

						}
						
						((TTree*)f.Get("Vars"))->Project("temp_Q2Up",var1.c_str(),("weight_Q2Up* (" +selection + "&& WHFClass == 1)").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_Q2Down",var1.c_str(),("weight_Q2Down*(" +selection + "&& WHFClass == 1)").c_str());
						
			
					}
			
					else if ((it-> first).find("Wjets_W_light") != string::npos ) 
					{
						((TTree*)f.Get("Vars"))->Project("temp_pile_upUp",var1.c_str(),("weight_PUUp* (" +selection + "&& WHFClass == 3)").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_pile_upDown",var1.c_str(),("weight_PUDown* (" +selection + "&& WHFClass == 3)").c_str());

						for (Int_t tt =0; tt < 20; ++tt)
						{

							((TTree*)f.Get("Vars"))->Project(("temp" + pdfUp[tt]).c_str(),var1.c_str(),("weight"+unc_PDFUp[tt]+ "* (" +selection + "&& WHFClass == 3)").c_str());
							
							((TTree*)f.Get("Vars"))->Project(("temp" + pdfDown[tt]).c_str(),var1.c_str(),("weight"+unc_PDFDown[tt]+ "* (" +selection + "&& WHFClass == 3)").c_str());

						}

						((TTree*)f.Get("Vars"))->Project("temp_Q2Up",var1.c_str(),("weight_Q2Up* (" +selection + "&& WHFClass == 3)").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_Q2Down",var1.c_str(),("weight_Q2Down*(" +selection + "&& WHFClass == 3)").c_str());

						
					}
					
					else if ((it-> first).find("Wjets_W_other") != string::npos)
					{
						((TTree*)f.Get("Vars"))->Project("temp_pile_upUp",var1.c_str(),("weight_PUUp*(" +selection + ")*(WHFClass == 2 || WHFClass == 4)").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_pile_upDown",var1.c_str(),("weight_PUDown*(" +selection + ")*(WHFClass == 2 || WHFClass == 4)").c_str());

						for (Int_t tt =0; tt < 20; ++tt)
						{

							((TTree*)f.Get("Vars"))->Project(("temp" + pdfUp[tt]).c_str(),var1.c_str(),("weight"+unc_PDFUp[tt]+ "* (" +selection + "&& (WHFClass == 2 || WHFClass == 4))").c_str());
							
							((TTree*)f.Get("Vars"))->Project(("temp" + pdfDown[tt]).c_str(),var1.c_str(),("weight"+unc_PDFDown[tt]+ "* (" +selection + "&&  (WHFClass == 2 || WHFClass == 4))").c_str());

						}

						((TTree*)f.Get("Vars"))->Project("temp_Q2Up",var1.c_str(),("weight_Q2Up* (" +selection + "&& (WHFClass == 2 || WHFClass == 4))").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_Q2Down",var1.c_str(),("weight_Q2Down*(" +selection + "&& (WHFClass == 2 || WHFClass == 4))").c_str());

					}
					
					else if ((it-> first)=="Wjets")
					{
						((TTree*)f.Get("Vars"))->Project("temp_pile_upUp",var1.c_str(),("weight_PUUp*(" +selection + ")").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_pile_upDown",var1.c_str(),("weight_PUDown*(" +selection + ")").c_str());

						for (Int_t tt =0; tt < 20; ++tt)
						{

							((TTree*)f.Get("Vars"))->Project(("temp" + pdfUp[tt]).c_str(),var1.c_str(),("weight"+unc_PDFUp[tt]+ "* (" +selection + ")").c_str());
							
							((TTree*)f.Get("Vars"))->Project(("temp" + pdfDown[tt]).c_str(),var1.c_str(),("weight"+unc_PDFDown[tt]+ "* (" +selection + ")").c_str());

						}

						((TTree*)f.Get("Vars"))->Project("temp_Q2Up",var1.c_str(),("weight_Q2Up* (" +selection + ")").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_Q2Down",var1.c_str(),("weight_Q2Down*(" +selection + ")").c_str());

					}
			
							
					else 
					{
						((TTree*)f.Get("Vars"))->Project("temp_pile_upUp",var1.c_str(),("weight_PUUp* (" + selection + ")").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_pile_upDown",var1.c_str(),("weight_PUDown* (" + selection + ")").c_str());

						for (Int_t tt =0; tt < 20; ++tt)
						{

							((TTree*)f.Get("Vars"))->Project(("temp" + pdfUp[tt]).c_str(),var1.c_str(),("weight"+unc_PDFUp[tt]+ "* (" +selection + ")").c_str());
							
							((TTree*)f.Get("Vars"))->Project(("temp" + pdfDown[tt]).c_str(),var1.c_str(),("weight"+unc_PDFDown[tt]+ "* (" +selection + ")").c_str());

						}
						 
					}
				
					hist_1dim_pile_up_Up -> SetName(((it-> first) + "_pile_upUp").c_str());
					hist_1dim_pile_up_Up -> SetTitle(((it-> first) + "_pile_upUp").c_str());
					
					hist_1dim_pile_up_Down -> SetName(((it-> first) + "_pile_upDown").c_str());
					hist_1dim_pile_up_Down -> SetTitle(((it-> first) + "_pile_upDown").c_str());

					for (Int_t ii = 0; ii < 20;++ii)
					{
						hist_1dim_pdfUp[ii] -> SetName(((it-> first) + pdfUp[ii]).c_str());
						hist_1dim_pdfDown[ii] -> SetName(((it-> first) + pdfDown[ii]).c_str());

						hist_1dim_pdfUp[ii] ->  SetTitle(((it-> first) + pdfUp[ii]).c_str());
						hist_1dim_pdfDown[ii] ->  SetTitle(((it-> first) + pdfDown[ii]).c_str());
					}
					
					if ((it-> first).find("Wjets")!= string::npos) 
					{
					    Wjets_1dim_Q2Up -> SetName(((it-> first) +  "_Q2Up").c_str());
					    Wjets_1dim_Q2Down -> SetName(((it-> first) + "_Q2Down").c_str());

					    Wjets_1dim_Q2Up ->  SetTitle(( (it-> first)+  "_Q2Up").c_str());
					    Wjets_1dim_Q2Down ->  SetTitle(((it-> first) + "_Q2Down").c_str());
					  
					}
					
					
					if (xmin != xmax) 
					{
						hist_1dim_pile_up_Up -> SetBins(Nxbins, xmin, xmax);
						hist_1dim_pile_up_Down -> SetBins(Nxbins, xmin, xmax);
				
						for (Int_t ii = 0; ii < 20;++ii)
						{
							hist_1dim_pdfUp[ii] -> SetBins(Nxbins, xmin, xmax);
							hist_1dim_pdfDown[ii] -> SetBins(Nxbins, xmin, xmax);
						}
					
					
						if ((it-> first).find("Wjets") != string::npos) 
						{

						    Wjets_1dim_Q2Up -> SetBins(Nxbins, xmin, xmax);
						    Wjets_1dim_Q2Down -> SetBins(Nxbins, xmin, xmax);
						   
						}
					}
					
					if (xmin == xmax) 
					{
						hist_1dim_pile_up_Up -> SetBins(Nxbins, edges1);
						hist_1dim_pile_up_Down -> SetBins(Nxbins,edges1);

						for (Int_t ii = 0; ii < 20;++ii)
						{
							hist_1dim_pdfUp[ii] -> SetBins(Nxbins, edges1);
							hist_1dim_pdfDown[ii] -> SetBins(Nxbins, edges1);
						}
						
					}
				
					hist_1dim_pile_up_Up -> Add(temp_pile_up_Up);
					hist_1dim_pile_up_Down -> Add(temp_pile_up_Down);
												
					for (Int_t ii = 0; ii < 20;++ii)
					{
						hist_1dim_pdfUp[ii] -> Add(temp_pdfUp[ii]);
						hist_1dim_pdfDown[ii] -> Add(temp_pdfDown[ii]);

					}
					
					if ((it-> first).find("Wjets") != string::npos) 
					{

					    Wjets_1dim_Q2Up -> Add(temp_Q2Up);
					    Wjets_1dim_Q2Down -> Add(temp_Q2Down);
					    
					    // normalizing W+jets Q2 up/down to nominal
					    Wjets_1dim_Q2Up -> Scale((hist_1dim-> Integral())/( Wjets_1dim_Q2Up -> Integral()));
					    Wjets_1dim_Q2Down -> Scale((hist_1dim-> Integral())/( Wjets_1dim_Q2Down -> Integral()));					    
					}  
					delete temp_pile_up_Up;
					delete temp_pile_up_Down;

					for (Int_t ii = 0; ii < 20;++ii)
					{
						delete temp_pdfUp[ii];
						delete temp_pdfDown[ii];

					}
					
					if ((it-> first).find("Wjets")!= string::npos) 
					{
					   
					    delete temp_Q2Up;
					    delete temp_Q2Down;				
					} 

				};
			
			}
			/*
			 *  2 dimension
			 */
			if (dim == 2)
			{
				TH2F *temp = new TH2F("temp","temp",Nxbins, xmin, xmax, Nybins, ymin, ymax);
				temp -> Sumw2();


				if (xmin == xmax) temp -> SetBins(Nxbins, edges1, Nybins, edges2);
				
				if ((it-> first).find("Wjets_WQQ")  != string::npos) ((TTree*)f.Get("Vars"))->Project("temp",(var1+":"+var2).c_str(),("weight* (" +selection + ")*( WHFClass == 0)").c_str());
				else if ((it-> first).find("Wjets_Wc")   != string::npos)	((TTree*)f.Get("Vars"))->Project("temp",(var1+":"+var2).c_str(),("(" + selectionMC +")*("+selection + ")*( WHFClass == 1)").c_str());
				else if ((it-> first).find("Wjets_W_light")  != string::npos) ((TTree*)f.Get("Vars"))->Project("temp", (var1+":"+var2).c_str(),("(" + selectionMC +")*("+selection + ")*( WHFClass == 3)").c_str());
				else if ((it-> first).find("Wjets_W_other")  != string::npos) ((TTree*)f.Get("Vars"))->Project("temp",(var1+":"+var2).c_str(),("(" + selectionMC +")*("+selection + ")* (WHFClass == 2 || WHFClass == 4)").c_str());
				else if ((it-> first) =="data")  ((TTree*)f.Get("Vars"))->Project("temp",(var1+":"+var2).c_str(),selection.c_str());
				else if ((it-> first) =="QCD")  ((TTree*)f.Get("Vars"))->Project("temp",(var1+":"+var2).c_str(),("(" + selectionQCD+")*("+selection + ")").c_str());
				else ((TTree*)f.Get("Vars"))->Project("temp",(var1+":"+var2).c_str(),("(" + selectionMC +")*("+ selection + ")").c_str());
				
				hist_2dim -> SetName((it-> first).c_str());
				hist_2dim -> SetTitle((it-> first).c_str());
				if (xmin != xmax) hist_2dim -> SetBins(Nxbins, xmin, xmax, Nybins, ymin, ymax);
				if (xmin == xmax) hist_2dim -> SetBins(Nxbins, edges1, Nybins, edges2);
				
				hist_2dim -> Add(temp);
				delete temp;
									
				if ( nominal_flag == true) 
				{
					
					TH2F *temp_pile_up_Up = new TH2F("temp_pile_upUp", "temp_pile_upUp",Nxbins, xmin, xmax, Nybins, ymin, ymax );
					TH2F *temp_pile_up_Down = new TH2F("temp_pile_upDown", "temp_pile_upDown",Nxbins, xmin, xmax, Nybins, ymin, ymax);
					
					temp_pile_up_Up -> Sumw2();
					temp_pile_up_Down -> Sumw2();

									
					TH2F * temp_pdfUp[20];
					TH2F * temp_pdfDown[20];
					for (Int_t l =0; l < 20; ++l)
					{
						temp_pdfUp[l] = new TH2F(("temp" + pdfUp[l]).c_str(),("temp" + pdfUp[l]).c_str(),Nxbins, xmin, xmax,Nybins, ymin, ymax);
						temp_pdfDown[l] = new TH2F(("temp" + pdfDown[l]).c_str(),("temp" + pdfDown[l]).c_str(),Nxbins, xmin, xmax,Nybins, ymin, ymax);
	
						temp_pdfUp[l] -> Sumw2();
						temp_pdfDown[l] -> Sumw2();	
	
					}
	
					if (xmin == xmax)
					{
						temp_pile_up_Up -> SetBins(Nxbins, edges1, Nybins, edges2);
						temp_pile_up_Down -> SetBins(Nxbins, edges1, Nybins,  edges2);
					}
					
					TH2F * temp_Q2Up;
					TH2F * temp_Q2Down;
					
					if ((it-> first).find("Wjets") != string::npos) 
					{

					    temp_Q2Up = new TH2F("temp_Q2Up","temp_Q2Up", Nxbins, xmin, xmax, Nybins, ymin, ymax );
					    temp_Q2Down = new TH2F("temp_Q2Down","temp_Q2Down", Nxbins, xmin, xmax, Nybins, ymin, ymax );
					    
					    temp_Q2Up -> Sumw2();
					    temp_Q2Down-> Sumw2();
					  
					}
					
			
					//Wjets components 
					if ((it-> first).find("Wjets_WQQ")  != string::npos) 
					{
						((TTree*)f.Get("Vars"))->Project("temp_pile_upUp",(var1+":"+var2).c_str(),("weight_PUUp* (" +selection + ")*( WHFClass == 0)").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_pile_upDown",(var1+":"+var2).c_str(),("weight_PUDown* (" +selection + ")*(WHFClass == 0)").c_str());
						for (Int_t tt =0; tt < 20; ++tt)
						{

							((TTree*)f.Get("Vars"))->Project(("temp" + pdfUp[tt]).c_str(),(var1+":"+var2).c_str(),("weight"+unc_PDFUp[tt]+ "* (" +selection + "&& WHFClass == 0)").c_str());
							
							((TTree*)f.Get("Vars"))->Project(("temp" + pdfDown[tt]).c_str(),(var1+":"+var2).c_str(),("weight"+unc_PDFDown[tt]+ "* (" +selection + "&& WHFClass == 0)").c_str());

						}
						
						//Q2
						((TTree*)f.Get("Vars"))->Project("temp_Q2Up",(var1+":"+var2).c_str(),("weight_Q2Up* (" +selection + "&& WHFClass == 0)").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_Q2Down",(var1+":"+var2).c_str(),("weight_Q2Down*(" +selection + "&& WHFClass == 0)").c_str());
		
					}
			
					else if ((it-> first).find("Wjets_Wc")  != string::npos ) 
					{
						((TTree*)f.Get("Vars"))->Project("temp_pile_upUp",(var1+":"+var2).c_str(),("weight_PUUp* (" +selection + ")*( WHFClass == 1)").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_pile_upDown",(var1+":"+var2).c_str(),("weight_PUDown* (" +selection + ")*( WHFClass == 1)").c_str());

						for (Int_t tt =0; tt < 20; ++tt)
						{

							((TTree*)f.Get("Vars"))->Project(("temp" + pdfUp[tt]).c_str(),(var1+":"+var2).c_str(),("weight"+unc_PDFUp[tt]+ "* (" +selection + "&& WHFClass == 1)").c_str());
							
							((TTree*)f.Get("Vars"))->Project(("temp" + pdfDown[tt]).c_str(),(var1+":"+var2).c_str(),("weight"+unc_PDFDown[tt]+ "* (" +selection + "&& WHFClass == 1)").c_str());

						}
						
						//Q2
						((TTree*)f.Get("Vars"))->Project("temp_Q2Up",(var1+":"+var2).c_str(),("weight_Q2Up* (" +selection + "&& WHFClass == 1)").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_Q2Down",(var1+":"+var2).c_str(),("weight_Q2Down*(" +selection + "&& WHFClass == 1)").c_str());
						
			
					}
			
					else if ((it-> first).find("Wjets_W_light") != string::npos ) 
					{
						((TTree*)f.Get("Vars"))->Project("temp_pile_upUp",(var1+":"+var2).c_str(),("weight_PUUp* (" +selection + ")*( WHFClass == 3)").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_pile_upDown",(var1+":"+var2).c_str(),("weight_PUDown* (" +selection + ")*(WHFClass == 3)").c_str());

						for (Int_t tt =0; tt < 20; ++tt)
						{

							((TTree*)f.Get("Vars"))->Project(("temp" + pdfUp[tt]).c_str(),(var1+":"+var2).c_str(),("weight"+unc_PDFUp[tt]+ "* (" +selection + "&& WHFClass == 3)").c_str());
							
							((TTree*)f.Get("Vars"))->Project(("temp" + pdfDown[tt]).c_str(),(var1+":"+var2).c_str(),("weight"+unc_PDFDown[tt]+ "* (" +selection + "&& WHFClass == 3)").c_str());

						}
						
						//Q2
						((TTree*)f.Get("Vars"))->Project("temp_Q2Up",(var1+":"+var2).c_str(),("weight_Q2Up* (" +selection + "&& WHFClass == 3)").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_Q2Down",(var1+":"+var2).c_str(),("weight_Q2Down*(" +selection + "&& WHFClass == 3)").c_str());
					}
					
					else if ((it-> first).find("Wjets_W_other")  != string::npos)
					{
						((TTree*)f.Get("Vars"))->Project("temp_pile_upUp",(var1+":"+var2).c_str(),("weight_PUUp*(" +selection + ")*(WHFClass == 2 || WHFClass == 4)").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_pile_upDown",(var1+":"+var2).c_str(),("weight_PUDown*(" +selection + ")*(WHFClass == 2 || WHFClass == 4)").c_str());

						for (Int_t tt =0; tt < 20; ++tt)
						{

							((TTree*)f.Get("Vars"))->Project(("temp" + pdfUp[tt]).c_str(),(var1+":"+var2).c_str(),("weight"+unc_PDFUp[tt]+ "* (" +selection + "&& (WHFClass == 2 || WHFClass == 4))").c_str());
							
							((TTree*)f.Get("Vars"))->Project(("temp" + pdfDown[tt]).c_str(),(var1+":"+var2).c_str(),("weight"+unc_PDFDown[tt]+ "* (" +selection + "&&(WHFClass == 2 || WHFClass == 4))").c_str());

						}
						
						//Q2
						((TTree*)f.Get("Vars"))->Project("temp_Q2Up",(var1+":"+var2).c_str(),("weight_Q2Up* (" +selection + ")*(WHFClass == 2 || WHFClass == 4)").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_Q2Down",(var1+":"+var2).c_str(),("weight_Q2Down*(" +selection + ")*(WHFClass == 2 || WHFClass == 4)").c_str());
					}
					
					else if ((it-> first) == "Wjets")
					{
						((TTree*)f.Get("Vars"))->Project("temp_pile_upUp",(var1+":"+var2).c_str(),("weight_PUUp*(" +selection + ")").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_pile_upDown",(var1+":"+var2).c_str(),("weight_PUDown*(" +selection + ")").c_str());

						for (Int_t tt =0; tt < 20; ++tt)
						{

							((TTree*)f.Get("Vars"))->Project(("temp" + pdfUp[tt]).c_str(),(var1+":"+var2).c_str(),("weight"+unc_PDFUp[tt]+ "* (" +selection + ")").c_str());
							
							((TTree*)f.Get("Vars"))->Project(("temp" + pdfDown[tt]).c_str(),(var1+":"+var2).c_str(),("weight"+unc_PDFDown[tt]+ "* (" +selection + ")").c_str());

						}
						
						//Q2
						((TTree*)f.Get("Vars"))->Project("temp_Q2Up",(var1+":"+var2).c_str(),("weight_Q2Up* (" +selection + ")").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_Q2Down",(var1+":"+var2).c_str(),("weight_Q2Down*(" +selection + ")").c_str());
					}
			
							
					else
					{
						((TTree*)f.Get("Vars"))->Project("temp_pile_upUp",(var1+":"+var2).c_str(),("weight_PUUp* (" + selection + ")").c_str());
						((TTree*)f.Get("Vars"))->Project("temp_pile_upDown",(var1+":"+var2).c_str(),("weight_PUDown* (" + selection + ")").c_str());
				
						for (Int_t tt =0; tt < 20; ++tt)
						{

							((TTree*)f.Get("Vars"))->Project(("temp" + pdfUp[tt]).c_str(),(var1+":"+var2).c_str(),("weight"+unc_PDFUp[tt]+ "* (" +selection + ")").c_str());
							
							((TTree*)f.Get("Vars"))->Project(("temp" + pdfDown[tt]).c_str(),(var1+":"+var2).c_str(),("weight"+unc_PDFDown[tt]+ "* (" +selection + ")").c_str());

						}

						
					}
				
					
					hist_2dim_pile_up_Up -> SetName(((it-> first) + "_pile_upUp").c_str());
					hist_2dim_pile_up_Up -> SetTitle(((it-> first) + "_pile_upUp").c_str());
										
					hist_2dim_pile_up_Down -> SetName(((it-> first) + "_pile_upDown").c_str());
					hist_2dim_pile_up_Down -> SetTitle(((it-> first) + "_pile_upDown").c_str());

					for (Int_t ii = 0; ii < 20;++ii)
					{
						hist_2dim_pdfUp[ii] -> SetName(((it-> first) + pdfUp[ii]).c_str());
						hist_2dim_pdfDown[ii] -> SetName(((it-> first) + pdfDown[ii]).c_str());

						hist_2dim_pdfUp[ii] ->  SetTitle(((it-> first) + pdfUp[ii]).c_str());
						hist_2dim_pdfDown[ii] ->  SetTitle(((it-> first) + pdfDown[ii]).c_str());
					}
					
					if ((it-> first).find("Wjets")  != string::npos) 
					{
					    Wjets_2dim_Q2Up -> SetName(((it-> first) +  "_Q2Up_2dim").c_str());
					    Wjets_2dim_Q2Down -> SetName(((it-> first) + "_Q2Down_2dim").c_str());

					    Wjets_2dim_Q2Up ->  SetTitle(( (it-> first)+  "_Q2Up_2dim").c_str());
					    Wjets_2dim_Q2Down ->  SetTitle(((it-> first) + "_Q2Down_2dim").c_str());
					  
					}
										
					if (xmin != xmax) 
					{
						hist_2dim_pile_up_Up -> SetBins(Nxbins, xmin, xmax, Nybins, ymin, ymax);
						hist_2dim_pile_up_Down -> SetBins(Nxbins, xmin, xmax, Nybins, ymin, ymax);
		
						for (Int_t ii = 0; ii < 20;++ii)
						{
							hist_2dim_pdfUp[ii] -> SetBins(Nxbins, xmin, xmax, Nybins, ymin, ymax);
							hist_2dim_pdfDown[ii] -> SetBins(Nxbins, xmin, xmax, Nybins, ymin, ymax);
						}
						
						if ((it-> first).find("Wjets")  != string::npos) 
						{

						    Wjets_2dim_Q2Up -> SetBins(Nxbins, xmin, xmax, Nybins, ymin, ymax);
						    Wjets_2dim_Q2Down -> SetBins(Nxbins, xmin, xmax, Nybins, ymin, ymax);
						   
						}
											
					}
					
					if (xmin == xmax) 
					{
						hist_2dim_pile_up_Up -> SetBins(Nxbins, edges1, Nybins, edges2);
						hist_2dim_pile_up_Down -> SetBins(Nxbins, edges1, Nybins, edges2);

						for (Int_t ii = 0; ii < 20;++ii)
						{
							hist_2dim_pdfUp[ii] -> SetBins(Nxbins, edges1, Nybins, edges2);
							hist_2dim_pdfDown[ii] -> SetBins(Nxbins, edges1, Nybins, edges2);
						}
											
					}
				
					hist_2dim_pile_up_Up -> Add(temp_pile_up_Up);
					hist_2dim_pile_up_Down -> Add(temp_pile_up_Down);
										
					for (Int_t ii = 0; ii < 20;++ii)
					{
						hist_2dim_pdfUp[ii] -> Add(temp_pdfUp[ii]);
						hist_2dim_pdfDown[ii] -> Add(temp_pdfDown[ii]);

					}
					
					if ((it-> first).find("Wjets")  != string::npos) 
					{

					    Wjets_2dim_Q2Up -> Add(temp_Q2Up);
					    Wjets_2dim_Q2Down -> Add(temp_Q2Down);
					    
					    // normalizing W+jets Q2 up/down to nominal
					    Wjets_2dim_Q2Up -> Scale((hist_2dim-> Integral())/( Wjets_2dim_Q2Up -> Integral()));
					    Wjets_2dim_Q2Down -> Scale((hist_2dim-> Integral())/( Wjets_2dim_Q2Down -> Integral()));

					    
					}
					
					delete temp_pile_up_Up;
					delete temp_pile_up_Down;

					for (Int_t ii = 0; ii < 20;++ii)
					{
						delete temp_pdfUp[ii];
						delete temp_pdfDown[ii];

					}
					
					if((it-> first).find("Wjets") != string::npos) 
					{
					   
					    delete temp_Q2Up;
					    delete temp_Q2Down;				
					} 

				};
			
				
			}
			f.Close();
		}
	
		
	
		file.cd();
	/*	if ((it-> first) == "Wjets_WQQ") wqq = hist_1dim -> Integral();
		else if ((it-> first) == "Wjets_W_light") wlight = hist_1dim -> Integral();
 		else if ((it-> first) == "Wjets_W_other") wother = hist_1dim -> Integral();
 		else if ((it-> first) == "Wjets_Wc") wc = hist_1dim -> Integral();*/


		if (dim == 1)
		{
		  /*if ((it-> first).find("Wjets_WQQ")!=string::npos &&  (it-> first).find("matching")!=string::npos) hist_1dim -> Scale(wqq/(hist_1dim -> Integral()));
		  if ((it-> first).find("Wjets_Wc")!=string::npos &&  (it-> first).find("matching")!=string::npos) hist_1dim -> Scale(wc/(hist_1dim -> Integral()));
		  if ((it-> first).find("Wjets_W_light")!=string::npos &&  (it-> first).find("matching")!=string::npos) hist_1dim -> Scale(wlight/(hist_1dim -> Integral()));
		  if ((it-> first).find("Wjets_W_other")!=string::npos &&  (it-> first).find("matching")!=string::npos) hist_1dim -> Scale(wother/(hist_1dim -> Integral()));*/
		  
		  hist_1dim -> Write();
		  delete hist_1dim;
		  		   
		     if (nominal_flag == true)
		     {
			  hist_1dim_pile_up_Up -> Write();
			  hist_1dim_pile_up_Down -> Write();
			  delete hist_1dim_pile_up_Up ;
			  delete hist_1dim_pile_up_Down;
			  
			  for (Int_t ii =0; ii < 20; ++ii)
			  {
				  hist_1dim_pdfUp[ii] -> Write();
				  hist_1dim_pdfDown[ii] -> Write();
				  delete hist_1dim_pdfUp[ii];
				  delete hist_1dim_pdfDown[ii];

			  }
			  
			  if ((it-> first).find("Wjets") != string::npos && nominal_flag == true ) 
			  {
			    Wjets_1dim_Q2Up -> Write();
			    Wjets_1dim_Q2Down -> Write();
			    
			    delete Wjets_1dim_Q2Up;
			    delete Wjets_1dim_Q2Down;
			  } 
		     }
		}  
		
		if (dim == 2)
		{
		  
		  if (convert == false)
		  {
		    hist_2dim -> Write();
		    	    
		    
		    delete hist_2dim;
		    
		    
		      if (nominal_flag == true)
		      {
			
			hist_2dim_pile_up_Up -> Write();
			hist_2dim_pile_up_Down -> Write();
			
			delete hist_2dim_pile_up_Up ;
			delete hist_2dim_pile_up_Down;
			
			    for (Int_t ii =0; ii < 20; ++ii)
			    {
				    hist_2dim_pdfUp[ii] -> Write();
				    hist_2dim_pdfDown[ii] -> Write();
				    
				    delete hist_2dim_pdfUp[ii];
				    delete hist_2dim_pdfDown[ii];

			    }
			    
			    if ((it-> first).find("Wjets") != string::npos && nominal_flag == true ) 
			    {
			      Wjets_2dim_Q2Up -> Write();
			      Wjets_2dim_Q2Down -> Write();
			      
			      delete Wjets_2dim_Q2Up;
			      delete Wjets_2dim_Q2Down;
			    } 
		      }
		  } 
		  
		   if (convert == true)
		  {
		    
		    ConvertHist(hist_2dim , (it->first))-> Write();
		    
		    
		      if (nominal_flag == true)
		      {
			  ConvertHist(hist_2dim_pile_up_Up , ((it->first) +"_pile_upUp"))-> Write();
			  ConvertHist(hist_2dim_pile_up_Down , ((it->first) +"_pile_upDown"))-> Write();

			  for (Int_t ii =0; ii < 20; ++ii)
			    {
				    ConvertHist(hist_2dim_pdfUp[ii], ((it->first) + pdfUp[ii]))-> Write();
				    ConvertHist(hist_2dim_pdfDown[ii], ((it->first) + pdfDown[ii]))-> Write();

			    }
			    
			    if ((it-> first).find("Wjets") != string::npos && nominal_flag == true ) 
			    {
			        ConvertHist(Wjets_2dim_Q2Up, ((it->first) + "_Q2Up"))-> Write();
				ConvertHist(Wjets_2dim_Q2Down, ((it->first) + "_Q2Down"))-> Write();
			    } 
		      }
		  }   
		}   
		   
	
		
	 }

	file.Close();
}	 
