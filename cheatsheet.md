# Cheatsheet: VCS vs Icarus Verilog vs Verilator

Nota: los flags de VCS pueden variar entre versiones; verificar con `vcs -help`. Icarus asumido >= 11, Verilator >= 5.

Leyenda: **No soportado** = no existe; **(3ros)** = requiere herramienta de terceros; **Parcial** = con condiciones.

---

## 1. Compilacion / elaboracion

| Aspecto | VCS | Icarus | Verilator |
|---|---|---|---|
| Comando base | `vcs -full64 -sverilog -timescale=1ns/1ps -debug_access+all -top tb a.sv tb.sv -o simv` | `iverilog -g2012 -Wall -s tb -o sim.vvp a.sv tb.sv` | `verilator --binary -sv --timing --trace --top-module tb a.sv tb.sv -Mdir obj_dir` |
| Salida | `./simv` (+ `simv.daidir/`, `csrc/`) | `sim.vvp` (se corre con `vvp`) | `obj_dir/Vtb` (compila C++ internamente) |
| Definir top | `-top tb` | `-s tb` | `--top-module tb` |
| Includes | `+incdir+dir` | `-I dir` | `-Idir` |
| Defines | `+define+NAME=val` | `-DNAME=val` | `-DNAME=val` |
| Lista de archivos | `-f files.f` | `-c files.f` | `-f files.f` |
| Librerias | `-y dir +libext+.v+.sv` | `-y dir -Y .sv` | `-y dir` |
| Activar SV | `-sverilog` | `-g2012` | `-sv` (o extension `.sv`) |
| Delays (`#10`) | Si | Si | Parcial: requiere `--timing` |
| Lint / warnings | `-lint=all` | `-Wall` | `-Wall`; `--lint-only` solo analiza |
| Soporte SV | Completo (clases, SVA, UVM) | Subconjunto (sin UVM, interfaces limitadas, sin SVA) | Gran parte de RTL, structs y `--timing`; UVM no soportado o experimental |
| Logica | 4 estados | 4 estados | Parcial: 2 estados (X se convierte en 0 o aleatorio) |
| Flujo en 2 pasos | `vlogan` y luego `vcs` (UVM, multi-lib) | No aplica | No aplica |

Atajos:
- VCS: `vcs ... -R` compila y corre.
- Verilator: `-Wno-fatal` evita que los warnings aborten la compilacion.
- Verilator: `--public-flat-rw` expone senales internas.
- Icarus: `iverilog -t null` solo chequea sintaxis.

---

## 2. Ejecucion, plusargs, fin de sim, dump

| Aspecto | VCS | Icarus | Verilator |
|---|---|---|---|
| Correr | `./simv` | `vvp sim.vvp` | `./obj_dir/Vtb` |
| Plusargs | `./simv +N=50` | `vvp sim.vvp +N=50` | `./obj_dir/Vtb +N=50` |
| Leer en el TB | `$value$plusargs("N=%d", n)` / `$test$plusargs("X")` | igual | igual |
| Terminar | `$finish`; `+vcs+finish+1000` (tiempo max.) | `$finish`; `vvp -n` hace que `$stop` termine | `$finish`; `+verilator+error+limit+N` |
| Seed | `+ntb_random_seed=N` | No aplica | `+verilator+seed+N`, `+verilator+rand+reset+2` |
| Log | `-l sim.log` | redirigir con `> log` | redirigir con `> log` |
| Dump VCD | `$dumpfile("d.vcd"); $dumpvars(0,tb);` | igual | igual, pero compilar con `--trace` |
| Otros formatos | FSDB: `$fsdbDumpfile/$fsdbDumpvars` (necesita Verdi PLI, `-kdb`); VPD: `$vcdpluson` | FST/LXT2: `vvp sim.vvp -fst` o `-lxt2` | FST: `--trace-fst` |

---

## 3. Visualizacion de ondas

| Aspecto | VCS | Icarus | Verilator |
|---|---|---|---|
| Recomendado | Verdi (comercial) | GTKWave (open source) | GTKWave o Surfer |
| Formatos | FSDB (nativo), VCD, VPD (legacy) | VCD, FST, LXT2 | VCD, FST |
| Abrir | `verdi -ssf dump.fsdb` o `verdi -ssf dump.vcd`; con `-kdb`: `verdi -dbdir simv.daidir -ssf dump.fsdb` | `gtkwave dump.vcd` | `gtkwave dump.vcd` o `gtkwave dump.fst` |
| Alternativa comercial | DVE (legacy, `-vpd`) | No aplica | No aplica |
| Alternativa open source | GTKWave solo con VCD o FST; (3ros) `fsdb2vcd` (de Verdi) para convertir FSDB | Surfer | Surfer |

