// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VFP21_greater_than.h for the primary calling header

#ifndef VERILATED_VFP21_GREATER_THAN___024ROOT_H_
#define VERILATED_VFP21_GREATER_THAN___024ROOT_H_  // guard

#include "verilated.h"


class VFP21_greater_than__Syms;

class alignas(VL_CACHE_LINE_BYTES) VFP21_greater_than___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(sign_a,0,0);
    VL_IN8(sign_b,0,0);
    VL_OUT8(result,0,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(exp_a,8,0);
    VL_IN16(frac_a,12,0);
    VL_IN16(exp_b,8,0);
    VL_IN16(frac_b,12,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VFP21_greater_than__Syms* const vlSymsp;

    // CONSTRUCTORS
    VFP21_greater_than___024root(VFP21_greater_than__Syms* symsp, const char* v__name);
    ~VFP21_greater_than___024root();
    VL_UNCOPYABLE(VFP21_greater_than___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
