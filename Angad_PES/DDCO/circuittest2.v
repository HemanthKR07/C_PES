`include "circuit2.v"

module circuittest2;
    reg a,b,c;
    wire f;
    circuit2 b1(a,b,c,f);
    initial
    begin
    $monitor($time, "a=%b, b=%b, c=%b, f=%b", a, b, c,f);
        #000 a=1'b0; b=1'b0; c=1'b0;
        #100 a=1'b0; b=1'b0; c=1'b1;
        #100 a=1'b0; b=1'b1; c=1'b0;
        #100 a=1'b0; b=1'b1; c=1'b1;
        #100 a=1'b1; b=1'b0; c=1'b0;
        #100 a=1'b1; b=1'b0; c=1'b1;
        #100 a=1'b1; b=1'b1; c=1'b0;
        #100 a=1'b1; b=1'b1; c=1'b1;
    end
    initial
    begin
        $dumpfile("circuittest2.vcd");
        $dumpvars(0, circuittest2);
     end
endmodule
