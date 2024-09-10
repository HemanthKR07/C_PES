module mux (
	input S,
	output A0,A1
);
	
assign A0 = ~S;
assign A1 = S;

endmodule
