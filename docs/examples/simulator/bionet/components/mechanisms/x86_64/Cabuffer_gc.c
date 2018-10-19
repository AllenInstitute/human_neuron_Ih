/* Created by Language version: 7.5.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
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
 
#define nrn_init _nrn_init__Cabuffer
#define _nrn_initial _nrn_initial__Cabuffer
#define nrn_cur _nrn_cur__Cabuffer
#define _nrn_current _nrn_current__Cabuffer
#define nrn_jacob _nrn_jacob__Cabuffer
#define nrn_state _nrn_state__Cabuffer
#define _net_receive _net_receive__Cabuffer 
#define state state__Cabuffer 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define tau _p[0]
#define brat _p[1]
#define ica _p[2]
#define VSR _p[3]
#define ncai _p[4]
#define inca _p[5]
#define lcai _p[6]
#define ilca _p[7]
#define tcai _p[8]
#define itca _p[9]
#define B _p[10]
#define cai _p[11]
#define Dcai _p[12]
#define cao _p[13]
#define Dcao _p[14]
#define _g _p[15]
#define _ion_ica	*_ppvar[0]._pval
#define _ion_cai	*_ppvar[1]._pval
#define _ion_cao	*_ppvar[2]._pval
#define _style_ca	*((int*)_ppvar[3]._pvoid)
#define _ion_inca	*_ppvar[4]._pval
#define _ion_ncai	*_ppvar[5]._pval
#define _style_nca	*((int*)_ppvar[6]._pvoid)
#define _ion_ilca	*_ppvar[7]._pval
#define _ion_lcai	*_ppvar[8]._pval
#define _style_lca	*((int*)_ppvar[9]._pvoid)
#define _ion_itca	*_ppvar[10]._pval
#define _ion_tcai	*_ppvar[11]._pval
#define _style_tca	*((int*)_ppvar[12]._pvoid)
#define diam	*_ppvar[13]._pval
 
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
 /* external NEURON variables */
 /* declaration of user functions */
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_Cabuffer", _hoc_setdata,
 0, 0
};
 /* declare global and static user variables */
#define Fa Fa_Cabuffer
 double Fa = 96485.3;
#define cai0 cai0_Cabuffer
 double cai0 = 4.8e-05;
#define cao0 cao0_Cabuffer
 double cao0 = 2;
#define depth depth_Cabuffer
 double depth = 0.05;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "depth_Cabuffer", "um",
 "cai0_Cabuffer", "mM",
 "cao0_Cabuffer", "mM",
 "Fa_Cabuffer", "coulomb",
 "tau_Cabuffer", "ms",
 0,0
};
 static double delta_t = 0.01;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "depth_Cabuffer", &depth_Cabuffer,
 "cai0_Cabuffer", &cai0_Cabuffer,
 "cao0_Cabuffer", &cao0_Cabuffer,
 "Fa_Cabuffer", &Fa_Cabuffer,
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
 
