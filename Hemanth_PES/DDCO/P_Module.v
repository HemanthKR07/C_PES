// This is module file;

module gates(

input a,b,
output and1,
output not1,
output or1,
output nand1,
output nor1,
output xor1,
output xnor1
);

assign and1 = a&b;
assign or1 = a|b;
assign not1 = ~a;
assign nand1 = ~(a&b);
assign nor1 = ~(a|b);
assign xor1 = a^b;
assign xnor1 = ~(a^b);

initial begin 
	$dumpfile("secGates_Waves.vcd");
	$dumpvars(0, firstInstance);
end
endmodule