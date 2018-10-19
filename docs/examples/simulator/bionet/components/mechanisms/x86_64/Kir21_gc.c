/* Created by Language version: 7.5.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__Kir21
#define _nrn_initial _nrn_initial__Kir21
#define nrn_cur _nrn_cur__Kir21
#define _nrn_current _nrn_current__Kir21
#define nrn_jacob _nrn_jacob__Kir21
#define nrn_state _nrn_state__Kir21
#define _net_receive _net_receive__Kir21 
#define kin kin__Kir21 
#define rate rate__Kir21 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define gkbar _p[0]
#define ik _p[1]
#define gk _p[2]
#define O _p[3]
#define BS _p[4]
#define B1 _p[5]
#define B2 _p[6]
#define B3 _p[7]
#define BB _p[8]
#define DO _p[9]
#define DBS _p[10]
#define DB1 _p[11]
#define DB2 _p[12]
#define DB3 _p[13]
#define DBB _p[14]
#define ek _p[15]
#define alpha1 _p[16]
#define beta1 _p[17]
#define alphas _p[18]
#define betas _p[19]
#define alphas2 _p[20]
#define betas2 _p[21]
#define v _p[22]
#define _g _p[23]
#define _ion_ek	*_ppvar[0]._pval
#define _ion_ik	*_ppvar[1]._pval
#define _ion_dikdv	*_ppvar[2]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_rate(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_Kir21", _hoc_setdata,
 "rate_Kir21", _hoc_rate,
 0, 0
};
 /* declare global and static user variables */
#define As As_Kir21
 double As = 0.2;
#define b b_Kir21
 double b = 0.105;
#define cas cas_Kir21
 double cas = 0.142857;
#define fac fac_Kir21
 double fac = 0.005;
#define gsub gsub_Kir21
 double gsub = 0.25;
#define mg_i mg_i_Kir21
 double mg_i = 4;
#define spm_i spm_i_Kir21
 double spm_i = 1;
#define shiftmg shiftmg_Kir21
 double shiftmg = 0.5;
#define vshiftbs vshiftbs_Kir21
 double vshiftbs = 0;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "mg_i_Kir21", "mM",
 "spm_i_Kir21", "uM",
 "vshiftbs_Kir21", "mV",
 "gkbar_Kir21", "S/cm2",
 "ik_Kir21", "mA/cm2",
 "gk_Kir21", "S/cm2",
 0,0
};
 static double BB0 = 0;
 static double B30 = 0;
 static double B20 = 0;
 static double B10 = 0;
 static double BS0 = 0;
 static double O0 = 0;
 static double delta_t = 0.01;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "mg_i_Kir21", &mg_i_Kir21,
 "spm_i_Kir21", &spm_i_Kir21,
 "As_Kir21", &As_Kir21,
 "vshiftbs_Kir21", &vshiftbs_Kir21,
 "b_Kir21", &b_Kir21,
 "fac_Kir21", &fac_Kir21,
 "gsub_Kir21", &gsub_Kir21,
 "shiftmg_Kir21", &shiftmg_Kir21,
 "cas_Kir21", &cas_Kir21,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.5.0",
"Kir21",
 "gkbar_Kir21",
 0,
 "ik_Kir21",
 "gk_Kir21",
 0,
 "O_Kir21",
 "BS_Kir21",
 "B1_Kir21",
 "B2_Kir21",
 "B3_Kir21",
 "BB_Kir21",
 0,
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 24, _prop);
 	/*initialize range parameters*/
 	gkbar = 0.000353903;
 	_prop->param = _p;
 	_prop->param_size = 24;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _thread_cleanup(Datum*);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _Kir21_gc_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 3);
  _extcall_thread = (Datum*)ecalloc(2, sizeof(Datum));
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 24, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Kir21 /Volumes/Brain&Co/SCIENCE/Projects/EPILEPSY_ALLEN/BIONET/bmtk-all-comp-record/docs/examples/simulator/bionet/components/mechanisms/x86_64/Kir21_gc.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Kir potassium current";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rate(_threadargsprotocomma_ double);
 
#define _MATELM1(_row,_col) *(_nrn_thread_getelm(_so, _row + 1, _col + 1))
 
#define _RHS1(_arg) _rhs[_arg+1]
  static int _cvspth1 = 1;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 extern double *_nrn_thread_getelm();
 
#define _MATELM1(_row,_col) *(_nrn_thread_getelm(_so, _row + 1, _col + 1))
 
