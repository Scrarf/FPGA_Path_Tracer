// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFP21_pack_unpack.h for the primary calling header

#include "VFP21_pack_unpack__pch.h"
#include "VFP21_pack_unpack___024root.h"

void VFP21_pack_unpack___024root___ico_sequent__TOP__0(VFP21_pack_unpack___024root* vlSelf);

void VFP21_pack_unpack___024root___eval_ico(VFP21_pack_unpack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack_unpack___024root___eval_ico\n"); );
    VFP21_pack_unpack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VFP21_pack_unpack___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VFP21_pack_unpack___024root___ico_sequent__TOP__0(VFP21_pack_unpack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack_unpack___024root___ico_sequent__TOP__0\n"); );
    VFP21_pack_unpack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.FP21_unpack__02Esign = (1U & (vlSelfRef.FP21_in 
                                            >> 0x14U));
    vlSelfRef.FP21_unpack__02Eexp = (0x1ffU & ((0xffU 
                                                & (vlSelfRef.FP21_in 
                                                   >> 0xcU)) 
                                               - (IData)(0x7fU)));
    vlSelfRef.FP21_unpack__02Efrac = (0x1000U | (0xfffU 
                                                 & vlSelfRef.FP21_in));
    vlSelfRef.FP21_out = (((IData)(vlSelfRef.FP21_pack__02Esign) 
                           << 0x14U) | ((0xff000U & 
                                         (((IData)(0x7fU) 
                                           + (IData)(vlSelfRef.FP21_pack__02Eexp)) 
                                          << 0xcU)) 
                                        | (0xfffU & (IData)(vlSelfRef.FP21_pack__02Efrac))));
}

void VFP21_pack_unpack___024root___eval_triggers__ico(VFP21_pack_unpack___024root* vlSelf);

bool VFP21_pack_unpack___024root___eval_phase__ico(VFP21_pack_unpack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack_unpack___024root___eval_phase__ico\n"); );
    VFP21_pack_unpack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VFP21_pack_unpack___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        VFP21_pack_unpack___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VFP21_pack_unpack___024root___eval_act(VFP21_pack_unpack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack_unpack___024root___eval_act\n"); );
    VFP21_pack_unpack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VFP21_pack_unpack___024root___eval_nba(VFP21_pack_unpack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack_unpack___024root___eval_nba\n"); );
    VFP21_pack_unpack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VFP21_pack_unpack___024root___eval_triggers__act(VFP21_pack_unpack___024root* vlSelf);

bool VFP21_pack_unpack___024root___eval_phase__act(VFP21_pack_unpack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack_unpack___024root___eval_phase__act\n"); );
    VFP21_pack_unpack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VFP21_pack_unpack___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VFP21_pack_unpack___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VFP21_pack_unpack___024root___eval_phase__nba(VFP21_pack_unpack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack_unpack___024root___eval_phase__nba\n"); );
    VFP21_pack_unpack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VFP21_pack_unpack___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VFP21_pack_unpack___024root___dump_triggers__ico(VFP21_pack_unpack___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VFP21_pack_unpack___024root___dump_triggers__nba(VFP21_pack_unpack___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VFP21_pack_unpack___024root___dump_triggers__act(VFP21_pack_unpack___024root* vlSelf);
#endif  // VL_DEBUG

void VFP21_pack_unpack___024root___eval(VFP21_pack_unpack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack_unpack___024root___eval\n"); );
    VFP21_pack_unpack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            VFP21_pack_unpack___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("FP21_cores/FP21_pack_unpack.v", 4, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VFP21_pack_unpack___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VFP21_pack_unpack___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("FP21_cores/FP21_pack_unpack.v", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VFP21_pack_unpack___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("FP21_cores/FP21_pack_unpack.v", 4, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VFP21_pack_unpack___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VFP21_pack_unpack___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VFP21_pack_unpack___024root___eval_debug_assertions(VFP21_pack_unpack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack_unpack___024root___eval_debug_assertions\n"); );
    VFP21_pack_unpack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.FP21_pack__02Esign 
                      & 0xfeU)))) {
        Verilated::overWidthError("FP21_pack.sign");}
    if (VL_UNLIKELY(((vlSelfRef.FP21_pack__02Eexp & 0xfe00U)))) {
        Verilated::overWidthError("FP21_pack.exp");}
    if (VL_UNLIKELY(((vlSelfRef.FP21_pack__02Efrac 
                      & 0xe000U)))) {
        Verilated::overWidthError("FP21_pack.frac");}
    if (VL_UNLIKELY(((vlSelfRef.FP21_in & 0xffe00000U)))) {
        Verilated::overWidthError("FP21_in");}
}
#endif  // VL_DEBUG
