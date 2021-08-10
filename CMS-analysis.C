#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TF1.h>
#include <TH1.h>
#include <TRandom.h>
#include <TClonesArray.h>
#include <Pythia8/Pythia.h>
#include <TStopwatch.h>
#include <TAxis.h>
#include <THnSparse.h>
#include <THashList.h>
#include <TString.h>
#include <TLorentzVector.h>
#include <TVector2.h>
#include <TRandom3.h>

#include "fastjet/config.h"
#include "fastjet/PseudoJet.hh"
#include "fastjet/JetDefinition.hh"
#include "fastjet/ClusterSequenceArea.hh"
#include "fastjet/AreaDefinition.hh"
#include "fastjet/tools/JetMedianBackgroundEstimator.hh"

#include "src/AliJCDijetHistos.h"
#include "src/AliJBaseTrack.h"
#include "src/AliJCard.h"
#include "src/AliJJet.h"
#include "src/AliJHistManager.h"
#include "src/JHistos.h"
#include "src/JTreeDataManager.h"

// Configuration for Toy MC track generation //
const double pi = TMath::Pi();

const char* inputpath = "/home/maxim/Documents/Työt/CMS-opendata/Data2JTree/outputs";

using namespace std;
using namespace Pythia8;
TFile* fOutput;

THnSparse* CreateTHnSparse(const char *name, const char *title, int ndim, const TAxis **axes, Option_t *opt) {
  //TString dirname(basename(name)), hname(histname(name));
  //THashList *parent(FindGroup(dirname));
  //if(!parent) parent = CreateHistoGroup(dirname);
  //if(parent->FindObject(hname)){
    //Fatal("THistManager::CreateTHnSparse", "Object %s already exists in group %s", hname.Data(), dirname.Data());
    //return 0;
  //}
  TArrayD xmin(ndim), xmax(ndim);
  TArrayI nbins(ndim);
  for(int idim = 0; idim < ndim; ++idim){
    const TAxis &myaxis = *(axes[idim]);
    nbins[idim] = myaxis.GetNbins();
    xmin[idim] = myaxis.GetXmin();
    xmax[idim] = myaxis.GetXmax();
  }
  THnSparseD *hsparse = new THnSparseD(name, title, ndim, nbins.GetArray(), xmin.GetArray(), xmax.GetArray());
  for(int id = 0; id < ndim; ++id)
    *(hsparse->GetAxis(id)) = *(axes[id]);
  TString optionstring(opt);
  optionstring.ToLower();
  if(optionstring.Contains("s"))
    hsparse->Sumw2();
  //parent->Add(hsparse);
  return hsparse;
}



THnSparse * CreateTHnSparse(TString name
    , TString title, Int_t ndim, std::vector<TAxis> bins, Option_t * opt){
  const TAxis * axises[bins.size()];
  for( UInt_t i=0;i<bins.size();i++ ) axises[i]= &bins[i];
  auto h= CreateTHnSparse(name, title, ndim, axises,opt );
  return h;
}

THnSparse * CreateTHnSparse(TString name
    , TString title, TString templ, Option_t * opt){
  auto o = fOutput->FindObject(templ);
  if( !o ) {
    cout<<"ERROR: no "<<templ<<endl;
    exit(1);
  }
  auto ht = dynamic_cast<THnSparse*>( o );
  const TAxis * axises[ht->GetNdimensions()];
  for( int i=0;i<ht->GetNdimensions();i++ ) axises[i]= ht->GetAxis(i);
  auto h= CreateTHnSparse(name, title, ht->GetNdimensions(), axises,opt );
  return h;
}
Long64_t FillTHnSparse( THnSparse *h, std::vector<Double_t> x, Double_t w ){
  if( int(x.size()) != h->GetNdimensions() ){
    cout<<"ERROR : wrong sized of array while Fill "<<h->GetName()<<endl;
    exit(1);
  }
  return h->Fill( &x.front(), w );
}

