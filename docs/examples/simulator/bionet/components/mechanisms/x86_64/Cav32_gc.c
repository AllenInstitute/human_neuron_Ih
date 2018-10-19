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
 
#define nrn_init _nrn_init__Cav32
#define _nrn_initial _nrn_initial__Cav32
#define nrn_cur _nrn_cur__Cav32
#define _nrn_current _nrn_current__Cav32
#define nrn_jacob _nrn_jacob__Cav32
#define nrn_state _nrn_state__Cav32
#define _net_receive _net_receive__Cav32 
#define kin kin__Cav32 
#define rates rates__Cav32 
 
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
#define gbar _p[0]
#define g _p[1]
#define kc1c2 _p[2]
#define kc2c1 _p[3]
#define kc2c3 _p[4]
#define kc3c2 _p[5]
#define kc3o _p[6]
#define koc3 _p[7]
#define ki2i1 _p[8]
#define ki3i2 _p[9]
#define c1 _p[10]
#define c2 _p[11]
#define c3 _p[12]
#define i1 _p[13]
#define i2 _p[14]
#define i3 _p[15]
#define io _p[16]
#define o _p[17]
#define eca _p[18]
#define ica _p[19]
#define ki1i2 _p[20]
#define ki2i3 _p[21]
#define itca _p[22]
#define Dc1 _p[23]
#define Dc2 _p[24]
#define Dc3 _p[25]
#define Di1 _p[26]
#define Di2 _p[27]
#define Di3 _p[28]
#define Dio _p[29]
#define Do _p[30]
#define v _p[31]
#define _g _p[32]
#define _ion_eca	*_ppvar[0]._pval
#define _ion_ica	*_ppvar[1]._pval
#define _ion_dicadv	*_ppvar[2]._pval
#define _ion_itca	*_ppvar[3]._pval
#define _ion_ditcadv	*_ppvar[4]._pval
 
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
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_alpha(void);
 static void _hoc_beta(void);
 static void _hoc_rates(void);
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
 "setdata_Cav32", _hoc_setdata,
 "alpha_Cav32", _hoc_alpha,
 "beta_Cav32", _hoc_beta,
 "rates_Cav32", _hoc_rates,
 0, 0
};
#define alpha alpha_Cav32
#define beta beta_Cav32
 extern double alpha( _threadargsprotocomma_ double , double , double , double );
 extern double beta( _threadargsprotocomma_ double , double , double , double );
 /* declare global and static user variables */
#define kic3 kic3_Cav32
 double kic3 = 8e-05;
#define kci3 kci3_Cav32
 double kci3 = 0.058;
#define kic2 kic2_Cav32
 double kic2 = 0.0007;
#define kci2 kci2_Cav32
 double kci2 = 0.0034;
#define kic kic_Cav32
 double kic = 0.0002;
#define kci kci_Cav32
 double kci = 0.0006;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "kci_Cav32", "/ms",
 "kic_Cav32", "/ms",
 "kci2_Cav32", "/ms",
 "kic2_Cav32", "/ms",
 "kci3_Cav32", "/ms",
 "kic3_Cav32", "/ms",
 "gbar_Cav32", "S/cm2",
 "g_Cav32", "S/cm2",
 "kc1c2_Cav32", "/ms",
 "kc2c1_Cav32", "/ms",
 "kc2c3_Cav32", "/ms",
 "kc3c2_Cav32", "/ms",
 "kc3o_Cav32", "/ms",
 "koc3_Cav32", "/ms",
 "ki2i1_Cav32", "/ms",
 "ki3i2_Cav32", "/ms",
 0,0
};
 static double c30 = 0;
 static double c20 = 0;
 static double c10 = 0;
 static double delta_t = 0.01;
 static double io0 = 0;
 static double i30 = 0;
 static double i20 = 0;
 static double i10 = 0;
 static double o0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "kci_Cav32", &kci_Cav32,
 "kic_Cav32", &kic_Cav32,
 "kci2_Cav32", &kci2_Cav32,
 "kic2_Cav32", &kic2_Cav32,
 "kci3_Cav32", &kci3_Cav32,
 "kic3_Cav32", &kic3_Cav32,
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
 
