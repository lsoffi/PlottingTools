#include"TPaveText.h"
#include "TChain.h"
#include "TH1F.h"
#include <vector>
#include <cmath>
#include "TFile.h"
#include "TLegend.h"
#include "TPad.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TStyle.h"
#include <stdio.h>
#include "TCanvas.h"
#include "TPad.h"
#include "TH1F.h"
#include "THStack.h"
#include "TProfile.h"
#include "TH2D.h"
#include "TF1.h"
#include "TGraphErrors.h"
#include "TFile.h"
#include "TTree.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TPaveText.h"
#include "TColor.h"
#include "TLatex.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
  

std::string get_sqrtText() {

   char label_sqrt_text[150];
  
    sprintf( label_sqrt_text, "#sqrt{s} = 7 TeV");
    std::string returnString(label_sqrt_text);

  return returnString;

}


TPaveText* get_labelCMS( int legendQuadrant = 0 , std::string year="2011", bool sim=false, std::string run = "ALL") {

  if( legendQuadrant!=0 && legendQuadrant!=1 && legendQuadrant!=2 && legendQuadrant!=3 ) {
    std::cout << "WARNING! Legend quadrant '" << legendQuadrant << "' not yet implemented for CMS label. Using 2." << std::endl;
    legendQuadrant = 2;
  }

  float x1, y1, x2, y2;
  if( legendQuadrant==1 ) {
    x1 = 0.63;
    y1 = 0.83;
    x2 = 0.8;
    y2 = 0.87;
  } else if( legendQuadrant==2 ) {
    x1 =  0.25;
    y1 = 0.83;
    x2 =  0.42;
    y2 = 0.87;
  } else if( legendQuadrant==3 ) {
    x1 = 0.25;
    y1 = 0.2;
    x2 = 0.42;
    y2 = 0.24;
  } else if( legendQuadrant==0 ) {
    x1 = 0.175;
    y1 = 0.953;
    x2 = 0.6;
    y2 = 0.975;
  }

  
  TPaveText* cmslabel = new TPaveText( x1, y1, x2, y2, "brNDC" );
  cmslabel->SetFillColor(kWhite);
  cmslabel->SetTextSize(0.038);
  if( legendQuadrant==0 ) cmslabel->SetTextAlign(11);
  cmslabel->SetTextSize(0.038);
  cmslabel->SetTextFont(42);
 
    std::string leftText;
   
    if(year == "2010")  leftText = "CMS Preliminary 2010, 34 pb^{-1}";
    if (sim)  leftText = "CMS Simulation"; //cwr ->remove 2011
    else {
      if(year == "2011" && run == "RUN2011A")  leftText = "CMS Preliminary RUN2011A 2.034 fb^{-1}";
      if(year == "2011" && run == "RUN2011B")  leftText = "CMS Preliminary 2011, 2.516 fb^{-1}";
      if(year == "2011" && run == "ALL")  leftText = "CMS 4.9 fb^{-1}"; //cwr ->remove 2011
      if(year == "none" && run == "ALL")  leftText = "CMS Data"; //cwr ->remove 2011
      if(year == "May2011")leftText = "CMS Preliminary 2011, 858.4 pb^{-1}";

    }
    cmslabel->AddText(leftText.c_str());
    return cmslabel;

}




