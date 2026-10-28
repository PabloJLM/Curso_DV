// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb.h for the primary calling header

#ifndef VERILATED_VTB___024ROOT_H_
#define VERILATED_VTB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
#include "Vtb___024root.h"
class Vtb___024unit;


class Vtb__Syms;

// UNPACKED STRUCT TYPES
struct Vtb_tb__DOT__transaction_t__struct__0 {
    CData/*1:0*/ __PVT__op;
    CData/*7:0*/ __PVT__address;
    IData/*31:0*/ __PVT__data;

    bool operator==(const Vtb_tb__DOT__transaction_t__struct__0& rhs) const {
        return __PVT__op == rhs.__PVT__op
            && __PVT__address == rhs.__PVT__address
            && __PVT__data == rhs.__PVT__data;
    }
    bool operator!=(const Vtb_tb__DOT__transaction_t__struct__0& rhs) const {
        return !(*this == rhs);
    }
};

class alignas(VL_CACHE_LINE_BYTES) Vtb___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtb___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb__DOT__clk;
    CData/*0:0*/ tb__DOT__write_en;
    CData/*0:0*/ tb__DOT__read_en;
    CData/*7:0*/ tb__DOT__addr;
    Vtb_tb__DOT__transaction_t__struct__0 tb__DOT__unnamedblk1__DOT__pkt;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ tb__DOT__wdata;
    IData/*31:0*/ tb__DOT__rdata;
    IData/*31:0*/ tb__DOT__demo_val;
    IData/*31:0*/ tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 256> tb__DOT__dut__DOT__mem;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlQueue<Vtb_tb__DOT__transaction_t__struct__0> tb__DOT__history_queue;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h8aadc0b9__0;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb___024root(Vtb__Syms* symsp, const char* v__name);
    ~Vtb___024root();
    VL_UNCOPYABLE(Vtb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vtb_tb__DOT__transaction_t__struct__0& obj);

#endif  // guard
