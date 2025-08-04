// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFP21_pack__Syms.h"


VL_ATTR_COLD void VFP21_pack___024root__trace_init_sub__TOP__0(VFP21_pack___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root__trace_init_sub__TOP__0\n"); );
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"sign",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"exp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+3,0,"frac",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+4,0,"FP21_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->popPrefix();
    tracep->pushPrefix("FP21_pack", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"sign",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"exp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+3,0,"frac",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+4,0,"FP21_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void VFP21_pack___024root__trace_init_top(VFP21_pack___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root__trace_init_top\n"); );
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VFP21_pack___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VFP21_pack___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VFP21_pack___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VFP21_pack___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VFP21_pack___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VFP21_pack___024root__trace_register(VFP21_pack___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root__trace_register\n"); );
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VFP21_pack___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VFP21_pack___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VFP21_pack___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VFP21_pack___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VFP21_pack___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root__trace_const_0\n"); );
    // Init
    VFP21_pack___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFP21_pack___024root*>(voidSelf);
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void VFP21_pack___024root__trace_full_0_sub_0(VFP21_pack___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VFP21_pack___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root__trace_full_0\n"); );
    // Init
    VFP21_pack___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFP21_pack___024root*>(voidSelf);
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VFP21_pack___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VFP21_pack___024root__trace_full_0_sub_0(VFP21_pack___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFP21_pack___024root__trace_full_0_sub_0\n"); );
    VFP21_pack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.sign));
    bufp->fullSData(oldp+2,(vlSelfRef.exp),9);
    bufp->fullSData(oldp+3,(vlSelfRef.frac),13);
    bufp->fullIData(oldp+4,(vlSelfRef.FP21_out),21);
}
