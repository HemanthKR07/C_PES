module mux_21_tb;

reg s;
wire a0,a1;

mux uut (
	.S(s),
	.A0(a0),
	.A1(a1)
);

initial begin 
	$dumpfile("mux21.vcd");
	$dumpvars(0,mux_21_tb);
	
	$monitor("S = %b  A0 = %b | A1 = %b", s, a0, a1);
	
	s=0;
	#20
	
	s=1;
	#20;
	
	$finish;
	
	end
endmodule