Long64_t FillTHnSparse( TString name, std::vector<Double_t> x, Double_t w ){
  auto hsparse = dynamic_cast<THnSparse*>( fOutput->FindObject(name) );
  if(! hsparse ){
    cout<<"ERROR : no "<<name<<endl;
    exit(1);
  }
  return FillTHnSparse( hsparse, x, w );
}

TAxis AxisFix
( TString name, int nbin, Double_t xmin, Double_t xmax ){
  TAxis axis(nbin, xmin, xmax);axis.SetName(name);
  return axis;
}

TAxis AxisStr( TString name, std::vector<TString> bin ){
  TAxis ax = AxisFix( name, bin.size(), 0.5, bin.size()+0.5);
  UInt_t i=1;
  for( auto blabel : bin )
    ax.SetBinLabel( i++, blabel );
  return ax;
}

TAxis AxisVar( TString name, std::vector<Double_t> bin ){
  TAxis axis( bin.size()-1, &bin.front() ) ;axis.SetName(name);
  return axis;
}

TAxis AxisLog
( TString name, int nbin, Double_t xmin, Double_t xmax, Double_t xmin0){
  int binoffset = ( xmin0<0 || (xmin-xmin0)<1e-9) ? 0 : 1;
  std::vector<Double_t> bin(nbin+1+binoffset,0);
  double logBW3 = (log(xmax)-log(xmin))/nbin;
  for(int ij=0;ij<=nbin;ij++) bin[ij+binoffset]=xmin*exp(ij*logBW3);
  TAxis axis( nbin, &bin.front() ) ;
  axis.SetName(name);
  return axis;
}

bool CheckEtaAcceptanceForMultiplicity( double eta, int IsCMS ){
 if( IsCMS ) return (fabs(eta)<2.4);
 else{
        return ( ( eta> 2.8 && eta< 5.1 ) ||
                 ( eta>-3.7 && eta<-1.7 ) );
 }
}

bool CheckPtAcceptanceForMultiplicity( double pt,  int IsCMS ){
 double MinPt = (bool)IsCMS ? 0.4 : 0.0;
 return pt>MinPt;
}

bool CheckPtAcceptance( double pt, int IsCMS ){
 double MinPt = (bool)IsCMS ? 0.1 : 0.2;
 return pt>MinPt;
}

bool CheckEtaAcceptance( double eta, int IsCMS ){
 double MaxEta = (bool)IsCMS ? 2.4 : 0.9;
 return fabs(eta)<MaxEta;
}

