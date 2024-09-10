module fullAdder_tb;
	
reg a,b,cin;
wire s,cout;
	
fullAdder uut (
	.A(a),
	.B(b),
	.Cin(Cin),
	.S(sum),
	.Cout(Cout)
);

	initial begin 
		$dumpfile("fullAdder.vcd");
		$dumpvars(0,fullAdder_tb);
		
		a=0; b=0;
		#10
		$display("A=%b B=%b CIN=%b SUM+%b COUT=%b",a,b,cin,s,cout);
		
		a=0; b=1;
		#10
		$display("A=%b B=%b CIN=%b SUM+%b COUT=%b",a,b,cin,s,cout);
		
		
		a=1; b=0;
		#10
		$display("A=%b B=%b CIN=%b SUM+%b COUT=%b",a,b,cin,s,cout);
		
		
		a=1; b=1;
		#10
		$display("A=%b B=%b CIN=%b SUM+%b COUT=%b",a,b,cin,s,cout);
		
		end
endmodule