#define _cvode_ieq _ppvar[14]._i
 static void _ode_synonym(int, double**, Datum**);
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.5.0",
"Cabuffer",
 "tau_Cabuffer",
 "brat_Cabuffer",
 0,
 0,
 0,
 0};
 static Symbol* _morphology_sym;
 static Symbol* _ca_sym;
 static Symbol* _nca_sym;
 static Symbol* _lca_sym;
 static Symbol* _tca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 16, _prop);
 	/*initialize range parameters*/
 	tau = 240;
 	brat = 50;
 	_prop->param = _p;
 	_prop->param_size = 16;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 15, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_morphology_sym);
 	_ppvar[13]._pval = &prop_ion->param[0]; /* diam */
 prop_ion = need_memb(_ca_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_check_conc_write(_prop, prop_ion, 0);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[1]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[2]._pval = &prop_ion->param[2]; /* cao */
 	_ppvar[3]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for ca */
 prop_ion = need_memb(_nca_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[4]._pval = &prop_ion->param[3]; /* inca */
 	_ppvar[5]._pval = &prop_ion->param[1]; /* ncai */
 	_ppvar[6]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for nca */
 prop_ion = need_memb(_lca_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[7]._pval = &prop_ion->param[3]; /* ilca */
 	_ppvar[8]._pval = &prop_ion->param[1]; /* lcai */
 	_ppvar[9]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for lca */
 prop_ion = need_memb(_tca_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[10]._pval = &prop_ion->param[3]; /* itca */
 	_ppvar[11]._pval = &prop_ion->param[1]; /* tcai */
 	_ppvar[12]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for tca */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _Cabuffer_gc_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("ca", -10000.);
 	ion_reg("nca", 0.0);
 	ion_reg("lca", 0.0);
 	ion_reg("tca", 0.0);
 	_morphology_sym = hoc_lookup("morphology");
 	_ca_sym = hoc_lookup("ca_ion");
 	_nca_sym = hoc_lookup("nca_ion");
 	_lca_sym = hoc_lookup("lca_ion");
 	_tca_sym = hoc_lookup("tca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 16, 15);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "#ca_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "nca_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "nca_ion");
  hoc_register_dparam_semantics(_mechtype, 6, "#nca_ion");
  hoc_register_dparam_semantics(_mechtype, 7, "lca_ion");
  hoc_register_dparam_semantics(_mechtype, 8, "lca_ion");
  hoc_register_dparam_semantics(_mechtype, 9, "#lca_ion");
  hoc_register_dparam_semantics(_mechtype, 10, "tca_ion");
  hoc_register_dparam_semantics(_mechtype, 11, "tca_ion");
  hoc_register_dparam_semantics(_mechtype, 12, "#tca_ion");
  hoc_register_dparam_semantics(_mechtype, 14, "cvodeieq");
  hoc_register_dparam_semantics(_mechtype, 13, "diam");
 	nrn_writes_conc(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_synonym(_mechtype, _ode_synonym);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Cabuffer /Volumes/Brain&Co/SCIENCE/Projects/EPILEPSY_ALLEN/BIONET/bmtk-all-comp-record/docs/examples/simulator/bionet/components/mechanisms/x86_64/Cabuffer_gc.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[2], _dlist1[2];
 static int state(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   ncai = - inca * B ;
   lcai = - ilca * B ;
   tcai = - itca * B ;
   Dcai = - ica * B / brat - ( cai - cai0 ) / tau ;
   Dcao = 0.0 ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 ncai = - inca * B ;
 lcai = - ilca * B ;
 tcai = - itca * B ;
 Dcai = Dcai  / (1. - dt*( ( - ( ( 1.0 ) ) / tau ) )) ;
 Dcao = Dcao  / (1. - dt*( 0.0 )) ;
 return 0;
}
 /*END CVODE*/
 static int state () {_reset=0;
 {
   ncai = - inca * B ;
   lcai = - ilca * B ;
   tcai = - itca * B ;
    cai = cai + (1. - exp(dt*(( - ( ( 1.0 ) ) / tau ))))*(- ( ( ( - ica )*( B ) ) / brat - ( ( ( - cai0 ) ) ) / tau ) / ( ( - ( ( 1.0 ) ) / tau ) ) - cai) ;
    cao = cao - dt*(- ( 0.0 ) ) ;
   }
  return 0;
}
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ica = _ion_ica;
  cai = _ion_cai;
  cao = _ion_cao;
  cai = _ion_cai;
  cao = _ion_cao;
  inca = _ion_inca;
  ncai = _ion_ncai;
  ilca = _ion_ilca;
  lcai = _ion_lcai;
  itca = _ion_itca;
  tcai = _ion_tcai;
     _ode_spec1 ();
  _ion_cai = cai;
  _ion_cao = cao;
  _ion_ncai = ncai;
  _ion_lcai = lcai;
  _ion_tcai = tcai;
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 	_pv[0] = &(_ion_cai);
 	_pv[1] = &(_ion_cao);
 }
 static void _ode_synonym(int _cnt, double** _pp, Datum** _ppd) { 
 	int _i; 
	for (_i=0; _i < _cnt; ++_i) {_p = _pp[_i]; _ppvar = _ppd[_i];
 _ion_ncai =  - inca * B ;
 _ion_lcai =  - ilca * B ;
 _ion_tcai =  - itca * B ;
 }}
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 ();
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ica = _ion_ica;
  cai = _ion_cai;
  cao = _ion_cao;
  cai = _ion_cai;
  cao = _ion_cao;
  inca = _ion_inca;
  ncai = _ion_ncai;
  ilca = _ion_ilca;
  lcai = _ion_lcai;
  itca = _ion_itca;
  tcai = _ion_tcai;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 2);
   nrn_update_ion_pointer(_nca_sym, _ppvar, 4, 3);
   nrn_update_ion_pointer(_nca_sym, _ppvar, 5, 1);
   nrn_update_ion_pointer(_lca_sym, _ppvar, 7, 3);
   nrn_update_ion_pointer(_lca_sym, _ppvar, 8, 1);
   nrn_update_ion_pointer(_tca_sym, _ppvar, 10, 3);
   nrn_update_ion_pointer(_tca_sym, _ppvar, 11, 1);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
 {
   if ( 2.0 * depth >= diam ) {
     VSR = 0.25 * diam ;
     }
   else {
     VSR = depth * ( 1.0 - depth / diam ) ;
     }
   B = ( 1e4 ) / ( 2.0 * Fa * VSR ) ;
   cao0 = cao ;
   cai0 = cai ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
  ica = _ion_ica;
  cai = _ion_cai;
  cao = _ion_cao;
  cai = _ion_cai;
  cao = _ion_cao;
  inca = _ion_inca;
  ncai = _ion_ncai;
  ilca = _ion_ilca;
  lcai = _ion_lcai;
  itca = _ion_itca;
  tcai = _ion_tcai;
 initmodel();
  _ion_cai = cai;
  _ion_cao = cao;
  nrn_wrote_conc(_ca_sym, (&(_ion_cao)) - 2, _style_ca);
  _ion_ncai = ncai;
  nrn_wrote_conc(_nca_sym, (&(_ion_ncai)) - 1, _style_nca);
  _ion_lcai = lcai;
  nrn_wrote_conc(_lca_sym, (&(_ion_lcai)) - 1, _style_lca);
  _ion_tcai = tcai;
  nrn_wrote_conc(_tca_sym, (&(_ion_tcai)) - 1, _style_tca);
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{
} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
  ica = _ion_ica;
  cai = _ion_cai;
  cao = _ion_cao;
  cai = _ion_cai;
  cao = _ion_cao;
  inca = _ion_inca;
  ncai = _ion_ncai;
  ilca = _ion_ilca;
  lcai = _ion_lcai;
  itca = _ion_itca;
  tcai = _ion_tcai;
 { error =  state();
 if(error){fprintf(stderr,"at line 49 in file Cabuffer_gc.mod:\n	SOLVE state METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
 } {
   }
  _ion_cai = cai;
  _ion_cao = cao;
  _ion_ncai = ncai;
  _ion_lcai = lcai;
  _ion_tcai = tcai;
}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(cai) - _p;  _dlist1[0] = &(Dcai) - _p;
 _slist1[1] = &(cao) - _p;  _dlist1[1] = &(Dcao) - _p;
_first = 0;
}
