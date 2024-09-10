// This is without Enabler.

module decoder (
	input D0, D1,
	output A0,A1,A2,A3
);

assign A0 = ~D0 & ~D1;
assign A1 = ~D0 & D1;
assign A2 = D0 & ~D1;
assign A3 = D0 & D1;

endmodule
