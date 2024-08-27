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

module halfadder(a,b,s,c);
	output s,c;
	input a,b;
	andgate g1 (c, a, b);
	xorgate g2 (s, a, b);
endmodule