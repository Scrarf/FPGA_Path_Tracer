// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFP21_mult.h for the primary calling header

#include "VFP21_mult__pch.h"
#include "VFP21_mult___024root.h"

VL_ATTR_COLD void VFP21_mult___024root___eval_static(VFP21_mult___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root___eval_static\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void VFP21_mult___024root___eval_initial(VFP21_mult___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root___eval_initial\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VFP21_mult___024root___eval_final(VFP21_mult___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root___eval_final\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VFP21_mult___024root___eval_settle(VFP21_mult___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root___eval_settle\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VFP21_mult___024root___dump_triggers__act(VFP21_mult___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root___dump_triggers__act\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
VL_ATTR_COLD void VFP21_mult___024root___dump_triggers__nba(VFP21_mult___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root___dump_triggers__nba\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void VFP21_mult___024root___ctor_var_reset(VFP21_mult___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root___ctor_var_reset\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->sign_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2875868019146230608ull);
    vlSelf->sign_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6475962564470844071ull);
    vlSelf->frac_a = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 8840225640659568960ull);
    vlSelf->frac_b = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 13752795161662576600ull);
    vlSelf->exp_a = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 5706431221230547549ull);
    vlSelf->exp_b = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 16434564124392783341ull);
    vlSelf->sign_c_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4954284098569951287ull);
    vlSelf->frac_c_out = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 15105547024045243953ull);
    vlSelf->exp_c_out = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 12169620595640578657ull);
    vlSelf->FP21_mult__DOT__sign_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17317883369382310975ull);
    vlSelf->FP21_mult__DOT__exp_c = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 10720420438018960443ull);
    vlSelf->FP21_mult__DOT__prod = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 6392752877136160931ull);
    vlSelf->FP21_mult__DOT__shift_prod = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 13296019409718859816ull);
    vlSelf->FP21_mult__DOT__norm_exp_c = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 3441318310704040319ull);
    vlSelf->FP21_mult__DOT__norm_exp_c_dl = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 7587871901127916356ull);
    vlSelf->FP21_mult__DOT__norm_exp_c_dl2 = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 13934842983101594954ull);
    vlSelf->FP21_mult__DOT__prod_trunk = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 11059428220821134942ull);
    vlSelf->FP21_mult__DOT__prod_trunk_dl = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 11402091468736955137ull);
    vlSelf->FP21_mult__DOT__guard = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6301686397945041858ull);
    vlSelf->FP21_mult__DOT__round = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1418365500005890100ull);
    vlSelf->FP21_mult__DOT__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14395295605064553095ull);
    vlSelf->FP21_mult__DOT__round_up = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17996028430115338862ull);
    vlSelf->FP21_mult__DOT__sign_c_dl = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14437837377981381140ull);
    vlSelf->FP21_mult__DOT__sign_c_dl2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17965602721859407570ull);
    vlSelf->FP21_mult__DOT__sign_c_dl3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6481967327846289427ull);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
