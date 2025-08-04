// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VFP21_add.h for the primary calling header

#ifndef VERILATED_VFP21_ADD___024ROOT_H_
#define VERILATED_VFP21_ADD___024ROOT_H_  // guard

#include "verilated.h"


class VFP21_add__Syms;

class alignas(VL_CACHE_LINE_BYTES) VFP21_add___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(sign_a,0,0);
    VL_IN8(sign_b,0,0);
    VL_IN8(exp_a,7,0);
    VL_IN8(exp_b,7,0);
    CData/*0:0*/ FP21_add__DOT__needs_swap;
    CData/*0:0*/ FP21_add__DOT__sign_dl_a;
    CData/*0:0*/ FP21_add__DOT__sign_dl_b;
    CData/*0:0*/ FP21_add__DOT__sign_swap_a;
    CData/*0:0*/ FP21_add__DOT__sign_swap_b;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(frac_a,11,0);
    VL_IN16(frac_b,11,0);
    SData/*8:0*/ FP21_add__DOT__exp_norm_a;
    SData/*8:0*/ FP21_add__DOT__exp_norm_b;
    SData/*11:0*/ FP21_add__DOT__frac_dl_a;
    SData/*11:0*/ FP21_add__DOT__frac_dl_b;
    SData/*8:0*/ FP21_add__DOT__exp_diff;
    SData/*8:0*/ FP21_add__DOT__exp_norm_swap_a;
    SData/*8:0*/ FP21_add__DOT__exp_norm_swap_b;
    SData/*11:0*/ FP21_add__DOT__frac_swap_a;
    SData/*11:0*/ FP21_add__DOT__frac_swap_b;
    SData/*11:0*/ FP21_add__DOT__frac_norm_a;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VFP21_add__Syms* const vlSymsp;

    // CONSTRUCTORS
    VFP21_add___024root(VFP21_add__Syms* symsp, const char* v__name);
    ~VFP21_add___024root();
    VL_UNCOPYABLE(VFP21_add___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
