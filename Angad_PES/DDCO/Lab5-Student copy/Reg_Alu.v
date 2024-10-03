// Write code for modules you need here

module reg_file (
	input wire clk, 
	reset, 
	wr, 
	input wire [2:0] rd_addr_a, 
	rd_addr_b, 
	wr_addr, 
	input wire [15:0] d_in, 
	output wire [15:0] d_out_a, 
	d_out_b
);
	// Declare register file
	reg [15:0] reg_array [0:7];

	// Read operations
	assign d_out_a = reg_array[rd_addr_a];
	assign d_out_b = reg_array[rd_addr_b];

	// Write operation
	always @(posedge clk or posedge reset) begin
		if (reset) begin
			reg_array[0] <= 16'b0;
			reg_array[1] <= 16'b0;
			reg_array[2] <= 16'b0;
			reg_array[3] <= 16'b0;
			reg_array[4] <= 16'b0;
			reg_array[5] <= 16'b0;
			reg_array[6] <= 16'b0;
			reg_array[7] <= 16'b0;
		end else if (wr) begin
			reg_array[wr_addr] <= d_in;
		end
	end
endmodule

module reg_alu (
	input wire clk, 
	reset, 
	sel, 
	wr, 
	input wire [1:0] op, 
	input wire [2:0] rd_addr_a,
	rd_addr_b, 
	wr_addr, 
	input wire [15:0] d_in, 
	output wire [15:0] d_out_a, 
	d_out_b, 
	output wire cout
);
	// Declare wires here
	wire [15:0] reg_out_a, reg_out_b, alu_out;

	// Instantiate reg_file
	reg_file reg_file_0 (
		.clk(clk), 
		.reset(reset), 
		.wr(wr), 
		.rd_addr_a(rd_addr_a), 
		.rd_addr_b(rd_addr_b), 
		.wr_addr(wr_addr), 
		.d_in(d_in), 
		.d_out_a(reg_out_a), 
		.d_out_b(reg_out_b)
	);

	// Instantiate alu
	alu alu_0 (
		.op(op), 
		.i0(reg_out_a), 
		.i1(reg_out_b), 
		.o(alu_out), 
		.cout(cout)
	);

	// Select between register output and ALU output
	assign d_out_a = reg_out_a;
	assign d_out_b = (sel) ? alu_out : reg_out_b;
endmodule
