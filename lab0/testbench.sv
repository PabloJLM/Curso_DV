module tb;

    // Generación de reloj (Hardware/Estático)
    logic clk = 0;
    always #5 clk = ~clk;

    // Señales físicas
    logic        write_en;
    logic        read_en;
    logic [7:0]  addr;
    logic [31:0] wdata;
    logic [31:0] rdata;

    // FEATURE 1: Conexión implícita. Si los nombres coinciden, '.*' conecta todo.
    // Esto le encanta a los diseñadores de Verilog puro.
    ram_dp dut (.*);

    typedef enum logic [1:0] {IDLE, WRITE, READ} cmd_t;

    typedef struct {
        cmd_t        op;
        logic [7:0]  address;
        logic [31:0] data;
    } transaction_t;

    // FEATURE 2 y 3: Tipos String y estructuras de datos dinámicas (Queues)
    string test_name = "Demostracion de SV para DV";
    transaction_t history_queue[$]; 

    // EJERCICIO: Cambiar el tipo a bit y ver cómo cambia en Verdi.
    logic [31:0] demo_val; 

    initial begin
        transaction_t pkt;

        $dumpfile("waves.vcd");
        $dumpvars(0, tb);

        write_en = 0; read_en = 0; addr = 0; wdata = 0;
        @(posedge clk); 
        demo_val = 32'hDEADBEEF;

        $display("----------------------------------------");
        $display("Iniciando prueba: %s", test_name);
        $display("----------------------------------------");

        // Ciclo de estímulos
        for (int i = 0; i < 3; i++) begin
            pkt.op = WRITE;
            pkt.address = 8'h10 + i;
            pkt.data = 32'hAABB0000 + i;

            // FEATURE 4: Pretty print con '%p' para imprimir todo el struct sin esfuerzo
            $display("[%0t] Preparando paquete: %p", $time, pkt);

            // Guardamos la transacción en la cola dinámica (crece automáticamente)
            history_queue.push_back(pkt);

            write_en = (pkt.op == WRITE);
            read_en  = (pkt.op == READ);
            addr     = pkt.address;
            wdata    = pkt.data;

            @(posedge clk); 
            write_en = 0;
            @(posedge clk);
        end

        // FEATURE 5: Iterar dinámicamente con foreach y usar el método .name() del enum
        $display("\nRevisando el historial guardado en la cola:");
        foreach(history_queue[i]) begin
            $display("  -> Indice %0d | Comando: %s | Addr: %h", 
                     i, history_queue[i].op.name(), history_queue[i].address);
        end

        #20;
        $display("Simulación terminada.");
        $finish;
    end
endmodule