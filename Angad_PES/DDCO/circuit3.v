module circuit3(a,b,c,f);
    input a,b,c;
    output f;
    wire x1,x2,x3;
    and1 pt(x1,b,c);
    and1 rt(x2,a,b);
    or1 qt(x3,x1,a);
    or1 st(f,x2,x3);
endmodule