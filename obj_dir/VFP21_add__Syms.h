// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VFP21_ADD__SYMS_H_
#define VERILATED_VFP21_ADD__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VFP21_add.h"

// INCLUDE MODULE CLASSES
#include "VFP21_add___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VFP21_add__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VFP21_add* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VFP21_add___024root            TOP;

    // CONSTRUCTORS
    VFP21_add__Syms(VerilatedContext* contextp, const char* namep, VFP21_add* modelp);
    ~VFP21_add__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
