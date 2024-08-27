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

module simp02(a,b,c,y);
	output y;
	input a,b,c;
	wire w1;
	andgate g1 (w1, b, c);
	orgate g2 (y, a, w1);
endmodule