#!/bin/bash
set -e
OUT=simulacion                      # carpeta de salida jsjs
mkdir -p "$OUT"
# compila con verilator
verilator --binary -sv --timing --trace -Wno-fatal --top-module tb \
          design.sv testbench.sv -Mdir "$OUT/obj_dir"
#         diseno    testbench           a donde sale
(cd "$OUT" && ./obj_dir/Vtb "$@")
setsid gtkwave "$OUT/waves.vcd" >/dev/null 2>&1 &