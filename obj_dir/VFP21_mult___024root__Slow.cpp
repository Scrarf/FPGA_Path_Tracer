// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFP21_mult.h for the primary calling header

#include "VFP21_mult__pch.h"
#include "VFP21_mult__Syms.h"
#include "VFP21_mult___024root.h"

void VFP21_mult___024root___ctor_var_reset(VFP21_mult___024root* vlSelf);

VFP21_mult___024root::VFP21_mult___024root(VFP21_mult__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VFP21_mult___024root___ctor_var_reset(this);
}

void VFP21_mult___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VFP21_mult___024root::~VFP21_mult___024root() {
}