TPaveText* get_labelSqrt( int legendQuadrant ) {

  if( legendQuadrant!=0 && legendQuadrant!=1 && legendQuadrant!=2 && legendQuadrant!=3 ) {
    std::cout << "WARNING! Legend quadrant '" << legendQuadrant << "' not yet implemented for Sqrt label. Using 2." << std::endl;
    legendQuadrant = 2;
  }


  float x1, y1, x2, y2;
  if( legendQuadrant==1 ) {
    x1 = 0.63;
    y1 = 0.78;
    x2 = 0.8;
    y2 = 0.82;
  } else if( legendQuadrant==2 ) {
    x1 = 0.25;
    y1 = 0.78;
    x2 = 0.42;
    y2 = 0.82;
  } else if( legendQuadrant==3 ) {
    x1 = 0.25;
    y1 = 0.16;
    x2 = 0.42;
    y2 = 0.2;
  } else if( legendQuadrant==0 ) {
    x1 = 0.65;
    y1 = 0.953;
    x2 = 0.87;
    y2 = 0.975;
  }


  TPaveText* label_sqrt = new TPaveText(x1,y1,x2,y2, "brNDC");
  label_sqrt->SetFillColor(kWhite);
  label_sqrt->SetTextSize(0.038);
  label_sqrt->SetTextFont(42);
  label_sqrt->SetTextAlign(31); // align right
  label_sqrt->AddText("#sqrt{s} = 7 TeV");
  return label_sqrt;

}


 



