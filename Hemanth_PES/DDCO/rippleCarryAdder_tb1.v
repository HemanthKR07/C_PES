module rippleCarryAdder_tb1;

reg [3:0]a,b;
reg cin;
wire [3:0]sum;
wire cout;

rippleCarry uut (
	.A(a), 
	.B(b),
	.Sum(sum),
	.Cin(cin),
	.Cout(cout)
);

initial begin

	$dumpfile("rippleCarryAdder.vcd");
	$dumpvars(0,rippleCarryAdder_tb1);
	
	a=4'b1100; b=4'b1111; cin=1;
	#10
	$display("A=%b B=%b Cin=%b Sum=%b Cout=%b",a,b,cin,sum,cout);
	
	a=4'b1000; b=4'b1001; cin=0;
	#10 
	$display("A=%b B=%b Cin=%b Sum=%b Cout=%b",a,b,cin,sum,cout);
	
	a=4'b1110; b=4'b1111; cin=1;
	#10
	$display("A=%b B=%b Cin=%b Sum=%b Cout=%b",a,b,cin,sum,cout);
	
	a=4'b0101; b=4'b1011; cin=0;
	#10
	$display("A=%b B=%b Cin=%b Sum=%b Cout=%b",a,b,cin,sum,cout);
	
	$finish;
end
endmodule

