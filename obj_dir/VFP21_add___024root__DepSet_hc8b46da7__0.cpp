// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFP21_add.h for the primary calling header

#include "VFP21_add__pch.h"
#include "VFP21_add___024root.h"

void VFP21_add___024root___eval_act(VFP21_add___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root___eval_act\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VFP21_add___024root___nba_sequent__TOP__0(VFP21_add___024root* vlSelf);

void VFP21_add___024root___eval_nba(VFP21_add___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root___eval_nba\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VFP21_add___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void VFP21_add___024root___nba_sequent__TOP__0(VFP21_add___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root___nba_sequent__TOP__0\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.FP21_add__DOT__frac_norm_a = (0xfffU 
                                            & VL_SHIFTR_III(12,12,9, (IData)(vlSelfRef.frac_a), (IData)(vlSelfRef.FP21_add__DOT__exp_diff)));
    vlSelfRef.FP21_add__DOT__exp_diff = (0x1ffU & ((IData)(vlSelfRef.FP21_add__DOT__exp_norm_a) 
                                                   - (IData)(vlSelfRef.FP21_add__DOT__exp_norm_b)));
    if (vlSelfRef.FP21_add__DOT__needs_swap) {
        vlSelfRef.FP21_add__DOT__exp_norm_swap_a = vlSelfRef.FP21_add__DOT__exp_norm_b;
        vlSelfRef.FP21_add__DOT__exp_norm_swap_b = vlSelfRef.FP21_add__DOT__exp_norm_a;
        vlSelfRef.FP21_add__DOT__sign_swap_a = vlSelfRef.FP21_add__DOT__sign_dl_b;
        vlSelfRef.FP21_add__DOT__sign_swap_b = vlSelfRef.FP21_add__DOT__sign_dl_a;
        vlSelfRef.FP21_add__DOT__frac_swap_a = vlSelfRef.FP21_add__DOT__frac_dl_b;
        vlSelfRef.FP21_add__DOT__frac_swap_b = vlSelfRef.FP21_add__DOT__frac_dl_a;
    } else {
        vlSelfRef.FP21_add__DOT__exp_norm_swap_a = vlSelfRef.FP21_add__DOT__exp_norm_a;
        vlSelfRef.FP21_add__DOT__exp_norm_swap_b = vlSelfRef.FP21_add__DOT__exp_norm_b;
        vlSelfRef.FP21_add__DOT__sign_swap_a = vlSelfRef.FP21_add__DOT__sign_dl_a;
        vlSelfRef.FP21_add__DOT__sign_swap_b = vlSelfRef.FP21_add__DOT__sign_dl_b;
        vlSelfRef.FP21_add__DOT__frac_swap_a = vlSelfRef.FP21_add__DOT__frac_dl_a;
        vlSelfRef.FP21_add__DOT__frac_swap_b = vlSelfRef.FP21_add__DOT__frac_dl_b;
    }
    vlSelfRef.FP21_add__DOT__sign_dl_b = vlSelfRef.sign_b;
    vlSelfRef.FP21_add__DOT__sign_dl_a = vlSelfRef.sign_a;
    vlSelfRef.FP21_add__DOT__frac_dl_b = vlSelfRef.frac_b;
    vlSelfRef.FP21_add__DOT__exp_norm_a = (0x1ffU & 
                                           ((IData)(vlSelfRef.exp_a) 
                                            - (IData)(0x7fU)));
    vlSelfRef.FP21_add__DOT__exp_norm_b = (0x1ffU & 
                                           ((IData)(vlSelfRef.exp_b) 
                                            - (IData)(0x7fU)));
    vlSelfRef.FP21_add__DOT__frac_dl_a = vlSelfRef.frac_a;
    vlSelfRef.FP21_add__DOT__needs_swap = ((IData)(vlSelfRef.exp_a) 
                                           > (IData)(vlSelfRef.exp_b));
}

void VFP21_add___024root___eval_triggers__act(VFP21_add___024root* vlSelf);

bool VFP21_add___024root___eval_phase__act(VFP21_add___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root___eval_phase__act\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VFP21_add___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VFP21_add___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VFP21_add___024root___eval_phase__nba(VFP21_add___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root___eval_phase__nba\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VFP21_add___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VFP21_add___024root___dump_triggers__nba(VFP21_add___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VFP21_add___024root___dump_triggers__act(VFP21_add___024root* vlSelf);
#endif  // VL_DEBUG

void VFP21_add___024root___eval(VFP21_add___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root___eval\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            VFP21_add___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("FP21_cores/FP21_add.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VFP21_add___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("FP21_cores/FP21_add.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VFP21_add___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VFP21_add___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VFP21_add___024root___eval_debug_assertions(VFP21_add___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root___eval_debug_assertions\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.sign_a & 0xfeU)))) {
        Verilated::overWidthError("sign_a");}
    if (VL_UNLIKELY(((vlSelfRef.sign_b & 0xfeU)))) {
        Verilated::overWidthError("sign_b");}
    if (VL_UNLIKELY(((vlSelfRef.frac_a & 0xf000U)))) {
        Verilated::overWidthError("frac_a");}
    if (VL_UNLIKELY(((vlSelfRef.frac_b & 0xf000U)))) {
        Verilated::overWidthError("frac_b");}
}
#endif  // VL_DEBUG
