module tb_16bitserialadder;

    // Inputs
    reg clk;
    reg reset;
    reg start;
    reg [15:0] A;
    reg [15:0] B;

    // Outputs
    wire [15:0] Sum;
    wire done;

    // Instantiate the Unit Under Test (UUT)
    serial_adder uut (
        .clk(clk), 
        .reset(reset), 
        .start(start), 
        .A(A), 
        .B(B), 
        .Sum(Sum), 
        .done(done)
    );

    initial begin
        // Initialize Inputs
        clk = 0;
        reset = 0;
        start = 0;
        A = 0;
        B = 0;

        // Wait for global reset
        #100;
                
        // Apply test vectors
        reset = 1;
        #10;
        reset = 0;
        #10;
        
        A = 16'h1234;
        B = 16'h5678;
        start = 1;
        #10;
        start = 0;
        
        // Wait for the operation to complete
        wait(done);
        #10;
        
        // Check the result
        if (Sum == (A + B))
            $display("Test Passed: %h + %h = %h", A, B, Sum);
        else
            $display("Test Failed: %h + %h != %h", A, B, Sum);
        
        // Add more test cases as needed
        // ...

        $stop;
    end
    
    always #5 clk = ~clk; // Clock generation

    initial begin
        $monitor("At time %t: clk = %b, reset = %b, start = %b, A = %h, B = %h, Sum = %h, done = %b", 
                 $time, clk, reset, start, A, B, Sum, done);
    end

endmodule