int main(int argc, char **argv) {

	//==== Read arguments =====
	// if ( argc<3 ) {
	// 	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	// 	cout<<"+  "<<argv[0]<<" [outputFile] [Seed] [init seed] [Nevt] [gAmp=3] [pT cut=2] [IsCMS=0] [String shoving=0]"<<endl;
	// 	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	// 	cout << endl << endl;
	// 	exit(1);
	// }

	char *outFile;
	outFile   = argv[1];
	char *inFile;
	inFile = argv[2];
	// int randomseed = atoi(argv[2]);
	// int seedoffset = atoi(argv[3]);
	// randomseed += seedoffset;
	// int Nevt = atoi(argv[4]);

	double gAmp = 3.0;
	double PtCut = 2.0;
	int IsCMS = 1;
	int IsStringShoving = 0;

	if( argc>5 ) gAmp = (double)(atof(argv[5]));
	if( argc>6 ) PtCut = (double)(atof(argv[6]));
	if( argc>7 ) IsCMS = atoi(argv[7]);
	if( argc>8 ) IsStringShoving = atoi(argv[8]);



	//---------------------
	//Pythia initialization
	//---------------------

	int test;
  //------------------------------------------------------------------
  // Define jet reconstruction
  //------------------------------------------------------------------
  TClonesArray *inputList = new TClonesArray("AliJBaseTrack",1500);

  double partMinPtCut         = 0.15;// atlas 0.5 cms/alice 0.15
//  double partMinEtaCut        = 1.2;
  double partMinEtaCut 	      = 0.8;
  double coneR                = 0.4; // atlas 0.6, cms 0.7 alice 0.4
  double ktconeR              = 0.4;
  double fusePionMassInktjets = false;
  double fuseDeltaPhiBGSubtr  = false;
  double jetConstituentCut    = 5.0;
  double dijetSubleadingPt    = 20.0;
  double dijetDeltaPhiCut     = 2.0; // Cut is pi/dijetDeltaPhiCut
  double jetEtaCut            = 0.25;
  int fktScheme               = 1;
  int doLeadingRef=0;

	// Read in commands from external file.
	//pythia.readFile(pythiaconfig);

	// Extract settings to be used in the main program.

	typedef std::vector<Double_t> Double1D;

        typedef std::vector<TLorentzVector*> TRACKS;
        typedef std::deque<TRACKS> EVENTPOOL ;
        typedef std::vector<EVENTPOOL> MIXINGPOOL;


				Double1D varmultbin = {0, 15, 35, 80, 105, 1500};

        Double1D ptbin = {0.1,0.5,1.0,1.5,2.0,2.5,3.0,4.0,6.0,14.0,100};

        Double1D ltpttrackbin = {0.2, 3.0, 4.0, 5.0, 6.0, 7.0, 9.0, 13.0, 20.0, 1e5};
        Double1D jetptbin = { 0, 10, 20, 30, 40, 50, 60, 80, 100, 1e5 };


	auto binCent = AxisVar("Cent", varmultbin);
//	auto binPhi = AxisFix("phi",32,-0.5*pi, 1.5*pi);
	auto binPhi = AxisFix("phi",32,-0.5*pi-pi/32.0, 1.5*pi-pi/32.0);
	auto binEta = AxisFix("eta",80,-4.0,4.0);

	auto binTPt = AxisVar("TPt",ptbin); //trig
	auto binAPt = AxisVar("APt",ptbin); //associatei

	auto binLtpt = AxisVar("LPPt",ltpttrackbin);
	auto binJetpT = AxisVar("JetPt",jetptbin);

	auto binNtrig = AxisFix("Ntrig",1,0.5,1.5);

	auto binPtTrack = AxisFix("PT",100,0,10);
        auto binPhiTrack = AxisFix("PHI",180,0,2*pi);
        auto binEtaTrack = AxisFix("ETA",80,-4,4);


        TH1D *hJetPt = new TH1D("hJetPt","Jet pT distribution",240,0,120);
        TH1D *hLHPt = new TH1D("hLHPt","Leading Hadron pT distribution",240,0,120);
        TH1D *hmulGeoV0M = new TH1D("hmulGeoV0M","Geo V0M mult",500,0,500) ;

        TH2D *hJetPt_mult = new TH2D("hJetPt_mult","hJetPt_mult",240,0,120,1000,0,1000);
        TH2D *hLHPt_mult = new TH2D("hLHPt_mult","hLHPt_mult",240,0,120,1000,0,1000);


	auto hSingleTrack = CreateTHnSparse("hSingleTrack","hSingleTrack",3,{binPtTrack,binPhiTrack,binEtaTrack},"s");

        auto hNtrig = CreateTHnSparse("hNtrig","hNtrig",4,{binCent,binTPt,binNtrig,binLtpt},"s"); 
        auto hNtrigJet = CreateTHnSparse("hNtrigJet","hNtrigJet",4,{binCent,binTPt,binNtrig,binJetpT},"s");

        auto hRidgeLT = CreateTHnSparse("hRidgeLT","RidgeLT",6,{binCent,binPhi,binEta,binTPt,binAPt,binLtpt},"s");
        auto hRidgeJet = CreateTHnSparse("hRidgeJet","RidgeJet",6,{binCent,binPhi,binEta,binTPt,binAPt,binJetpT},"s");

        auto hRidgeLTMixing = CreateTHnSparse("hRidgeLTMixing","RidgeLTMixing",6,{binCent,binPhi,binEta,binTPt,binAPt,binLtpt},"s");
        auto hRidgeJetMixing = CreateTHnSparse("hRidgeJetMixing","RidgeJetMixing",6,{binCent,binPhi,binEta,binTPt,binAPt,binJetpT},"s");




	TRACKS *tracks;

	MIXINGPOOL mixingpool;
	mixingpool.resize(binCent.GetNbins());	

	EVENTPOOL *eventpool;

	vector<fastjet::PseudoJet> chparticles;


	const double v0a_min_eta = 2.8;
	const double v0a_max_eta = 5.1;

	const double v0c_min_eta = -3.7;
	const double v0c_max_eta = -1.7;

	const double CMS_max_eta = 2.4;
	const double CMS_min_pt = 0.4; 
	const double CMS_min_pt_track = 0.1;

        const double ALICE_max_eta = 0.9;
        const double ALICE_min_pt = 0.2;



	double JetCone = 0.4;
        double const etaMaxCutForJet = partMinEtaCut-JetCone;
        double const MinJetPt = 5.0; // Min Jet Pt cut to disregard low pt jets
        double const ghost_maxrap = partMinEtaCut;
        unsigned int const repeat = 1; // default
        double const ghost_area   = 0.005; // ALICE=0.005 // default=0.01


	int centbin;
	double MaxPt;
	double MaxJetPt;


	TClonesArray *trackList = new TClonesArray("AliJBaseTrack", 10000);
	JTreeDataManager *dmg = new JTreeDataManager();

	JHistos *histos = new JHistos();
	histos->CreateQAHistos();
	AliJBaseEventHeader *eventHeader;

	dmg->ChainInputStream(inFile);


	int Nevt = dmg->GetNEvents();

	cout << "Number of events: " << Nevt << "\n\n" <<endl;

	int ieout = Nevt/20;
	int EventCounter = 0;

	if (ieout<1) ieout=1;

	TStopwatch timer;
	timer.Start();

	for(int ievt=0; ievt<Nevt; ievt++){
		// if (!pythia.next()) continue;
		// Particle generation ===========================================
		// check the multiploicity

		fastjet::PseudoJet fTrack;
		vector<fastjet::PseudoJet> jets;


		dmg->LoadEvent(ievt);
		eventHeader = dmg->GetEventHeader();


		if(!dmg->IsGoodEvent()) continue;

		MaxPt = 0.0;
		MaxJetPt = 0.0;

		trackList->Clear("C");

		dmg->RegisterList(trackList, NULL);
		inputList = trackList;
		int noAT = inputList->GetEntries();
		Double_t mulGeoV0M = 0;


		for(int i = 0; i < noAT; ++i) {//loop over all  particles in the event
			// Particle& p = pythia.event[i];
			// if( !p.isFinal() || !p.isCharged() ) continue;
			AliJBaseTrack *trk = (AliJBaseTrack*)inputList->At(i);

			if( CheckEtaAcceptanceForMultiplicity( trk->Eta(), IsCMS ) &&
			CheckPtAcceptanceForMultiplicity( trk->Pt(), IsCMS ) ) mulGeoV0M++;
			// Multiplicity

			if( CheckEtaAcceptance( trk->Eta(), IsCMS ) &&
			CheckPtAcceptance( trk->Pt(), IsCMS ) ) FillTHnSparse(hSingleTrack,{trk->Pt(),trk->Phi(),trk->Eta() }, 1.0 );
			// Single Track

			if( CheckEtaAcceptance( trk->Eta(), 1 ) && CheckPtAcceptance( trk->Pt(), 1 ) && MaxPt < trk->Pt() ) MaxPt = trk->Pt();

      if( true ){
              TLorentzVector lParticle(trk->Px(), trk->Py(), trk->Pz(), trk->E());
              AliJBaseTrack track( lParticle );
              track.SetID(trk->GetID());
              track.SetTrackEff(1.);
              new ((*inputList)[inputList->GetEntriesFast()]) AliJBaseTrack(track);
      }
		} //end for jet
		if (mulGeoV0M>varmultbin[5]) continue;
		hmulGeoV0M -> Fill (mulGeoV0M);

		chparticles.clear();

		for(int itrack = 0; itrack < inputList->GetEntries(); ++itrack){
			AliJBaseTrack *trk = (AliJBaseTrack*)inputList->At(itrack);
			if( trk->Pt() >partMinPtCut && fabs(trk->Eta()) < partMinEtaCut){
				fTrack = fastjet::PseudoJet(trk->Px(),trk->Py(),trk->Pz(),trk->E());
				fTrack.set_user_index(itrack);
				chparticles.push_back(fTrack);
			}
		}



		fastjet::GhostedAreaSpec const area_spec(ghost_maxrap, repeat, ghost_area);
		fastjet::AreaDefinition const area_def(fastjet::active_area, area_spec);
		fastjet::JetDefinition jet_def(fastjet::antikt_algorithm,JetCone,fastjet::pt_scheme);
		fastjet::ClusterSequenceArea cs(chparticles,jet_def,area_def);
		jets    = fastjet::sorted_by_pt(cs.inclusive_jets(MinJetPt)); // APPLY Min pt cut for jet

		for(int i=0;i<jets.size();i++){
			if( fabs( jets[i].eta() ) > 0.8 - JetCone ) continue;
			hJetPt->Fill( jets[i].pt() );
			hJetPt_mult->Fill( jets[i].pt(), mulGeoV0M );
			if( MaxJetPt < jets[i].pt() ) MaxJetPt = jets[i].pt();
		}



		centbin = binCent.FindBin(mulGeoV0M) -1;
		
		eventpool = &mixingpool.at(centbin);

		eventpool->push_back(TRACKS());
		tracks = &(eventpool->back());


		for(int i = 0; i < noAT; ++i){//loop over all the particles in the event
			// Particle& p = pythia.event[i];
			// if( !p.isFinal() || !p.isCharged() ) continue;
	AliJBaseTrack *trk1 = (AliJBaseTrack*)inputList->At(i);
			if( CheckEtaAcceptance( trk1->Eta(), IsCMS ) &&
			CheckPtAcceptance( trk1->Pt(), IsCMS ) ){
				FillTHnSparse(hNtrig,{mulGeoV0M,trk1->Pt(),1.0,MaxPt},1.0);
				FillTHnSparse(hNtrigJet,{mulGeoV0M,trk1->Pt(),1.0,MaxJetPt},1.0);
				tracks->push_back( new TLorentzVector(trk1->Px(),trk1->Py(),trk1->Pz(),trk1->E()) );
			}
		}

		hLHPt->Fill( MaxPt );
		hLHPt_mult->Fill( MaxPt, mulGeoV0M );


		if ( eventpool->size() > 6 ){
			for (auto it: eventpool->front()) delete it;
			eventpool->pop_front();
		}

		TRACKS alltracks;
		int nn =0;
		for (auto pool: *eventpool){
			if (nn > eventpool->size()-2 ) continue;
			for (auto trk1: pool) alltracks.push_back(trk1);
			nn++;
		}
	
//		for (int i = 0; i < pythia.event.size() -1 ; ++i) {//loop over particles
		for (int i = 0; i < noAT; ++i) {//loop over particles
			// Particle& p = pythia.event[i];
			// if( !p.isFinal() || !p.isCharged() ) continue;
			AliJBaseTrack *trk2 = (AliJBaseTrack*)inputList->At(i);

			if( !CheckEtaAcceptance( trk2->Eta(), IsCMS ) || !CheckPtAcceptance( trk2->Pt(), IsCMS ) ) continue;

			TLorentzVector P (trk2->Px(), trk2->Py(), trk2->Pz(), trk2->E());
			for (int j = 0; j < noAT  ; ++j) {//loop over particles
//			for (int j = i+1; j < pythia.event.size()  ; ++j) {//loop over particles
				AliJBaseTrack *trk3 = (AliJBaseTrack*)inputList->At(j);


				if( i==j ) continue;
				// Particle& q = pythia.event[j];
				// if( !q.isFinal() || !q.isCharged() ) continue;
				if( !CheckEtaAcceptance( trk3->Eta(), IsCMS ) || !CheckPtAcceptance( trk3->Pt(), IsCMS ) ) continue;

				TLorentzVector Q (trk3->Px(), trk3->Py(), trk3->Pz(), trk3->E());

				double deltaeta = P.Eta() - Q.Eta();
				double deltaphi = P.Phi() - Q.Phi();

				if( P.Pt() < Q.Pt()){ deltaeta *= -1.0; deltaphi *= -1.0;}
				deltaphi = TVector2::Phi_0_2pi(deltaphi);
				if( deltaphi > 1.5*pi-pi/32.0 ) deltaphi -= 2.0*pi;
				FillTHnSparse(hRidgeLT,{mulGeoV0M, deltaphi, deltaeta, P.Pt(), Q.Pt(),MaxPt}, 1.0 );
				FillTHnSparse(hRidgeJet,{mulGeoV0M, deltaphi, deltaeta, P.Pt(), Q.Pt(),MaxJetPt}, 1.0 );
			}
		}


		if (eventpool->size() == 6) {
			for (int i = 0; i < noAT  ; ++i) {//loop over particles
				// Particle& p = pythia.event[i];
				// if( !p.isFinal() || !p.isCharged() ) continue;

				AliJBaseTrack *trk4 = (AliJBaseTrack*)inputList->At(i);

				if( !CheckEtaAcceptance( trk4->Eta(), IsCMS ) || !CheckPtAcceptance( trk4->Pt(), IsCMS ) ) continue;
				
				TLorentzVector P (trk4->Px(), trk4->Py(), trk4->Pz(), trk4->E());
				for (auto Q :  alltracks ) {//loop over particles
					double deltaeta = P.Eta() - Q->Eta();
					double deltaphi = P.Phi() - Q->Phi();
					test+=1;
					
					if( P.Pt() < Q->Pt()){ deltaeta *= -1.0; deltaphi *= -1.0;}
					deltaphi = TVector2::Phi_0_2pi(deltaphi);
					if( deltaphi > 1.5*pi-pi/32.0 ) deltaphi -= 2.0*pi;
					FillTHnSparse(hRidgeLTMixing,{mulGeoV0M, deltaphi, deltaeta, P.Pt(), Q->Pt(),MaxPt}, 1.0 );
					FillTHnSparse(hRidgeJetMixing,{mulGeoV0M, deltaphi, deltaeta, P.Pt(), Q->Pt(),MaxJetPt}, 1.0 );
				}

			}
		}

		if(ievt % ieout == 0) cout <<"Events processed: " << ievt << ",\t" << int(round(float(ievt)/Nevt*100)) << "%" << endl;
	} // event loop done.


	fOutput = new TFile(outFile ,"recreate" );

	hSingleTrack->Write();

	hRidgeLT->Write();
	hRidgeLTMixing->Write();
	hNtrig->Write();

        hRidgeJet->Write();
	hRidgeJetMixing->Write();
        hNtrigJet->Write();

	hmulGeoV0M->Write();

	hJetPt->Write();
	hLHPt->Write();

	hJetPt_mult->Write();
	hLHPt_mult->Write();

	fOutput->Write();
	fOutput->Close();

	cout << "\nWrote to file: " << outFile <<"\n"<<endl;

	timer.Print();
}



