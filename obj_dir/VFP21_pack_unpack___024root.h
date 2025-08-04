// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VFP21_pack_unpack.h for the primary calling header

#ifndef VERILATED_VFP21_PACK_UNPACK___024ROOT_H_
#define VERILATED_VFP21_PACK_UNPACK___024ROOT_H_  // guard

#include "verilated.h"


class VFP21_pack_unpack__Syms;

class alignas(VL_CACHE_LINE_BYTES) VFP21_pack_unpack___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(FP21_pack__02Esign,0,0);
    VL_OUT8(FP21_unpack__02Esign,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    VL_IN16(FP21_pack__02Eexp,8,0);
    VL_IN16(FP21_pack__02Efrac,12,0);
    VL_OUT16(FP21_unpack__02Eexp,8,0);
    VL_OUT16(FP21_unpack__02Efrac,12,0);
    VL_OUT(FP21_out,20,0);
    VL_IN(FP21_in,20,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    VFP21_pack_unpack__Syms* const vlSymsp;

    // CONSTRUCTORS
    VFP21_pack_unpack___024root(VFP21_pack_unpack__Syms* symsp, const char* v__name);
    ~VFP21_pack_unpack___024root();
    VL_UNCOPYABLE(VFP21_pack_unpack___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
