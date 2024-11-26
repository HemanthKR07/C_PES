module ALU (
    input [7:0] A,
    input [7:0] B,
    input [1:0] opcode,
    output reg [7:0] result
);
    always @(*) begin
        case (opcode)
            2'b00: result = A & B;  // AND
            2'b01: result = A | B;  // OR
            2'b10: result = ~(A & B); // NAND
            2'b11: result = ~(A | B); // NOR
            default: result = 8'b00000000;
        endcase
    end
endmodule

module RegisterFile (
    input clk,
    input [2:0] read_reg1,
    input [2:0] read_reg2,
    input [2:0] write_reg,
    input [7:0] write_data,
    input reg_write,
    output [7:0] read_data1,
    output [7:0] read_data2
);
    reg [7:0] registers [7:0];

    // Read operations
    assign read_data1 = registers[read_reg1];
    assign read_data2 = registers[read_reg2];

    // Write operation
    always @(posedge clk) begin
        if (reg_write) begin
            registers[write_reg] <= write_data;
        end
    end
endmodule

module ALU_RegFile (
    input clk,
    input [2:0] read_reg1,
    input [2:0] read_reg2,
    input [2:0] write_reg,
    input [1:0] opcode,
    input reg_write,
    output [7:0] result
);
    wire [7:0] read_data1;
    wire [7:0] read_data2;
    wire [7:0] alu_result;

    // Instantiate Register File
    RegisterFile rf (
        .clk(clk),
        .read_reg1(read_reg1),
        .read_reg2(read_reg2),
        .write_reg(write_reg),
        .write_data(alu_result),
        .reg_write(reg_write),
        .read_data1(read_data1),
        .read_data2(read_data2)
    );

    // Instantiate ALU
    ALU alu (
        .A(read_data1),
        .B(read_data2),
        .opcode(opcode),
        .result(alu_result)
    );

    assign result = alu_result;
endmodule