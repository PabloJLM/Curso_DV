// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb__Syms.h"


void Vtb___024root__trace_chg_0_sub_0(Vtb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_chg_0\n"); );
    // Init
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb___024root__trace_chg_0_sub_0(Vtb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,(vlSelf->tb__DOT__write_en));
        bufp->chgBit(oldp+1,(vlSelf->tb__DOT__read_en));
        bufp->chgCData(oldp+2,(vlSelf->tb__DOT__addr),8);
        bufp->chgIData(oldp+3,(vlSelf->tb__DOT__wdata),32);
        bufp->chgIData(oldp+4,(vlSelf->tb__DOT__demo_val),32);
        bufp->chgCData(oldp+5,(vlSelf->tb__DOT__unnamedblk1__DOT__pkt
                               .__PVT__op),2);
        bufp->chgCData(oldp+6,(vlSelf->tb__DOT__unnamedblk1__DOT__pkt
                               .__PVT__address),8);
        bufp->chgIData(oldp+7,(vlSelf->tb__DOT__unnamedblk1__DOT__pkt
                               .__PVT__data),32);
        bufp->chgIData(oldp+8,(vlSelf->tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i),32);
    }
    bufp->chgBit(oldp+9,(vlSelf->tb__DOT__clk));
    bufp->chgIData(oldp+10,(vlSelf->tb__DOT__rdata),32);
}

void Vtb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_cleanup\n"); );
    // Init
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
