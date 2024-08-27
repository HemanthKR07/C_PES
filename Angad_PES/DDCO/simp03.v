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

module orgate (y,a,b);
	input a,b;
	output y;
	assign y = a|b; 
endmodule

module simp03(a,b,c,y);
	output y;
	input a,b,c;
	wire w1, w2, w3;
	andgate g1 (w1, b, c);
	orgate g2 (w2, w1, a);
	andgate g3 (w3, a, b);
	orgate g4 (y, w2, w3);
endmodule