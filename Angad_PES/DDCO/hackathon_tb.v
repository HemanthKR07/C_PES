module tb_ALU_RegFile;
    reg clk;
    reg [2:0] read_reg1;
    reg [2:0] read_reg2;
    reg [2:0] write_reg;
    reg [1:0] opcode;
    reg reg_write;
    wire [7:0] result;

    ALU_RegFile uut (
        .clk(clk),
        .read_reg1(read_reg1),
        .read_reg2(read_reg2),
        .write_reg(write_reg),
        .opcode(opcode),
        .reg_write(reg_write),
        .result(result)
    );

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        // Initialize registers
        reg_write = 1;
        write_reg = 3'b000; uut.rf.registers[0] = 8'b00001111;
        write_reg = 3'b001; uut.rf.registers[1] = 8'b11110000;
        #10;

        // Perform AND operation
        read_reg1 = 3'b000;
        read_reg2 = 3'b001;
        opcode = 2'b00;
        #10;
        $display("AND result: %b", result);

        // Perform OR operation
        opcode = 2'b01;
        #10;
        $display("OR result: %b", result);

        // Perform NAND operation
        opcode = 2'b10;
        #10;
        $display("NAND result: %b", result);

        // Perform NOR operation
        opcode = 2'b11;
        #10;
        $display("NOR result: %b", result);

        $stop;
    end
endmodule