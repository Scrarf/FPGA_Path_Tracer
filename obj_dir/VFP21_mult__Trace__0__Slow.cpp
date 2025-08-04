// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFP21_mult__Syms.h"


VL_ATTR_COLD void VFP21_mult___024root__trace_init_sub__TOP__0(VFP21_mult___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root__trace_init_sub__TOP__0\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+17,0,"sign_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"sign_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"frac_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+20,0,"frac_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+21,0,"exp_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+22,0,"exp_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+23,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"sign_c_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"frac_c_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+26,0,"exp_c_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->popPrefix();
    tracep->pushPrefix("FP21_mult", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+17,0,"sign_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"sign_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"frac_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+20,0,"frac_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+21,0,"exp_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+22,0,"exp_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+23,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"sign_c_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"frac_c_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+26,0,"exp_c_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+1,0,"sign_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"exp_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+3,0,"prod",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+4,0,"shift_prod",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+5,0,"norm_exp_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+6,0,"norm_exp_c_dl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+7,0,"norm_exp_c_dl2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+8,0,"prod_trunk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+9,0,"prod_trunk_dl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+10,0,"guard",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"round",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"round_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"sign_c_dl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"sign_c_dl2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"sign_c_dl3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
}

VL_ATTR_COLD void VFP21_mult___024root__trace_init_top(VFP21_mult___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root__trace_init_top\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VFP21_mult___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VFP21_mult___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VFP21_mult___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VFP21_mult___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VFP21_mult___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VFP21_mult___024root__trace_register(VFP21_mult___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root__trace_register\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VFP21_mult___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VFP21_mult___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VFP21_mult___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VFP21_mult___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VFP21_mult___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root__trace_const_0\n"); );
    // Init
    VFP21_mult___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFP21_mult___024root*>(voidSelf);
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void VFP21_mult___024root__trace_full_0_sub_0(VFP21_mult___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VFP21_mult___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root__trace_full_0\n"); );
    // Init
    VFP21_mult___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFP21_mult___024root*>(voidSelf);
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VFP21_mult___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VFP21_mult___024root__trace_full_0_sub_0(VFP21_mult___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_mult___024root__trace_full_0_sub_0\n"); );
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.FP21_mult__DOT__sign_c));
    bufp->fullSData(oldp+2,(vlSelfRef.FP21_mult__DOT__exp_c),9);
    bufp->fullIData(oldp+3,(vlSelfRef.FP21_mult__DOT__prod),26);
    bufp->fullIData(oldp+4,(vlSelfRef.FP21_mult__DOT__shift_prod),25);
    bufp->fullSData(oldp+5,(vlSelfRef.FP21_mult__DOT__norm_exp_c),9);
    bufp->fullSData(oldp+6,(vlSelfRef.FP21_mult__DOT__norm_exp_c_dl),9);
    bufp->fullSData(oldp+7,(vlSelfRef.FP21_mult__DOT__norm_exp_c_dl2),9);
    bufp->fullSData(oldp+8,(vlSelfRef.FP21_mult__DOT__prod_trunk),13);
    bufp->fullSData(oldp+9,(vlSelfRef.FP21_mult__DOT__prod_trunk_dl),13);
    bufp->fullBit(oldp+10,(vlSelfRef.FP21_mult__DOT__guard));
    bufp->fullBit(oldp+11,(vlSelfRef.FP21_mult__DOT__round));
    bufp->fullBit(oldp+12,(vlSelfRef.FP21_mult__DOT__sticky));
    bufp->fullBit(oldp+13,(vlSelfRef.FP21_mult__DOT__round_up));
    bufp->fullBit(oldp+14,(vlSelfRef.FP21_mult__DOT__sign_c_dl));
    bufp->fullBit(oldp+15,(vlSelfRef.FP21_mult__DOT__sign_c_dl2));
    bufp->fullBit(oldp+16,(vlSelfRef.FP21_mult__DOT__sign_c_dl3));
    bufp->fullBit(oldp+17,(vlSelfRef.sign_a));
    bufp->fullBit(oldp+18,(vlSelfRef.sign_b));
    bufp->fullSData(oldp+19,(vlSelfRef.frac_a),13);
    bufp->fullSData(oldp+20,(vlSelfRef.frac_b),13);
    bufp->fullSData(oldp+21,(vlSelfRef.exp_a),9);
    bufp->fullSData(oldp+22,(vlSelfRef.exp_b),9);
    bufp->fullBit(oldp+23,(vlSelfRef.clk));
    bufp->fullBit(oldp+24,(vlSelfRef.sign_c_out));
    bufp->fullSData(oldp+25,(vlSelfRef.frac_c_out),13);
    bufp->fullSData(oldp+26,(vlSelfRef.exp_c_out),9);
}