#define _cvode_ieq _ppvar[5]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.5.0",
"Cav32",
 "gbar_Cav32",
 0,
 "g_Cav32",
 "kc1c2_Cav32",
 "kc2c1_Cav32",
 "kc2c3_Cav32",
 "kc3c2_Cav32",
 "kc3o_Cav32",
 "koc3_Cav32",
 "ki2i1_Cav32",
 "ki3i2_Cav32",
 0,
 "c1_Cav32",
 "c2_Cav32",
 "c3_Cav32",
 "i1_Cav32",
 "i2_Cav32",
 "i3_Cav32",
 "io_Cav32",
 "o_Cav32",
 0,
 0};
 static Symbol* _ca_sym;
 static Symbol* _tca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 33, _prop);
 	/*initialize range parameters*/
 	gbar = 2.2e-05;
 	_prop->param = _p;
 	_prop->param_size = 33;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 6, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* eca */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 prop_ion = need_memb(_tca_sym);
 	_ppvar[3]._pval = &prop_ion->param[3]; /* itca */
 	_ppvar[4]._pval = &prop_ion->param[4]; /* _ion_ditcadv */
 
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

 void _Cav32_gc_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", -10000.);
 	ion_reg("tca", 0.0);
 	_ca_sym = hoc_lookup("ca_ion");
 	_tca_sym = hoc_lookup("tca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 3);
  _extcall_thread = (Datum*)ecalloc(2, sizeof(Datum));
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 33, 6);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "tca_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "tca_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Cav32 /Volumes/Brain&Co/SCIENCE/Projects/EPILEPSY_ALLEN/BIONET/bmtk-all-comp-record/docs/examples/simulator/bionet/components/mechanisms/x86_64/Cav32_gc.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double FARADAY = 96.485309;
 static double R = 8.31449871704;
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(_threadargsprotocomma_ double);
 extern double *_nrn_thread_getelm();
 
#define _MATELM1(_row,_col) *(_nrn_thread_getelm(_so, _row + 1, _col + 1))
 
#define _RHS1(_arg) _rhs[_arg+1]
  
#define _linmat1  1
 static int _spth1 = 1;
 static int _cvspth1 = 0;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[8], _dlist1[8]; static double *_temp1;
 static int kin();
 
