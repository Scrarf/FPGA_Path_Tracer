// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFP21_add__Syms.h"


VL_ATTR_COLD void VFP21_add___024root__trace_init_sub__TOP__0(VFP21_add___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root__trace_init_sub__TOP__0\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+16,0,"sign_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"sign_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"frac_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+19,0,"frac_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+20,0,"exp_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+21,0,"exp_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+22,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("FP21_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+16,0,"sign_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"sign_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"frac_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+19,0,"frac_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+20,0,"exp_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+21,0,"exp_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+22,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"exp_norm_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+2,0,"exp_norm_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+3,0,"needs_swap",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"sign_dl_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"sign_dl_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"frac_dl_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+7,0,"frac_dl_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+8,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+9,0,"exp_norm_swap_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+10,0,"exp_norm_swap_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+11,0,"sign_swap_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"sign_swap_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"frac_swap_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+14,0,"frac_swap_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+15,0,"frac_norm_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void VFP21_add___024root__trace_init_top(VFP21_add___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root__trace_init_top\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VFP21_add___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VFP21_add___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VFP21_add___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VFP21_add___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VFP21_add___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VFP21_add___024root__trace_register(VFP21_add___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root__trace_register\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VFP21_add___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VFP21_add___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VFP21_add___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VFP21_add___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VFP21_add___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root__trace_const_0\n"); );
    // Init
    VFP21_add___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFP21_add___024root*>(voidSelf);
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void VFP21_add___024root__trace_full_0_sub_0(VFP21_add___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VFP21_add___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root__trace_full_0\n"); );
    // Init
    VFP21_add___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFP21_add___024root*>(voidSelf);
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VFP21_add___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VFP21_add___024root__trace_full_0_sub_0(VFP21_add___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_add___024root__trace_full_0_sub_0\n"); );
    VFP21_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+1,(vlSelfRef.FP21_add__DOT__exp_norm_a),9);
    bufp->fullSData(oldp+2,(vlSelfRef.FP21_add__DOT__exp_norm_b),9);
    bufp->fullBit(oldp+3,(vlSelfRef.FP21_add__DOT__needs_swap));
    bufp->fullBit(oldp+4,(vlSelfRef.FP21_add__DOT__sign_dl_a));
    bufp->fullBit(oldp+5,(vlSelfRef.FP21_add__DOT__sign_dl_b));
    bufp->fullSData(oldp+6,(vlSelfRef.FP21_add__DOT__frac_dl_a),12);
    bufp->fullSData(oldp+7,(vlSelfRef.FP21_add__DOT__frac_dl_b),12);
    bufp->fullSData(oldp+8,(vlSelfRef.FP21_add__DOT__exp_diff),9);
    bufp->fullSData(oldp+9,(vlSelfRef.FP21_add__DOT__exp_norm_swap_a),9);
    bufp->fullSData(oldp+10,(vlSelfRef.FP21_add__DOT__exp_norm_swap_b),9);
    bufp->fullBit(oldp+11,(vlSelfRef.FP21_add__DOT__sign_swap_a));
    bufp->fullBit(oldp+12,(vlSelfRef.FP21_add__DOT__sign_swap_b));
    bufp->fullSData(oldp+13,(vlSelfRef.FP21_add__DOT__frac_swap_a),12);
    bufp->fullSData(oldp+14,(vlSelfRef.FP21_add__DOT__frac_swap_b),12);
    bufp->fullSData(oldp+15,(vlSelfRef.FP21_add__DOT__frac_norm_a),12);
    bufp->fullBit(oldp+16,(vlSelfRef.sign_a));
    bufp->fullBit(oldp+17,(vlSelfRef.sign_b));
    bufp->fullSData(oldp+18,(vlSelfRef.frac_a),12);
    bufp->fullSData(oldp+19,(vlSelfRef.frac_b),12);
    bufp->fullCData(oldp+20,(vlSelfRef.exp_a),8);
    bufp->fullCData(oldp+21,(vlSelfRef.exp_b),8);
    bufp->fullBit(oldp+22,(vlSelfRef.clk));
}
