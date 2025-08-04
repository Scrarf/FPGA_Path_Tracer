// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VFP21_pack.h for the primary calling header

#ifndef VERILATED_VFP21_PACK___024ROOT_H_
#define VERILATED_VFP21_PACK___024ROOT_H_  // guard

#include "verilated.h"


class VFP21_pack__Syms;

class alignas(VL_CACHE_LINE_BYTES) VFP21_pack___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(sign,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    VL_IN16(exp,8,0);
    VL_IN16(frac,12,0);
    VL_OUT(FP21_out,20,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    VFP21_pack__Syms* const vlSymsp;

    // CONSTRUCTORS
    VFP21_pack___024root(VFP21_pack__Syms* symsp, const char* v__name);
    ~VFP21_pack___024root();
    VL_UNCOPYABLE(VFP21_pack___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