static int kin (void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt)
 {int _reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=1;_i<8;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 rates ( _threadargscomma_ v ) ;
   /* ~ c1 <-> c2 ( kc1c2 , kc2c1 )*/
 f_flux =  kc1c2 * c1 ;
 b_flux =  kc2c1 * c2 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  kc1c2 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  kc2c1 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ c2 <-> c3 ( kc2c3 , kc3c2 )*/
 f_flux =  kc2c3 * c2 ;
 b_flux =  kc3c2 * c3 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  kc2c3 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  kc3c2 ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ c3 <-> o ( kc3o , koc3 )*/
 f_flux =  kc3o * c3 ;
 b_flux =  koc3 * o ;
 _RHS1( 1) -= (f_flux - b_flux);
 
 _term =  kc3o ;
 _MATELM1( 1 ,1)  += _term;
 _term =  koc3 ;
 _MATELM1( 1 ,0)  -= _term;
 /*REACTION*/
  /* ~ i1 <-> i2 ( ki1i2 , ki2i1 )*/
 f_flux =  ki1i2 * i1 ;
 b_flux =  ki2i1 * i2 ;
 _RHS1( 7) -= (f_flux - b_flux);
 _RHS1( 6) += (f_flux - b_flux);
 
 _term =  ki1i2 ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 6 ,7)  -= _term;
 _term =  ki2i1 ;
 _MATELM1( 7 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ i2 <-> i3 ( ki2i3 , ki3i2 )*/
 f_flux =  ki2i3 * i2 ;
 b_flux =  ki3i2 * i3 ;
 _RHS1( 6) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  ki2i3 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  ki3i2 ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ i3 <-> io ( kc3o , koc3 )*/
 f_flux =  kc3o * i3 ;
 b_flux =  koc3 * io ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  kc3o ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 4 ,5)  -= _term;
 _term =  koc3 ;
 _MATELM1( 5 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ i1 <-> c1 ( kic , kci )*/
 f_flux =  kic * i1 ;
 b_flux =  kci * c1 ;
 _RHS1( 7) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  kic ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 3 ,7)  -= _term;
 _term =  kci ;
 _MATELM1( 7 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ i2 <-> c2 ( kic2 , kci2 )*/
 f_flux =  kic2 * i2 ;
 b_flux =  kci2 * c2 ;
 _RHS1( 6) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  kic2 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 2 ,6)  -= _term;
 _term =  kci2 ;
 _MATELM1( 6 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ i3 <-> c3 ( kic3 , kci3 )*/
 f_flux =  kic3 * i3 ;
 b_flux =  kci3 * c3 ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  kic3 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 1 ,5)  -= _term;
 _term =  kci3 ;
 _MATELM1( 5 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ io <-> o ( kic3 , kci3 )*/
 f_flux =  kic3 * io ;
 b_flux =  kci3 * o ;
 _RHS1( 4) -= (f_flux - b_flux);
 
 _term =  kic3 ;
 _MATELM1( 4 ,4)  += _term;
 _term =  kci3 ;
 _MATELM1( 4 ,0)  -= _term;
 /*REACTION*/
   /* c1 + c2 + c3 + i1 + i2 + i3 + io + o = 1.0 */
 _RHS1(0) =  1.0;
 _MATELM1(0, 0) = 1;
 _RHS1(0) -= o ;
 _MATELM1(0, 4) = 1;
 _RHS1(0) -= io ;
 _MATELM1(0, 5) = 1;
 _RHS1(0) -= i3 ;
 _MATELM1(0, 6) = 1;
 _RHS1(0) -= i2 ;
 _MATELM1(0, 7) = 1;
 _RHS1(0) -= i1 ;
 _MATELM1(0, 1) = 1;
 _RHS1(0) -= c3 ;
 _MATELM1(0, 2) = 1;
 _RHS1(0) -= c2 ;
 _MATELM1(0, 3) = 1;
 _RHS1(0) -= c1 ;
 /*CONSERVATION*/
   } return _reset;
 }
 
static int  rates ( _threadargsprotocomma_ double _lv ) {
   kc1c2 = alpha ( _threadargscomma_ 1.6 , 0.72 , 1.82 , _lv ) ;
   kc2c1 = beta ( _threadargscomma_ 0.032 , 0.72 , 1.82 , _lv ) ;
   kc2c3 = alpha ( _threadargscomma_ 41.0 , 0.31 , 4.5 , _lv ) ;
   kc3c2 = beta ( _threadargscomma_ 0.027 , 0.31 , 4.5 , _lv ) ;
   kc3o = 0.42 ;
   koc3 = beta ( _threadargscomma_ 0.015 , 0.0 , 0.7 , _lv ) ;
   ki1i2 = alpha ( _threadargscomma_ 0.032 , 0.72 , 1.82 , _lv ) ;
   ki2i1 = beta ( _threadargscomma_ 0.0004 , 0.72 , 1.82 , _lv ) ;
   ki2i3 = alpha ( _threadargscomma_ 0.25 , 0.31 , 4.5 , _lv ) ;
   ki3i2 = beta ( _threadargscomma_ 0.0000011 , 0.31 , 4.5 , _lv ) ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rates ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double alpha ( _threadargsprotocomma_ double _lA , double _ld , double _lq , double _lv ) {
   double _lalpha;
 _lalpha = _lA * exp ( _ld * _lq * _lv * FARADAY / ( R * ( celsius + 273.15 ) ) ) ;
   
return _lalpha;
 }
 
static void _hoc_alpha(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alpha ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) , *getarg(4) );
 hoc_retpushx(_r);
}
 
