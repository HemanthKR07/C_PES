module rippleCarry (
	input [3:0]A,B,
	input Cin,
	output [3:0]Sum, 
	output Cout
	);
	
	full_adder a1(A[0], B[0], Cin,   Sum[0], cout0);
	full_adder a2(A[1], B[1], cout0, Sum[1], cout1);
	full_adder a3(A[2], B[2], cout1, Sum[2], cout2);
	full_adder a4(A[3], B[3], cout2, Sum[3], Cout);
endmodule

module full_adder(
	input A,B,Cin,
	output S,Cout
	);
	assign Sum = (A ^ B) ^ Cin;
	assign Cout = (A & B) | (Cin & A) | (Cin & B);
endmodule
