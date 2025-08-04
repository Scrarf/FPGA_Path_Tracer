// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFP21_add__Syms.h"


void VFP21_add___024root__trace_chg_0_sub_0(VFP21_add___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VFP21_add___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root__trace_chg_0\n"); );
    // Init
    VFP21_add___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFP21_add___024root*>(voidSelf);
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VFP21_add___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VFP21_add___024root__trace_chg_0_sub_0(VFP21_add___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root__trace_chg_0_sub_0\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgSData(oldp+0,(vlSelfRef.FP21_add__DOT__exp_norm_a),9);
        bufp->chgSData(oldp+1,(vlSelfRef.FP21_add__DOT__exp_norm_b),9);
        bufp->chgBit(oldp+2,(vlSelfRef.FP21_add__DOT__needs_swap));
        bufp->chgBit(oldp+3,(vlSelfRef.FP21_add__DOT__sign_dl_a));
        bufp->chgBit(oldp+4,(vlSelfRef.FP21_add__DOT__sign_dl_b));
        bufp->chgSData(oldp+5,(vlSelfRef.FP21_add__DOT__frac_dl_a),12);
        bufp->chgSData(oldp+6,(vlSelfRef.FP21_add__DOT__frac_dl_b),12);
        bufp->chgSData(oldp+7,(vlSelfRef.FP21_add__DOT__exp_diff),9);
        bufp->chgSData(oldp+8,(vlSelfRef.FP21_add__DOT__exp_norm_swap_a),9);
        bufp->chgSData(oldp+9,(vlSelfRef.FP21_add__DOT__exp_norm_swap_b),9);
        bufp->chgBit(oldp+10,(vlSelfRef.FP21_add__DOT__sign_swap_a));
        bufp->chgBit(oldp+11,(vlSelfRef.FP21_add__DOT__sign_swap_b));
        bufp->chgSData(oldp+12,(vlSelfRef.FP21_add__DOT__frac_swap_a),12);
        bufp->chgSData(oldp+13,(vlSelfRef.FP21_add__DOT__frac_swap_b),12);
        bufp->chgSData(oldp+14,(vlSelfRef.FP21_add__DOT__frac_norm_a),12);
    }
    bufp->chgBit(oldp+15,(vlSelfRef.sign_a));
    bufp->chgBit(oldp+16,(vlSelfRef.sign_b));
    bufp->chgSData(oldp+17,(vlSelfRef.frac_a),12);
    bufp->chgSData(oldp+18,(vlSelfRef.frac_b),12);
    bufp->chgCData(oldp+19,(vlSelfRef.exp_a),8);
    bufp->chgCData(oldp+20,(vlSelfRef.exp_b),8);
    bufp->chgBit(oldp+21,(vlSelfRef.clk));
}

void VFP21_add___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root__trace_cleanup\n"); );
    // Init
    VFP21_add___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFP21_add___024root*>(voidSelf);
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
