module mux_41_tb;

reg s0,s1;
wire a0,a1,a2,a3;

mux_41 uut (
	.S0(s0),
	.S1(s1),
	.A0(a0),
	.A1(a1),
	.A2(a2),
	.A3(a3)
);

initial begin
	$dumpfile("mux_41.vcd");
	$dumpvars(0,mux_41_tb);
	
	$monitor("S0 = %b, S1 = %b || A0 = %b | A1 = %b | A2 = %b | A3 = %b",s0,s1,a0,a1,a2,a3);
	
	s0=0;s1=1;
	#20
	s0=1; s1=1;
	#20
	s0=1; s1=0;
	#20
	s0=0; s1=0;
	#20
	$finish;
	end
endmodule
