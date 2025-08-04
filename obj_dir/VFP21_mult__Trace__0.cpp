// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFP21_mult__Syms.h"


void VFP21_mult___024root__trace_chg_0_sub_0(VFP21_mult___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VFP21_mult___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root__trace_chg_0\n"); );
    // Init
    VFP21_mult___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFP21_mult___024root*>(voidSelf);
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VFP21_mult___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VFP21_mult___024root__trace_chg_0_sub_0(VFP21_mult___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root__trace_chg_0_sub_0\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.FP21_mult__DOT__sign_c));
        bufp->chgSData(oldp+1,(vlSelfRef.FP21_mult__DOT__exp_c),9);
        bufp->chgIData(oldp+2,(vlSelfRef.FP21_mult__DOT__prod),26);
        bufp->chgIData(oldp+3,(vlSelfRef.FP21_mult__DOT__shift_prod),25);
        bufp->chgSData(oldp+4,(vlSelfRef.FP21_mult__DOT__norm_exp_c),9);
        bufp->chgSData(oldp+5,(vlSelfRef.FP21_mult__DOT__norm_exp_c_dl),9);
        bufp->chgSData(oldp+6,(vlSelfRef.FP21_mult__DOT__norm_exp_c_dl2),9);
        bufp->chgSData(oldp+7,(vlSelfRef.FP21_mult__DOT__prod_trunk),13);
        bufp->chgSData(oldp+8,(vlSelfRef.FP21_mult__DOT__prod_trunk_dl),13);
        bufp->chgBit(oldp+9,(vlSelfRef.FP21_mult__DOT__guard));
        bufp->chgBit(oldp+10,(vlSelfRef.FP21_mult__DOT__round));
        bufp->chgBit(oldp+11,(vlSelfRef.FP21_mult__DOT__sticky));
        bufp->chgBit(oldp+12,(vlSelfRef.FP21_mult__DOT__round_up));
        bufp->chgBit(oldp+13,(vlSelfRef.FP21_mult__DOT__sign_c_dl));
        bufp->chgBit(oldp+14,(vlSelfRef.FP21_mult__DOT__sign_c_dl2));
        bufp->chgBit(oldp+15,(vlSelfRef.FP21_mult__DOT__sign_c_dl3));
    }
    bufp->chgBit(oldp+16,(vlSelfRef.sign_a));
    bufp->chgBit(oldp+17,(vlSelfRef.sign_b));
    bufp->chgSData(oldp+18,(vlSelfRef.frac_a),13);
    bufp->chgSData(oldp+19,(vlSelfRef.frac_b),13);
    bufp->chgSData(oldp+20,(vlSelfRef.exp_a),9);
    bufp->chgSData(oldp+21,(vlSelfRef.exp_b),9);
    bufp->chgBit(oldp+22,(vlSelfRef.clk));
    bufp->chgBit(oldp+23,(vlSelfRef.sign_c_out));
    bufp->chgSData(oldp+24,(vlSelfRef.frac_c_out),13);
    bufp->chgSData(oldp+25,(vlSelfRef.exp_c_out),9);
}

void VFP21_mult___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root__trace_cleanup\n"); );
    // Init
    VFP21_mult___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFP21_mult___024root*>(voidSelf);
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