void makePlot(){



  TFile* file_data_B;
  file_data_B = new TFile("/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_01162018/PU/pileup_2017_RUNB.root", "READ");
  TFile* file_data_C;
  file_data_C = new TFile("/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_01162018/PU/pileup_2017_RUNC.root", "READ");
  TFile* file_data_D;
  file_data_D = new TFile("/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_01162018/PU/pileup_2017_RUND.root", "READ");
  TFile* file_data_E;
  file_data_E = new TFile("/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_01162018/PU/pileup_2017_RUNE.root", "READ");
  TFile* file_data_F;
  file_data_F = new TFile("/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_01162018/PU/pileup_2017_RUNF.root", "READ");
  
  TFile* file_mc_mad;
  file_mc_mad= new TFile("/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_01292018/Moriond18_V1/mc/TnPTree_DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_all.root", "READ");
  TTree* t_mc_mad = (TTree*) file_mc_mad->Get("tnpPhoIDs/fitter_tree"); 
  TFile* file_mc_amc;
  file_mc_amc= new TFile("/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_01292018/Moriond18_V1/mc/TnPTree_DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_all.root", "READ");
  TTree* t_mc_amc = (TTree*) file_mc_amc->Get("tnpPhoIDs/fitter_tree"); 


  TFile* file_mc_mad_friend_new;
  file_mc_mad_friend_new= new TFile("/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_01292018/Moriond18_V1/PU/mc-V2-customW/DY_madgraph_pho.pu.puTree.root", "READ");
  TFile* file_mc_mad_friend_old;
  file_mc_mad_friend_old= new TFile("/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_01292018/Moriond18_V1/PU/mc-V2-customW/DY_madgraph_Moriond18_pho.pu.puTree.root", "READ");
  TTree *t_friend_new  = (TTree*)file_mc_mad_friend_new->Get("weights_2017_runBCDEF"); //weights_2017_runBCDEF->Draw("PUweight")
  TTree *t_friend_old  = (TTree*)file_mc_mad_friend_old->Get("weights_2017_runBCDEF"); //weights_2017_runBCDEF->Draw("PUweight")
  
  t_mc_mad->AddFriend("weights_2017_runBCDEF", "/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_01292018/Moriond18_V1/PU/mc-V2-customW/DY_madgraph_pho.pu.puTree.root");


  std::cout<<"---------------------> "<<t_friend_new->GetEntries()<<" "<<t_friend_old->GetEntries()<<" "<<t_mc_mad->GetEntries()<<std::endl;
  TH1F* h1_data_B;
  h1_data_B= (TH1F*) file_data_B->Get("pileup");
  TH1F* h1_data_C= (TH1F*) file_data_C->Get("pileup");
  TH1F* h1_data_D= (TH1F*) file_data_D->Get("pileup");
  TH1F* h1_data_E= (TH1F*) file_data_E->Get("pileup");
  TH1F* h1_data_F= (TH1F*) file_data_F->Get("pileup");
  TH1F* h1_data_all = (TH1F*) h1_data_B->Clone();
  h1_data_all->SetName("h1_data_all");
  h1_data_all->Add(h1_data_C);
  h1_data_all->Add(h1_data_D);
  h1_data_all->Add(h1_data_E);
  h1_data_all->Add(h1_data_F);
  TH1F* h1_mc_mad= new TH1F("h1_mc_mad","h1_mc_mad",h1_data_B->GetNbinsX(), 0., 100);
  TH1F* h1_mc_amc  =new TH1F("h1_mc_amc","h1_mc_amc",h1_data_B->GetNbinsX(), 0., 100);

  t_mc_mad->Draw("truePU>>h1_mc_mad", "truePU>-10");
  t_mc_amc->Draw("truePU>>h1_mc_amc", "truePU>-10");


  TFile* f_runB= new TFile("/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_01162018/Moriond18_V1/data/TnPTree_17Nov2017_RunB.root");
  TFile* f_runC= new TFile("/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_01162018/Moriond18_V1/data/TnPTree_17Nov2017_RunC.root");
  TFile* f_runD= new TFile("/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_01162018/Moriond18_V1/data/TnPTree_17Nov2017_RunD.root");
  TFile* f_runE= new TFile("/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_01162018/Moriond18_V1/data/TnPTree_17Nov2017_RunE.root");
  TFile* f_runF= new TFile("/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_01162018/Moriond18_V1/data/TnPTree_17Nov2017_RunF.root");
  
  TTree* t_runB = (TTree*) f_runB->Get("tnpPhoIDs/fitter_tree");
  TTree* t_runC = (TTree*) f_runC->Get("tnpPhoIDs/fitter_tree");
  TTree* t_runD = (TTree*) f_runD->Get("tnpPhoIDs/fitter_tree");
  TTree* t_runE = (TTree*) f_runE->Get("tnpPhoIDs/fitter_tree");
  TTree* t_runF = (TTree*) f_runF->Get("tnpPhoIDs/fitter_tree");

  TH1F* h1_nvtx_data_B = new TH1F("h1_nvtx_data_B","h1_nvtx_data_B",100,0., 100.);
  TH1F* h1_nvtx_data_C = new TH1F("h1_nvtx_data_C","h1_nvtx_data_C",100,0., 100.);
  TH1F* h1_nvtx_data_D = new TH1F("h1_nvtx_data_D","h1_nvtx_data_D",100,0., 100.);
  TH1F* h1_nvtx_data_E = new TH1F("h1_nvtx_data_E","h1_nvtx_data_E",100,0., 100.);
  TH1F* h1_nvtx_data_F = new TH1F("h1_nvtx_data_F","h1_nvtx_data_F",100,0., 100.);
  TH1F* h1_nvtx_data_all = new TH1F("h1_nvtx_data_all","h1_nvtx_data_all",100,0., 100.);

  t_runB->Draw("event_nPV>>h1_nvtx_data_B");
  t_runC->Draw("event_nPV>>h1_nvtx_data_C");
  t_runD->Draw("event_nPV>>h1_nvtx_data_D");
  t_runE->Draw("event_nPV>>h1_nvtx_data_E");
  t_runF->Draw("event_nPV>>h1_nvtx_data_F");

  
  h1_nvtx_data_all->Add(h1_nvtx_data_B);
  h1_nvtx_data_all->Add(h1_nvtx_data_C);
  h1_nvtx_data_all->Add(h1_nvtx_data_D);
  h1_nvtx_data_all->Add(h1_nvtx_data_E);
  h1_nvtx_data_all->Add(h1_nvtx_data_F);


  TH1F* h1_nvtx_mc_mad= new TH1F("h1_nvtx_mc_mad","h1_nvtx_mc_mad",h1_nvtx_data_B->GetNbinsX(), 0., 100);
  TH1F* h1_nvtx_mc_amc  =new TH1F("h1_nvtx_mc_amc","h1_nvtx_mc_amc",h1_nvtx_data_B->GetNbinsX(), 0., 100);
  TH1F* h1_nvtx_mc_mad_w= new TH1F("h1_nvtx_mc_mad_w","h1_nvtx_mc_mad_w",h1_nvtx_data_B->GetNbinsX(), 0., 100);
  TH1F* h1_nvtx_mc_amc_w  =new TH1F("h1_nvtx_mc_amc_w","h1_nvtx_mc_amc_w",h1_nvtx_data_B->GetNbinsX(), 0., 100);
  TH1F* h1_nvtx_mc_mad_w_new= new TH1F("h1_nvtx_mc_mad_w_new","h1_nvtx_mc_mad_w_new",h1_nvtx_data_B->GetNbinsX(), 0., 100);
  TH1F* h1_nvtx_mc_amc_w_new  =new TH1F("h1_nvtx_mc_amc_w_new","h1_nvtx_mc_amc_w_new",h1_nvtx_data_B->GetNbinsX(), 0., 100);



  
  

  //------fix legend-----//
  TLegend* legend1;
  legend1 = new TLegend(0.6, 0.6, 0.89, 0.89);
  legend1->SetFillColor(kWhite);
  legend1->SetTextFont(42);
 

  h1_data_B->SetLineColor(kRed);
  h1_data_C->SetLineColor(kBlue);
  h1_data_D->SetLineColor(kOrange);
  h1_data_E->SetLineColor(kGreen+8);
  h1_data_F->SetLineColor(kViolet);

  h1_mc_mad->SetLineColor(kPink);
  h1_mc_amc->SetLineColor(kSpring);

  legend1->AddEntry(h1_data_B, "RUN B", "L");
  legend1->AddEntry(h1_data_C, "RUN C", "L");
  legend1->AddEntry(h1_data_D, "RUN D", "L");
  legend1->AddEntry(h1_data_E, "RUN E", "L");
  legend1->AddEntry(h1_data_F, "RUN F", "L");
  legend1->AddEntry(h1_mc_mad, "DY - madgraph", "L");
  legend1->AddEntry(h1_mc_amc, "DY- amcatnlo", "L");
  
  TCanvas* c = new TCanvas("c", "c",1);
  c->cd();
  h1_data_B->GetXaxis()->SetTitle("nPU True");
  h1_data_B->DrawNormalized("histF");
  h1_data_C->DrawNormalized("histsame");
  h1_data_D->DrawNormalized("histsame");
  h1_data_E->DrawNormalized("histsame");
  h1_data_F->DrawNormalized("histsame");
  h1_mc_mad->DrawNormalized("histsame");
  h1_mc_amc->DrawNormalized("histsame");
  legend1->Draw("same");
  c->SaveAs("~/www/Tnp-2017-012918/PU_2017.png");
 
  legend1->Clear();
  legend1->AddEntry(h1_data_all, "All RUNs", "L");
  legend1->AddEntry(h1_mc_mad, "DY - madgraph", "L");
  h1_data_all->GetXaxis()->SetTitle("nPU True");
  h1_data_all->DrawNormalized("hist");
  h1_mc_mad->DrawNormalized("histsame");
  legend1->Draw("same");
  c->SaveAs("~/www/Tnp-2017-012918/PU_2017_inclusive.png");

  
  h1_data_all->Scale(1./h1_data_all->Integral());
  h1_mc_mad->Scale(1./h1_mc_mad->Integral());
  
  //compute weights hist
  TH1F* weightsTMP = (TH1F*) h1_data_all->Clone();
  weightsTMP->Divide(h1_mc_mad);

  TH1D* weightedPU= (TH1D*)h1_mc_mad->Clone("weightedPU");
  weightedPU->Multiply(weightsTMP);

  //  std::cout<<weightedPU->Integral(1,100)<<" "<<h1_mc_mad->Integral(1,100)<<std::endl;
  TH1D* weights = (TH1D*)weightsTMP->Clone("rescaledWeights");
  weights->Scale( h1_mc_mad->Integral(1,h1_mc_mad->GetNbinsX()) / weightedPU->Integral(1,h1_mc_mad->GetNbinsX()) );
  
  //  std::cout<<weightsTMP->Integral()<<" "<<weights->Integral()<<std::endl;

  //  weights->Draw("histsame");
  legend1->AddEntry(weightedPU, "DY - madgraph - after reweight", "F");
  weightedPU->SetLineColor(kBlue);
  weightedPU->SetFillColor(kBlue);
  weightedPU->Draw("histF");
  weightedPU->GetXaxis()->SetTitle("nPU True");
  h1_data_all->Draw("histsame");
  h1_mc_mad->Draw("histsame");
  legend1->Draw("same");
  c->SaveAs("~/www/Tnp-2017-012918/PU_2017_W_and WO_weights.png");

  std::vector<double>puweights_;
  TH1F* h_weights = new TH1F("h_weights", "h_weights", 80., 0., 3);
  TH2F* h2_weights = new TH2F("h2_weights", "h2_weights", 80., 0., 3,80., 0., 3);
  TH1F* h_tot_weights = new TH1F("h_tot_weights", "h_tot_weights", 80., 0., 3);
  TH1F* h_tot_weights_new = new TH1F("h_tot_weights_new", "h_tot_weights_new", 80., 0., 3);
  for (int i = 0; i<h1_mc_mad->GetNbinsX(); i++) {
    float weight=1.;
    weight=weights->GetBinContent(i+1);
    puweights_.push_back(weight);
    h_weights->Fill(weight);
  }
  h_weights->GetXaxis()->SetTitle("pu weights");
  h_weights->Draw("hist");
  c->SaveAs("~/www/Tnp-2017-012918/PU_2017_Weight.png");

  for (int i = 0; i<h1_mc_mad->GetNbinsX(); i++) std::cout<<" if(npu== "<<i<<") weight="<<puweights_[i]<<"; \t"<<std::endl;
  t_mc_mad->Draw("event_nPV>>h1_nvtx_mc_mad");
  t_mc_amc->Draw("event_nPV>>h1_nvtx_mc_amc");

  t_mc_mad->Draw("event_nPV>>h1_nvtx_mc_mad_w", "getPUweight(truePU)");
  t_mc_amc->Draw("event_nPV>>h1_nvtx_mc_amc_w", "getPUweight(truePU)");


  t_mc_mad->Draw("getPUweight(truePU):weights_2017_runBCDEF.PUweight>>h2_weights");
  t_mc_mad->Draw("getPUweight(truePU)>>h_tot_weights");
  t_mc_mad->Draw("weights_2017_runBCDEF.PUweight>>h_tot_weights_new");

  legend1->Clear();
  legend1->AddEntry(h_tot_weights_new, "TnP weights", "L");
  legend1->AddEntry(h_tot_weights, "Customized weights", "L");
  h_tot_weights->GetXaxis()->SetTitle("tot pu weights");
  h_tot_weights->Draw("hist");
  h_tot_weights_new->SetLineColor(kOrange);
  h_tot_weights_new->Draw("histsame");
  c->SaveAs("~/www/Tnp-2017-012918/PU_2017_Weight_TOT.png");

  h2_weights->Draw("COLZ");
  h2_weights->GetXaxis()->SetTitle("TnP weights");
  h2_weights->GetYaxis()->SetTitle("Customized weights");
  c->SaveAs("~/www/Tnp-2017-012918/PU_2017_Weight_TOT_2D.png");


  
  t_mc_mad->Draw("event_nPV>>h1_nvtx_mc_mad_w_new", "weights_2017_runBCDEF.PUweight");
  t_mc_mad->Scan("event_nPV:truePU:getPUweight(truePU):weights_2017_runBCDEF.PUweight");


  legend1->Clear();
  legend1->AddEntry(h1_nvtx_data_all, "All Runs", "P");
  legend1->AddEntry(h1_nvtx_mc_mad, "DY - madgraph - before reweight", "L");
  legend1->AddEntry(h1_nvtx_mc_mad_w, "DY - madgraph - after TnP reweight", "L");
  legend1->AddEntry(h1_nvtx_mc_mad_w_new, "DY - madgraph - after Customized reweight ", "L");
  h1_nvtx_mc_mad_w_new->SetLineColor(kOrange);
  h1_nvtx_mc_mad_w->SetLineColor(kBlue);
  h1_nvtx_mc_mad->SetLineColor(kRed);
  
  h1_nvtx_mc_mad_w->Scale(h1_nvtx_data_all->Integral()/h1_nvtx_mc_mad_w->Integral());
  h1_nvtx_mc_mad_w_new->Scale(h1_nvtx_data_all->Integral()/h1_nvtx_mc_mad_w_new->Integral());
  h1_nvtx_mc_mad->Scale(h1_nvtx_data_all->Integral()/h1_nvtx_mc_mad->Integral());
  h1_nvtx_mc_mad_w->Draw("hist");
  h1_nvtx_mc_mad_w->GetXaxis()->SetTitle("nPV");
  h1_nvtx_mc_mad->Draw("histsame");
  h1_nvtx_mc_mad_w_new->Draw("histsame");
  h1_nvtx_data_all->Draw("pesame");
  legend1->Draw("same");
  c->SaveAs("~/www/Tnp-2017-012918/PU_2017_NVTX.png");

  c->SetLogy();
  c->SaveAs("~/www/Tnp-2017-012918/PU_2017_NVTX_LOGY.png");




  
}




