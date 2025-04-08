// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpa_fpu.h for the primary calling header

#ifndef VERILATED_VPA_FPU___024ROOT_H_
#define VERILATED_VPA_FPU___024ROOT_H_  // guard

#include "verilated.h"


class Vpa_fpu__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vpa_fpu___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(arst,0,0);
        VL_IN8(clk,0,0);
        VL_IN8(operation,3,0);
        VL_IN8(start,0,0);
        VL_OUT8(cmd_end,0,0);
        VL_OUT8(busy,0,0);
        CData/*7:0*/ fpu__DOT__a_exp;
        CData/*7:0*/ fpu__DOT__a_exp_adjusted;
        CData/*0:0*/ fpu__DOT__a_sign;
        CData/*7:0*/ fpu__DOT__b_exp;
        CData/*0:0*/ fpu__DOT__b_sign;
        CData/*7:0*/ fpu__DOT__result_e_addsub_norm;
        CData/*4:0*/ fpu__DOT__zcount_div;
        CData/*7:0*/ fpu__DOT__result_exp_div;
        CData/*0:0*/ fpu__DOT__result_sign_div;
        CData/*7:0*/ fpu__DOT__sqrt_xn_exp;
        CData/*0:0*/ fpu__DOT__sqrt_xn_sign;
        CData/*7:0*/ fpu__DOT__sqrt_A_exp;
        CData/*0:0*/ fpu__DOT__sqrt_A_sign;
        CData/*3:0*/ fpu__DOT__sqrt_counter;
        CData/*0:0*/ fpu__DOT__start_operation_sqrt_fsm;
        CData/*0:0*/ fpu__DOT__operation_done_sqrt_fsm;
        CData/*0:0*/ fpu__DOT__sqrt_xn_A_wrt;
        CData/*0:0*/ fpu__DOT__sqrt_xn_a_approx_wrt;
        CData/*0:0*/ fpu__DOT__sqrt_xn_a_wrt;
        CData/*0:0*/ fpu__DOT__sqrt_xn_add_wrt;
        CData/*0:0*/ fpu__DOT__sqrt_A_a_wrt;
        CData/*0:0*/ fpu__DOT__sqrt_a_xn_wrt;
        CData/*0:0*/ fpu__DOT__sqrt_a_A_wrt;
        CData/*0:0*/ fpu__DOT__sqrt_b_xn_wrt;
        CData/*0:0*/ fpu__DOT__sqrt_b_div_wrt;
        CData/*0:0*/ fpu__DOT__start_operation_ar_fsm;
        CData/*0:0*/ fpu__DOT__operation_done_ar_fsm;
        CData/*5:0*/ fpu__DOT__log2_zcount;
        CData/*3:0*/ fpu__DOT__curr_state_main_fsm;
        CData/*3:0*/ fpu__DOT__next_state_main_fsm;
        CData/*3:0*/ fpu__DOT__curr_state_arith_fsm;
        CData/*3:0*/ fpu__DOT__next_state_arith_fsm;
        CData/*3:0*/ fpu__DOT__curr_state_sqrt_fsm;
        CData/*3:0*/ fpu__DOT__next_state_sqrt_fsm;
        CData/*0:0*/ fpu__DOT____Vlvbound_hbdf1056a__0;
        CData/*5:0*/ __Vfunc_fpu__DOT__lzc__0__Vfuncout;
        CData/*5:0*/ __Vfunc_fpu__DOT__lzc__1__Vfuncout;
        CData/*5:0*/ __Vfunc_fpu__DOT__lzc__2__Vfuncout;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__arst__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __VactContinue;
        VL_IN(a_operand,31,0);
        VL_IN(b_operand,31,0);
        VL_OUT(ieee_packet_out,31,0);
        IData/*25:0*/ fpu__DOT__a_mantissa;
        IData/*25:0*/ fpu__DOT__a_mantissa_adjusted;
        IData/*25:0*/ fpu__DOT__b_mantissa;
        IData/*25:0*/ fpu__DOT__b_mantissa_adjusted;
        IData/*25:0*/ fpu__DOT__result_m_addsub_prenorm;
        IData/*25:0*/ fpu__DOT__result_m_addsub_norm;
        IData/*23:0*/ fpu__DOT__div_quotient_prenorm_out;
        IData/*23:0*/ fpu__DOT__sqrt_xn_mantissa;
        IData/*23:0*/ fpu__DOT__sqrt_A_mantissa;
        IData/*31:0*/ fpu__DOT__result_float2int;
        IData/*30:0*/ fpu__DOT__log2_prenorm;
        IData/*30:0*/ fpu__DOT__log2_abs;
    };
    struct {
        IData/*31:0*/ fpu__DOT____VdfgRegularize_hab43e411_0_7;
        IData/*31:0*/ __Vfunc_fpu__DOT__lzc__0__a;
        IData/*31:0*/ __Vfunc_fpu__DOT__lzc__1__a;
        IData/*31:0*/ __Vfunc_fpu__DOT__lzc__2__a;
        IData/*31:0*/ __VactIterCount;
        QData/*48:0*/ fpu__DOT__product_rounded;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vpa_fpu__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpa_fpu___024root(Vpa_fpu__Syms* symsp, const char* v__name);
    ~Vpa_fpu___024root();
    VL_UNCOPYABLE(Vpa_fpu___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
