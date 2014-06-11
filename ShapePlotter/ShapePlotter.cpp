#include "ShapePlotter.hpp"

ShapePlotter::ShapePlotter()
{}

void ShapePlotter::AddVariable(string VarName_, string TreeName_, Color_t color_)
{
  Variable var_tmp;
  var_tmp.VarName = VarName_;
  var_tmp.TreeName = TreeName_;
  var_tmp.color  = color_;
  
  Variables.push_back(var_tmp);
}


void ShapePlotter::ClearVariables()
{
  Variables.clear();
  hists.clear();
}

void ShapePlotter::SetInputFiles(string inputFile)
{
  FileNames.push_back(inputFile);
}

void ShapePlotter::ClearInputFiles()
{
  FileNames.clear();
}

void ShapePlotter::SetTitle(string title_)
{
  title = title_;
}
void ShapePlotter::Draw()
{
  gStyle->SetOptStat(0);
  TCanvas *c1=  new TCanvas("c1","canvas",1200,900);
  
  TPad *pad1 = new TPad("pad1","This is pad1",0.0,0.38,1.0,0.98);
  TPad *pad2 = new TPad("pad2","This is pad2",0.0,0.02,1.0,0.39);
  
  TLegend  *leg = new TLegend(0.8,0.6,0.9,0.9);
  leg ->  SetFillColor(kWhite);
   
  pad1->Draw();
  pad2->Draw();
  pad1 -> cd();

  float ymax=0;
  TH1F *h_tmp;
  for (unsigned int iVar =0; iVar < Variables.size(); iVar++)
  {
    TChain *chain = new TChain((Variables.at(iVar).TreeName).c_str());
  
    for( unsigned int iFile = 0; iFile < FileNames.size(); ++iFile)
    {
      chain -> Add(FileNames.at(iFile).c_str());
    
    }
    
    vector <float>* tmp = new std::vector<float>();
    tmp -> clear();
    chain -> SetBranchAddress(Variables.at(iVar).VarName.c_str(), &tmp);
    h_tmp = new TH1F(("temp" + Variables.at(iVar).VarName).c_str(), ("temp" + Variables.at(iVar).VarName).c_str(), Nbins, xmin, xmax);
    h_tmp -> SetTitle(title.c_str());
    for (unsigned int iEntry =0;  iEntry < chain -> GetEntriesFast(); ++iEntry)
    {
      chain -> GetEntry(iEntry);
    
      for (unsigned int iE =0; iE < tmp -> size(); ++iE)
      {
	h_tmp -> Fill(tmp -> at(iE));
	
      }
      tmp -> clear();
    }
    hists.push_back(h_tmp);
    h_tmp -> SetLineWidth(4.);
    h_tmp -> SetLineColor(Variables.at(iVar).color);
    if(h_tmp->GetMaximum()>ymax){
	ymax = h_tmp->GetMaximum();
	hists[0]->SetMaximum(ymax*1.2);
    }
    hists.at(iVar) -> Sumw2();
    hists.at(iVar) -> GetXaxis() -> SetTitle("GeV");
    hists.at(iVar) -> Draw("SAME HISTE1");  
    leg->AddEntry(hists.at(iVar),Variables.at(iVar).VarName.c_str(),"l");
    
  } 
   
  leg -> Draw("SAME");
  if (hists.size() == 2)
  {
    TH1F *h_dif = new TH1F(("dif" + Variables.at(0).VarName + "_vs_" + Variables.at(1).VarName).c_str(), ("dif" + Variables.at(0).VarName + "_vs_" + Variables.at(1).VarName).c_str(), Nbins, xmin, xmax);
    for (int iBin = 1; iBin <= hists.at(0) -> GetNbinsX(); ++iBin)
    {
      if (hists.at(0) -> GetBinContent(iBin) ==0) cerr << "There are zero bins. Try to change binning" << endl;
      h_dif -> SetBinContent(iBin, (( hists.at(0) -> GetBinContent(iBin)) - ( hists.at(1) -> GetBinContent(iBin)) )/ ( hists.at(0) -> GetBinContent(iBin))) ;
      
    }
    h_dif -> SetLineColor(kBlack);
    h_dif -> SetLineWidth(4.);
    h_dif -> GetYaxis() -> SetLabelSize(0.06);
    h_dif -> GetXaxis() -> SetLabelSize(0.06);
    h_dif -> GetXaxis() -> SetTitleSize(0.06);
    h_dif -> GetXaxis() -> SetTitle("GeV");
    h_dif -> SetTitle(("#frac{" + Variables.at(0).VarName + "-" + Variables.at(1).VarName + "}{" + Variables.at(0).VarName + "}").c_str());
    pad2 -> cd();
    h_dif -> Sumw2();
    h_dif -> Draw("HISTE1");
    TLine *line = new TLine(xmin,0., xmax,0.);
    line -> Draw("SAME");
  }
   c1 -> Print((Variables.at(0).VarName + "_vs_" + Variables.at(1).VarName + ".png").c_str());
   c1 -> Close();
}