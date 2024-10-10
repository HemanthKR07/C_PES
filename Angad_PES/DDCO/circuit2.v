module circuit2(a,b,c,f);
    input a,b,c;
    output f;
    wire x1;
    and1 ta(x1,b,c);
    or1 to(f,x1,a);
endmodule