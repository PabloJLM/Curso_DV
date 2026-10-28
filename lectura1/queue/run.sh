#!/usr/bin/env bash
set -e

N="$1"
mkdir -p "salida${N}/obj_dir"
verilator --binary -sv --timing --trace -Wno-fatal "ejemplo${N}.sv" -Mdir "salida${N}/obj_dir"
"./salida${N}/obj_dir/Vejemplo${N}"