module andgate (y,a,b);
	input a,b;
	output y;
	assign y = a&b; 
endmodule

module notgate (y,a);
	input a;
	output y;
	assign y = !a; 
endmodule

module xorgate (y,a,b);
	input a,b;
	output y;
	assign y = a^b; 
endmodule

module orgate (y,a,b);
	input a,b;
	output y;
	assign y = a|b; 
endmodule

module fulladder(x,y,z,s,c);
	output s,c;
	input x,y,z;
	wire w1, w2, w3;
	xorgate g1 (w1, x, y);
	xorgate g2 (s, w1, z);
	andgate g3 (w2, w1, z);
	andgate g4 (w3, x, y);
	orgate g5 (c, w3, w2);
endmodule