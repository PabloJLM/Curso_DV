// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb__Syms.h"
#include "Vtb___024root.h"

VL_INLINE_OPT VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    IData/*31:0*/ tb__DOT__unnamedblk1__DOT__unnamedblk2_1__DOT__i;
    tb__DOT__unnamedblk1__DOT__unnamedblk2_1__DOT__i = 0;
    VlWide<3>/*95:0*/ __Vtemp_1;
    std::string __Vtemp_2;
    std::string __Vtemp_3;
    std::string __Vtemp_4;
    std::string __Vtemp_5;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x61766573U;
    __Vtemp_1[2U] = 0x77U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelf->tb__DOT__write_en = 0U;
    vlSelf->tb__DOT__read_en = 0U;
    vlSelf->tb__DOT__addr = 0U;
    vlSelf->tb__DOT__wdata = 0U;
    co_await vlSelf->__VtrigSched_h8aadc0b9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb.clk)", 
                                                       "testbench.sv", 
                                                       40);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb__DOT__demo_val = 0xdeadbeefU;
    VL_WRITEF("----------------------------------------\nIniciando prueba: Demostracion de SV para DV\n----------------------------------------\n");
    vlSelf->tb__DOT__unnamedblk1__DOT__pkt.__PVT__op = 1U;
    vlSelf->tb__DOT__unnamedblk1__DOT__pkt.__PVT__address = 0x10U;
    vlSelf->tb__DOT__unnamedblk1__DOT__pkt.__PVT__data = 0xaabb0000U;
    __Vtemp_2 = VL_TO_STRING(vlSelf->tb__DOT__unnamedblk1__DOT__pkt);
    VL_WRITEF("[%0t] Preparando paquete: %@\n",64,VL_TIME_UNITED_Q(1),
              -12,-1,&(__Vtemp_2));
    vlSelf->tb__DOT__history_queue.push_back(vlSelf->tb__DOT__unnamedblk1__DOT__pkt);
    vlSelf->tb__DOT__write_en = (1U == vlSelf->tb__DOT__unnamedblk1__DOT__pkt
                                 .__PVT__op);
    vlSelf->tb__DOT__read_en = (2U == vlSelf->tb__DOT__unnamedblk1__DOT__pkt
                                .__PVT__op);
    vlSelf->tb__DOT__addr = vlSelf->tb__DOT__unnamedblk1__DOT__pkt
        .__PVT__address;
    vlSelf->tb__DOT__wdata = vlSelf->tb__DOT__unnamedblk1__DOT__pkt
        .__PVT__data;
    co_await vlSelf->__VtrigSched_h8aadc0b9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb.clk)", 
                                                       "testbench.sv", 
                                                       64);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb__DOT__write_en = 0U;
    co_await vlSelf->__VtrigSched_h8aadc0b9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb.clk)", 
                                                       "testbench.sv", 
                                                       66);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 1U;
    vlSelf->tb__DOT__unnamedblk1__DOT__pkt.__PVT__op = 1U;
    vlSelf->tb__DOT__unnamedblk1__DOT__pkt.__PVT__address = 0x11U;
    vlSelf->tb__DOT__unnamedblk1__DOT__pkt.__PVT__data = 0xaabb0001U;
    __Vtemp_3 = VL_TO_STRING(vlSelf->tb__DOT__unnamedblk1__DOT__pkt);
    VL_WRITEF("[%0t] Preparando paquete: %@\n",64,VL_TIME_UNITED_Q(1),
              -12,-1,&(__Vtemp_3));
    vlSelf->tb__DOT__history_queue.push_back(vlSelf->tb__DOT__unnamedblk1__DOT__pkt);
    vlSelf->tb__DOT__write_en = (1U == vlSelf->tb__DOT__unnamedblk1__DOT__pkt
                                 .__PVT__op);
    vlSelf->tb__DOT__read_en = (2U == vlSelf->tb__DOT__unnamedblk1__DOT__pkt
                                .__PVT__op);
    vlSelf->tb__DOT__addr = vlSelf->tb__DOT__unnamedblk1__DOT__pkt
        .__PVT__address;
    vlSelf->tb__DOT__wdata = vlSelf->tb__DOT__unnamedblk1__DOT__pkt
        .__PVT__data;
    co_await vlSelf->__VtrigSched_h8aadc0b9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb.clk)", 
                                                       "testbench.sv", 
                                                       64);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb__DOT__write_en = 0U;
    co_await vlSelf->__VtrigSched_h8aadc0b9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb.clk)", 
                                                       "testbench.sv", 
                                                       66);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 2U;
    vlSelf->tb__DOT__unnamedblk1__DOT__pkt.__PVT__op = 1U;
    vlSelf->tb__DOT__unnamedblk1__DOT__pkt.__PVT__address = 0x12U;
    vlSelf->tb__DOT__unnamedblk1__DOT__pkt.__PVT__data = 0xaabb0002U;
    __Vtemp_4 = VL_TO_STRING(vlSelf->tb__DOT__unnamedblk1__DOT__pkt);
    VL_WRITEF("[%0t] Preparando paquete: %@\n",64,VL_TIME_UNITED_Q(1),
              -12,-1,&(__Vtemp_4));
    vlSelf->tb__DOT__history_queue.push_back(vlSelf->tb__DOT__unnamedblk1__DOT__pkt);
    vlSelf->tb__DOT__write_en = (1U == vlSelf->tb__DOT__unnamedblk1__DOT__pkt
                                 .__PVT__op);
    vlSelf->tb__DOT__read_en = (2U == vlSelf->tb__DOT__unnamedblk1__DOT__pkt
                                .__PVT__op);
    vlSelf->tb__DOT__addr = vlSelf->tb__DOT__unnamedblk1__DOT__pkt
        .__PVT__address;
    vlSelf->tb__DOT__wdata = vlSelf->tb__DOT__unnamedblk1__DOT__pkt
        .__PVT__data;
    co_await vlSelf->__VtrigSched_h8aadc0b9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb.clk)", 
                                                       "testbench.sv", 
                                                       64);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb__DOT__write_en = 0U;
    co_await vlSelf->__VtrigSched_h8aadc0b9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb.clk)", 
                                                       "testbench.sv", 
                                                       66);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 3U;
    VL_WRITEF("\nRevisando el historial guardado en la cola:\n");
    tb__DOT__unnamedblk1__DOT__unnamedblk2_1__DOT__i = 0U;
    while (VL_LTS_III(32, tb__DOT__unnamedblk1__DOT__unnamedblk2_1__DOT__i, vlSelf->tb__DOT__history_queue.size())) {
        __Vtemp_5 = Vtb___024unit::__Venumtab_enum_name0
            [vlSelf->tb__DOT__history_queue.at(tb__DOT__unnamedblk1__DOT__unnamedblk2_1__DOT__i)
            .__PVT__op];
        VL_WRITEF("  -> Indice %0d | Comando: %@ | Addr: %x\n",
                  32,tb__DOT__unnamedblk1__DOT__unnamedblk2_1__DOT__i,
                  -1,&(__Vtemp_5),8,vlSelf->tb__DOT__history_queue.at(tb__DOT__unnamedblk1__DOT__unnamedblk2_1__DOT__i)
                  .__PVT__address);
        tb__DOT__unnamedblk1__DOT__unnamedblk2_1__DOT__i 
            = ((IData)(1U) + tb__DOT__unnamedblk1__DOT__unnamedblk2_1__DOT__i);
    }
    co_await vlSelf->__VdlySched.delay(0x14ULL, nullptr, 
                                       "testbench.sv", 
                                       76);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("Simulaci\303\263n terminada.\n");
    VL_FINISH_MT("testbench.sv", 78, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(Vtb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb___024root___eval_triggers__act(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->tb__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb__DOT__clk__0))));
    vlSelf->__VactTriggered.set(1U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb__DOT__clk__0 
        = vlSelf->tb__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