GTKWave no abre FSDB.

---

## 4. Depuracion interactiva

| Aspecto | VCS | Icarus | Verilator |
|---|---|---|---|
| Entrar | `./simv -ucli` (CLI), `./simv -gui` (Verdi/DVE), o `$stop` en el TB | `$stop` en el TB deja un prompt de `vvp` | No soportado: no hay consola de simulacion |
| Compilar para debug | `-debug_access+all` | No aplica | `-CFLAGS "-g -O0"` y `--public-flat-rw` |
| Comandos basicos | `run`, `run 100ns`, `get tb.dut.sum`, `scope tb.dut`, `force`/`release`, `next`, `step`, `quit` | `help`, `cont`, `finish`, `time`, `list`, `push`/`pop` | No aplica |
| Inspeccionar senales | `get`, `show`, GUI | Limitado; en la practica `$display` y ondas | `$display`, ondas, `gdb ./obj_dir/Vtb` |
| Breakpoints | `stop -time T`, `stop -line N -file f.sv`, `stop -condition {expr}`, `stop -change sig` | No soportado | Parcial: solo en C++ con gdb |

---

## 5. Reportes y cobertura

| Aspecto | VCS | Icarus | Verilator |
|---|---|---|---|
| Codigo (line/cond/fsm/tgl/branch) | Compilar con `-cm line+cond+fsm+tgl+branch -cm_dir cov.vdb`, correr con `./simv -cm line+cond+fsm+tgl+branch -cm_name t1` | No soportado | `--coverage` (o `--coverage-line --coverage-toggle`), genera `coverage.dat` |
| Funcional (covergroup) | Nativo | No soportado | Parcial: soporte limitado, verificar version |
| Aserciones (SVA) | Nativo | No soportado | Parcial: subconjunto con `--assert` |
| Reporte | `urg -dir cov.vdb -report urgReport` (HTML) o `verdi -cov -covdir cov.vdb` | No aplica | `verilator_coverage --annotate out/ coverage.dat`; HTML: `verilator_coverage --write-info c.info coverage.dat` y luego (3ros) `genhtml c.info -o html` |
| Merge | `urg -dir a.vdb -dir b.vdb` | No aplica | `verilator_coverage --write coverage.dat run1.dat run2.dat` |

---

## 6. Utilidades complementarias

| Utilidad | VCS | Icarus | Verilator |
|---|---|---|---|
| Automatizacion | `make` o scripts de shell; `vcs -R` | `make` | `make`; `--build` ya invoca make internamente |
| Chequeo de sintaxis | `vcs -sverilog -lint=all` | `iverilog -t null -g2012 f.sv` | `verilator --lint-only -Wall f.sv` |
| Linter / formatter | (3ros) Verible: `verible-verilog-lint`, `verible-verilog-format` | igual | igual |
| Tests en Python | (3ros) cocotb | (3ros) cocotb | (3ros) cocotb |
| Gestion de builds | (3ros) FuseSoC | (3ros) FuseSoC | (3ros) FuseSoC |
| Conversion SV a Verilog | No aplica | (3ros) `sv2v` (util para llevar SV a Icarus) | No aplica |
| Linter comercial | Spyglass (Synopsys) | No aplica | No aplica |

---

## Ejemplo minimo end-to-end

### `sumador.sv`

```systemverilog
`timescale 1ns/1ps
module sumador #(parameter int W = 8) (
  input  logic [W-1:0] a, b,
  input  logic         cin,
  output logic [W-1:0] sum,
  output logic         cout
);
  assign {cout, sum} = a + b + cin;
endmodule
```

### `tb_sumador.sv` (valido en los tres)

```systemverilog
`timescale 1ns/1ps
module tb;
  localparam int W = 8;
  logic [W-1:0] a, b, sum;
  logic cin, cout;
  logic [W:0] exp;
  int n = 20, errors = 0;

  sumador #(W) dut (.a(a), .b(b), .cin(cin), .sum(sum), .cout(cout));

  initial begin
    if (!$value$plusargs("N=%d", n)) n = 20;
    $dumpfile("dump.vcd");
    $dumpvars(0, tb);
    for (int i = 0; i < n; i++) begin
      a = $random; b = $random; cin = $random;
      #10;
      exp = a + b + cin;
      if ({cout, sum} !== exp) begin
        $display("ERROR t=%0t a=%0d b=%0d cin=%0b -> %0d (esp. %0d)",
                 $time, a, b, cin, {cout, sum}, exp);
        errors++;
      end
    end
    $display("FIN: %0d errores en %0d vectores", errors, n);
    $finish;
  end
endmodule
```

