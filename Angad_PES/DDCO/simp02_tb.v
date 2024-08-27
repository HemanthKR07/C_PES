module simp02_test;
	reg a, b, c;  
	wire d, e;    
	simp02 simp02_test(a,b,c,y);
	
	initial  
	begin   
		#0 a=0; b=0; c=0;
		#100 a=0; b=0; c=1;
		#100 a=0; b=1; c=0;
		#100 a=0; b=1; c=1;
		#100 a=1; b=0; c=0;
		#100 a=1; b=0; c=1;
		#100 a=1; b=1; c=0;
		#100 a=1; b=1; c=1;
	end   	
	initial
	begin
		$monitor($time, "a=%b, b=%b, c=%b, y=%b", a, b, c, y); 
	end
	initial
	begin
	$dumpfile("simp02_test.vcd");
		$dumpvars(0, simp02_test);
	end
endmodule