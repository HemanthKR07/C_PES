module decoder_En_tb;

reg d0,d1, e;
wire a0,a1,a2,a3;

Decoder uut (
	.D0(d0),
	.D1(d1),
	.A0(a0),
	.A1(a1),
	.A2(a2),
	.A3(a3),
	.E(e)
);

initial begin 
	$dumpfile("decoder_EN.vcd");
	$dumpvars(0,decoder_En_tb);
	
	$monitor ("D0 = %b | D1 = %b ||| A0 = %b | A1 = %b | A2 = %b | A3 = %b ||| E = %b " ,d0,d1,a0,a1,a2,a3,e);
	
	d0=0; d1=0; e=0;
	#20
	
	d0=0; d1=1; e=0;
	#20
	
	d0=1; d1=0; e=1;
	#20
	
	d0=1; d1=1; e=0;
	#20
	
	$finish;
	
	end
endmodule
	
