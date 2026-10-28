# Guía rápida: Icarus Verilog y Verilator en Ubuntu

## 1. Instalación

### Icarus Verilog + GTKWave
sudo apt update
sudo apt install -y iverilog gtkwave

Verificar:
iverilog -V

### Verilator
sudo apt install -y verilator build-essential

Verificar:
verilator --version

---

## 2. Flujo con Icarus Verilog

### 2.1 Archivos de ejemplo

sumador.sv (diseño):
module sumador (
    input  logic [3:0] a,
    input  logic [3:0] b,
    output logic [4:0] suma
);
    assign suma = a + b;
endmodule

tb_sumador.sv (testbench):
module tb_sumador;
    logic [3:0] a, b;
    logic [4:0] suma;

    sumador dut (.a(a), .b(b), .suma(suma));

    initial begin
        $dumpfile("wave.vcd");
        $dumpvars(0, tb_sumador);

        a = 3; b = 4; #10;
        $display("a=%0d b=%0d suma=%0d", a, b, suma);

        a = 15; b = 1; #10;
        $display("a=%0d b=%0d suma=%0d", a, b, suma);

        $finish;
    end
endmodule

### 2.2 Compilar y simular
iverilog -g2012 -o sim sumador.sv tb_sumador.sv
vvp sim

Salida esperada:
a=3 b=4 suma=7
a=15 b=1 suma=16

### 2.3 Ver ondas
gtkwave wave.vcd

### 2.4 Atajo con archivo de lista
Crear files.f:
sumador.sv
tb_sumador.sv

Compilar:
iverilog -g2012 -c files.f -o sim

---

## 3. Flujo con Verilator

Verilator requiere testbench en C++, no en SystemVerilog.

### 3.1 Diseño
Usar el mismo sumador.sv.

### 3.2 Testbench en C++ (tb_main.cpp)

#include "Vsumador.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vsumador* dut = new Vsumador;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("wave.vcd");

    dut->a = 3; dut->b = 4; dut->eval();
    tfp->dump(10);
    printf("a=%d b=%d suma=%d\n", dut->a, dut->b, dut->suma);

    dut->a = 15; dut->b = 1; dut->eval();
    tfp->dump(20);
    printf("a=%d b=%d suma=%d\n", dut->a, dut->b, dut->suma);

    tfp->close();
    delete dut;
    delete tfp;
    return 0;
}

### 3.3 Compilar y ejecutar
verilator --cc --exe --build -j 0 -Wall --trace sumador.sv tb_main.cpp --top sumador
./obj_dir/Vsumador

### 3.4 Ver ondas
gtkwave wave.vcd

---

## 4. Resumen de diferencias

| Característica          | Icarus        | Verilator     |
|-------------------------|---------------|---------------|
| Testbench en SV         | Sí            | No (C++)      |
| Soporte de structs      | Limitado      | Amplio        |
| Velocidad de simulación | Moderada      | Alta          |
| Facilidad de setup      | Alta          | Media         |
| Ideal para              | Pruebas rápidas | SV moderno   |

---

## 5. Notas útiles

- Icarus no soporta unpacked structs. Evitarlos o usar Verilator.
- Siempre incluir $finish en testbenches de Icarus.
- En Verilator, el header C++ es "V" + nombre del top (ej. Vsumador.h).
- GTKWave abre los .vcd generados por ambos simuladores.