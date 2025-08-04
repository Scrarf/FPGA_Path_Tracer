// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFP21_mult.h for the primary calling header

#include "VFP21_mult__pch.h"
#include "VFP21_mult___024root.h"

void VFP21_mult___024root___eval_act(VFP21_mult___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root___eval_act\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VFP21_mult___024root___nba_sequent__TOP__0(VFP21_mult___024root* vlSelf);

void VFP21_mult___024root___eval_nba(VFP21_mult___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root___eval_nba\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VFP21_mult___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void VFP21_mult___024root___nba_sequent__TOP__0(VFP21_mult___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root___nba_sequent__TOP__0\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.sign_c_out = vlSelfRef.FP21_mult__DOT__sign_c_dl3;
    vlSelfRef.exp_c_out = vlSelfRef.FP21_mult__DOT__norm_exp_c_dl2;
    vlSelfRef.frac_c_out = (0x1fffU & ((IData)(vlSelfRef.FP21_mult__DOT__prod_trunk_dl) 
                                       + (IData)(vlSelfRef.FP21_mult__DOT__round_up)));
    vlSelfRef.FP21_mult__DOT__sign_c_dl3 = vlSelfRef.FP21_mult__DOT__sign_c_dl2;
    vlSelfRef.FP21_mult__DOT__norm_exp_c_dl2 = vlSelfRef.FP21_mult__DOT__norm_exp_c_dl;
    vlSelfRef.FP21_mult__DOT__prod_trunk_dl = vlSelfRef.FP21_mult__DOT__prod_trunk;
    vlSelfRef.FP21_mult__DOT__round_up = ((IData)(vlSelfRef.FP21_mult__DOT__guard) 
                                          & (((IData)(vlSelfRef.FP21_mult__DOT__round) 
                                              | (IData)(vlSelfRef.FP21_mult__DOT__sticky)) 
                                             | (IData)(vlSelfRef.FP21_mult__DOT__prod_trunk)));
    vlSelfRef.FP21_mult__DOT__sign_c_dl2 = vlSelfRef.FP21_mult__DOT__sign_c_dl;
    vlSelfRef.FP21_mult__DOT__norm_exp_c_dl = vlSelfRef.FP21_mult__DOT__norm_exp_c;
    vlSelfRef.FP21_mult__DOT__prod_trunk = (0x1fffU 
                                            & (vlSelfRef.FP21_mult__DOT__shift_prod 
                                               >> 0xcU));
    vlSelfRef.FP21_mult__DOT__guard = (1U & (vlSelfRef.FP21_mult__DOT__shift_prod 
                                             >> 0xbU));
    vlSelfRef.FP21_mult__DOT__round = (1U & (vlSelfRef.FP21_mult__DOT__shift_prod 
                                             >> 0xaU));
    vlSelfRef.FP21_mult__DOT__sticky = (0U != (0x3ffU 
                                               & vlSelfRef.FP21_mult__DOT__shift_prod));
    vlSelfRef.FP21_mult__DOT__sign_c_dl = vlSelfRef.FP21_mult__DOT__sign_c;
    vlSelfRef.FP21_mult__DOT__shift_prod = (0x3ffffffU 
                                            & (vlSelfRef.FP21_mult__DOT__prod 
                                               >> (1U 
                                                   & (vlSelfRef.FP21_mult__DOT__prod 
                                                      >> 0x19U))));
    vlSelfRef.FP21_mult__DOT__norm_exp_c = (0x1ffU 
                                            & ((IData)(vlSelfRef.FP21_mult__DOT__exp_c) 
                                               + (1U 
                                                  & (vlSelfRef.FP21_mult__DOT__prod 
                                                     >> 0x19U))));
    vlSelfRef.FP21_mult__DOT__sign_c = ((IData)(vlSelfRef.sign_a) 
                                        ^ (IData)(vlSelfRef.sign_b));
    vlSelfRef.FP21_mult__DOT__prod = (0x3ffffffU & 
                                      ((IData)(vlSelfRef.frac_a) 
                                       * (IData)(vlSelfRef.frac_b)));
    vlSelfRef.FP21_mult__DOT__exp_c = (0x1ffU & ((IData)(vlSelfRef.exp_a) 
                                                 + (IData)(vlSelfRef.exp_b)));
}

void VFP21_mult___024root___eval_triggers__act(VFP21_mult___024root* vlSelf);

bool VFP21_mult___024root___eval_phase__act(VFP21_mult___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root___eval_phase__act\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VFP21_mult___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VFP21_mult___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VFP21_mult___024root___eval_phase__nba(VFP21_mult___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root___eval_phase__nba\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VFP21_mult___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VFP21_mult___024root___dump_triggers__nba(VFP21_mult___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VFP21_mult___024root___dump_triggers__act(VFP21_mult___024root* vlSelf);
#endif  // VL_DEBUG

void VFP21_mult___024root___eval(VFP21_mult___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root___eval\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VFP21_mult___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("FP21_cores/FP21_mult.v", 9, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VFP21_mult___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("FP21_cores/FP21_mult.v", 9, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VFP21_mult___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VFP21_mult___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VFP21_mult___024root___eval_debug_assertions(VFP21_mult___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root___eval_debug_assertions\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.sign_a & 0xfeU)))) {
        Verilated::overWidthError("sign_a");}
    if (VL_UNLIKELY(((vlSelfRef.sign_b & 0xfeU)))) {
        Verilated::overWidthError("sign_b");}
    if (VL_UNLIKELY(((vlSelfRef.frac_a & 0xe000U)))) {
        Verilated::overWidthError("frac_a");}
    if (VL_UNLIKELY(((vlSelfRef.frac_b & 0xe000U)))) {
        Verilated::overWidthError("frac_b");}
    if (VL_UNLIKELY(((vlSelfRef.exp_a & 0xfe00U)))) {
        Verilated::overWidthError("exp_a");}
    if (VL_UNLIKELY(((vlSelfRef.exp_b & 0xfe00U)))) {
        Verilated::overWidthError("exp_b");}
}
#endif  // VL_DEBUG
