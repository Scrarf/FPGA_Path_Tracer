// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFP21_add.h for the primary calling header

#include "VFP21_add__pch.h"
#include "VFP21_add___024root.h"

VL_ATTR_COLD void VFP21_add___024root___eval_static(VFP21_add___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root___eval_static\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void VFP21_add___024root___eval_initial(VFP21_add___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root___eval_initial\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VFP21_add___024root___eval_final(VFP21_add___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root___eval_final\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VFP21_add___024root___eval_settle(VFP21_add___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root___eval_settle\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VFP21_add___024root___dump_triggers__act(VFP21_add___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root___dump_triggers__act\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
VL_ATTR_COLD void VFP21_add___024root___dump_triggers__nba(VFP21_add___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root___dump_triggers__nba\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void VFP21_add___024root___ctor_var_reset(VFP21_add___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root___ctor_var_reset\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->sign_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2875868019146230608ull);
    vlSelf->sign_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6475962564470844071ull);
    vlSelf->frac_a = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 8840225640659568960ull);
    vlSelf->frac_b = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 13752795161662576600ull);
    vlSelf->exp_a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5706431221230547549ull);
    vlSelf->exp_b = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16434564124392783341ull);
    vlSelf->FP21_add__DOT__exp_norm_a = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 17606883771990459436ull);
    vlSelf->FP21_add__DOT__exp_norm_b = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 10965029441658745935ull);
    vlSelf->FP21_add__DOT__needs_swap = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13995916047320935034ull);
    vlSelf->FP21_add__DOT__sign_dl_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9931122125603450117ull);
    vlSelf->FP21_add__DOT__sign_dl_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10223977546997265310ull);
    vlSelf->FP21_add__DOT__frac_dl_a = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 6126617573404752816ull);
    vlSelf->FP21_add__DOT__frac_dl_b = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 16768239218979982943ull);
    vlSelf->FP21_add__DOT__exp_diff = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 17122258874984456980ull);
    vlSelf->FP21_add__DOT__exp_norm_swap_a = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 18043878628854850365ull);
    vlSelf->FP21_add__DOT__exp_norm_swap_b = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 17424739743385590969ull);
    vlSelf->FP21_add__DOT__sign_swap_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10423238856681371016ull);
    vlSelf->FP21_add__DOT__sign_swap_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12045552109013503852ull);
    vlSelf->FP21_add__DOT__frac_swap_a = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 4886134991487096045ull);
    vlSelf->FP21_add__DOT__frac_swap_b = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 12943815171639828632ull);
    vlSelf->FP21_add__DOT__frac_norm_a = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 17409333392077855533ull);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