double beta ( _threadargsprotocomma_ double _lA , double _ld , double _lq , double _lv ) {
   double _lbeta;
 _lbeta = _lA * exp ( - ( 1.0 - _ld ) * _lq * _lv * FARADAY / ( R * ( celsius + 273.15 ) ) ) ;
   
return _lbeta;
 }
 
static void _hoc_beta(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  beta ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) , *getarg(4) );
 hoc_retpushx(_r);
}
 
/*CVODE ode begin*/
 static int _ode_spec1(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<8;_i++) _p[_dlist1[_i]] = 0.0;}
 rates ( _threadargscomma_ v ) ;
 /* ~ c1 <-> c2 ( kc1c2 , kc2c1 )*/
 f_flux =  kc1c2 * c1 ;
 b_flux =  kc2c1 * c2 ;
 Dc1 -= (f_flux - b_flux);
 Dc2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c2 <-> c3 ( kc2c3 , kc3c2 )*/
 f_flux =  kc2c3 * c2 ;
 b_flux =  kc3c2 * c3 ;
 Dc2 -= (f_flux - b_flux);
 Dc3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c3 <-> o ( kc3o , koc3 )*/
 f_flux =  kc3o * c3 ;
 b_flux =  koc3 * o ;
 Dc3 -= (f_flux - b_flux);
 Do += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i1 <-> i2 ( ki1i2 , ki2i1 )*/
 f_flux =  ki1i2 * i1 ;
 b_flux =  ki2i1 * i2 ;
 Di1 -= (f_flux - b_flux);
 Di2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i2 <-> i3 ( ki2i3 , ki3i2 )*/
 f_flux =  ki2i3 * i2 ;
 b_flux =  ki3i2 * i3 ;
 Di2 -= (f_flux - b_flux);
 Di3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i3 <-> io ( kc3o , koc3 )*/
 f_flux =  kc3o * i3 ;
 b_flux =  koc3 * io ;
 Di3 -= (f_flux - b_flux);
 Dio += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i1 <-> c1 ( kic , kci )*/
 f_flux =  kic * i1 ;
 b_flux =  kci * c1 ;
 Di1 -= (f_flux - b_flux);
 Dc1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i2 <-> c2 ( kic2 , kci2 )*/
 f_flux =  kic2 * i2 ;
 b_flux =  kci2 * c2 ;
 Di2 -= (f_flux - b_flux);
 Dc2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i3 <-> c3 ( kic3 , kci3 )*/
 f_flux =  kic3 * i3 ;
 b_flux =  kci3 * c3 ;
 Di3 -= (f_flux - b_flux);
 Dc3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ io <-> o ( kic3 , kci3 )*/
 f_flux =  kic3 * io ;
 b_flux =  kci3 * o ;
 Dio -= (f_flux - b_flux);
 Do += (f_flux - b_flux);
 
 /*REACTION*/
   /* c1 + c2 + c3 + i1 + i2 + i3 + io + o = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1(void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<8;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 rates ( _threadargscomma_ v ) ;
 /* ~ c1 <-> c2 ( kc1c2 , kc2c1 )*/
 _term =  kc1c2 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  kc2c1 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ c2 <-> c3 ( kc2c3 , kc3c2 )*/
 _term =  kc2c3 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  kc3c2 ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ c3 <-> o ( kc3o , koc3 )*/
 _term =  kc3o ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 0 ,1)  -= _term;
 _term =  koc3 ;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ i1 <-> i2 ( ki1i2 , ki2i1 )*/
 _term =  ki1i2 ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 6 ,7)  -= _term;
 _term =  ki2i1 ;
 _MATELM1( 7 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ i2 <-> i3 ( ki2i3 , ki3i2 )*/
 _term =  ki2i3 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  ki3i2 ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ i3 <-> io ( kc3o , koc3 )*/
 _term =  kc3o ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 4 ,5)  -= _term;
 _term =  koc3 ;
 _MATELM1( 5 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ i1 <-> c1 ( kic , kci )*/
 _term =  kic ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 3 ,7)  -= _term;
 _term =  kci ;
 _MATELM1( 7 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ i2 <-> c2 ( kic2 , kci2 )*/
 _term =  kic2 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 2 ,6)  -= _term;
 _term =  kci2 ;
 _MATELM1( 6 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ i3 <-> c3 ( kic3 , kci3 )*/
 _term =  kic3 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 1 ,5)  -= _term;
 _term =  kci3 ;
 _MATELM1( 5 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ io <-> o ( kic3 , kci3 )*/
 _term =  kic3 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 0 ,4)  -= _term;
 _term =  kci3 ;
 _MATELM1( 4 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
   /* c1 + c2 + c3 + i1 + i2 + i3 + io + o = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 8;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  eca = _ion_eca;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
   }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 8; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse_thread(&_thread[_cvspth1]._pvoid, 8, _dlist1, _p, _ode_matsol1, _ppvar, _thread, _nt);
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
  eca = _ion_eca;
 _ode_matsol_instance1(_threadargs_);
 }}
 
static void _thread_cleanup(Datum* _thread) {
   _nrn_destroy_sparseobj_thread(_thread[_cvspth1]._pvoid);
   _nrn_destroy_sparseobj_thread(_thread[_spth1]._pvoid);
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 4);
   nrn_update_ion_pointer(_tca_sym, _ppvar, 3, 3);
   nrn_update_ion_pointer(_tca_sym, _ppvar, 4, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  c3 = c30;
  c2 = c20;
  c1 = c10;
  io = io0;
  i3 = i30;
  i2 = i20;
  i1 = i10;
  o = o0;
 {
    _ss_sparse_thread(&_thread[_spth1]._pvoid, 8, _slist1, _dlist1, _p, &t, dt, kin, _linmat1, _ppvar, _thread, _nt);
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 8; ++_i) {
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
  eca = _ion_eca;
 initmodel(_p, _ppvar, _thread, _nt);
  }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   g = gbar * o ;
   ica = g * ( v - eca ) ;
   itca = ica ;
   }
 _current += ica;
 _current += itca;

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
  eca = _ion_eca;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _ditca;
 double _dica;
  _dica = ica;
  _ditca = itca;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dicadv += (_dica - ica)/.001 ;
  _ion_ditcadv += (_ditca - itca)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ica += ica ;
  _ion_itca += itca ;
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
  eca = _ion_eca;
 {  sparse_thread(&_thread[_spth1]._pvoid, 8, _slist1, _dlist1, _p, &t, dt, kin, _linmat1, _ppvar, _thread, _nt);
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 8; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 }  }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(o) - _p;  _dlist1[0] = &(Do) - _p;
 _slist1[1] = &(c3) - _p;  _dlist1[1] = &(Dc3) - _p;
 _slist1[2] = &(c2) - _p;  _dlist1[2] = &(Dc2) - _p;
 _slist1[3] = &(c1) - _p;  _dlist1[3] = &(Dc1) - _p;
 _slist1[4] = &(io) - _p;  _dlist1[4] = &(Dio) - _p;
 _slist1[5] = &(i3) - _p;  _dlist1[5] = &(Di3) - _p;
 _slist1[6] = &(i2) - _p;  _dlist1[6] = &(Di2) - _p;
 _slist1[7] = &(i1) - _p;  _dlist1[7] = &(Di1) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
