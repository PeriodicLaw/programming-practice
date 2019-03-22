`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/08 22:31:38
// Design Name: 
// Module Name: PulseMaker
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module PulseMaker(
    input clk_100MHz,
    output reg clk_pulse_1Hz
    );
    parameter countMax=99999999;
    reg [26:0] count;
    always @(posedge clk_100MHz)
        if(count==countMax)
            begin
                count<=0;
                clk_pulse_1Hz<=1;
            end
        else
            begin
                count<=count+1;
                clk_pulse_1Hz<=0;
            end
endmodule
