#include <TFile.h>
#include <TTree.h>
#include <TTreeFormula.h>
#include <TH1.h>
#include <TH2.h>
#include <THStack.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TRandom3.h>
#include <TAxis.h>
#include <iostream>
#include <iostream>
#include <sstream>
#include <map>
#include <Math/Random.h>
#include <Math/GSLRndmEngines.h>
#include <time.h> 

void covariance_matrix()
{
//   index 0 corresponds to LV
//   index 1 corresponds to RV
  double gen[2], pdf[2], stat[2], matchingTtbar[2], matchingWjets[2], scaleTtbar[2], scaleWjets[2], scale_T_CH[2], scale_TW_CH[2],trig[2];
  double par[2];
  par[0] =0.87;//LV value
  par[1] = 0.28;//RV (LT)value

//Here is information from studying of unmarginalized systematics to be put.  
//   LV
//   uncertainty is in percent.
  gen[0]=1.38;
  pdf[0]=0.9;
  matchingTtbar[0]= 1.51;
//   matchingWjets[0]=9.89;
  scale_T_CH[0]=1.8;
  scale_TW_CH[0]=0.96;
  scaleWjets[0]=2.91;
  scaleTtbar[0]=2.79;
  trig[0]=0.9;
  
  //RV(LT)
//   uncertainty is in percent. 
  gen[1]=2.72;
//   stat[1]=520.95;
  pdf[1]=7.74;
  matchingTtbar[1]= 35.62;
//   matchingWjets[1]=1592.65;
  scale_T_CH[1]=6.19;
  scale_TW_CH[1]=8.9;
  scaleWjets[1]=33.62;
  scaleTtbar[1]=22.96;
  trig[1]=11.43;
  
//   Covariance matrices are constructed
  double GEN[2][2], PDF[2][2], STAT[2][2], MATCHING_Ttbar[2][2], MATCHING_Wjets[2][2], SCALE_Ttbar[2][2], SCALE_Wjets[2][2], SCALE_T_CH[2][2], SCALE_TW_CH[2][2],TRIG[2][2], COV_MATRIX[2][2] ;
  
  for (int i =0; i< 2;++i)
  {
    
    for (int j=0; j <2; ++j)
    {
      
      GEN[i][j]=par[i]*(gen[i]/100.)*par[j]*(gen[j]/100.);
//       STAT[i][j]=par[i]*(stat[i]/100.)*par[j]*(stat[j]/100.);
      PDF[i][j]=par[i]*(pdf[i]/100.)*par[j]*(pdf[j]/100.);
      MATCHING_Ttbar[i][j]=par[i]*(matchingTtbar[i]/100.)*par[j]*(matchingTtbar[j]/100.);
//       MATCHING_Wjets[i][j]=par[i]*(matchingWjets[i]/100.)*par[j]*(matchingWjets[j]/100.);
      SCALE_Ttbar[i][j]=par[i]*(scaleTtbar[i]/100.)*par[j]*(scaleTtbar[j]/100.);
      SCALE_Wjets[i][j]=par[i]*(scaleWjets[i]/100.)*par[j]*(scaleWjets[j]/100.);
      SCALE_T_CH[i][j]=par[i]*(scale_T_CH[i]/100.)*par[j]*(scale_T_CH[j]/100.);
      SCALE_TW_CH[i][j]=par[i]*(scale_TW_CH[i]/100.)*par[j]*(scale_TW_CH[j]/100.);
      TRIG[i][j]=par[i]*(trig[i]/100.)*par[j]*(trig[j]/100.);
      
    }
    
  }
  
  for (int i =0; i< 2;++i)
  {
    
    for (int j=0; j <2; ++j)
    {
      
      COV_MATRIX[i][j] = GEN[i][j] + PDF[i][j] +  MATCHING_Ttbar[i][j]  +  SCALE_Ttbar[i][j] + SCALE_Wjets[i][j] + SCALE_T_CH[i][j] + SCALE_TW_CH[i][j] +  TRIG[i][j];
      cout << "[" << i<<"]" <<   "[" << j<<"]" << COV_MATRIX[i][j] << endl;
    }
    
  }
  cout << "correlation coefficient   " << (COV_MATRIX[0][1])/(sqrt(COV_MATRIX[0][0])*sqrt(COV_MATRIX[1][1])) << endl;
  cout << "sigma LV  " << sqrt(COV_MATRIX[0][0]) << endl;
  cout << "sigma RV(LT)  " << sqrt(COV_MATRIX[1][1]) << endl;
  
}
