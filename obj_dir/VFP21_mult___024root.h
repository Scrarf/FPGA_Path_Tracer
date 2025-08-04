// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VFP21_mult.h for the primary calling header

#ifndef VERILATED_VFP21_MULT___024ROOT_H_
#define VERILATED_VFP21_MULT___024ROOT_H_  // guard

#include "verilated.h"


class VFP21_mult__Syms;

class alignas(VL_CACHE_LINE_BYTES) VFP21_mult___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(sign_a,0,0);
    VL_IN8(sign_b,0,0);
    VL_OUT8(sign_c_out,0,0);
    CData/*0:0*/ FP21_mult__DOT__sign_c;
    CData/*0:0*/ FP21_mult__DOT__guard;
    CData/*0:0*/ FP21_mult__DOT__round;
    CData/*0:0*/ FP21_mult__DOT__sticky;
    CData/*0:0*/ FP21_mult__DOT__round_up;
    CData/*0:0*/ FP21_mult__DOT__sign_c_dl;
    CData/*0:0*/ FP21_mult__DOT__sign_c_dl2;
    CData/*0:0*/ FP21_mult__DOT__sign_c_dl3;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(frac_a,12,0);
    VL_IN16(frac_b,12,0);
    VL_IN16(exp_a,8,0);
    VL_IN16(exp_b,8,0);
    VL_OUT16(frac_c_out,12,0);
    VL_OUT16(exp_c_out,8,0);
    SData/*8:0*/ FP21_mult__DOT__exp_c;
    SData/*8:0*/ FP21_mult__DOT__norm_exp_c;
    SData/*8:0*/ FP21_mult__DOT__norm_exp_c_dl;
    SData/*8:0*/ FP21_mult__DOT__norm_exp_c_dl2;
    SData/*12:0*/ FP21_mult__DOT__prod_trunk;
    SData/*12:0*/ FP21_mult__DOT__prod_trunk_dl;
    IData/*25:0*/ FP21_mult__DOT__prod;
    IData/*24:0*/ FP21_mult__DOT__shift_prod;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VFP21_mult__Syms* const vlSymsp;

    // CONSTRUCTORS
    VFP21_mult___024root(VFP21_mult__Syms* symsp, const char* v__name);
    ~VFP21_mult___024root();
    VL_UNCOPYABLE(VFP21_mult___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
