// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024unit.h"

VL_ATTR_COLD void Vtb___024unit___ctor_var_reset(Vtb___024unit* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vtb___024unit___ctor_var_reset\n"); );
    // Body
    for (int __Vi = 0; __Vi < 4; ++__Vi) {
        vlSelf->__Venumtab_enum_name0[__Vi] = std::string{""};
    }
    vlSelf->__Venumtab_enum_name0[0] = std::string{"IDLE"};
    vlSelf->__Venumtab_enum_name0[1] = std::string{"WRITE"};
    vlSelf->__Venumtab_enum_name0[2] = std::string{"READ"};
}
