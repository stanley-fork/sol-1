// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpa_fpu.h for the primary calling header

#include "Vpa_fpu__pch.h"
#include "Vpa_fpu__Syms.h"
#include "Vpa_fpu___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpa_fpu___024root___dump_triggers__ico(Vpa_fpu___024root* vlSelf);
#endif  // VL_DEBUG

void Vpa_fpu___024root___eval_triggers__ico(Vpa_fpu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpa_fpu___024root___eval_triggers__ico\n"); );
    Vpa_fpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vpa_fpu___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpa_fpu___024root___dump_triggers__act(Vpa_fpu___024root* vlSelf);
#endif  // VL_DEBUG

void Vpa_fpu___024root___eval_triggers__act(Vpa_fpu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpa_fpu___024root___eval_triggers__act\n"); );
    Vpa_fpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.arst) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__arst__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((IData)(vlSelfRef.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__arst__0 = vlSelfRef.arst;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vpa_fpu___024root___dump_triggers__act(vlSelf);
    }
#endif
}
