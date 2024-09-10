module decoder_tb;
reg d0,d1;
wire a0,a1,a2,a3;

decoder uut (
	.D0(d0),
	.D1(d1),
	.A0(a0),
	.A1(a1),
	.A2(a2),
	.A3(a3)
);

initial begin 
	$dumpfile("decoder.vcd");
	$dumpvars(0,decoder_tb);
	
	$monitor ("D0 = %b | D1 = %b || A0 = %b | A1 = %b | A2 = %b | A3 = %b",d0,d1,a0,a1,a2,a3);
	d0=0; d1=0;
	#20
	
	d0=0; d1=1;
	#20
	//$display ("D0 = %b | D1 = %b || A0 = %b | A1 = %b | A2 = %b | A3 = %b",d0,d1,a0,a1,a2,a3);
	
	d0=1; d1=0;
	#20
	//$display ("D0 = %b | D1 = %b || A0 = %b | A1 = %b | A2 = %b | A3 = %b",d0,d1,a0,a1,a2,a3);
	
	d0=1; d1=1;
	#20
	//$display ("D0 = %b | D1 = %b || A0 = %b | A1 = %b | A2 = %b | A3 = %b",d0,d1,a0,a1,a2,a3);
	$finish;
	end
endmodule
