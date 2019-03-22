`timescale 1ns / 1ps

module RandomGen1(
    input clk,
    input reset,
    input [7:0]seed,
    output reg [4:0]rand //rand:I1,J1,L1,O,S1,T1,Z1
);
    parameter I1 = 5'd1;
    parameter J1 = 5'd3;
    parameter L1 = 5'd7;
    parameter O = 5'd11;
    parameter S1 = 5'd12;
    parameter T1 = 5'd14;
    parameter Z1 = 5'd18;
    reg [7:0] state;
    always @(posedge clk or posedge reset)
        if(reset)
            state <= seed;
        else
            state <= {state[6],state[5]^state[7],state[4]^state[7],state[3]^state[7],state[2],state[1],state[0],state[7]};
    always @(*)
        case(state%7)
            0:rand=I1;
            1:rand=J1;
            2:rand=L1;
            3:rand=O;
            4:rand=S1;
            5:rand=T1;
            6:rand=Z1;
            default rand=0;
        endcase
endmodule

module RandomGen2(
    input clk,
    input reset,
    input [7:0]seed,
    output [3:0]rand //rand:2~7
);
    reg [7:0] state;
    always @(posedge clk or posedge reset)
        if(reset)
            state <= seed;
        else
            state <= {state[6],state[5]^state[7],state[4]^state[7],state[3]^state[7],state[2],state[1],state[0],state[7]};
    assign rand=4'd2+state%6;
endmodule