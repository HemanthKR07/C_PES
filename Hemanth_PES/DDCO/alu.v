module alu (input wire [1:0] op, input wire [15:0] i0, i1, output reg [15:0] o, output wire cout);
    
      // Declare wires here
      wire [15:0] sum;
      wire [15:0] diff;
      wire [15:0] logic_and;
      wire [15:0] logic_or;
      reg carry;
      reg overflow;

  // Instantiate modules here
  assign sum = i0 + i1;
  assign diff = i0 - i1;
  assign logic_and = i0 & i1;
  assign logic_or = i0 | i1;

  always @(*) begin
    case (op)
      2'b00: begin
        o = sum;
        carry = sum[15];
        overflow = (i0[15] == i1[15] && sum[15] != i0[15]);
      end
      2'b01: begin
        o = diff;
        carry = diff[15];
        overflow = (i0[15] != i1[15] && diff[15] != i0[15]);
      end
      2'b10: begin
        o = logic_and;
        carry = 1'b0;
        overflow = 1'b0;
      end
      2'b11: begin
        o = logic_or;
        carry = 1'b0;
        overflow = 1'b0;
      end
    endcase
  end

endmodule

