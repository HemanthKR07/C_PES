module demux (
	input I,
	output A0,A1
);

assign A0 = ~I;
assign A1 = I;

endmodule
