module halfadder_test;
	reg a, b;  
	wire s, c;    
	halfadder halfadder_test(a,b,s,c);
	
	initial  
	begin   
		#0 a=0; b=0;
		#100 a=0; b=1;
		#100 a=1; b=0;
		#100 a=1; b=1;
		#100 a=1; b=1;
	end   	
	initial
	begin
		$monitor($time, "a=%b, b=%b, s=%b, c=%b", a, b, s, c); 
	end
	initial
	begin
	$dumpfile("halfadder_test.vcd");
		$dumpvars(0, halfadder_test);
	end
endmodule