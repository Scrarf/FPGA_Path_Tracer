// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFP21_less_than.h for the primary calling header

#include "VFP21_less_than__pch.h"
#include "VFP21_less_than___024root.h"

VL_ATTR_COLD void VFP21_less_than___024root___eval_static(VFP21_less_than___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_less_than___024root___eval_static\n"); );
    VFP21_less_than__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void VFP21_less_than___024root___eval_initial(VFP21_less_than___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_less_than___024root___eval_initial\n"); );
    VFP21_less_than__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VFP21_less_than___024root___eval_final(VFP21_less_than___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_less_than___024root___eval_final\n"); );
    VFP21_less_than__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VFP21_less_than___024root___eval_settle(VFP21_less_than___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_less_than___024root___eval_settle\n"); );
    VFP21_less_than__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VFP21_less_than___024root___dump_triggers__act(VFP21_less_than___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_less_than___024root___dump_triggers__act\n"); );
    VFP21_less_than__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VFP21_less_than___024root___dump_triggers__nba(VFP21_less_than___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_less_than___024root___dump_triggers__nba\n"); );
    VFP21_less_than__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VFP21_less_than___024root___ctor_var_reset(VFP21_less_than___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_less_than___024root___ctor_var_reset\n"); );
    VFP21_less_than__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->sign_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2875868019146230608ull);
    vlSelf->exp_a = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 5706431221230547549ull);
    vlSelf->frac_a = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 8840225640659568960ull);
    vlSelf->sign_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6475962564470844071ull);
    vlSelf->exp_b = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 16434564124392783341ull);
    vlSelf->frac_b = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 13752795161662576600ull);
    vlSelf->result = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16664408842984530663ull);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
}
