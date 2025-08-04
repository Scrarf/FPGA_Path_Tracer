// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFP21_greater_than__Syms.h"


void VFP21_greater_than___024root__trace_chg_0_sub_0(VFP21_greater_than___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VFP21_greater_than___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_greater_than___024root__trace_chg_0\n"); );
    // Init
    VFP21_greater_than___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFP21_greater_than___024root*>(voidSelf);
    VFP21_greater_than__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VFP21_greater_than___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VFP21_greater_than___024root__trace_chg_0_sub_0(VFP21_greater_than___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_greater_than___024root__trace_chg_0_sub_0\n"); );
    VFP21_greater_than__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.sign_a));
    bufp->chgSData(oldp+2,(vlSelfRef.exp_a),9);
    bufp->chgSData(oldp+3,(vlSelfRef.frac_a),13);
    bufp->chgBit(oldp+4,(vlSelfRef.sign_b));
    bufp->chgSData(oldp+5,(vlSelfRef.exp_b),9);
    bufp->chgSData(oldp+6,(vlSelfRef.frac_b),13);
    bufp->chgBit(oldp+7,(vlSelfRef.result));
}

void VFP21_greater_than___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_greater_than___024root__trace_cleanup\n"); );
    // Init
    VFP21_greater_than___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFP21_greater_than___024root*>(voidSelf);
    VFP21_greater_than__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