#define _RHS1(_arg) _rhs[_arg+1]
  
#define _linmat1  1
 static int _spth1 = 0;
 static int _slist1[6], _dlist1[6]; static double *_temp1;
 static int kin();
 
static int kin (void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt)
 {int _reset=0;
 {
   double _lalpha2 , _lalpha3 , _lbeta2 , _lbeta3 ;
 double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=1;_i<6;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 rate ( _threadargscomma_ v ) ;
   _lalpha2 = 2.0 * alpha1 ;
   _lbeta2 = 2.0 * beta1 ;
   _lalpha3 = 3.0 * alpha1 ;
   _lbeta3 = 3.0 * beta1 ;
   /* ~ BS <-> O ( alphas , betas )*/
 f_flux =  alphas * BS ;
 b_flux =  betas * O ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  alphas ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 5 ,4)  -= _term;
 _term =  betas ;
 _MATELM1( 4 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ B1 <-> O ( alpha1 , _lbeta3 )*/
 f_flux =  alpha1 * B1 ;
 b_flux =  _lbeta3 * O ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  alpha1 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 5 ,3)  -= _term;
 _term =  _lbeta3 ;
 _MATELM1( 3 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ B2 <-> B1 ( _lalpha2 , _lbeta2 )*/
 f_flux =  _lalpha2 * B2 ;
 b_flux =  _lbeta2 * B1 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  _lalpha2 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 3 ,2)  -= _term;
 _term =  _lbeta2 ;
 _MATELM1( 2 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ B3 <-> B2 ( _lalpha3 , beta1 )*/
 f_flux =  _lalpha3 * B3 ;
 b_flux =  beta1 * B2 ;
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  _lalpha3 ;
 _MATELM1( 2 ,0)  -= _term;
 _term =  beta1 ;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ BB <-> BS ( alphas2 , betas2 )*/
 f_flux =  alphas2 * BB ;
 b_flux =  betas2 * BS ;
 _RHS1( 1) -= (f_flux - b_flux);
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  alphas2 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 4 ,1)  -= _term;
 _term =  betas2 ;
 _MATELM1( 1 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
   /* O + BS + BB + B1 + B2 + B3 = 1.0 */
 _RHS1(0) =  1.0;
 _MATELM1(0, 0) = 1;
 _RHS1(0) -= B3 ;
 _MATELM1(0, 2) = 1;
 _RHS1(0) -= B2 ;
 _MATELM1(0, 3) = 1;
 _RHS1(0) -= B1 ;
 _MATELM1(0, 1) = 1;
 _RHS1(0) -= BB ;
 _MATELM1(0, 4) = 1;
 _RHS1(0) -= BS ;
 _MATELM1(0, 5) = 1;
 _RHS1(0) -= O ;
 /*CONSERVATION*/
   } return _reset;
 }
 
static int  rate ( _threadargsprotocomma_ double _lv ) {
   double _la , _ld ;
 alpha1 = 12.0 * exp ( - 0.025 * ( _lv - ( shiftmg * ( ek ) ) ) ) ;
   beta1 = mg_i / 8.0 * 28.0 * exp ( 0.025 * ( _lv - ( shiftmg * ( ek ) ) ) ) ;
   alphas = As * 0.17 * exp ( cas * - 0.07 * ( _lv - ( ek ) + 8.0 / 8.0 * mg_i ) ) ;
   betas = As * spm_i * 0.28 * exp ( 0.15 * ( _lv - ( ek ) + 8.0 / 8.0 * mg_i ) ) ;
   _la = - 1.0 / 9.1 + b ;
   alphas2 = fac * 40.0 * exp ( _la * ( _lv - ( ek + vshiftbs ) ) ) ;
   betas2 = spm_i * fac * exp ( b * ( _lv - ( ek + vshiftbs ) ) ) ;
    return 0; }
 
