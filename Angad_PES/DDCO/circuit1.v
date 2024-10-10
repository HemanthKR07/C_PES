module circuit1(a,b,c,f);
    input a,b,c;
    output f;
    wire x1,x2;
    and1 at(x1,a,b);
    not1 nt(x2,c);
    or1 ot(f,x1,x2);
endmodule