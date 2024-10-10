module serial_adder (
    input clk,
    input reset,
    input start,
    input [15:0] A,
    input [15:0] B,
    output reg [15:0] sum,
    output reg done
);

    reg [15:0] A_reg, B_reg;
    reg [3:0] count;
    reg carry;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            sum <= 16'b0;
            done <= 1'b0;
            A_reg <= 16'b0;
            B_reg <= 16'b0;
            count <= 4'b0;
            carry <= 1'b0;
        end else if (start) begin
            if (count == 4'b0) begin
                A_reg <= A;
                B_reg <= B;
                sum <= 16'b0;
                carry <= 1'b0;
                count <= 4'b1111;
                done <= 1'b0;
            end else begin
                {carry, sum[count]} <= A_reg[count] + B_reg[count] + carry;
                count <= count - 1;
                if (count == 4'b0) begin
                    done <= 1'b1;
                end
            end
        end
    end

endmodule