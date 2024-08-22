module and_test;
    reg a, b;
    wire y; 
    andgate2 and_test(y,a,b);
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
        $monitor($time, "a=%b, b=%b, y=%b", a, b, y); // display function
    end
    initial
    begin
        $dumpfile("and2_test.vcd");
        $dumpvars(0, and_test);
    end
endmodule