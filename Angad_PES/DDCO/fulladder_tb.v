module fulladder_test;
	reg x, y, z;  
	wire s, c;    
	fulladder fulladder_test(x,y,z,s,c);
	
	initial  
begin   
    #0 x=0; y=0; z=0;
    #100 x=0; y=0; z=1;
    #100 x=0; y=1; z=0;
    #100 x=0; y=1; z=1;
    #100 x=1; y=0; z=0;
    #100 x=1; y=0; z=1;
    #100 x=1; y=1; z=0;
    #100 x=1; y=1; z=1;
end   

initial
begin
    $monitor($time, " x=%b, y=%b, z=%b, s=%b, c=%b", x, y, z, s, c); 
	end
	initial
	begin
	$dumpfile("fulladder_test.vcd");
		$dumpvars(0, fulladder_test);
	end
endmodule