module alu (input wire [1:0] op, input wire [15:0] i0, i1,
    output reg [15:0] o, output wire cout);
    
      wire [15:0] add_result;
      wire [15:0] sub_result;
      wire [15:0] and_result;
      wire [15:0] or_result;
      reg carry_out;
      reg overflow;

  assign add_result = i0 + i1;

  assign sub_result = i0 - i1;

  assign and_result = i0 & i1;

  assign or_result = i0 | i1;

  always @*
    case (op)
      2'b00: begin
        o = add_result;
        carry_out = add_result[15];
        overflow = (i0[15] == i1[15] && o[15] != i0[15]);
      end
      2'b01: begin
        o = sub_result;
        carry_out = sub_result[15];
        overflow = (i0[15] != i1[15] && o[15] != i0[15]);
      end
      2'b10: begin
        o = and_result;
        carry_out = 1'b0;
        overflow = 1'b0;
      end
      2'b11: begin
        o = or_result;
        carry_out = 1'b0;
        overflow = 1'b0;
      end
    endcase

  assign cout = carry_out;

endmodule