double getPUweight(int npu){
  
  double weight=1;
  if(npu== 0) weight=0.000290519; 
  if(npu== 1) weight=0.0426723; 
  if(npu== 2) weight=0.0538389; 
  if(npu== 3) weight=0.0618043; 
  if(npu== 4) weight=0.0706721; 
  if(npu== 5) weight=0.10739; 
  if(npu== 6) weight=0.117541; 
  if(npu== 7) weight=0.157374; 
  if(npu== 8) weight=0.113807; 
  if(npu== 9) weight=0.375898; 
  if(npu== 10) weight=0.489549; 
  if(npu== 11) weight=0.638777; 
  if(npu== 12) weight=0.674733; 
  if(npu== 13) weight=0.6911; 
  if(npu== 14) weight=0.71833; 
  if(npu== 15) weight=0.79244; 
  if(npu== 16) weight=0.886634; 
  if(npu== 17) weight=0.985348; 
  if(npu== 18) weight=1.06373; 
  if(npu== 19) weight=1.12014; 
  if(npu== 20) weight=1.17759; 
  if(npu== 21) weight=1.22413; 
  if(npu== 22) weight=1.27543; 
  if(npu== 23) weight=1.31065; 
  if(npu== 24) weight=1.31197; 
  if(npu== 25) weight=1.32909; 
  if(npu== 26) weight=1.32662; 
  if(npu== 27) weight=1.33397; 
  if(npu== 28) weight=1.34961; 
  if(npu== 29) weight=1.33725; 
  if(npu== 30) weight=1.30888; 
  if(npu== 31) weight=1.25283; 
  if(npu== 32) weight=1.18327; 
  if(npu== 33) weight=1.12254; 
  if(npu== 34) weight=1.05132; 
  if(npu== 35) weight=0.986593; 
  if(npu== 36) weight=0.947691; 
  if(npu== 37) weight=0.90616; 
  if(npu== 38) weight=0.854766; 
  if(npu== 39) weight=0.821432; 
  if(npu== 40) weight=0.822173; 
  if(npu== 41) weight=0.87463; 
  if(npu== 42) weight=0.953544; 
  if(npu== 43) weight=1.07717; 
  if(npu== 44) weight=1.23485; 
  if(npu== 45) weight=1.40911; 
  if(npu== 46) weight=1.57351; 
  if(npu== 47) weight=1.62395; 
  if(npu== 48) weight=1.64713; 
  if(npu== 49) weight=1.56322; 
  if(npu== 50) weight=1.35788; 
  if(npu== 51) weight=1.17681; 
  if(npu== 52) weight=0.958381; 
  if(npu== 53) weight=0.743467; 
  if(npu== 54) weight=0.56131; 
  if(npu== 55) weight=0.398767; 
  if(npu== 56) weight=0.28608; 
  if(npu== 57) weight=0.203759; 
  if(npu== 58) weight=0.146431; 
  if(npu== 59) weight=0.107066; 
  if(npu== 60) weight=0.0825301; 
  if(npu== 61) weight=0.0676224; 
  if(npu== 62) weight=0.0586444; 
  if(npu== 63) weight=0.0524112; 
  if(npu== 64) weight=0.0507798; 
  if(npu== 65) weight=0.0458278; 
  if(npu== 66) weight=0.0424304; 
  if(npu== 67) weight=0.0443636; 
  if(npu== 68) weight=0.0530278; 
  if(npu== 69) weight=0.0594876; 
  if(npu== 70) weight=0.0674961; 
  if(npu== 71) weight=0.0650366; 
  if(npu== 72) weight=0.0749932; 
  if(npu== 73) weight=0.0829989; 
  if(npu== 74) weight=0.0506497; 
  if(npu== 75) weight=0.0687934; 
  if(npu== 76) weight=0.0484804; 
  if(npu== 77) weight=0.0464887; 
  if(npu== 78) weight=0.0256093; 
  if(npu== 79) weight=0.0167982; 
  if(npu== 80) weight=0.00903542; 
  if(npu== 81) weight=0.0121093; 
  if(npu== 82) weight=0.0136211; 
  if(npu== 83) weight=0.0044012; 
  if(npu== 84) weight=0.00476258; 
  if(npu== 85) weight=0.00298744; 
  if(npu== 86) weight=0.0047395; 
  if(npu== 87) weight=0.00125339; 
  if(npu== 88) weight=0.000863082; 
  if(npu== 89) weight=0.000640387; 
  if(npu== 90) weight=0.00151275; 
  if(npu== 91) weight=0.00120526; 
  if(npu== 92) weight=0.00153402; 
  if(npu== 93) weight=0.00046018; 
  if(npu== 94) weight=0.000167228; 
  if(npu== 95) weight=4.18485e-05; 
  if(npu== 96) weight=0.00010091; 
  if(npu== 97) weight=9.68945e-05; 
  if(npu== 98) weight=3.03309e-05; 
  if(npu== 99) weight=1.63608e-05; 

  /* 

 if(npu ==0) weight = 0.000319471;
  if(npu ==1) weight = 0.043333;
  if(npu ==2) weight = 0.0627865;
  if(npu ==3) weight = 0.0647238;
  if(npu ==4) weight = 0.0780242;
  if(npu ==5) weight = 0.108199;
  if(npu ==6) weight = 0.111983;
  if(npu ==7) weight = 0.148095;
  if(npu ==8) weight = 0.112399;
  if(npu ==9) weight = 0.381801;
  if(npu ==10) weight = 0.494781;
  if(npu ==11) weight = 0.647735;
  if(npu ==12) weight = 0.674107;
  if(npu ==13) weight = 0.687767;
  if(npu ==14) weight = 0.723788;
  if(npu ==15) weight = 0.784618;
  if(npu ==16) weight = 0.898843;
  if(npu ==17) weight = 0.979519;
  if(npu ==18) weight = 1.0633;
  if(npu ==19) weight = 1.11899;
  if(npu ==20) weight = 1.16819;
  if(npu ==21) weight = 1.22006;
  if(npu ==22) weight = 1.27549;
  if(npu ==23) weight = 1.30905;
  if(npu ==24) weight = 1.31339;
  if(npu ==25) weight = 1.32447;
  if(npu ==26) weight = 1.31354;
  if(npu ==27) weight = 1.32983;
  if(npu ==28) weight = 1.34375;
  if(npu ==29) weight = 1.33185;
  if(npu ==30) weight = 1.29874;
  if(npu ==31) weight = 1.24632;
  if(npu ==32) weight = 1.18278;
  if(npu ==33) weight = 1.11995;
  if(npu ==34) weight = 1.04354;
  if(npu ==35) weight = 0.988411;
  if(npu ==36) weight = 0.944833;
  if(npu ==37) weight = 0.896181;
  if(npu ==38) weight = 0.851375;
  if(npu ==39) weight = 0.820549;
  if(npu ==40) weight = 0.820257;
  if(npu ==41) weight = 0.877121;
  if(npu ==42) weight = 0.9505;
  if(npu ==43) weight = 1.06921;
  if(npu ==44) weight = 1.23497;
  if(npu ==45) weight = 1.41449;
  if(npu ==46) weight = 1.57161;
  if(npu ==47) weight = 1.62378;
  if(npu ==48) weight = 1.64322;
  if(npu ==49) weight = 1.5508;
  if(npu ==50) weight = 1.37578;
  if(npu ==51) weight = 1.1718;
  if(npu ==52) weight = 0.953895;
  if(npu ==53) weight = 0.744876;
  if(npu ==54) weight = 0.558862;
  if(npu ==55) weight = 0.394524;
  if(npu ==56) weight = 0.285334;
  if(npu ==57) weight = 0.20402;
  if(npu ==58) weight = 0.146289;
  if(npu ==59) weight = 0.107565;
  if(npu ==60) weight = 0.0833341;
  if(npu ==61) weight = 0.0678563;
  if(npu ==62) weight = 0.0583878;
  if(npu ==63) weight = 0.0521837;
  if(npu ==64) weight = 0.0511854;
  if(npu ==65) weight = 0.0457683;
  if(npu ==66) weight = 0.042717;
  if(npu ==67) weight = 0.0450134;
  if(npu ==68) weight = 0.0516682;
  if(npu ==69) weight = 0.0609794;
  if(npu ==70) weight = 0.0681131;
  if(npu ==71) weight = 0.0769145;
  if(npu ==72) weight = 0.068758;
  if(npu ==73) weight = 0.082488;
  if(npu ==74) weight = 0.0519442;
  if(npu ==75) weight = 0.0923373;
  if(npu ==76) weight = 0.0581781;
  if(npu ==77) weight = 0.0534347;
  if(npu ==78) weight = 0.031191;
  if(npu ==79) weight = 0.0244144;
  if(npu ==80) weight = 0.00726572;
  if(npu ==81) weight = 0.0146515;
  if(npu ==82) weight = 0.0141407;
  if(npu ==83) weight = 0.00517426;
  if(npu ==84) weight = 0.00389476;
  if(npu ==85) weight = 0.00262877;
  if(npu ==86) weight = 0.00503468;
  if(npu ==87) weight = 0.000850185;
  if(npu ==88) weight = 0.000801798;
  if(npu ==89) weight = 0.000572691;
  if(npu ==90) weight = 0.00170316;
  if(npu ==91) weight = 0.000746922;
  if(npu ==92) weight = 0.000965814;
  if(npu ==93) weight = 0.00091529;
  if(npu ==94) weight = 9.42116e-05;
  if(npu ==95) weight = 6.22164e-05;
  if(npu ==96) weight = 8.96588e-05;
  if(npu ==97) weight = 4.89178e-05;
  if(npu ==98) weight = 7.75365e-05;
  if(npu ==99) weight = 1.57862e-05;
  */
  return weight;

}
