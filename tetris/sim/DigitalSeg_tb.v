`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/12 21:23:51
// Design Name: 
// Module Name: DigitalSeg_tb
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


module DigitalSeg_tb;
    reg clk,reset;
    wire[6:0]seg;
    wire[7:0]an;
    DigitalSeg DUT(clk,reset,14'd12,seg,an);
    integer k;
    initial
    begin   
        clk=0;reset=1;
        #2 reset=0;
        for(k=0;k<5000000;k=k+1)
            #1 clk=~clk;
    end
endmodule
