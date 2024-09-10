module halfAdder_tb ;

reg A, B;
wire Sum, Cout;
	

halfAdder halfAdder_tb (
	.a(A),
	.b(B),
	.s(Sum),
	.cout(Cout)
);

initial begin
	$dumpfile("halfAdder_tb.vcd");
	$dumpvars(0, halfAdder_tb);
	
	$display("A B | Sum Cout");
		
	A=0; B=0;
	#10
	$display("%b %b | %b %b", A, B, Sum, Cout);
		
	A=0; B=1;
	#10
	$display("%b %b | %b %b", A, B, Sum, Cout);
		
	A=1; B=0;
	#10
	$display("%b %b | %b %b", A, B, Sum, Cout);
		
	A=1; B=1;
	#10
	$display("%b %b | %b %b", A, B, Sum, Cout);
end 
endmodule
