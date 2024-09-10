module Decoder (
	input D0, D1, E,
	output A0,A1,A2,A3
);

assign A0 = E & (~D0 & ~D1);
assign A1 = E & (~D0 & D1);
assign A2 = E & (D0 & ~D1);
assign A3 = E & (D0 & D1);

endmodule;
