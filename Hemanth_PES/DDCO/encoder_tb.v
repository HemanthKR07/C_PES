module encoder_tb;

reg a0,a1,a2,a3;
wire y0, y1;

encoder uut (
	.A0(a0),
	.A1(a1),
	.A2(a2),
	.A3(a3),
	.Y0(y0),
	.Y1(y1)
);

initial begin 

	$dumpfile("encoder.vcd");
	$dumpvars(0,encoder_tb);
	
	
	a0=0; a1=0; a2=0; a3=1;
	#20
	$display("A0 = %b | A1 = %b | A2 = %b | A3 = %b || Y0 = %b || Y1 = %b" ,a0,a1,a2,a3,y0,y1);
	
	a0=0; a1=0; a2=1; a3=0;
	#20
	$display("A0 = %b | A1 = %b | A2 = %b | A3 = %b || Y0 = %b || Y1 = %b" ,a0,a1,a2,a3,y0,y1);
	
	a0=0; a1=1; a2=0; a3=0;
	#20
	$display("A0 = %b | A1 = %b | A2 = %b | A3 = %b || Y0 = %b || Y1 = %b" ,a0,a1,a2,a3,y0,y1);
	
	a0=1; a1=0; a2=0; a3=0;
	#20
	$display("A0 = %b | A1 = %b | A2 = %b | A3 = %b || Y0 = %b || Y1 = %b" ,a0,a1,a2,a3,y0,y1);
	
	$finish;
	
end

endmodule
