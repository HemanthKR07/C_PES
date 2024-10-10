module mux8 (
    input wire [7:0] in,  // 8-bit input
    input wire [2:0] sel, // 3-bit select signal
    output wire out       // 1-bit output
);

    assign out = (sel == 3'b000) ? in[0] :
                             (sel == 3'b001) ? in[1] :
                             (sel == 3'b002) ? in[2] :
                             (sel == 3'b003) ? in[3] :
                             (sel == 3'b100) ? in[4] :
                             (sel == 3'b101) ? in[5] :
                             (sel == 3'b110) ? in[6] :
                             in[7];

endmodule