static void _hoc_rate(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rate ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
/*CVODE ode begin*/
 static int _ode_spec1(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double _lalpha2 , _lalpha3 , _lbeta2 , _lbeta3 ;
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<6;_i++) _p[_dlist1[_i]] = 0.0;}
 rate ( _threadargscomma_ v ) ;
 _lalpha2 = 2.0 * alpha1 ;
 _lbeta2 = 2.0 * beta1 ;
 _lalpha3 = 3.0 * alpha1 ;
 _lbeta3 = 3.0 * beta1 ;
 /* ~ BS <-> O ( alphas , betas )*/
 f_flux =  alphas * BS ;
 b_flux =  betas * O ;
 DBS -= (f_flux - b_flux);
 DO += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ B1 <-> O ( alpha1 , _lbeta3 )*/
 f_flux =  alpha1 * B1 ;
 b_flux =  _lbeta3 * O ;
 DB1 -= (f_flux - b_flux);
 DO += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ B2 <-> B1 ( _lalpha2 , _lbeta2 )*/
 f_flux =  _lalpha2 * B2 ;
 b_flux =  _lbeta2 * B1 ;
 DB2 -= (f_flux - b_flux);
 DB1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ B3 <-> B2 ( _lalpha3 , beta1 )*/
 f_flux =  _lalpha3 * B3 ;
 b_flux =  beta1 * B2 ;
 DB3 -= (f_flux - b_flux);
 DB2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ BB <-> BS ( alphas2 , betas2 )*/
 f_flux =  alphas2 * BB ;
 b_flux =  betas2 * BS ;
 DBB -= (f_flux - b_flux);
 DBS += (f_flux - b_flux);
 
 /*REACTION*/
   /* O + BS + BB + B1 + B2 + B3 = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1(void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double _lalpha2 , _lalpha3 , _lbeta2 , _lbeta3 ;
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<6;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 rate ( _threadargscomma_ v ) ;
 _lalpha2 = 2.0 * alpha1 ;
 _lbeta2 = 2.0 * beta1 ;
 _lalpha3 = 3.0 * alpha1 ;
 _lbeta3 = 3.0 * beta1 ;
 /* ~ BS <-> O ( alphas , betas )*/
 _term =  alphas ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 5 ,4)  -= _term;
 _term =  betas ;
 _MATELM1( 4 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ B1 <-> O ( alpha1 , _lbeta3 )*/
 _term =  alpha1 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 5 ,3)  -= _term;
 _term =  _lbeta3 ;
 _MATELM1( 3 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ B2 <-> B1 ( _lalpha2 , _lbeta2 )*/
 _term =  _lalpha2 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 3 ,2)  -= _term;
 _term =  _lbeta2 ;
 _MATELM1( 2 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ B3 <-> B2 ( _lalpha3 , beta1 )*/
 _term =  _lalpha3 ;
 _MATELM1( 0 ,0)  += _term;
 _MATELM1( 2 ,0)  -= _term;
 _term =  beta1 ;
 _MATELM1( 0 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ BB <-> BS ( alphas2 , betas2 )*/
 _term =  alphas2 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 4 ,1)  -= _term;
 _term =  betas2 ;
 _MATELM1( 1 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
   /* O + BS + BB + B1 + B2 + B3 = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 6;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 6; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse_thread(&_thread[_cvspth1]._pvoid, 6, _dlist1, _p, _ode_matsol1, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
 _ode_matsol_instance1(_threadargs_);
 }}
 
static void _thread_cleanup(Datum* _thread) {
   _nrn_destroy_sparseobj_thread(_thread[_spth1]._pvoid);
   _nrn_destroy_sparseobj_thread(_thread[_cvspth1]._pvoid);
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  BB = BB0;
  B3 = B30;
  B2 = B20;
  B1 = B10;
  BS = BS0;
  O = O0;
 {
   rate ( _threadargscomma_ v ) ;
    _ss_sparse_thread(&_thread[_spth1]._pvoid, 6, _slist1, _dlist1, _p, &t, dt, kin, _linmat1, _ppvar, _thread, _nt);
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 6; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  ek = _ion_ek;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   gk = ( gkbar ) * ( O + 1.0 / 3.0 * B2 + 2.0 / 3.0 * B1 ) + ( gkbar * gsub ) * BS ;
   ik = gk * ( v - ek ) ;
   }
 _current += ik;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  ek = _ion_ek;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  ek = _ion_ek;
 {  sparse_thread(&_thread[_spth1]._pvoid, 6, _slist1, _dlist1, _p, &t, dt, kin, _linmat1, _ppvar, _thread, _nt);
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 6; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(B3) - _p;  _dlist1[0] = &(DB3) - _p;
 _slist1[1] = &(BB) - _p;  _dlist1[1] = &(DBB) - _p;
 _slist1[2] = &(B2) - _p;  _dlist1[2] = &(DB2) - _p;
 _slist1[3] = &(B1) - _p;  _dlist1[3] = &(DB1) - _p;
 _slist1[4] = &(BS) - _p;  _dlist1[4] = &(DBS) - _p;
 _slist1[5] = &(O) - _p;  _dlist1[5] = &(DO) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