### VCS

```bash
vcs -full64 -sverilog -debug_access+all -top tb sumador.sv tb_sumador.sv -l comp.log
./simv +N=50 -l sim.log
verdi -ssf dump.vcd &        # o: gtkwave dump.vcd
```

### Icarus

```bash
iverilog -g2012 -Wall -s tb -o sim.vvp sumador.sv tb_sumador.sv
vvp sim.vvp +N=50
gtkwave dump.vcd &
```

### Verilator

```bash
verilator --binary -sv --timing --trace -Wall -Wno-fatal --top-module tb \
          sumador.sv tb_sumador.sv -Mdir obj_dir
./obj_dir/Vtb +N=50
gtkwave dump.vcd &
```

---

## Escenario: WSL local + VCS en servidor remoto

| Paso | Que cambia |
|---|---|
| Codigo | Trabajar en `~` dentro de WSL, no en `/mnt/c` (lento). Sincronizar con `rsync -avz --exclude simv.daidir --exclude csrc --exclude obj_dir ./ user@srv:~/proj/` |
| Entorno remoto | Los shells no interactivos no cargan `module` ni licencias. Usar `ssh user@srv 'bash -lc "cd ~/proj && vcs ... && ./simv +N=50"'`, o hacer `source` del script de setup de Synopsys. Revisar `SNPSLMD_LICENSE_FILE` |
| Compilar y simular | Todo en remoto. Correr en `tmux` si es largo |
| Ondas | Dump en **VCD** (o FST) y traer el archivo: `scp user@srv:~/proj/dump.vcd .`, luego `gtkwave dump.vcd` en WSL. Si se genero FSDB, convertir en el servidor: `fsdb2vcd dump.fsdb -o dump.vcd` |
| Verdi remoto | `ssh -Y` funciona pero es lento. Mejor VNC o X2Go si el servidor lo ofrece |
| Cobertura | `urg` en el servidor y luego `scp -r user@srv:~/proj/urgReport .` (o `tar czf` antes). Abrir `dashboard.html` en el navegador de Windows |
| GUI local | Windows 11: WSLg ya funciona con GTKWave (`sudo apt install gtkwave`). Windows 10: servidor X (VcXsrv) |
| Icarus y Verilator | Siguen 100% locales: `sudo apt install iverilog verilator gtkwave`. El `verilator` de apt puede ser antiguo y no tener `--binary`; compilar desde fuente si pasa |

Target de Makefile para el flujo remoto:

```make
SRV=user@srv
remote:
	rsync -az --exclude simv.daidir --exclude csrc ./ $(SRV):~/proj/
	ssh $(SRV) 'bash -lc "cd ~/proj && vcs -full64 -sverilog -debug_access+all -top tb sumador.sv tb_sumador.sv -l comp.log && ./simv +N=50 -l sim.log"'
	scp $(SRV):~/proj/dump.vcd .
	gtkwave dump.vcd &
```

---

## Que herramienta usar segun el caso

| Caso | Herramienta |
|---|---|
| Verilog clasico, prueba rapida | Icarus |
| TB SV moderno con structs, DUT grande, simulacion rapida | Verilator (2 estados) o VCS |
| Necesitas X/Z (4 estados) y semantica estricta | Icarus o VCS |
| UVM, covergroups, SVA completo | VCS |
| Flujo comercial con cobertura y Verdi | VCS |
| Cobertura de codigo gratis | Verilator (`--coverage` + `verilator_coverage`) |
| CI sin licencias | Verilator o Icarus (+ cocotb) |
| Maxima velocidad de simulacion RTL | Verilator |
| Depurar con breakpoints y consola | VCS (`-ucli` / Verdi) |
| Solo lint o sintaxis | `verilator --lint-only` + Verible |
| Ondas en WSL sin licencias | GTKWave o Surfer con VCD/FST |

---

## Fuentes

- Verilator Guide: https://verilator.org/guide/latest
- Icarus Verilog: https://steveicarus.github.io/iverilog
- GTKWave: https://gtkwave.sourceforge.net
- Verible: https://github.com/chipsalliance/verible
- VCS, UCLI, URG y Verdi: User Guides en SolvNet (ver tambien `cheatsheet_vcs_verdi.md` y `coverage_vcs_verdi.md` del proyecto)