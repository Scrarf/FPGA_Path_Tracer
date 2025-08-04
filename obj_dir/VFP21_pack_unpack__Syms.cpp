// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VFP21_pack_unpack__pch.h"
#include "VFP21_pack_unpack.h"
#include "VFP21_pack_unpack___024root.h"

// FUNCTIONS
VFP21_pack_unpack__Syms::~VFP21_pack_unpack__Syms()
{
}

VFP21_pack_unpack__Syms::VFP21_pack_unpack__Syms(VerilatedContext* contextp, const char* namep, VFP21_pack_unpack* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(25);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
