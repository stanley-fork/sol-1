// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpa_fpu.h for the primary calling header

#include "Vpa_fpu__pch.h"
#include "Vpa_fpu___024root.h"

void Vpa_fpu___024root___ico_sequent__TOP__0(Vpa_fpu___024root* vlSelf);

void Vpa_fpu___024root___eval_ico(Vpa_fpu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpa_fpu___024root___eval_ico\n"); );
    Vpa_fpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vpa_fpu___024root___ico_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*3:0*/, 64> Vpa_fpu__ConstPool__TABLE_hbd668048_0;
extern const VlUnpacked<CData/*3:0*/, 1024> Vpa_fpu__ConstPool__TABLE_h24e7a3d6_0;

VL_INLINE_OPT void Vpa_fpu___024root___ico_sequent__TOP__0(Vpa_fpu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpa_fpu___024root___ico_sequent__TOP__0\n"); );
    Vpa_fpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*25:0*/ fpu__DOT__result_m_addsub_abs;
    fpu__DOT__result_m_addsub_abs = 0;
    CData/*5:0*/ fpu__DOT__zcount_addsub;
    fpu__DOT__zcount_addsub = 0;
    IData/*31:0*/ fpu__DOT____VdfgRegularize_hab43e411_0_6;
    fpu__DOT____VdfgRegularize_hab43e411_0_6 = 0;
    IData/*31:0*/ __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i;
    __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0;
    IData/*31:0*/ __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i;
    __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0;
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    SData/*9:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelfRef.fpu__DOT__operation_done_ar_fsm) 
                     << 5U) | (((IData)(vlSelfRef.start) 
                                << 4U) | (IData)(vlSelfRef.fpu__DOT__curr_state_main_fsm)));
    vlSelfRef.fpu__DOT__next_state_main_fsm = Vpa_fpu__ConstPool__TABLE_hbd668048_0
        [__Vtableidx1];
    __Vtableidx3 = ((((IData)(vlSelfRef.operation) 
                      << 6U) | ((IData)(vlSelfRef.fpu__DOT__operation_done_sqrt_fsm) 
                                << 5U)) | (((IData)(vlSelfRef.fpu__DOT__start_operation_ar_fsm) 
                                            << 4U) 
                                           | (IData)(vlSelfRef.fpu__DOT__curr_state_arith_fsm)));
    vlSelfRef.fpu__DOT__next_state_arith_fsm = Vpa_fpu__ConstPool__TABLE_h24e7a3d6_0
        [__Vtableidx3];
    vlSelfRef.fpu__DOT__log2_prenorm = (0x7fffffffU 
                                        & ((IData)(0x58233U) 
                                           + ((0x7f800000U 
                                               & (((vlSelfRef.a_operand 
                                                    >> 0x17U) 
                                                   - (IData)(0x7fU)) 
                                                  << 0x17U)) 
                                              | (0x7fffffU 
                                                 & vlSelfRef.a_operand))));
    vlSelfRef.fpu__DOT__log2_abs = (0x7fffffffU & (
                                                   (0x40000000U 
                                                    & vlSelfRef.fpu__DOT__log2_prenorm)
                                                    ? 
                                                   (- vlSelfRef.fpu__DOT__log2_prenorm)
                                                    : vlSelfRef.fpu__DOT__log2_prenorm));
    vlSelfRef.fpu__DOT__result_m_addsub_prenorm = (0x3ffffffU 
                                                   & ((0U 
                                                       == (IData)(vlSelfRef.operation))
                                                       ? 
                                                      (vlSelfRef.fpu__DOT__a_mantissa_adjusted 
                                                       + vlSelfRef.fpu__DOT__b_mantissa_adjusted)
                                                       : 
                                                      (vlSelfRef.fpu__DOT__a_mantissa_adjusted 
                                                       - vlSelfRef.fpu__DOT__b_mantissa_adjusted)));
    fpu__DOT__result_m_addsub_abs = (0x3ffffffU & (
                                                   (0x2000000U 
                                                    & vlSelfRef.fpu__DOT__result_m_addsub_prenorm)
                                                    ? 
                                                   (- vlSelfRef.fpu__DOT__result_m_addsub_prenorm)
                                                    : vlSelfRef.fpu__DOT__result_m_addsub_prenorm));
    vlSelfRef.fpu__DOT__log2_zcount = (0x3fU & (([&]() {
                    vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a 
                        = vlSelfRef.fpu__DOT__log2_abs;
                    __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0;
                    {
                        if ((vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a 
                             >> 0x1fU)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 1U;
                        if ((0x40000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 1U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 2U;
                        if ((0x20000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 2U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 3U;
                        if ((0x10000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 3U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 4U;
                        if ((0x8000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 4U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 5U;
                        if ((0x4000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 5U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 6U;
                        if ((0x2000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 6U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 7U;
                        if ((0x1000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 7U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 8U;
                        if ((0x800000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 8U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 9U;
                        if ((0x400000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 9U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0xaU;
                        if ((0x200000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0xaU;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0xbU;
                        if ((0x100000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0xbU;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0xcU;
                        if ((0x80000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0xcU;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0xdU;
                        if ((0x40000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0xdU;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0xeU;
                        if ((0x20000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0xeU;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0xfU;
                        if ((0x10000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0xfU;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x10U;
                        if ((0x8000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x10U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x11U;
                        if ((0x4000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x11U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x12U;
                        if ((0x2000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x12U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x13U;
                        if ((0x1000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x13U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x14U;
                        if ((0x800U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x14U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x15U;
                        if ((0x400U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x15U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x16U;
                        if ((0x200U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x16U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x17U;
                        if ((0x100U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x17U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x18U;
                        if ((0x80U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x18U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x19U;
                        if ((0x40U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x19U;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x1aU;
                        if ((0x20U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x1aU;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x1bU;
                        if ((0x10U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x1bU;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x1cU;
                        if ((8U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x1cU;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x1dU;
                        if ((4U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x1dU;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x1eU;
                        if ((2U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x1eU;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x1fU;
                        if ((1U & vlSelfRef.__Vfunc_fpu__DOT__lzc__2__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x1fU;
                            goto __Vlabel1;
                        }
                        __Vfunc_fpu__DOT__lzc__2__unnamedblk1__DOT__i = 0x20U;
                        vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout = 0x20U;
                        __Vlabel1: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_fpu__DOT__lzc__2__Vfuncout)) 
                                                - (IData)(1U)));
    fpu__DOT__zcount_addsub = (0x3fU & (([&]() {
                    vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a 
                        = fpu__DOT__result_m_addsub_abs;
                    __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0;
                    {
                        if ((vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a 
                             >> 0x1fU)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 1U;
                        if ((0x40000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 1U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 2U;
                        if ((0x20000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 2U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 3U;
                        if ((0x10000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 3U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 4U;
                        if ((0x8000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 4U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 5U;
                        if ((0x4000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 5U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 6U;
                        if ((0x2000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 6U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 7U;
                        if ((0x1000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 7U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 8U;
                        if ((0x800000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 8U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 9U;
                        if ((0x400000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 9U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0xaU;
                        if ((0x200000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0xaU;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0xbU;
                        if ((0x100000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0xbU;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0xcU;
                        if ((0x80000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0xcU;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0xdU;
                        if ((0x40000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0xdU;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0xeU;
                        if ((0x20000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0xeU;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0xfU;
                        if ((0x10000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0xfU;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x10U;
                        if ((0x8000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x10U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x11U;
                        if ((0x4000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x11U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x12U;
                        if ((0x2000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x12U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x13U;
                        if ((0x1000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x13U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x14U;
                        if ((0x800U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x14U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x15U;
                        if ((0x400U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x15U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x16U;
                        if ((0x200U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x16U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x17U;
                        if ((0x100U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x17U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x18U;
                        if ((0x80U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x18U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x19U;
                        if ((0x40U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x19U;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x1aU;
                        if ((0x20U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x1aU;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x1bU;
                        if ((0x10U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x1bU;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x1cU;
                        if ((8U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x1cU;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x1dU;
                        if ((4U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x1dU;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x1eU;
                        if ((2U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x1eU;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x1fU;
                        if ((1U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x1fU;
                            goto __Vlabel2;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x20U;
                        vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x20U;
                        __Vlabel2: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout)) 
                                        - (IData)(8U)));
    if ((0U == fpu__DOT__result_m_addsub_abs)) {
        vlSelfRef.fpu__DOT__result_m_addsub_norm = 
            (0x3ffffffU & fpu__DOT__result_m_addsub_abs);
        vlSelfRef.fpu__DOT__result_e_addsub_norm = 0U;
    } else if ((0x1000000U & fpu__DOT__result_m_addsub_abs)) {
        vlSelfRef.fpu__DOT__result_m_addsub_norm = 
            (0x3ffffffU & VL_SHIFTR_III(26,26,32, fpu__DOT__result_m_addsub_abs, 1U));
        vlSelfRef.fpu__DOT__result_e_addsub_norm = 
            (0xffU & ((IData)(1U) + (IData)(vlSelfRef.fpu__DOT__a_exp_adjusted)));
    } else {
        vlSelfRef.fpu__DOT__result_m_addsub_norm = 
            (0x3ffffffU & VL_SHIFTL_III(26,26,6, fpu__DOT__result_m_addsub_abs, (IData)(fpu__DOT__zcount_addsub)));
        vlSelfRef.fpu__DOT__result_e_addsub_norm = 
            (0xffU & ((IData)(vlSelfRef.fpu__DOT__a_exp_adjusted) 
                      - (IData)(fpu__DOT__zcount_addsub)));
    }
    fpu__DOT____VdfgRegularize_hab43e411_0_6 = ((0x80000000U 
                                                 & (vlSelfRef.fpu__DOT__result_m_addsub_prenorm 
                                                    << 6U)) 
                                                | (((IData)(vlSelfRef.fpu__DOT__result_e_addsub_norm) 
                                                    << 0x17U) 
                                                   | (0x7fffffU 
                                                      & vlSelfRef.fpu__DOT__result_m_addsub_norm)));
    vlSelfRef.ieee_packet_out = ((0U == (IData)(vlSelfRef.operation))
                                  ? fpu__DOT____VdfgRegularize_hab43e411_0_6
                                  : ((1U == (IData)(vlSelfRef.operation))
                                      ? fpu__DOT____VdfgRegularize_hab43e411_0_6
                                      : ((2U == (IData)(vlSelfRef.operation))
                                          ? vlSelfRef.fpu__DOT____VdfgRegularize_hab43e411_0_7
                                          : ((3U == (IData)(vlSelfRef.operation))
                                              ? vlSelfRef.fpu__DOT____VdfgRegularize_hab43e411_0_7
                                              : ((4U 
                                                  == (IData)(vlSelfRef.operation))
                                                  ? 
                                                 (((IData)(vlSelfRef.fpu__DOT__result_sign_div) 
                                                   << 0x1fU) 
                                                  | (((IData)(vlSelfRef.fpu__DOT__result_exp_div) 
                                                      << 0x17U) 
                                                     | (0x7fffffU 
                                                        & (vlSelfRef.fpu__DOT__div_quotient_prenorm_out 
                                                           << (IData)(vlSelfRef.fpu__DOT__zcount_div)))))
                                                  : 
                                                 ((5U 
                                                   == (IData)(vlSelfRef.operation))
                                                   ? 
                                                  (((IData)(vlSelfRef.fpu__DOT__sqrt_xn_exp) 
                                                    << 0x17U) 
                                                   | (0x7fffffU 
                                                      & vlSelfRef.fpu__DOT__sqrt_xn_mantissa))
                                                   : 
                                                  ((0xeU 
                                                    == (IData)(vlSelfRef.operation))
                                                    ? vlSelfRef.fpu__DOT__result_float2int
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlSelfRef.operation))
                                                     ? 
                                                    ((0x80000000U 
                                                      & (vlSelfRef.fpu__DOT__log2_prenorm 
                                                         << 1U)) 
                                                     | ((0x7f800000U 
                                                         & (((IData)(0x7fU) 
                                                             + 
                                                             ((IData)(7U) 
                                                              - (IData)(vlSelfRef.fpu__DOT__log2_zcount))) 
                                                            << 0x17U)) 
                                                        | (0x7fffffU 
                                                           & (VL_SHIFTL_III(31,31,6, vlSelfRef.fpu__DOT__log2_abs, (IData)(vlSelfRef.fpu__DOT__log2_zcount)) 
                                                              >> 7U))))
                                                     : 0U))))))));
}

void Vpa_fpu___024root___eval_triggers__ico(Vpa_fpu___024root* vlSelf);

bool Vpa_fpu___024root___eval_phase__ico(Vpa_fpu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpa_fpu___024root___eval_phase__ico\n"); );
    Vpa_fpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vpa_fpu___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vpa_fpu___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vpa_fpu___024root___eval_act(Vpa_fpu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpa_fpu___024root___eval_act\n"); );
    Vpa_fpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vpa_fpu___024root___nba_sequent__TOP__0(Vpa_fpu___024root* vlSelf);

void Vpa_fpu___024root___eval_nba(Vpa_fpu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpa_fpu___024root___eval_nba\n"); );
    Vpa_fpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vpa_fpu___024root___nba_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*2:0*/, 32> Vpa_fpu__ConstPool__TABLE_h700d187c_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vpa_fpu__ConstPool__TABLE_h917f4cf8_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vpa_fpu__ConstPool__TABLE_h10089e38_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vpa_fpu__ConstPool__TABLE_h9bdc596b_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vpa_fpu__ConstPool__TABLE_h9c5943e7_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vpa_fpu__ConstPool__TABLE_ha69cfa64_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vpa_fpu__ConstPool__TABLE_hafb50d5e_0;
extern const VlUnpacked<SData/*9:0*/, 32> Vpa_fpu__ConstPool__TABLE_hcf65d04e_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vpa_fpu__ConstPool__TABLE_h033e2374_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vpa_fpu__ConstPool__TABLE_h752762e2_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vpa_fpu__ConstPool__TABLE_h8f677608_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vpa_fpu__ConstPool__TABLE_h1fdf9182_0;
extern const VlUnpacked<CData/*3:0*/, 512> Vpa_fpu__ConstPool__TABLE_h855ee2ba_0;

VL_INLINE_OPT void Vpa_fpu___024root___nba_sequent__TOP__0(Vpa_fpu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpa_fpu___024root___nba_sequent__TOP__0\n"); );
    Vpa_fpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*25:0*/ fpu__DOT__a_mantissa_shifted;
    fpu__DOT__a_mantissa_shifted = 0;
    IData/*25:0*/ fpu__DOT__b_mantissa_shifted;
    fpu__DOT__b_mantissa_shifted = 0;
    SData/*8:0*/ fpu__DOT__ab_exp_diff;
    fpu__DOT__ab_exp_diff = 0;
    IData/*25:0*/ fpu__DOT__result_m_addsub_abs;
    fpu__DOT__result_m_addsub_abs = 0;
    CData/*5:0*/ fpu__DOT__zcount_addsub;
    fpu__DOT__zcount_addsub = 0;
    QData/*47:0*/ fpu__DOT__product_pre_norm;
    fpu__DOT__product_pre_norm = 0;
    QData/*48:0*/ fpu__DOT__product_norm;
    fpu__DOT__product_norm = 0;
    CData/*7:0*/ fpu__DOT__unnamedblk2__DOT__shift;
    fpu__DOT__unnamedblk2__DOT__shift = 0;
    IData/*23:0*/ fpu__DOT__unnamedblk2__DOT__intval;
    fpu__DOT__unnamedblk2__DOT__intval = 0;
    IData/*31:0*/ fpu__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i;
    fpu__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i = 0;
    IData/*31:0*/ fpu__DOT____VdfgRegularize_hab43e411_0_6;
    fpu__DOT____VdfgRegularize_hab43e411_0_6 = 0;
    CData/*0:0*/ fpu__DOT____VdfgRegularize_hab43e411_0_8;
    fpu__DOT____VdfgRegularize_hab43e411_0_8 = 0;
    CData/*0:0*/ fpu__DOT____VdfgRegularize_hab43e411_0_12;
    fpu__DOT____VdfgRegularize_hab43e411_0_12 = 0;
    QData/*47:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_80;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_80 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_81;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_81 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_83;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_83 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_85;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_85 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_86;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_86 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_88;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_88 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_90;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_90 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_91;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_91 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_92;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_92 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_94;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_94 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_96;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_96 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_97;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_97 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_98;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_98 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_99;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_99 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_101;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_101 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_103;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_103 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_104;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_104 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_105;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_105 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_106;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_106 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_107;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_107 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_109;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_109 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_111;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_111 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_112;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_112 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_113;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_113 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_114;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_114 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_115;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_115 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_116;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_116 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_118;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_118 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_120;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_120 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_121;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_121 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_122;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_122 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_123;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_123 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_124;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_124 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_125;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_125 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_126;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_126 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_128;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_128 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_130;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_130 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_131;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_131 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_132;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_132 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_133;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_133 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_134;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_134 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_135;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_135 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_136;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_136 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_137;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_137 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_139;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_139 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_141;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_141 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_142;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_142 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_143;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_143 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_144;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_144 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_145;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_145 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_146;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_146 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_147;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_147 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_148;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_148 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_149;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_149 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_151;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_151 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_153;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_153 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_154;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_154 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_155;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_155 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_156;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_156 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_157;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_157 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_158;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_158 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_159;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_159 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_160;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_160 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_161;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_161 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_162;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_162 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_164;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_164 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_166;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_166 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_167;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_167 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_168;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_168 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_169;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_169 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_170;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_170 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_171;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_171 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_172;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_172 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_173;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_173 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_174;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_174 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_175;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_175 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_176;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_176 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_178;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_178 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_180;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_180 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_181;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_181 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_182;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_182 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_183;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_183 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_184;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_184 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_185;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_185 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_186;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_186 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_187;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_187 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_188;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_188 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_189;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_189 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_190;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_190 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_191;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_191 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_193;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_193 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_195;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_195 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_196;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_196 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_197;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_197 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_198;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_198 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_199;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_199 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_200;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_200 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_201;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_201 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_202;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_202 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_203;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_203 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_204;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_204 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_205;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_205 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_206;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_206 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_207;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_207 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_209;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_209 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_211;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_211 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_212;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_212 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_213;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_213 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_214;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_214 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_215;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_215 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_216;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_216 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_217;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_217 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_218;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_218 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_219;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_219 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_220;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_220 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_221;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_221 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_222;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_222 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_223;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_223 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_224;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_224 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_226;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_226 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_228;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_228 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_229;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_229 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_230;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_230 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_231;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_231 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_232;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_232 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_233;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_233 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_234;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_234 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_235;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_235 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_236;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_236 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_237;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_237 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_238;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_238 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_239;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_239 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_240;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_240 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_241;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_241 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_242;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_242 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_244;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_244 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_246;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_246 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_247;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_247 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_248;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_248 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_249;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_249 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_250;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_250 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_251;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_251 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_252;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_252 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_253;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_253 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_254;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_254 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_255;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_255 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_256;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_256 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_257;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_257 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_258;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_258 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_259;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_259 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_260;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_260 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_261;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_261 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_263;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_263 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_265;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_265 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_266;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_266 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_267;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_267 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_268;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_268 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_269;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_269 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_270;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_270 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_271;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_271 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_272;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_272 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_273;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_273 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_274;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_274 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_275;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_275 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_276;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_276 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_277;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_277 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_278;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_278 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_279;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_279 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_280;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_280 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_281;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_281 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_283;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_283 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_285;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_285 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_286;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_286 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_287;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_287 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_288;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_288 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_289;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_289 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_290;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_290 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_291;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_291 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_292;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_292 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_293;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_293 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_294;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_294 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_295;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_295 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_296;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_296 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_297;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_297 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_298;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_298 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_299;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_299 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_300;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_300 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_301;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_301 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_302;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_302 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_304;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_304 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_306;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_306 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_307;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_307 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_308;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_308 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_309;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_309 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_310;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_310 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_311;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_311 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_312;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_312 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_313;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_313 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_314;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_314 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_315;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_315 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_316;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_316 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_317;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_317 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_318;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_318 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_319;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_319 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_320;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_320 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_321;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_321 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_322;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_322 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_323;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_323 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_324;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_324 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_326;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_326 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_328;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_328 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_329;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_329 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_330;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_330 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_331;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_331 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_332;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_332 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_333;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_333 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_334;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_334 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_335;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_335 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_336;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_336 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_337;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_337 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_338;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_338 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_339;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_339 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_340;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_340 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_341;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_341 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_342;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_342 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_343;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_343 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_344;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_344 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_345;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_345 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_346;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_346 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_347;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_347 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_349;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_349 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_351;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_351 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_352;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_352 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_353;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_353 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_354;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_354 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_355;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_355 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_356;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_356 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_357;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_357 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_358;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_358 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_359;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_359 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_360;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_360 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_361;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_361 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_362;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_362 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_363;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_363 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_364;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_364 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_365;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_365 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_366;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_366 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_367;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_367 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_368;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_368 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_369;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_369 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_370;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_370 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_371;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_371 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_373;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_373 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_375;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_375 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_376;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_376 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_377;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_377 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_378;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_378 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_379;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_379 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_380;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_380 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_381;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_381 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_382;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_382 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_383;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_383 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_384;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_384 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_385;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_385 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_386;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_386 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_387;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_387 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_388;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_388 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_389;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_389 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_390;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_390 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_391;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_391 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_392;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_392 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_393;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_393 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_394;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_394 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_395;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_395 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_396;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_396 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_398;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_398 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_400;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_400 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_401;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_401 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_402;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_402 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_403;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_403 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_404;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_404 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_405;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_405 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_406;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_406 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_407;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_407 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_408;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_408 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_409;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_409 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_410;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_410 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_411;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_411 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_412;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_412 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_413;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_413 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_414;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_414 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_415;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_415 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_416;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_416 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_417;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_417 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_418;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_418 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_419;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_419 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_420;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_420 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_421;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_421 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_422;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_422 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_424;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_424 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_426;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_426 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_427;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_427 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_428;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_428 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_429;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_429 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_430;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_430 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_431;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_431 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_432;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_432 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_433;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_433 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_434;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_434 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_435;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_435 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_436;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_436 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_437;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_437 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_438;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_438 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_439;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_439 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_440;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_440 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_441;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_441 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_442;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_442 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_443;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_443 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_444;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_444 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_445;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_445 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_446;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_446 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_447;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_447 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_448;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_448 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_450;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_450 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_451;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_451 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_452;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_452 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_453;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_453 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_454;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_454 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_455;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_455 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_456;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_456 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_457;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_457 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_458;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_458 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_459;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_459 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_460;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_460 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_461;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_461 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_462;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_462 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_463;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_463 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_464;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_464 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_465;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_465 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_466;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_466 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_467;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_467 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_468;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_468 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_469;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_469 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_470;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_470 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_471;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_471 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_472;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_472 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_474;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_474 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_475;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_475 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_476;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_476 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_477;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_477 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_478;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_478 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_479;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_479 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_480;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_480 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_481;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_481 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_482;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_482 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_483;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_483 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_484;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_484 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_485;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_485 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_486;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_486 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_487;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_487 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_488;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_488 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_489;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_489 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_490;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_490 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_491;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_491 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_492;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_492 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_493;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_493 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_494;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_494 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_495;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_495 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_497;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_497 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_498;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_498 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_499;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_499 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_500;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_500 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_501;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_501 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_502;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_502 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_503;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_503 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_504;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_504 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_505;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_505 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_506;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_506 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_507;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_507 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_508;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_508 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_509;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_509 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_510;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_510 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_511;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_511 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_512;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_512 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_513;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_513 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_514;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_514 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_515;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_515 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_516;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_516 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_517;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_517 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_519;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_519 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_520;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_520 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_521;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_521 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_522;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_522 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_523;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_523 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_524;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_524 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_525;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_525 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_526;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_526 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_527;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_527 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_528;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_528 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_529;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_529 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_530;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_530 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_531;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_531 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_532;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_532 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_533;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_533 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_534;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_534 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_535;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_535 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_536;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_536 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_537;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_537 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_538;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_538 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_540;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_540 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_541;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_541 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_542;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_542 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_543;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_543 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_544;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_544 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_545;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_545 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_546;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_546 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_547;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_547 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_548;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_548 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_549;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_549 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_550;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_550 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_551;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_551 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_552;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_552 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_553;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_553 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_554;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_554 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_555;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_555 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_556;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_556 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_557;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_557 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_558;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_558 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_560;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_560 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_561;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_561 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_562;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_562 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_563;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_563 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_564;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_564 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_565;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_565 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_566;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_566 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_567;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_567 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_568;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_568 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_569;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_569 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_570;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_570 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_571;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_571 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_572;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_572 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_573;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_573 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_574;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_574 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_575;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_575 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_576;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_576 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_577;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_577 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_579;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_579 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_580;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_580 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_581;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_581 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_582;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_582 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_583;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_583 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_584;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_584 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_585;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_585 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_586;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_586 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_587;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_587 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_588;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_588 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_589;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_589 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_590;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_590 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_591;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_591 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_592;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_592 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_593;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_593 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_594;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_594 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_595;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_595 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_597;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_597 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_598;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_598 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_599;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_599 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_600;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_600 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_601;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_601 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_602;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_602 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_603;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_603 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_604;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_604 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_605;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_605 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_606;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_606 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_607;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_607 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_608;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_608 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_609;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_609 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_610;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_610 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_611;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_611 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_612;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_612 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_614;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_614 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_615;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_615 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_616;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_616 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_617;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_617 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_618;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_618 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_619;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_619 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_620;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_620 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_621;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_621 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_622;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_622 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_623;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_623 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_624;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_624 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_625;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_625 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_626;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_626 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_627;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_627 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_628;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_628 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_630;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_630 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_631;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_631 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_632;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_632 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_633;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_633 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_634;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_634 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_635;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_635 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_636;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_636 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_637;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_637 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_638;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_638 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_639;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_639 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_640;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_640 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_641;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_641 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_642;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_642 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_643;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_643 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_645;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_645 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_646;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_646 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_647;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_647 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_648;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_648 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_649;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_649 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_650;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_650 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_651;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_651 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_652;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_652 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_653;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_653 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_654;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_654 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_655;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_655 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_656;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_656 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_657;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_657 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_659;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_659 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_660;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_660 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_661;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_661 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_662;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_662 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_663;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_663 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_664;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_664 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_665;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_665 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_666;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_666 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_667;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_667 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_668;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_668 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_669;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_669 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_670;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_670 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_672;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_672 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_673;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_673 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_674;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_674 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_675;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_675 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_676;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_676 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_677;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_677 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_678;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_678 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_679;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_679 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_680;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_680 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_681;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_681 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_682;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_682 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_684;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_684 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_685;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_685 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_686;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_686 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_687;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_687 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_688;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_688 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_689;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_689 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_690;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_690 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_691;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_691 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_692;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_692 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_693;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_693 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_695;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_695 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_696;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_696 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_697;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_697 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_698;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_698 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_699;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_699 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_700;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_700 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_701;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_701 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_702;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_702 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_703;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_703 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_705;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_705 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_706;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_706 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_707;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_707 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_708;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_708 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_709;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_709 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_710;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_710 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_711;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_711 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_712;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_712 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_714;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_714 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_715;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_715 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_716;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_716 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_717;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_717 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_718;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_718 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_719;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_719 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_720;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_720 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_722;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_722 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_723;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_723 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_724;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_724 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_725;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_725 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_726;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_726 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_727;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_727 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_729;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_729 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_730;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_730 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_731;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_731 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_732;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_732 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_733;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_733 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_735;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_735 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_736;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_736 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_737;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_737 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_738;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_738 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_740;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_740 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_741;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_741 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_742;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_742 = 0;
    CData/*5:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_744;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_744 = 0;
    CData/*0:0*/ fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_745;
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_745 = 0;
    IData/*25:0*/ fpu__DOT__div24_frac__DOT__partial;
    fpu__DOT__div24_frac__DOT__partial = 0;
    CData/*0:0*/ fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0;
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 = 0;
    IData/*31:0*/ __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i;
    __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0;
    IData/*31:0*/ __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i;
    __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0;
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*4:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    SData/*9:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*4:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    SData/*8:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*4:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    IData/*25:0*/ __Vdly__fpu__DOT__a_mantissa;
    __Vdly__fpu__DOT__a_mantissa = 0;
    CData/*7:0*/ __Vdly__fpu__DOT__a_exp;
    __Vdly__fpu__DOT__a_exp = 0;
    CData/*0:0*/ __Vdly__fpu__DOT__a_sign;
    __Vdly__fpu__DOT__a_sign = 0;
    CData/*3:0*/ __Vdly__fpu__DOT__sqrt_counter;
    __Vdly__fpu__DOT__sqrt_counter = 0;
    // Body
    __Vdly__fpu__DOT__sqrt_counter = vlSelfRef.fpu__DOT__sqrt_counter;
    __Vdly__fpu__DOT__a_sign = vlSelfRef.fpu__DOT__a_sign;
    __Vdly__fpu__DOT__a_exp = vlSelfRef.fpu__DOT__a_exp;
    __Vdly__fpu__DOT__a_mantissa = vlSelfRef.fpu__DOT__a_mantissa;
    if (vlSelfRef.arst) {
        __Vdly__fpu__DOT__sqrt_counter = 0U;
        __Vdly__fpu__DOT__a_sign = 0U;
        __Vdly__fpu__DOT__a_exp = 0U;
        __Vdly__fpu__DOT__a_mantissa = 0U;
        vlSelfRef.fpu__DOT__curr_state_main_fsm = 0U;
        vlSelfRef.fpu__DOT__curr_state_sqrt_fsm = 0U;
        vlSelfRef.fpu__DOT__curr_state_arith_fsm = 0U;
        vlSelfRef.fpu__DOT__b_sign = 0U;
        vlSelfRef.fpu__DOT__b_exp = 0U;
        vlSelfRef.fpu__DOT__b_mantissa = 0U;
        vlSelfRef.fpu__DOT__sqrt_A_sign = 0U;
        vlSelfRef.fpu__DOT__sqrt_xn_sign = 0U;
        vlSelfRef.fpu__DOT__sqrt_xn_exp = 0U;
        vlSelfRef.fpu__DOT__sqrt_xn_mantissa = 0U;
        vlSelfRef.fpu__DOT__sqrt_A_exp = 0U;
        vlSelfRef.fpu__DOT__sqrt_A_mantissa = 0U;
    } else {
        if ((1U == (IData)(vlSelfRef.fpu__DOT__next_state_sqrt_fsm))) {
            __Vdly__fpu__DOT__sqrt_counter = 0U;
        } else if ((4U == (IData)(vlSelfRef.fpu__DOT__next_state_sqrt_fsm))) {
            __Vdly__fpu__DOT__sqrt_counter = (0xfU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.fpu__DOT__sqrt_counter)));
        }
        if ((1U == (IData)(vlSelfRef.fpu__DOT__next_state_arith_fsm))) {
            __Vdly__fpu__DOT__a_sign = (vlSelfRef.a_operand 
                                        >> 0x1fU);
            __Vdly__fpu__DOT__a_exp = (0xffU & (vlSelfRef.a_operand 
                                                >> 0x17U));
            __Vdly__fpu__DOT__a_mantissa = (((0U != 
                                              (0xffU 
                                               & (vlSelfRef.a_operand 
                                                  >> 0x17U))) 
                                             << 0x17U) 
                                            | (0x7fffffU 
                                               & vlSelfRef.a_operand));
            vlSelfRef.fpu__DOT__b_sign = (vlSelfRef.b_operand 
                                          >> 0x1fU);
            vlSelfRef.fpu__DOT__b_exp = (0xffU & (vlSelfRef.b_operand 
                                                  >> 0x17U));
            vlSelfRef.fpu__DOT__b_mantissa = (((0U 
                                                != 
                                                (0xffU 
                                                 & (vlSelfRef.b_operand 
                                                    >> 0x17U))) 
                                               << 0x17U) 
                                              | (0x7fffffU 
                                                 & vlSelfRef.b_operand));
        }
        if (vlSelfRef.fpu__DOT__sqrt_a_xn_wrt) {
            __Vdly__fpu__DOT__a_sign = vlSelfRef.fpu__DOT__sqrt_xn_sign;
            __Vdly__fpu__DOT__a_exp = vlSelfRef.fpu__DOT__sqrt_xn_exp;
            __Vdly__fpu__DOT__a_mantissa = vlSelfRef.fpu__DOT__sqrt_xn_mantissa;
        } else if (vlSelfRef.fpu__DOT__sqrt_a_A_wrt) {
            __Vdly__fpu__DOT__a_sign = vlSelfRef.fpu__DOT__sqrt_A_sign;
            __Vdly__fpu__DOT__a_exp = vlSelfRef.fpu__DOT__sqrt_A_exp;
            __Vdly__fpu__DOT__a_mantissa = vlSelfRef.fpu__DOT__sqrt_A_mantissa;
        }
        vlSelfRef.fpu__DOT__curr_state_main_fsm = vlSelfRef.fpu__DOT__next_state_main_fsm;
        vlSelfRef.fpu__DOT__curr_state_sqrt_fsm = vlSelfRef.fpu__DOT__next_state_sqrt_fsm;
        vlSelfRef.fpu__DOT__curr_state_arith_fsm = vlSelfRef.fpu__DOT__next_state_arith_fsm;
        if (vlSelfRef.fpu__DOT__sqrt_b_xn_wrt) {
            vlSelfRef.fpu__DOT__b_sign = vlSelfRef.fpu__DOT__sqrt_xn_sign;
            vlSelfRef.fpu__DOT__b_exp = vlSelfRef.fpu__DOT__sqrt_xn_exp;
            vlSelfRef.fpu__DOT__b_mantissa = vlSelfRef.fpu__DOT__sqrt_xn_mantissa;
        } else if (vlSelfRef.fpu__DOT__sqrt_b_div_wrt) {
            vlSelfRef.fpu__DOT__b_sign = vlSelfRef.fpu__DOT__result_sign_div;
            vlSelfRef.fpu__DOT__b_exp = vlSelfRef.fpu__DOT__result_exp_div;
            vlSelfRef.fpu__DOT__b_mantissa = (0xffffffU 
                                              & (vlSelfRef.fpu__DOT__div_quotient_prenorm_out 
                                                 << (IData)(vlSelfRef.fpu__DOT__zcount_div)));
        }
        if (vlSelfRef.fpu__DOT__sqrt_xn_A_wrt) {
            vlSelfRef.fpu__DOT__sqrt_xn_sign = 0U;
            vlSelfRef.fpu__DOT__sqrt_xn_exp = vlSelfRef.fpu__DOT__sqrt_A_exp;
            vlSelfRef.fpu__DOT__sqrt_xn_mantissa = vlSelfRef.fpu__DOT__sqrt_A_mantissa;
        } else if (vlSelfRef.fpu__DOT__sqrt_xn_a_approx_wrt) {
            vlSelfRef.fpu__DOT__sqrt_xn_sign = vlSelfRef.fpu__DOT__a_sign;
            vlSelfRef.fpu__DOT__sqrt_xn_exp = (0xffU 
                                               & ((IData)(0x3fU) 
                                                  + 
                                                  ((IData)(vlSelfRef.fpu__DOT__a_exp) 
                                                   >> 1U)));
            vlSelfRef.fpu__DOT__sqrt_xn_mantissa = 
                (0xffffffU & vlSelfRef.fpu__DOT__a_mantissa);
        } else if (vlSelfRef.fpu__DOT__sqrt_xn_a_wrt) {
            vlSelfRef.fpu__DOT__sqrt_xn_sign = vlSelfRef.fpu__DOT__a_sign;
            vlSelfRef.fpu__DOT__sqrt_xn_exp = vlSelfRef.fpu__DOT__a_exp;
            vlSelfRef.fpu__DOT__sqrt_xn_mantissa = 
                (0xffffffU & vlSelfRef.fpu__DOT__a_mantissa);
        } else if (vlSelfRef.fpu__DOT__sqrt_xn_add_wrt) {
            vlSelfRef.fpu__DOT__sqrt_xn_sign = (1U 
                                                & (vlSelfRef.fpu__DOT__result_m_addsub_prenorm 
                                                   >> 0x19U));
            vlSelfRef.fpu__DOT__sqrt_xn_exp = (0xffU 
                                               & ((IData)(vlSelfRef.fpu__DOT__result_e_addsub_norm) 
                                                  - (IData)(1U)));
            vlSelfRef.fpu__DOT__sqrt_xn_mantissa = 
                (0xffffffU & vlSelfRef.fpu__DOT__result_m_addsub_norm);
        }
        if (vlSelfRef.fpu__DOT__sqrt_A_a_wrt) {
            vlSelfRef.fpu__DOT__sqrt_A_sign = vlSelfRef.fpu__DOT__a_sign;
            vlSelfRef.fpu__DOT__sqrt_A_exp = vlSelfRef.fpu__DOT__a_exp;
            vlSelfRef.fpu__DOT__sqrt_A_mantissa = (0xffffffU 
                                                   & vlSelfRef.fpu__DOT__a_mantissa);
        }
    }
    __Vtableidx2 = (((IData)(vlSelfRef.fpu__DOT__next_state_main_fsm) 
                     << 1U) | (IData)(vlSelfRef.arst));
    if ((1U & Vpa_fpu__ConstPool__TABLE_h700d187c_0
         [__Vtableidx2])) {
        vlSelfRef.fpu__DOT__start_operation_ar_fsm 
            = Vpa_fpu__ConstPool__TABLE_h917f4cf8_0
            [__Vtableidx2];
    }
    if ((2U & Vpa_fpu__ConstPool__TABLE_h700d187c_0
         [__Vtableidx2])) {
        vlSelfRef.cmd_end = Vpa_fpu__ConstPool__TABLE_h10089e38_0
            [__Vtableidx2];
    }
    if ((4U & Vpa_fpu__ConstPool__TABLE_h700d187c_0
         [__Vtableidx2])) {
        vlSelfRef.busy = Vpa_fpu__ConstPool__TABLE_h9bdc596b_0
            [__Vtableidx2];
    }
    __Vtableidx4 = (((IData)(vlSelfRef.fpu__DOT__next_state_arith_fsm) 
                     << 1U) | (IData)(vlSelfRef.arst));
    if ((1U & Vpa_fpu__ConstPool__TABLE_h9c5943e7_0
         [__Vtableidx4])) {
        vlSelfRef.fpu__DOT__operation_done_ar_fsm = 
            Vpa_fpu__ConstPool__TABLE_ha69cfa64_0[__Vtableidx4];
    }
    if ((2U & Vpa_fpu__ConstPool__TABLE_h9c5943e7_0
         [__Vtableidx4])) {
        vlSelfRef.fpu__DOT__start_operation_sqrt_fsm 
            = Vpa_fpu__ConstPool__TABLE_hafb50d5e_0
            [__Vtableidx4];
    }
    vlSelfRef.fpu__DOT__sqrt_counter = __Vdly__fpu__DOT__sqrt_counter;
    __Vtableidx1 = (((IData)(vlSelfRef.fpu__DOT__operation_done_ar_fsm) 
                     << 5U) | (((IData)(vlSelfRef.start) 
                                << 4U) | (IData)(vlSelfRef.fpu__DOT__curr_state_main_fsm)));
    vlSelfRef.fpu__DOT__next_state_main_fsm = Vpa_fpu__ConstPool__TABLE_hbd668048_0
        [__Vtableidx1];
    vlSelfRef.fpu__DOT__a_sign = __Vdly__fpu__DOT__a_sign;
    vlSelfRef.fpu__DOT__result_sign_div = ((IData)(vlSelfRef.fpu__DOT__a_sign) 
                                           ^ (IData)(vlSelfRef.fpu__DOT__b_sign));
    vlSelfRef.fpu__DOT__a_exp = __Vdly__fpu__DOT__a_exp;
    vlSelfRef.fpu__DOT__a_mantissa = __Vdly__fpu__DOT__a_mantissa;
    fpu__DOT____VdfgRegularize_hab43e411_0_8 = ((IData)(vlSelfRef.fpu__DOT__a_exp) 
                                                < (IData)(vlSelfRef.fpu__DOT__b_exp));
    fpu__DOT__ab_exp_diff = (0x1ffU & ((IData)(vlSelfRef.fpu__DOT__a_exp) 
                                       - (IData)(vlSelfRef.fpu__DOT__b_exp)));
    __Vtableidx6 = (((IData)(vlSelfRef.fpu__DOT__next_state_sqrt_fsm) 
                     << 1U) | (IData)(vlSelfRef.arst));
    if ((1U & Vpa_fpu__ConstPool__TABLE_hcf65d04e_0
         [__Vtableidx6])) {
        vlSelfRef.fpu__DOT__operation_done_sqrt_fsm 
            = Vpa_fpu__ConstPool__TABLE_h033e2374_0
            [__Vtableidx6];
    }
    if ((2U & Vpa_fpu__ConstPool__TABLE_hcf65d04e_0
         [__Vtableidx6])) {
        vlSelfRef.fpu__DOT__sqrt_xn_A_wrt = Vpa_fpu__ConstPool__TABLE_h752762e2_0
            [__Vtableidx6];
    }
    if ((4U & Vpa_fpu__ConstPool__TABLE_hcf65d04e_0
         [__Vtableidx6])) {
        vlSelfRef.fpu__DOT__sqrt_xn_a_approx_wrt = 
            Vpa_fpu__ConstPool__TABLE_h917f4cf8_0[__Vtableidx6];
    }
    if ((8U & Vpa_fpu__ConstPool__TABLE_hcf65d04e_0
         [__Vtableidx6])) {
        vlSelfRef.fpu__DOT__sqrt_xn_a_wrt = Vpa_fpu__ConstPool__TABLE_h752762e2_0
            [__Vtableidx6];
    }
    if ((0x10U & Vpa_fpu__ConstPool__TABLE_hcf65d04e_0
         [__Vtableidx6])) {
        vlSelfRef.fpu__DOT__sqrt_xn_add_wrt = Vpa_fpu__ConstPool__TABLE_h8f677608_0
            [__Vtableidx6];
    }
    if ((0x20U & Vpa_fpu__ConstPool__TABLE_hcf65d04e_0
         [__Vtableidx6])) {
        vlSelfRef.fpu__DOT__sqrt_A_a_wrt = Vpa_fpu__ConstPool__TABLE_h917f4cf8_0
            [__Vtableidx6];
    }
    if ((0x40U & Vpa_fpu__ConstPool__TABLE_hcf65d04e_0
         [__Vtableidx6])) {
        vlSelfRef.fpu__DOT__sqrt_a_xn_wrt = Vpa_fpu__ConstPool__TABLE_h10089e38_0
            [__Vtableidx6];
    }
    if ((0x80U & Vpa_fpu__ConstPool__TABLE_hcf65d04e_0
         [__Vtableidx6])) {
        vlSelfRef.fpu__DOT__sqrt_a_A_wrt = Vpa_fpu__ConstPool__TABLE_h1fdf9182_0
            [__Vtableidx6];
    }
    if ((0x100U & Vpa_fpu__ConstPool__TABLE_hcf65d04e_0
         [__Vtableidx6])) {
        vlSelfRef.fpu__DOT__sqrt_b_xn_wrt = Vpa_fpu__ConstPool__TABLE_h1fdf9182_0
            [__Vtableidx6];
    }
    if ((0x200U & Vpa_fpu__ConstPool__TABLE_hcf65d04e_0
         [__Vtableidx6])) {
        vlSelfRef.fpu__DOT__sqrt_b_div_wrt = Vpa_fpu__ConstPool__TABLE_h10089e38_0
            [__Vtableidx6];
    }
    fpu__DOT__unnamedblk2__DOT__shift = (0xffU & ((IData)(vlSelfRef.fpu__DOT__a_exp) 
                                                  - (IData)(0x7fU)));
    fpu__DOT__unnamedblk2__DOT__intval = 0U;
    fpu__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i = 0U;
    while ((fpu__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i 
            <= (IData)(fpu__DOT__unnamedblk2__DOT__shift))) {
        vlSelfRef.fpu__DOT____Vlvbound_hbdf1056a__0 
            = ((0x19U >= (0x1fU & (((IData)(0x17U) 
                                    - fpu__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i) 
                                   - (IData)(fpu__DOT__unnamedblk2__DOT__shift)))) 
               && (1U & (vlSelfRef.fpu__DOT__a_mantissa 
                         >> (0x1fU & (((IData)(0x17U) 
                                       - fpu__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i) 
                                      - (IData)(fpu__DOT__unnamedblk2__DOT__shift))))));
        if (VL_LIKELY(((0x17U >= (0x1fU & fpu__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i))))) {
            fpu__DOT__unnamedblk2__DOT__intval = ((
                                                   (~ 
                                                    ((IData)(1U) 
                                                     << 
                                                     (0x1fU 
                                                      & fpu__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i))) 
                                                   & fpu__DOT__unnamedblk2__DOT__intval) 
                                                  | (0xffffffU 
                                                     & ((IData)(vlSelfRef.fpu__DOT____Vlvbound_hbdf1056a__0) 
                                                        << 
                                                        (0x1fU 
                                                         & fpu__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i))));
        }
        fpu__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i 
            = ((IData)(1U) + fpu__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i);
    }
    vlSelfRef.fpu__DOT__result_float2int = fpu__DOT__unnamedblk2__DOT__intval;
    fpu__DOT__div24_frac__DOT__partial = (0xffffffU 
                                          & vlSelfRef.fpu__DOT__a_mantissa);
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0x7fffffU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 0x17U));
    if ((0x800000U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0x16U)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0x16U)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xbfffffU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 0x16U));
    if ((0x400000U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0x15U)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0x15U)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xdfffffU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 0x15U));
    if ((0x200000U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0x14U)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0x14U)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xefffffU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 0x14U));
    if ((0x100000U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0x13U)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0x13U)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xf7ffffU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 0x13U));
    if ((0x80000U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0x12U)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0x12U)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xfbffffU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 0x12U));
    if ((0x40000U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0x11U)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0x11U)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xfdffffU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 0x11U));
    if ((0x20000U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0x10U)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0x10U)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xfeffffU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 0x10U));
    if ((0x10000U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0xfU)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0xfU)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xff7fffU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 0xfU));
    if ((0x8000U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0xeU)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0xeU)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xffbfffU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 0xeU));
    if ((0x4000U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0xdU)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0xdU)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xffdfffU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 0xdU));
    if ((0x2000U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0xcU)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0xcU)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xffefffU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 0xcU));
    if ((0x1000U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0xbU)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0xbU)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xfff7ffU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 0xbU));
    if ((0x800U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0xaU)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 0xaU)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xfffbffU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 0xaU));
    if ((0x400U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 9U)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 9U)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xfffdffU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 9U));
    if ((0x200U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 8U)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 8U)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xfffeffU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 8U));
    if ((0x100U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 7U)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 7U)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xffff7fU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 7U));
    if ((0x80U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 6U)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 6U)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xffffbfU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 6U));
    if ((0x40U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 5U)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 5U)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xffffdfU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 5U));
    if ((0x20U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 4U)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 4U)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xffffefU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 4U));
    if ((0x10U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 3U)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 3U)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xfffff7U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 3U));
    if ((8U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 2U)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 2U)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xfffffbU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 2U));
    if ((4U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 1U)));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & (vlSelfRef.fpu__DOT__a_mantissa 
                                                    >> 1U)));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0 
        = (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                    >> 0x19U)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xfffffdU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | ((IData)(fpu__DOT__div24_frac__DOT____Vlvbound_hc77ac682__0) 
            << 1U));
    if ((2U & vlSelfRef.fpu__DOT__div_quotient_prenorm_out)) {
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & vlSelfRef.fpu__DOT__a_mantissa));
    } else {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
        fpu__DOT__div24_frac__DOT__partial = ((0x1fffffeU 
                                               & (fpu__DOT__div24_frac__DOT__partial 
                                                  << 1U)) 
                                              | (1U 
                                                 & vlSelfRef.fpu__DOT__a_mantissa));
    }
    fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                          & (fpu__DOT__div24_frac__DOT__partial 
                                             - (0xffffffU 
                                                & vlSelfRef.fpu__DOT__b_mantissa)));
    vlSelfRef.fpu__DOT__div_quotient_prenorm_out = 
        ((0xfffffeU & vlSelfRef.fpu__DOT__div_quotient_prenorm_out) 
         | (1U & (~ (fpu__DOT__div24_frac__DOT__partial 
                     >> 0x19U))));
    if ((1U & (~ vlSelfRef.fpu__DOT__div_quotient_prenorm_out))) {
        fpu__DOT__div24_frac__DOT__partial = (0x3ffffffU 
                                              & (fpu__DOT__div24_frac__DOT__partial 
                                                 + 
                                                 (0xffffffU 
                                                  & vlSelfRef.fpu__DOT__b_mantissa)));
    }
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_80 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_85 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_83 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 0x16U));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_91 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_90 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_88 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_98 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_97 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_96 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 0x15U));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_94 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_106 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_105 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_104 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_103 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_101 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_115 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_114 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_113 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_112 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 0x14U));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_111 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_109 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_125 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_124 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_123 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_122 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_121 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_120 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_118 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_136 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_135 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_134 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_133 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_132 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 0x13U));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_131 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_130 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_128 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_148 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_147 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_146 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_145 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_144 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_143 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_142 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_141 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_139 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_161 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_160 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_159 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_158 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_157 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_156 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 0x12U));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_155 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_154 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_153 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_151 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_175 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_174 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_173 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_172 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_171 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_170 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_169 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_168 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_167 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_166 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_164 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_190 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_189 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_188 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_187 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_186 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_185 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_184 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 0x11U));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_183 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_182 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_181 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_180 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_178 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_206 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_205 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_204 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_203 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_202 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_201 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_200 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_199 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_198 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_197 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_196 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_195 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_193 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_223 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_222 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_221 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_220 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_219 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_218 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_217 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_216 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 0x10U));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_215 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_214 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_213 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_212 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_211 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_209 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_241 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_240 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_239 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_238 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_237 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_236 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_235 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_234 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_233 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_232 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_231 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_230 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_229 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_228 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_226 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_260 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_259 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_258 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_257 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_256 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_255 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_254 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_253 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_252 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 0xfU));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_251 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_250 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_249 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_248 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_247 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_246 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_244 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_280 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_279 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_278 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_277 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_276 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_275 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_274 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_273 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_272 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_271 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_270 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_269 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_268 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_267 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_266 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_265 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_263 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_301 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_300 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_299 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_298 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_297 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_296 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_295 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_294 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_293 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_292 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 0xeU));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_291 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_290 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_289 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_288 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_287 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_286 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_285 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_283 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_323 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_322 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_321 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_320 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_319 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_318 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_317 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_316 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_315 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_314 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_313 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_312 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_311 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_310 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_309 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_308 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_307 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_306 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_304 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_346 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_345 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_344 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_343 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_342 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_341 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_340 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_339 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_338 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_337 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_336 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 0xdU));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_335 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_334 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_333 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_332 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_331 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_330 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_329 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_328 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_326 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_371 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_369 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_368 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_367 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_366 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_365 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_364 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_363 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_362 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_361 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_360 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_359 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_358 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_357 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_356 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_355 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_354 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_353 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_352 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_351 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_349 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_396 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_395 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_393 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_392 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_391 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_390 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_389 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_388 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_387 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_386 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_385 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_384 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 0xcU));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_383 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_382 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_381 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_380 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_379 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_378 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_377 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_376 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_375 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_373 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_422 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 0x17U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_421 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_420 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_418 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_417 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_416 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_415 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_414 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_413 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_412 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_411 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_410 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_409 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_408 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_407 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_406 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_405 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_404 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_403 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_402 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_401 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_400 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_398 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_448 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 0x16U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_447 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_446 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_444 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_443 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_442 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_441 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_440 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_439 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_438 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_437 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_436 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 0xbU));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_435 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_434 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_433 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_432 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_431 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_430 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_429 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_428 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_427 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_426 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_424 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x16U) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_472 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 0x15U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_471 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_470 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_468 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_467 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_466 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_465 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_464 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_463 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_462 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_461 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_460 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_459 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_458 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_457 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_456 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_455 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_454 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_453 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_452 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_451 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_450 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x15U) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_495 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 0x14U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_494 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_493 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_491 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_490 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_489 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_488 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_487 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_486 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_485 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_484 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 0xaU));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_483 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_482 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_481 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_480 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_479 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_478 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_477 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_476 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_475 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_474 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x14U) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_517 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 0x13U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_516 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_515 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_513 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_512 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_511 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_510 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_509 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_508 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_507 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_506 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_505 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_504 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_503 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_502 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_501 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_500 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_499 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_498 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_497 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x13U) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_538 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 0x12U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_537 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_536 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_535 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_533 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_532 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_531 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_530 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_529 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_528 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 9U));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_527 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_526 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_525 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_524 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_523 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_522 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_521 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_520 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_519 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x12U) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_558 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 0x11U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_557 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_556 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_554 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_553 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_552 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_551 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_550 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_549 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_548 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_547 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_546 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_545 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_544 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_543 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_542 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_541 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_540 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x11U) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_577 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 0x10U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_576 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_575 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_574 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_572 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_571 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_570 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_569 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_568 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 8U));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_567 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_566 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_565 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_564 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_563 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_562 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_561 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_560 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0x10U) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_595 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 0xfU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_594 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_593 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_591 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_590 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_589 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_588 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_587 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_586 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_585 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_584 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_583 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_582 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_581 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_580 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_579 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xfU) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_612 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 0xeU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_611 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_610 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_609 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_607 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_606 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_605 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_604 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 7U));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_603 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_602 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_601 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_600 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_599 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_598 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_597 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xeU) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_628 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 0xdU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_627 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_626 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_624 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_623 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_622 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_621 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_620 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_619 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_618 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_617 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_616 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_615 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_614 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xdU) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_643 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 0xcU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_642 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_641 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_640 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_638 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_637 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_636 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 6U));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_635 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_634 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_633 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_632 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_631 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_630 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xcU) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_657 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 0xbU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_656 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_655 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_653 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_652 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_651 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_650 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_649 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_648 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_647 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_646 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_645 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xbU) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_670 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 0xaU)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_669 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_668 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_667 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_665 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_664 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 5U));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_663 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_662 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_661 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_660 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_659 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 0xaU) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_682 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 9U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_681 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_680 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_678 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_677 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_676 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_675 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_674 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_673 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_672 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 9U) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_693 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_692 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_691 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_690 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_688 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 4U));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_687 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_686 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_685 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_684 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 8U) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_703 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 7U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_702 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_701 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_699 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_698 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_697 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_696 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_695 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 7U) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_712 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 6U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_711 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_710 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_709 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 3U));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_707 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_706 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_705 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 6U) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_720 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 5U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_719 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_718 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_716 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_715 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_714 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 5U) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_727 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 4U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_726 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_725 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 2U));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_724 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_722 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 4U) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_733 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 3U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_732 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_731 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & (vlSelfRef.fpu__DOT__a_mantissa 
                    >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_729 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 3U) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_738 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 2U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_737 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa) 
                 >> 1U));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_736 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 2U) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_742 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & (vlSelfRef.fpu__DOT__a_mantissa 
                                                   >> 1U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_741 
        = (1U & ((vlSelfRef.fpu__DOT__b_mantissa >> 1U) 
                 & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_745 
        = (1U & (vlSelfRef.fpu__DOT__b_mantissa & vlSelfRef.fpu__DOT__a_mantissa));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
        = ((- (QData)((IData)((1U & (vlSelfRef.fpu__DOT__b_mantissa 
                                     >> 0x17U))))) 
           & ((QData)((IData)((0xffffffU & vlSelfRef.fpu__DOT__a_mantissa))) 
              << 0x17U));
    if (fpu__DOT____VdfgRegularize_hab43e411_0_8) {
        vlSelfRef.fpu__DOT__a_exp_adjusted = vlSelfRef.fpu__DOT__b_exp;
        fpu__DOT__a_mantissa_shifted = (0x3ffffffU 
                                        & VL_SHIFTR_III(26,26,9, vlSelfRef.fpu__DOT__a_mantissa, 
                                                        (0x1ffU 
                                                         & (- (IData)(fpu__DOT__ab_exp_diff)))));
    } else {
        vlSelfRef.fpu__DOT__a_exp_adjusted = vlSelfRef.fpu__DOT__a_exp;
        fpu__DOT__a_mantissa_shifted = (0x3ffffffU 
                                        & vlSelfRef.fpu__DOT__a_mantissa);
    }
    fpu__DOT__b_mantissa_shifted = (0x3ffffffU & (((IData)(vlSelfRef.fpu__DOT__b_exp) 
                                                   < (IData)(vlSelfRef.fpu__DOT__a_exp))
                                                   ? 
                                                  VL_SHIFTR_III(26,26,9, vlSelfRef.fpu__DOT__b_mantissa, (IData)(fpu__DOT__ab_exp_diff))
                                                   : vlSelfRef.fpu__DOT__b_mantissa));
    __Vtableidx5 = (((IData)(vlSelfRef.fpu__DOT__sqrt_counter) 
                     << 5U) | (((IData)(vlSelfRef.fpu__DOT__start_operation_sqrt_fsm) 
                                << 4U) | (IData)(vlSelfRef.fpu__DOT__curr_state_sqrt_fsm)));
    vlSelfRef.fpu__DOT__next_state_sqrt_fsm = Vpa_fpu__ConstPool__TABLE_h855ee2ba_0
        [__Vtableidx5];
    vlSelfRef.fpu__DOT__zcount_div = (0x1fU & (([&]() {
                    vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a 
                        = vlSelfRef.fpu__DOT__div_quotient_prenorm_out;
                    __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0;
                    {
                        if ((vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a 
                             >> 0x1fU)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 1U;
                        if ((0x40000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 1U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 2U;
                        if ((0x20000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 2U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 3U;
                        if ((0x10000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 3U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 4U;
                        if ((0x8000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 4U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 5U;
                        if ((0x4000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 5U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 6U;
                        if ((0x2000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 6U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 7U;
                        if ((0x1000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 7U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 8U;
                        if ((0x800000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 8U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 9U;
                        if ((0x400000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 9U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0xaU;
                        if ((0x200000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0xaU;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0xbU;
                        if ((0x100000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0xbU;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0xcU;
                        if ((0x80000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0xcU;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0xdU;
                        if ((0x40000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0xdU;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0xeU;
                        if ((0x20000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0xeU;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0xfU;
                        if ((0x10000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0xfU;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x10U;
                        if ((0x8000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x10U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x11U;
                        if ((0x4000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x11U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x12U;
                        if ((0x2000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x12U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x13U;
                        if ((0x1000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x13U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x14U;
                        if ((0x800U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x14U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x15U;
                        if ((0x400U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x15U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x16U;
                        if ((0x200U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x16U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x17U;
                        if ((0x100U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x17U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x18U;
                        if ((0x80U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x18U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x19U;
                        if ((0x40U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x19U;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x1aU;
                        if ((0x20U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x1aU;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x1bU;
                        if ((0x10U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x1bU;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x1cU;
                        if ((8U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x1cU;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x1dU;
                        if ((4U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x1dU;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x1eU;
                        if ((2U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x1eU;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x1fU;
                        if ((1U & vlSelfRef.__Vfunc_fpu__DOT__lzc__1__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x1fU;
                            goto __Vlabel3;
                        }
                        __Vfunc_fpu__DOT__lzc__1__unnamedblk1__DOT__i = 0x20U;
                        vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout = 0x20U;
                        __Vlabel3: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_fpu__DOT__lzc__1__Vfuncout)) 
                                               - (IData)(8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_744 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_745) 
                    + (1U & (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28))));
    vlSelfRef.fpu__DOT__a_mantissa_adjusted = (0x3ffffffU 
                                               & ((IData)(vlSelfRef.fpu__DOT__a_sign)
                                                   ? 
                                                  ((IData)(1U) 
                                                   + 
                                                   (~ fpu__DOT__a_mantissa_shifted))
                                                   : fpu__DOT__a_mantissa_shifted));
    vlSelfRef.fpu__DOT__b_mantissa_adjusted = (0x3ffffffU 
                                               & ((IData)(vlSelfRef.fpu__DOT__b_sign)
                                                   ? 
                                                  ((IData)(1U) 
                                                   + 
                                                   (~ fpu__DOT__b_mantissa_shifted))
                                                   : fpu__DOT__b_mantissa_shifted));
    __Vtableidx3 = ((((IData)(vlSelfRef.operation) 
                      << 6U) | ((IData)(vlSelfRef.fpu__DOT__operation_done_sqrt_fsm) 
                                << 5U)) | (((IData)(vlSelfRef.fpu__DOT__start_operation_ar_fsm) 
                                            << 4U) 
                                           | (IData)(vlSelfRef.fpu__DOT__curr_state_arith_fsm)));
    vlSelfRef.fpu__DOT__next_state_arith_fsm = Vpa_fpu__ConstPool__TABLE_h24e7a3d6_0
        [__Vtableidx3];
    vlSelfRef.fpu__DOT__result_exp_div = (0xffU & (
                                                   ((IData)(0x7fU) 
                                                    + 
                                                    ((IData)(vlSelfRef.fpu__DOT__a_exp) 
                                                     - (IData)(vlSelfRef.fpu__DOT__b_exp))) 
                                                   - (IData)(vlSelfRef.fpu__DOT__zcount_div)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_740 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_742) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_741) 
                       + ((1U & (IData)((fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                         >> 1U))) + 
                          VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_744), 1U)))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_735 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_738) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_737) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_736) 
                          + ((1U & (IData)((fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                            >> 2U))) 
                             + VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_740), 1U))))));
    vlSelfRef.fpu__DOT__result_m_addsub_prenorm = (0x3ffffffU 
                                                   & ((0U 
                                                       == (IData)(vlSelfRef.operation))
                                                       ? 
                                                      (vlSelfRef.fpu__DOT__a_mantissa_adjusted 
                                                       + vlSelfRef.fpu__DOT__b_mantissa_adjusted)
                                                       : 
                                                      (vlSelfRef.fpu__DOT__a_mantissa_adjusted 
                                                       - vlSelfRef.fpu__DOT__b_mantissa_adjusted)));
    fpu__DOT__result_m_addsub_abs = (0x3ffffffU & (
                                                   (0x2000000U 
                                                    & vlSelfRef.fpu__DOT__result_m_addsub_prenorm)
                                                    ? 
                                                   (- vlSelfRef.fpu__DOT__result_m_addsub_prenorm)
                                                    : vlSelfRef.fpu__DOT__result_m_addsub_prenorm));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_730 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_733) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_732) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_731) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_729) 
                             + ((1U & (IData)((fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                               >> 3U))) 
                                + VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_735), 1U)))))));
    fpu__DOT__zcount_addsub = (0x3fU & (([&]() {
                    vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a 
                        = fpu__DOT__result_m_addsub_abs;
                    __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0;
                    {
                        if ((vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a 
                             >> 0x1fU)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 1U;
                        if ((0x40000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 1U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 2U;
                        if ((0x20000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 2U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 3U;
                        if ((0x10000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 3U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 4U;
                        if ((0x8000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 4U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 5U;
                        if ((0x4000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 5U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 6U;
                        if ((0x2000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 6U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 7U;
                        if ((0x1000000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 7U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 8U;
                        if ((0x800000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 8U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 9U;
                        if ((0x400000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 9U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0xaU;
                        if ((0x200000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0xaU;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0xbU;
                        if ((0x100000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0xbU;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0xcU;
                        if ((0x80000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0xcU;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0xdU;
                        if ((0x40000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0xdU;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0xeU;
                        if ((0x20000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0xeU;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0xfU;
                        if ((0x10000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0xfU;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x10U;
                        if ((0x8000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x10U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x11U;
                        if ((0x4000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x11U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x12U;
                        if ((0x2000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x12U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x13U;
                        if ((0x1000U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x13U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x14U;
                        if ((0x800U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x14U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x15U;
                        if ((0x400U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x15U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x16U;
                        if ((0x200U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x16U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x17U;
                        if ((0x100U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x17U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x18U;
                        if ((0x80U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x18U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x19U;
                        if ((0x40U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x19U;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x1aU;
                        if ((0x20U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x1aU;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x1bU;
                        if ((0x10U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x1bU;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x1cU;
                        if ((8U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x1cU;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x1dU;
                        if ((4U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x1dU;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x1eU;
                        if ((2U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x1eU;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x1fU;
                        if ((1U & vlSelfRef.__Vfunc_fpu__DOT__lzc__0__a)) {
                            vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x1fU;
                            goto __Vlabel4;
                        }
                        __Vfunc_fpu__DOT__lzc__0__unnamedblk1__DOT__i = 0x20U;
                        vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout = 0x20U;
                        __Vlabel4: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_fpu__DOT__lzc__0__Vfuncout)) 
                                        - (IData)(8U)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_723 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_727) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_726) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_725) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_724) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_722) 
                                + ((1U & (IData)((fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                  >> 4U))) 
                                   + VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_730), 1U))))))));
    if ((0U == fpu__DOT__result_m_addsub_abs)) {
        vlSelfRef.fpu__DOT__result_m_addsub_norm = 
            (0x3ffffffU & fpu__DOT__result_m_addsub_abs);
        vlSelfRef.fpu__DOT__result_e_addsub_norm = 0U;
    } else if ((0x1000000U & fpu__DOT__result_m_addsub_abs)) {
        vlSelfRef.fpu__DOT__result_m_addsub_norm = 
            (0x3ffffffU & VL_SHIFTR_III(26,26,32, fpu__DOT__result_m_addsub_abs, 1U));
        vlSelfRef.fpu__DOT__result_e_addsub_norm = 
            (0xffU & ((IData)(1U) + (IData)(vlSelfRef.fpu__DOT__a_exp_adjusted)));
    } else {
        vlSelfRef.fpu__DOT__result_m_addsub_norm = 
            (0x3ffffffU & VL_SHIFTL_III(26,26,6, fpu__DOT__result_m_addsub_abs, (IData)(fpu__DOT__zcount_addsub)));
        vlSelfRef.fpu__DOT__result_e_addsub_norm = 
            (0xffU & ((IData)(vlSelfRef.fpu__DOT__a_exp_adjusted) 
                      - (IData)(fpu__DOT__zcount_addsub)));
    }
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_717 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_720) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_719) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_718) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_716) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_715) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_714) 
                                   + ((1U & (IData)(
                                                    (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                     >> 5U))) 
                                      + VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_723), 1U)))))))));
    fpu__DOT____VdfgRegularize_hab43e411_0_6 = ((0x80000000U 
                                                 & (vlSelfRef.fpu__DOT__result_m_addsub_prenorm 
                                                    << 6U)) 
                                                | (((IData)(vlSelfRef.fpu__DOT__result_e_addsub_norm) 
                                                    << 0x17U) 
                                                   | (0x7fffffU 
                                                      & vlSelfRef.fpu__DOT__result_m_addsub_norm)));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_708 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_712) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_711) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_710) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_709) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_707) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_706) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_705) 
                                      + ((1U & (IData)(
                                                       (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                        >> 6U))) 
                                         + VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_717), 1U))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_700 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_703) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_702) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_701) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_699) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_698) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_697) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_696) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_695) 
                                         + ((1U & (IData)(
                                                          (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                           >> 7U))) 
                                            + VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_708), 1U)))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_689 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_693) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_692) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_691) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_690) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_688) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_687) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_686) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_685) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_684) 
                                            + ((1U 
                                                & (IData)(
                                                          (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                           >> 8U))) 
                                               + VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_700), 1U))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_679 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_682) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_681) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_680) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_678) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_677) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_676) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_675) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_674) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_673) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_672) 
                                               + ((1U 
                                                   & (IData)(
                                                             (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                              >> 9U))) 
                                                  + 
                                                  VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_689), 1U)))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_666 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_670) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_669) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_668) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_667) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_665) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_664) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_663) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_662) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_661) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_660) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_659) 
                                                  + 
                                                  ((1U 
                                                    & (IData)(
                                                              (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                               >> 0xaU))) 
                                                   + 
                                                   VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_679), 1U))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_654 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_657) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_656) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_655) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_653) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_652) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_651) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_650) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_649) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_648) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_647) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_646) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_645) 
                                                   + 
                                                   ((1U 
                                                     & (IData)(
                                                               (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                >> 0xbU))) 
                                                    + 
                                                    VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_666), 1U)))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_639 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_643) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_642) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_641) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_640) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_638) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_637) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_636) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_635) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_634) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_633) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_632) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_631) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_630) 
                                                    + 
                                                    ((1U 
                                                      & (IData)(
                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                 >> 0xcU))) 
                                                     + 
                                                     VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_654), 1U))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_625 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_628) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_627) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_626) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_624) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_623) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_622) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_621) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_620) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_619) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_618) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_617) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_616) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_615) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_614) 
                                                     + 
                                                     ((1U 
                                                       & (IData)(
                                                                 (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                  >> 0xdU))) 
                                                      + 
                                                      VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_639), 1U)))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_608 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_612) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_611) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_610) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_609) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_607) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_606) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_605) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_604) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_603) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_602) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_601) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_600) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_599) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_598) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_597) 
                                                      + 
                                                      ((1U 
                                                        & (IData)(
                                                                  (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                   >> 0xeU))) 
                                                       + 
                                                       VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_625), 1U))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_592 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_595) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_594) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_593) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_591) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_590) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_589) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_588) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_587) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_586) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_585) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_584) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_583) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_582) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_581) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_580) 
                                                      + 
                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_579) 
                                                       + 
                                                       ((1U 
                                                         & (IData)(
                                                                   (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                    >> 0xfU))) 
                                                        + 
                                                        VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_608), 1U)))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_573 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_577) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_576) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_575) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_574) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_572) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_571) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_570) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_569) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_568) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_567) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_566) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_565) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_564) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_563) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_562) 
                                                      + 
                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_561) 
                                                       + 
                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_560) 
                                                        + 
                                                        ((1U 
                                                          & (IData)(
                                                                    (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                     >> 0x10U))) 
                                                         + 
                                                         VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_592), 1U))))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_555 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_558) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_557) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_556) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_554) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_553) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_552) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_551) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_550) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_549) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_548) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_547) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_546) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_545) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_544) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_543) 
                                                      + 
                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_542) 
                                                       + 
                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_541) 
                                                        + 
                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_540) 
                                                         + 
                                                         ((1U 
                                                           & (IData)(
                                                                     (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                      >> 0x11U))) 
                                                          + 
                                                          VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_573), 1U)))))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_534 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_538) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_537) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_536) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_535) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_533) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_532) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_531) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_530) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_529) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_528) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_527) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_526) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_525) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_524) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_523) 
                                                      + 
                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_522) 
                                                       + 
                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_521) 
                                                        + 
                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_520) 
                                                         + 
                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_519) 
                                                          + 
                                                          ((1U 
                                                            & (IData)(
                                                                      (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                       >> 0x12U))) 
                                                           + 
                                                           VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_555), 1U))))))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_514 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_517) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_516) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_515) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_513) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_512) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_511) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_510) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_509) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_508) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_507) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_506) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_505) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_504) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_503) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_502) 
                                                      + 
                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_501) 
                                                       + 
                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_500) 
                                                        + 
                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_499) 
                                                         + 
                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_498) 
                                                          + 
                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_497) 
                                                           + 
                                                           ((1U 
                                                             & (IData)(
                                                                       (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                        >> 0x13U))) 
                                                            + 
                                                            VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_534), 1U)))))))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_492 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_495) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_494) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_493) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_491) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_490) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_489) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_488) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_487) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_486) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_485) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_484) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_483) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_482) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_481) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_480) 
                                                      + 
                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_479) 
                                                       + 
                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_478) 
                                                        + 
                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_477) 
                                                         + 
                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_476) 
                                                          + 
                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_475) 
                                                           + 
                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_474) 
                                                            + 
                                                            ((1U 
                                                              & (IData)(
                                                                        (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                         >> 0x14U))) 
                                                             + 
                                                             VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_514), 1U))))))))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_469 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_472) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_471) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_470) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_468) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_467) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_466) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_465) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_464) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_463) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_462) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_461) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_460) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_459) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_458) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_457) 
                                                      + 
                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_456) 
                                                       + 
                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_455) 
                                                        + 
                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_454) 
                                                         + 
                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_453) 
                                                          + 
                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_452) 
                                                           + 
                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_451) 
                                                            + 
                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_450) 
                                                             + 
                                                             ((1U 
                                                               & (IData)(
                                                                         (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                          >> 0x15U))) 
                                                              + 
                                                              VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_492), 1U)))))))))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_445 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_448) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_447) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_446) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_444) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_443) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_442) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_441) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_440) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_439) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_438) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_437) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_436) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_435) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_434) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_433) 
                                                      + 
                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_432) 
                                                       + 
                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_431) 
                                                        + 
                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_430) 
                                                         + 
                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_429) 
                                                          + 
                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_428) 
                                                           + 
                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_427) 
                                                            + 
                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_426) 
                                                             + 
                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_424) 
                                                              + 
                                                              ((1U 
                                                                & (IData)(
                                                                          (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                           >> 0x16U))) 
                                                               + 
                                                               VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_469), 1U))))))))))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_419 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_422) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_421) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_420) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_418) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_417) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_416) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_415) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_414) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_413) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_412) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_411) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_410) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_409) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_408) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_407) 
                                                      + 
                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_406) 
                                                       + 
                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_405) 
                                                        + 
                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_404) 
                                                         + 
                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_403) 
                                                          + 
                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_402) 
                                                           + 
                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_401) 
                                                            + 
                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_400) 
                                                             + 
                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_398) 
                                                              + 
                                                              ((1U 
                                                                & (IData)(
                                                                          (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                           >> 0x17U))) 
                                                               + 
                                                               VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_445), 1U))))))))))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_394 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_396) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_395) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_393) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_392) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_391) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_390) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_389) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_388) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_387) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_386) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_385) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_384) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_383) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_382) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_381) 
                                                      + 
                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_380) 
                                                       + 
                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_379) 
                                                        + 
                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_378) 
                                                         + 
                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_377) 
                                                          + 
                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_376) 
                                                           + 
                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_375) 
                                                            + 
                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_373) 
                                                             + 
                                                             ((1U 
                                                               & (IData)(
                                                                         (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                          >> 0x18U))) 
                                                              + 
                                                              VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_419), 1U)))))))))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_370 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_371) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_369) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_368) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_367) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_366) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_365) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_364) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_363) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_362) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_361) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_360) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_359) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_358) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_357) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_356) 
                                                      + 
                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_355) 
                                                       + 
                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_354) 
                                                        + 
                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_353) 
                                                         + 
                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_352) 
                                                          + 
                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_351) 
                                                           + 
                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_349) 
                                                            + 
                                                            ((1U 
                                                              & (IData)(
                                                                        (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                         >> 0x19U))) 
                                                             + 
                                                             VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_394), 1U))))))))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_347 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_346) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_345) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_344) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_343) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_342) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_341) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_340) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_339) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_338) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_337) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_336) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_335) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_334) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_333) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_332) 
                                                      + 
                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_331) 
                                                       + 
                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_330) 
                                                        + 
                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_329) 
                                                         + 
                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_328) 
                                                          + 
                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_326) 
                                                           + 
                                                           ((1U 
                                                             & (IData)(
                                                                       (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                        >> 0x1aU))) 
                                                            + 
                                                            VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_370), 1U)))))))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_324 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_323) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_322) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_321) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_320) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_319) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_318) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_317) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_316) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_315) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_314) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_313) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_312) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_311) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_310) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_309) 
                                                      + 
                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_308) 
                                                       + 
                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_307) 
                                                        + 
                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_306) 
                                                         + 
                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_304) 
                                                          + 
                                                          ((1U 
                                                            & (IData)(
                                                                      (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                       >> 0x1bU))) 
                                                           + 
                                                           VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_347), 1U))))))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_302 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_301) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_300) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_299) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_298) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_297) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_296) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_295) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_294) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_293) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_292) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_291) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_290) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_289) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_288) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_287) 
                                                      + 
                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_286) 
                                                       + 
                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_285) 
                                                        + 
                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_283) 
                                                         + 
                                                         ((1U 
                                                           & (IData)(
                                                                     (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                      >> 0x1cU))) 
                                                          + 
                                                          VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_324), 1U)))))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_281 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_280) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_279) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_278) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_277) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_276) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_275) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_274) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_273) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_272) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_271) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_270) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_269) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_268) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_267) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_266) 
                                                      + 
                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_265) 
                                                       + 
                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_263) 
                                                        + 
                                                        ((1U 
                                                          & (IData)(
                                                                    (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                     >> 0x1dU))) 
                                                         + 
                                                         VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_302), 1U))))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_261 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_260) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_259) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_258) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_257) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_256) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_255) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_254) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_253) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_252) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_251) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_250) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_249) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_248) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_247) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_246) 
                                                      + 
                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_244) 
                                                       + 
                                                       ((1U 
                                                         & (IData)(
                                                                   (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                    >> 0x1eU))) 
                                                        + 
                                                        VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_281), 1U)))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_242 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_241) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_240) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_239) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_238) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_237) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_236) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_235) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_234) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_233) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_232) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_231) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_230) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_229) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_228) 
                                                     + 
                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_226) 
                                                      + 
                                                      ((1U 
                                                        & (IData)(
                                                                  (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                   >> 0x1fU))) 
                                                       + 
                                                       VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_261), 1U))))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_224 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_223) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_222) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_221) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_220) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_219) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_218) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_217) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_216) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_215) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_214) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_213) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_212) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_211) 
                                                    + 
                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_209) 
                                                     + 
                                                     ((1U 
                                                       & (IData)(
                                                                 (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                  >> 0x20U))) 
                                                      + 
                                                      VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_242), 1U)))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_207 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_206) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_205) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_204) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_203) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_202) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_201) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_200) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_199) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_198) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_197) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_196) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_195) 
                                                   + 
                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_193) 
                                                    + 
                                                    ((1U 
                                                      & (IData)(
                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                 >> 0x21U))) 
                                                     + 
                                                     VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_224), 1U))))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_191 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_190) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_189) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_188) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_187) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_186) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_185) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_184) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_183) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_182) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_181) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_180) 
                                                  + 
                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_178) 
                                                   + 
                                                   ((1U 
                                                     & (IData)(
                                                               (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                >> 0x22U))) 
                                                    + 
                                                    VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_207), 1U)))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_176 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_175) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_174) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_173) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_172) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_171) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_170) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_169) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_168) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_167) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_166) 
                                               + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_164) 
                                                  + 
                                                  ((1U 
                                                    & (IData)(
                                                              (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                               >> 0x23U))) 
                                                   + 
                                                   VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_191), 1U))))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_162 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_161) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_160) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_159) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_158) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_157) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_156) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_155) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_154) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_153) 
                                            + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_151) 
                                               + ((1U 
                                                   & (IData)(
                                                             (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                              >> 0x24U))) 
                                                  + 
                                                  VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_176), 1U)))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_149 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_148) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_147) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_146) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_145) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_144) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_143) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_142) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_141) 
                                         + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_139) 
                                            + ((1U 
                                                & (IData)(
                                                          (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                           >> 0x25U))) 
                                               + VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_162), 1U))))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_137 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_136) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_135) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_134) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_133) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_132) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_131) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_130) 
                                      + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_128) 
                                         + ((1U & (IData)(
                                                          (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                           >> 0x26U))) 
                                            + VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_149), 1U)))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_126 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_125) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_124) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_123) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_122) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_121) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_120) 
                                   + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_118) 
                                      + ((1U & (IData)(
                                                       (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                        >> 0x27U))) 
                                         + VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_137), 1U))))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_116 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_115) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_114) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_113) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_112) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_111) 
                                + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_109) 
                                   + ((1U & (IData)(
                                                    (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                     >> 0x28U))) 
                                      + VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_126), 1U)))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_107 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_106) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_105) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_104) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_103) 
                             + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_101) 
                                + ((1U & (IData)((fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                  >> 0x29U))) 
                                   + VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_116), 1U))))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_99 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_98) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_97) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_96) 
                          + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_94) 
                             + ((1U & (IData)((fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                               >> 0x2aU))) 
                                + VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_107), 1U)))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_92 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_91) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_90) 
                       + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_88) 
                          + ((1U & (IData)((fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                            >> 0x2bU))) 
                             + VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_99), 1U))))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_86 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_85) 
                    + ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_83) 
                       + ((1U & (IData)((fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                         >> 0x2cU))) 
                          + VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_92), 1U)))));
    fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_81 
        = (0x3fU & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_80) 
                    + ((1U & (IData)((fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                      >> 0x2dU))) + 
                       VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_86), 1U))));
    fpu__DOT____VdfgRegularize_hab43e411_0_12 = (1U 
                                                 & ((IData)(
                                                            (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                             >> 0x2fU)) 
                                                    + 
                                                    (0x1fU 
                                                     & (((1U 
                                                          & (IData)(
                                                                    (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                     >> 0x2eU))) 
                                                         + 
                                                         VL_SHIFTR_III(6,6,32, (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_81), 1U)) 
                                                        >> 1U))));
    fpu__DOT__product_pre_norm = (((QData)((IData)(
                                                   (((((((IData)(fpu__DOT____VdfgRegularize_hab43e411_0_12) 
                                                         << 0x1fU) 
                                                        | (0x40000000U 
                                                           & (((IData)(
                                                                       (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                        >> 0x2eU)) 
                                                               + 
                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_81) 
                                                                >> 1U)) 
                                                              << 0x1eU))) 
                                                       | ((0x20000000U 
                                                           & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_80) 
                                                               + 
                                                               ((IData)(
                                                                        (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                         >> 0x2dU)) 
                                                                + 
                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_86) 
                                                                 >> 1U))) 
                                                              << 0x1dU)) 
                                                          | (0x10000000U 
                                                             & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_85) 
                                                                 + 
                                                                 ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_83) 
                                                                  + 
                                                                  ((IData)(
                                                                           (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                            >> 0x2cU)) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_92) 
                                                                    >> 1U)))) 
                                                                << 0x1cU)))) 
                                                      | (((0x8000000U 
                                                           & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_91) 
                                                               + 
                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_90) 
                                                                + 
                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_88) 
                                                                 + 
                                                                 ((IData)(
                                                                          (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                           >> 0x2bU)) 
                                                                  + 
                                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_99) 
                                                                   >> 1U))))) 
                                                              << 0x1bU)) 
                                                          | (0x4000000U 
                                                             & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_98) 
                                                                 + 
                                                                 ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_97) 
                                                                  + 
                                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_96) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_94) 
                                                                    + 
                                                                    ((IData)(
                                                                             (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                              >> 0x2aU)) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_107) 
                                                                      >> 1U)))))) 
                                                                << 0x1aU))) 
                                                         | ((0x2000000U 
                                                             & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_106) 
                                                                 + 
                                                                 ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_105) 
                                                                  + 
                                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_104) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_103) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_101) 
                                                                     + 
                                                                     ((IData)(
                                                                              (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                               >> 0x29U)) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_116) 
                                                                       >> 1U))))))) 
                                                                << 0x19U)) 
                                                            | (0x1000000U 
                                                               & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_115) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_114) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_113) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_112) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_111) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_109) 
                                                                        + 
                                                                        ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x28U)) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_126) 
                                                                          >> 1U)))))))) 
                                                                  << 0x18U))))) 
                                                     | ((((0x800000U 
                                                           & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_125) 
                                                               + 
                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_124) 
                                                                + 
                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_123) 
                                                                 + 
                                                                 ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_122) 
                                                                  + 
                                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_121) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_120) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_118) 
                                                                     + 
                                                                     ((IData)(
                                                                              (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                               >> 0x27U)) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_137) 
                                                                       >> 1U))))))))) 
                                                              << 0x17U)) 
                                                          | (0x400000U 
                                                             & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_136) 
                                                                 + 
                                                                 ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_135) 
                                                                  + 
                                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_134) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_133) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_132) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_131) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_130) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_128) 
                                                                        + 
                                                                        ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x26U)) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_149) 
                                                                          >> 1U)))))))))) 
                                                                << 0x16U))) 
                                                         | ((0x200000U 
                                                             & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_148) 
                                                                 + 
                                                                 ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_147) 
                                                                  + 
                                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_146) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_145) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_144) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_143) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_142) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_141) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_139) 
                                                                         + 
                                                                         ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x25U)) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_162) 
                                                                           >> 1U))))))))))) 
                                                                << 0x15U)) 
                                                            | (0x100000U 
                                                               & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_161) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_160) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_159) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_158) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_157) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_156) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_155) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_154) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_153) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_151) 
                                                                            + 
                                                                            ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x24U)) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_176) 
                                                                              >> 1U)))))))))))) 
                                                                  << 0x14U)))) 
                                                        | (((0x80000U 
                                                             & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_175) 
                                                                 + 
                                                                 ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_174) 
                                                                  + 
                                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_173) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_172) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_171) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_170) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_169) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_168) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_167) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_166) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_164) 
                                                                           + 
                                                                           ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x23U)) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_191) 
                                                                             >> 1U))))))))))))) 
                                                                << 0x13U)) 
                                                            | (0x40000U 
                                                               & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_190) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_189) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_188) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_187) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_186) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_185) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_184) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_183) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_182) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_181) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_180) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_178) 
                                                                              + 
                                                                              ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x22U)) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_207) 
                                                                                >> 1U)))))))))))))) 
                                                                  << 0x12U))) 
                                                           | ((0x20000U 
                                                               & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_206) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_205) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_204) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_203) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_202) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_201) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_200) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_199) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_198) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_197) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_196) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_195) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_193) 
                                                                               + 
                                                                               ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x21U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_224) 
                                                                                >> 1U))))))))))))))) 
                                                                  << 0x11U)) 
                                                              | (0x10000U 
                                                                 & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_223) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_222) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_221) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_220) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_219) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_218) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_217) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_216) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_215) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_214) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_213) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_212) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_211) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_209) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x20U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_242) 
                                                                                >> 1U)))))))))))))))) 
                                                                    << 0x10U)))))) 
                                                    | (((((0x8000U 
                                                           & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_241) 
                                                               + 
                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_240) 
                                                                + 
                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_239) 
                                                                 + 
                                                                 ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_238) 
                                                                  + 
                                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_237) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_236) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_235) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_234) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_233) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_232) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_231) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_230) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_229) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_228) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_226) 
                                                                             + 
                                                                             ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x1fU)) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_261) 
                                                                               >> 1U))))))))))))))))) 
                                                              << 0xfU)) 
                                                          | (0x4000U 
                                                             & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_260) 
                                                                 + 
                                                                 ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_259) 
                                                                  + 
                                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_258) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_257) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_256) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_255) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_254) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_253) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_252) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_251) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_250) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_249) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_248) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_247) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_246) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_244) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x1eU)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_281) 
                                                                                >> 1U)))))))))))))))))) 
                                                                << 0xeU))) 
                                                         | ((0x2000U 
                                                             & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_280) 
                                                                 + 
                                                                 ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_279) 
                                                                  + 
                                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_278) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_277) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_276) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_275) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_274) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_273) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_272) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_271) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_270) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_269) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_268) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_267) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_266) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_265) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_263) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x1dU)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_302) 
                                                                                >> 1U))))))))))))))))))) 
                                                                << 0xdU)) 
                                                            | (0x1000U 
                                                               & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_301) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_300) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_299) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_298) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_297) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_296) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_295) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_294) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_293) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_292) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_291) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_290) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_289) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_288) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_287) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_286) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_285) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_283) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x1cU)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_324) 
                                                                                >> 1U)))))))))))))))))))) 
                                                                  << 0xcU)))) 
                                                        | (((0x800U 
                                                             & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_323) 
                                                                 + 
                                                                 ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_322) 
                                                                  + 
                                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_321) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_320) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_319) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_318) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_317) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_316) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_315) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_314) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_313) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_312) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_311) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_310) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_309) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_308) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_307) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_306) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_304) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x1bU)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_347) 
                                                                                >> 1U))))))))))))))))))))) 
                                                                << 0xbU)) 
                                                            | (0x400U 
                                                               & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_346) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_345) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_344) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_343) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_342) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_341) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_340) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_339) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_338) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_337) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_336) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_335) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_334) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_333) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_332) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_331) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_330) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_329) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_328) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_326) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x1aU)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_370) 
                                                                                >> 1U)))))))))))))))))))))) 
                                                                  << 0xaU))) 
                                                           | ((0x200U 
                                                               & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_371) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_369) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_368) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_367) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_366) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_365) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_364) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_363) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_362) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_361) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_360) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_359) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_358) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_357) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_356) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_355) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_354) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_353) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_352) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_351) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_349) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x19U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_394) 
                                                                                >> 1U))))))))))))))))))))))) 
                                                                  << 9U)) 
                                                              | (0x100U 
                                                                 & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_396) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_395) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_393) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_392) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_391) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_390) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_389) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_388) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_387) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_386) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_385) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_384) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_383) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_382) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_381) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_380) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_379) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_378) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_377) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_376) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_375) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_373) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x18U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_419) 
                                                                                >> 1U)))))))))))))))))))))))) 
                                                                    << 8U))))) 
                                                       | ((((0x80U 
                                                             & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_422) 
                                                                 + 
                                                                 ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_421) 
                                                                  + 
                                                                  ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_420) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_418) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_417) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_416) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_415) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_414) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_413) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_412) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_411) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_410) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_409) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_408) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_407) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_406) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_405) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_404) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_403) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_402) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_401) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_400) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_398) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x17U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_445) 
                                                                                >> 1U))))))))))))))))))))))))) 
                                                                << 7U)) 
                                                            | (0x40U 
                                                               & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_448) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_447) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_446) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_444) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_443) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_442) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_441) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_440) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_439) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_438) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_437) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_436) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_435) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_434) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_433) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_432) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_431) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_430) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_429) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_428) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_427) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_426) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_424) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x16U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_469) 
                                                                                >> 1U))))))))))))))))))))))))) 
                                                                  << 6U))) 
                                                           | ((0x20U 
                                                               & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_472) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_471) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_470) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_468) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_467) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_466) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_465) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_464) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_463) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_462) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_461) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_460) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_459) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_458) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_457) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_456) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_455) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_454) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_453) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_452) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_451) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_450) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x15U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_492) 
                                                                                >> 1U)))))))))))))))))))))))) 
                                                                  << 5U)) 
                                                              | (0x10U 
                                                                 & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_495) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_494) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_493) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_491) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_490) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_489) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_488) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_487) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_486) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_485) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_484) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_483) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_482) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_481) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_480) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_479) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_478) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_477) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_476) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_475) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_474) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x14U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_514) 
                                                                                >> 1U))))))))))))))))))))))) 
                                                                    << 4U)))) 
                                                          | (((8U 
                                                               & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_517) 
                                                                   + 
                                                                   ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_516) 
                                                                    + 
                                                                    ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_515) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_513) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_512) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_511) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_510) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_509) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_508) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_507) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_506) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_505) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_504) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_503) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_502) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_501) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_500) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_499) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_498) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_497) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x13U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_534) 
                                                                                >> 1U)))))))))))))))))))))) 
                                                                  << 3U)) 
                                                              | (4U 
                                                                 & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_538) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_537) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_536) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_535) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_533) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_532) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_531) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_530) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_529) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_528) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_527) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_526) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_525) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_524) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_523) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_522) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_521) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_520) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_519) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x12U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_555) 
                                                                                >> 1U))))))))))))))))))))) 
                                                                    << 2U))) 
                                                             | ((2U 
                                                                 & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_558) 
                                                                     + 
                                                                     ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_557) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_556) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_554) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_553) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_552) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_551) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_550) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_549) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_548) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_547) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_546) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_545) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_544) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_543) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_542) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_541) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_540) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x11U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_573) 
                                                                                >> 1U)))))))))))))))))))) 
                                                                    << 1U)) 
                                                                | (1U 
                                                                   & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_577) 
                                                                      + 
                                                                      ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_576) 
                                                                       + 
                                                                       ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_575) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_574) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_572) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_571) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_570) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_569) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_568) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_567) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_566) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_565) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_564) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_563) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_562) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_561) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_560) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0x10U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_592) 
                                                                                >> 1U))))))))))))))))))))))))))) 
                                   << 0x10U) | (QData)((IData)(
                                                               (((((0x8000U 
                                                                    & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_595) 
                                                                        + 
                                                                        ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_594) 
                                                                         + 
                                                                         ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_593) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_591) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_590) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_589) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_588) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_587) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_586) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_585) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_584) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_583) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_582) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_581) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_580) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_579) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0xfU)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_608) 
                                                                                >> 1U)))))))))))))))))) 
                                                                       << 0xfU)) 
                                                                   | (0x4000U 
                                                                      & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_612) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_611) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_610) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_609) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_607) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_606) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_605) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_604) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_603) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_602) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_601) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_600) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_599) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_598) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_597) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0xeU)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_625) 
                                                                                >> 1U))))))))))))))))) 
                                                                         << 0xeU))) 
                                                                  | ((0x2000U 
                                                                      & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_628) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_627) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_626) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_624) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_623) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_622) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_621) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_620) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_619) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_618) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_617) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_616) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_615) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_614) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0xdU)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_639) 
                                                                                >> 1U)))))))))))))))) 
                                                                         << 0xdU)) 
                                                                     | (0x1000U 
                                                                        & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_643) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_642) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_641) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_640) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_638) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_637) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_636) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_635) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_634) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_633) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_632) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_631) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_630) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0xcU)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_654) 
                                                                                >> 1U))))))))))))))) 
                                                                           << 0xcU)))) 
                                                                 | (((0x800U 
                                                                      & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_657) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_656) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_655) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_653) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_652) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_651) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_650) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_649) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_648) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_647) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_646) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_645) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0xbU)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_666) 
                                                                                >> 1U)))))))))))))) 
                                                                         << 0xbU)) 
                                                                     | (0x400U 
                                                                        & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_670) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_669) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_668) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_667) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_665) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_664) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_663) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_662) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_661) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_660) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_659) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 0xaU)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_679) 
                                                                                >> 1U))))))))))))) 
                                                                           << 0xaU))) 
                                                                    | ((0x200U 
                                                                        & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_682) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_681) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_680) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_678) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_677) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_676) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_675) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_674) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_673) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_672) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 9U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_689) 
                                                                                >> 1U)))))))))))) 
                                                                           << 9U)) 
                                                                       | (0x100U 
                                                                          & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_693) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_692) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_691) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_690) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_688) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_687) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_686) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_685) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_684) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 8U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_700) 
                                                                                >> 1U))))))))))) 
                                                                             << 8U))))) 
                                                                | ((((0x80U 
                                                                      & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_703) 
                                                                          + 
                                                                          ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_702) 
                                                                           + 
                                                                           ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_701) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_699) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_698) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_697) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_696) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_695) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 7U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_708) 
                                                                                >> 1U)))))))))) 
                                                                         << 7U)) 
                                                                     | (0x40U 
                                                                        & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_712) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_711) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_710) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_709) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_707) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_706) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_705) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 6U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_717) 
                                                                                >> 1U))))))))) 
                                                                           << 6U))) 
                                                                    | ((0x20U 
                                                                        & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_720) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_719) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_718) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_716) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_715) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_714) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 5U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_723) 
                                                                                >> 1U)))))))) 
                                                                           << 5U)) 
                                                                       | (0x10U 
                                                                          & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_727) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_726) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_725) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_724) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_722) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 4U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_730) 
                                                                                >> 1U))))))) 
                                                                             << 4U)))) 
                                                                   | (((8U 
                                                                        & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_733) 
                                                                            + 
                                                                            ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_732) 
                                                                             + 
                                                                             ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_731) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_729) 
                                                                               + 
                                                                               ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 3U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_735) 
                                                                                >> 1U)))))) 
                                                                           << 3U)) 
                                                                       | (4U 
                                                                          & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_738) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_737) 
                                                                               + 
                                                                               ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_736) 
                                                                                + 
                                                                                ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 2U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_740) 
                                                                                >> 1U))))) 
                                                                             << 2U))) 
                                                                      | ((2U 
                                                                          & (((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_742) 
                                                                              + 
                                                                              ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_741) 
                                                                               + 
                                                                               ((IData)(
                                                                                (fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28 
                                                                                >> 1U)) 
                                                                                + 
                                                                                ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_744) 
                                                                                >> 1U)))) 
                                                                             << 1U)) 
                                                                         | (1U 
                                                                            & ((IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_745) 
                                                                               + (IData)(fpu__DOT__mantissa_mul__DOT____VdfgRegularize_h34717011_0_28))))))))));
    fpu__DOT__product_norm = (0x1ffffffffffffULL & 
                              ((IData)(fpu__DOT____VdfgRegularize_hab43e411_0_12)
                                ? fpu__DOT__product_pre_norm
                                : VL_SHIFTL_QQI(49,49,32, fpu__DOT__product_pre_norm, 1U)));
    vlSelfRef.fpu__DOT__product_rounded = ((0xffffffULL 
                                            & vlSelfRef.fpu__DOT__product_rounded) 
                                           | ((QData)((IData)(
                                                              (0x1ffffffU 
                                                               & ((0xffffffU 
                                                                   & (IData)(
                                                                             (fpu__DOT__product_norm 
                                                                              >> 0x18U))) 
                                                                  + 
                                                                  (1U 
                                                                   & ((IData)(
                                                                              (fpu__DOT__product_norm 
                                                                               >> 0x17U)) 
                                                                      | (((~ 
                                                                           ((IData)(1U) 
                                                                            + (IData)(
                                                                                (fpu__DOT__product_norm 
                                                                                >> 0x18U)))) 
                                                                          & (0U 
                                                                             == 
                                                                             (0xffffffU 
                                                                              & (IData)(fpu__DOT__product_norm)))) 
                                                                         | ((~ (IData)(
                                                                                (fpu__DOT__product_norm 
                                                                                >> 0x17U))) 
                                                                            & (0U 
                                                                               != 
                                                                               (0x7fffffU 
                                                                                & (IData)(fpu__DOT__product_norm))))))))))) 
                                              << 0x18U));
    vlSelfRef.fpu__DOT____VdfgRegularize_hab43e411_0_7 
        = (((IData)(vlSelfRef.fpu__DOT__result_sign_div) 
            << 0x1fU) | ((0x7f800000U & (((((IData)(vlSelfRef.fpu__DOT__a_exp) 
                                            - (IData)(0x7fU)) 
                                           + (IData)(vlSelfRef.fpu__DOT__b_exp)) 
                                          + ((IData)(fpu__DOT____VdfgRegularize_hab43e411_0_12) 
                                             + (1U 
                                                & (IData)(
                                                          (vlSelfRef.fpu__DOT__product_rounded 
                                                           >> 0x30U))))) 
                                         << 0x17U)) 
                         | (0x7fffffU & (IData)((0x1ffffffULL 
                                                 & (((1U 
                                                      & (IData)(
                                                                (vlSelfRef.fpu__DOT__product_rounded 
                                                                 >> 0x30U)))
                                                      ? 
                                                     VL_SHIFTR_QQI(49,49,32, vlSelfRef.fpu__DOT__product_rounded, 1U)
                                                      : vlSelfRef.fpu__DOT__product_rounded) 
                                                    >> 0x18U))))));
    vlSelfRef.ieee_packet_out = ((0U == (IData)(vlSelfRef.operation))
                                  ? fpu__DOT____VdfgRegularize_hab43e411_0_6
                                  : ((1U == (IData)(vlSelfRef.operation))
                                      ? fpu__DOT____VdfgRegularize_hab43e411_0_6
                                      : ((2U == (IData)(vlSelfRef.operation))
                                          ? vlSelfRef.fpu__DOT____VdfgRegularize_hab43e411_0_7
                                          : ((3U == (IData)(vlSelfRef.operation))
                                              ? vlSelfRef.fpu__DOT____VdfgRegularize_hab43e411_0_7
                                              : ((4U 
                                                  == (IData)(vlSelfRef.operation))
                                                  ? 
                                                 (((IData)(vlSelfRef.fpu__DOT__result_sign_div) 
                                                   << 0x1fU) 
                                                  | (((IData)(vlSelfRef.fpu__DOT__result_exp_div) 
                                                      << 0x17U) 
                                                     | (0x7fffffU 
                                                        & (vlSelfRef.fpu__DOT__div_quotient_prenorm_out 
                                                           << (IData)(vlSelfRef.fpu__DOT__zcount_div)))))
                                                  : 
                                                 ((5U 
                                                   == (IData)(vlSelfRef.operation))
                                                   ? 
                                                  (((IData)(vlSelfRef.fpu__DOT__sqrt_xn_exp) 
                                                    << 0x17U) 
                                                   | (0x7fffffU 
                                                      & vlSelfRef.fpu__DOT__sqrt_xn_mantissa))
                                                   : 
                                                  ((0xeU 
                                                    == (IData)(vlSelfRef.operation))
                                                    ? vlSelfRef.fpu__DOT__result_float2int
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlSelfRef.operation))
                                                     ? 
                                                    ((0x80000000U 
                                                      & (vlSelfRef.fpu__DOT__log2_prenorm 
                                                         << 1U)) 
                                                     | ((0x7f800000U 
                                                         & (((IData)(0x7fU) 
                                                             + 
                                                             ((IData)(7U) 
                                                              - (IData)(vlSelfRef.fpu__DOT__log2_zcount))) 
                                                            << 0x17U)) 
                                                        | (0x7fffffU 
                                                           & (VL_SHIFTL_III(31,31,6, vlSelfRef.fpu__DOT__log2_abs, (IData)(vlSelfRef.fpu__DOT__log2_zcount)) 
                                                              >> 7U))))
                                                     : 0U))))))));
}

