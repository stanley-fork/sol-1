// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpa_fpu__pch.h"

//============================================================
// Constructors

Vpa_fpu::Vpa_fpu(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vpa_fpu__Syms(contextp(), _vcname__, this)}
    , arst{vlSymsp->TOP.arst}
    , clk{vlSymsp->TOP.clk}
    , operation{vlSymsp->TOP.operation}
    , start{vlSymsp->TOP.start}
    , cmd_end{vlSymsp->TOP.cmd_end}
    , busy{vlSymsp->TOP.busy}
    , a_operand{vlSymsp->TOP.a_operand}
    , b_operand{vlSymsp->TOP.b_operand}
    , ieee_packet_out{vlSymsp->TOP.ieee_packet_out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vpa_fpu::Vpa_fpu(const char* _vcname__)
    : Vpa_fpu(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vpa_fpu::~Vpa_fpu() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vpa_fpu___024root___eval_debug_assertions(Vpa_fpu___024root* vlSelf);
#endif  // VL_DEBUG
void Vpa_fpu___024root___eval_static(Vpa_fpu___024root* vlSelf);
void Vpa_fpu___024root___eval_initial(Vpa_fpu___024root* vlSelf);
void Vpa_fpu___024root___eval_settle(Vpa_fpu___024root* vlSelf);
void Vpa_fpu___024root___eval(Vpa_fpu___024root* vlSelf);

void Vpa_fpu::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpa_fpu::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vpa_fpu___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vpa_fpu___024root___eval_static(&(vlSymsp->TOP));
        Vpa_fpu___024root___eval_initial(&(vlSymsp->TOP));
        Vpa_fpu___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vpa_fpu___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vpa_fpu::eventsPending() { return false; }

uint64_t Vpa_fpu::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vpa_fpu::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vpa_fpu___024root___eval_final(Vpa_fpu___024root* vlSelf);

VL_ATTR_COLD void Vpa_fpu::final() {
    Vpa_fpu___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpa_fpu::hierName() const { return vlSymsp->name(); }
const char* Vpa_fpu::modelName() const { return "Vpa_fpu"; }
unsigned Vpa_fpu::threads() const { return 1; }
void Vpa_fpu::prepareClone() const { contextp()->prepareClone(); }
void Vpa_fpu::atClone() const {
    contextp()->threadPoolpOnClone();
}
