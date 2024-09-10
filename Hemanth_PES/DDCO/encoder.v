module encoder (
	input A0, A1, A2, A3,
	output Y0, Y1
	);
	
assign YO = A3 + A1;
assign Y1 = A3 + A2;

endmodule
