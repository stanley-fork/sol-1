// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpa_fpu.h for the primary calling header

#include "Vpa_fpu__pch.h"
#include "Vpa_fpu__Syms.h"
#include "Vpa_fpu___024root.h"

void Vpa_fpu___024root___ctor_var_reset(Vpa_fpu___024root* vlSelf);

Vpa_fpu___024root::Vpa_fpu___024root(Vpa_fpu__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vpa_fpu___024root___ctor_var_reset(this);
}

void Vpa_fpu___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vpa_fpu___024root::~Vpa_fpu___024root() {
}
