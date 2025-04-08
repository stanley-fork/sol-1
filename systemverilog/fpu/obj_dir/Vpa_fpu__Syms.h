// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPA_FPU__SYMS_H_
#define VERILATED_VPA_FPU__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vpa_fpu.h"

// INCLUDE MODULE CLASSES
#include "Vpa_fpu___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vpa_fpu__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vpa_fpu* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vpa_fpu___024root              TOP;

    // CONSTRUCTORS
    Vpa_fpu__Syms(VerilatedContext* contextp, const char* namep, Vpa_fpu* modelp);
    ~Vpa_fpu__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
