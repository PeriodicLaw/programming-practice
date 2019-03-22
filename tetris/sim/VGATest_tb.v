`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/06 08:47:53
// Design Name: 
// Module Name: VGATest_tb
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


module VGATest_tb;
    reg clk,reset;
    wire VGA_HS,VGA_VS;
    wire[3:0] VGA_R,VGA_G,VGA_B;
    VGA VGA(200'b1,clk,reset,VGA_VS,VGA_HS,VGA_R,VGA_G,VGA_B);
    integer k;
    initial
    begin
    reset=1;
    #1 clk=0;reset=0;
    for(k=0;k<50000;k=k+1)
        #1 clk=~clk;
    end
endmodule
