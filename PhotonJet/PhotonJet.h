#ifndef __PHOTONJET_H__
#define __PHOTONJET_H__


#include <fun4all/SubsysReco.h>
#include <vector>

#include <TTree.h>
#include <TMath.h>
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>

class PHCompositeNode;
class RawClusterContainer;
class RawCluster;
class SvtxTrackMap;
class JetMap;
class JetEvalStack;
class JetRecoEval;
class SvtxTrackEval;
class PHG4TruthInfoContainer;
class PHHepMCGenEvent;
class PhotonJet: public SubsysReco
{

 public:
  
  PhotonJet(const std::string &name="photonjet.root");
  double isoconeradius,mincluspt;
  float jet_cone_size;
  int use_isocone;
  int Init(PHCompositeNode*);
  int process_event(PHCompositeNode*);
  int End(PHCompositeNode*);
  void Set_Isocone_radius(double rad){isoconeradius = rad;};
  void set_cluspt_mincut(double pt){mincluspt = pt;};
  void use_isocone_algorithm(int yes){use_isocone=yes;};//1 is use it, 0 is don't use it
  void set_jetcone_size(float size){jet_cone_size = size;}//float for jet cone size, i.e. 0.2,0.3,0.4, etc.




private:

  void Set_Tree_Branches();
 
  float ConeSum(RawCluster *cluster, RawClusterContainer *cluster_container, SvtxTrackMap *trackmap, float coneradius);
  void GetRecoHadronsAndJets(RawCluster *trig, SvtxTrackMap *tracks, JetMap *jets, JetRecoEval *recoeval, SvtxTrackEval *trackeval, PHG4TruthInfoContainer *alltruth);



  TFile *file;
  TTree *tree;
  TTree *cluster_tree;
  TTree *truth_g4particles;
  TTree *truthtree;
  TTree *isolated_clusters;
  TTree *tracktree;
  TTree *truthjettree;
  TTree *recojettree;
  TTree *isophot_jet_tree;
  TTree *isophot_had_tree;
  std::string outfilename;

  int nevents;
  TH1F *histo;

  //cluster info
  float clus_energy;
  float clus_eta;
  float clus_phi;
  float clus_pt;
  float clus_px;
  float clus_py;
  float clus_pz;
  float clus_theta;
  float clus_x,clus_y,clus_z,clus_t;

  //track info
  float tr_px,tr_py,tr_pz;
  float tr_p;
  float tr_pt;
  float tr_phi;
  float tr_eta;
  int charge;
  float chisq;
  unsigned int ndf;
  float dca;
  float tr_x,tr_y,tr_z;
  float truthtrackpx,truthtrackpy,truthtrackpz;
  float truthtrackp;
  float truthtracke;
  float truthtrackpt;
  float truthtrackphi;
  float truthtracketa;
  int truthtrackpid;
  bool truth_is_primary;

  //all truth jets
  float truthjetpt;
  float truthjetpx,truthjetpy,truthjetpz;
  float truthjetphi;
  float truthjeteta;
  float truthjetmass;
  float truthjetp;
  float truthjetenergy;

  //all reco jets
  float recojetpt;
  float recojetpx,recojetpy,recojetpz;
  float recojetphi;
  float recojeteta;
  float recojetmass;
  float recojetp;
  float recojetenergy;
  float recojetid;
  float truthjetid;

  //isophot+reco jet
  float _recojetid;
  float _recojetpt;
  float _recojetpx,_recojetpy,_recojetpz;
  float _recojetphi;
  float _recojeteta;
  float _recojetmass;
  float _recojetp;
  float _recojetenergy;
  float jetdphi;
  float jetpout;
  float jetdeta;
  float _truthjetid;
  float _truthjetpt;
  float _truthjetpx,_truthjetpy,_truthjetpz;
  float _truthjetphi;
  float _truthjeteta;
  float _truthjetmass;
  float _truthjetp;
  float _truthjetenergy;

  //isophot+reco hadron
  float _tr_px,_tr_py,_tr_pz;
  float _tr_p;
  float _tr_pt;
  float _tr_phi;
  float _tr_eta;
  int _charge;
  float _chisq;
  unsigned int _ndf;
  float _dca;
  float _tr_x,_tr_y,_tr_z;
  float haddphi;
  float hadpout;
  float haddeta;
  bool _truth_is_primary;
  float _truthtrackpx;
  float _truthtrackpy;
  float _truthtrackpz;
  float _truthtrackp;
  float _truthtracke;
  float _truthtrackpt;
  float _truthtrackphi;
  float _truthtracketa;
  int _truthtrackpid;


  //all truth particles
  float truthpx,truthpy,truthpz;
  float truthp;
  float truthphi;
  float trutheta;
  float truthpt;
  float truthenergy;
  int truthpid;
  int numparticlesinevent;
  int process_id;


  //clust truth variables
  float clustruthpx;
  float clustruthpy;
  float clustruthpz;
  float clustruthenergy;
  float clustruthpt;
  float clustruthphi;
  float clustrutheta;
  int clustruthpid;

  const float pi2 = -1.5707963;
  const float threepi2 = 4.71238898;
  const float pi = 3.1415926;

};

#endif // __PHOTONJET_H__
