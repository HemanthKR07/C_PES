// Write code for modules you need here
module dfrl_16 (input wire clk, reset, load, input wire [15:0] in, output wire [15:0] out);
dfrl _f0(clk,reset,load,in[0],out[0]);

endmodule
module mux8_16 (input wire [0:15] i0, i1, i2, i3, i4, i5, i6, i7, input wire [0:2] j, output wire [0:15] o);
  mux8 mux8_0({i0[0], i1[0], i2[0], i3[0], i4[0], i5[0], i6[0], i7[0]}, j[0], j[1], j[2], o[0]);
  mux8 mux8_1({i0[1], i1[1], i2[1], i3[1], i4[1], i5[1], i6[1], i7[1]}, j[0], j[1], j[2], o[1]);
 
endmodule






module reg_file (input wire clk, reset, wr, input wire [2:0] rd_addr_a, rd_addr_b, wr_addr, input wire [15:0] d_in, output wire [15:0] d_out_a, d_out_b);

// Declare wires here
wire [15:0] reg_out [7:0];

// Instantiate dfrl_16 modules for each register
dfrl_16 reg0 (clk, reset, wr & (wr_addr == 3'b000), d_in, reg_out[0]);
dfrl_16 reg1 (clk, reset, wr & (wr_addr == 3'b001), d_in, reg_out[1]);
dfrl_16 reg2 (clk, reset, wr & (wr_addr == 3'b010), d_in, reg_out[2]);
dfrl_16 reg3 (clk, reset, wr & (wr_addr == 3'b011), d_in, reg_out[3]);
dfrl_16 reg4 (clk, reset, wr & (wr_addr == 3'b100), d_in, reg_out[4]);
dfrl_16 reg5 (clk, reset, wr & (wr_addr == 3'b101), d_in, reg_out[5]);
dfrl_16 reg6 (clk, reset, wr & (wr_addr == 3'b110), d_in, reg_out[6]);
dfrl_16 reg7 (clk, reset, wr & (wr_addr == 3'b111), d_in, reg_out[7]);

// Instantiate mux8_16 modules for read ports
mux8_16 mux_a (reg_out[0], reg_out[1], reg_out[2], reg_out[3], reg_out[4], reg_out[5], reg_out[6], reg_out[7], rd_addr_a, d_out_a);
mux8_16 mux_b (reg_out[0], reg_out[1], reg_out[2], reg_out[3], reg_out[4], reg_out[5], reg_out[6], reg_out[7], rd_addr_b, d_out_b);
   
endmodule



