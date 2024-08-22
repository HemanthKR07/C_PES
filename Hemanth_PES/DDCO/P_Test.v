// This is a testbench file;

module gates_test;

reg i1,i2;
wire and1,not1,nand1, or1, nor1, xor1,xnor1;

gates firstInstance(
	.a(i1),
	.b(i2),
	.and1(and1),
	.not1(not1),
	.or1(or1),
	.nor1(nor1),
	.xor1(xor1),
	.xnor1(xnor1),
	.nand1(nand1)
);

initial begin 
	i1=0;i2=0;
	$display("a=%b b=%b",i1,i2);
	i1=0; i2=1;
	$display("a=%b b=%b",i1,i2);
	i1=1; i2=0;
	$display("a=%b b=%b",i1,i2);
	i1=1; i2=1;
	$display("a=%b b=%b",i1,i2);
$finish;
end
endmodule