void Vpa_fpu___024root___eval_triggers__act(Vpa_fpu___024root* vlSelf);

bool Vpa_fpu___024root___eval_phase__act(Vpa_fpu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpa_fpu___024root___eval_phase__act\n"); );
    Vpa_fpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vpa_fpu___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vpa_fpu___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vpa_fpu___024root___eval_phase__nba(Vpa_fpu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpa_fpu___024root___eval_phase__nba\n"); );
    Vpa_fpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vpa_fpu___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpa_fpu___024root___dump_triggers__ico(Vpa_fpu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpa_fpu___024root___dump_triggers__nba(Vpa_fpu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpa_fpu___024root___dump_triggers__act(Vpa_fpu___024root* vlSelf);
#endif  // VL_DEBUG

void Vpa_fpu___024root___eval(Vpa_fpu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpa_fpu___024root___eval\n"); );
    Vpa_fpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vpa_fpu___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("fpu_top.sv", 70, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vpa_fpu___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vpa_fpu___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("fpu_top.sv", 70, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vpa_fpu___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("fpu_top.sv", 70, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vpa_fpu___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vpa_fpu___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vpa_fpu___024root___eval_debug_assertions(Vpa_fpu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpa_fpu___024root___eval_debug_assertions\n"); );
    Vpa_fpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.arst & 0xfeU)))) {
        Verilated::overWidthError("arst");}
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.operation & 0xf0U)))) {
        Verilated::overWidthError("operation");}
    if (VL_UNLIKELY(((vlSelfRef.start & 0xfeU)))) {
        Verilated::overWidthError("start");}
}
#endif  // VL_DEBUG
