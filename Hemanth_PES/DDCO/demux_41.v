module demux_41 (
	input S0,S1,
	output A0,A1,A2,A3
);

assign A0 = ~S0 & ~S1;
assign A1 = ~S0 & S1;
assign A2 = S0 & ~S1;
assign A3 = S0 & S1;

endmodule
