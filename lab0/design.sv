module ram_dp (
    input  logic        clk,
    input  logic        write_en,
    input  logic        read_en,
    input  logic [7:0]  addr,
    input  logic [31:0] wdata,
    output logic [31:0] rdata
);

    // Memoria interna
    logic [31:0] mem [0:255];

    always_ff @(posedge clk) begin
        if (write_en) begin
            mem[addr] <= wdata;
        end
        if (read_en) begin
            rdata <= mem[addr];
        end
    end
endmodule