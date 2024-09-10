module demux_21_tb;

reg i;
wire a0,a1;

demux uut(
	.I(i),
	.A0(a0),
	.A1(a1)
);

initial begin
	$dumpfile("demux_21.vcd");
	$dumpvars(0,demux_21_tb);
	
	$monitor("I = %b || A0 = %b | A1 = %b",i,a0,a1);
	
	i=0;
	#20;
	
	i=1;
	#20
	
	$finish;
	end
endmodule
