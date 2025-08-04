// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFP21_pack.h for the primary calling header

#include "VFP21_pack__pch.h"
#include "VFP21_pack___024root.h"

VL_ATTR_COLD void VFP21_pack___024root___eval_static(VFP21_pack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root___eval_static\n"); );
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VFP21_pack___024root___eval_initial(VFP21_pack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root___eval_initial\n"); );
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VFP21_pack___024root___eval_final(VFP21_pack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root___eval_final\n"); );
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VFP21_pack___024root___dump_triggers__stl(VFP21_pack___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VFP21_pack___024root___eval_phase__stl(VFP21_pack___024root* vlSelf);

VL_ATTR_COLD void VFP21_pack___024root___eval_settle(VFP21_pack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root___eval_settle\n"); );
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VFP21_pack___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("FP21_cores/FP21_pack.v", 4, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VFP21_pack___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VFP21_pack___024root___dump_triggers__stl(VFP21_pack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root___dump_triggers__stl\n"); );
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void VFP21_pack___024root___ico_sequent__TOP__0(VFP21_pack___024root* vlSelf);

VL_ATTR_COLD void VFP21_pack___024root___eval_stl(VFP21_pack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root___eval_stl\n"); );
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VFP21_pack___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VFP21_pack___024root___eval_triggers__stl(VFP21_pack___024root* vlSelf);

VL_ATTR_COLD bool VFP21_pack___024root___eval_phase__stl(VFP21_pack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root___eval_phase__stl\n"); );
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VFP21_pack___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VFP21_pack___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VFP21_pack___024root___dump_triggers__ico(VFP21_pack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root___dump_triggers__ico\n"); );
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VFP21_pack___024root___dump_triggers__act(VFP21_pack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root___dump_triggers__act\n"); );
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VFP21_pack___024root___dump_triggers__nba(VFP21_pack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root___dump_triggers__nba\n"); );
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VFP21_pack___024root___ctor_var_reset(VFP21_pack___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root___ctor_var_reset\n"); );
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11405983793283811459ull);
    vlSelf->exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 17481336879453297663ull);
    vlSelf->frac = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 14603238086509860446ull);
    vlSelf->FP21_out = VL_SCOPED_RAND_RESET_I(21, __VscopeHash, 17991603732070329341ull);
}
