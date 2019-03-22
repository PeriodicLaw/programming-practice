`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/07 22:57:19
// Design Name: 
// Module Name: Game_tb
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


module Game_tb;
     reg clk,clk_pulse_1Hz,reset;
     wire [199:0]Blocks;
     wire [13:0]score;
     wire gameover;
     Game DUT(clk,clk_pulse_1Hz,1'b0,reset,1'b0,1'b0,1'b0,1'b0,1'b0,5'd1,4'd1,Blocks,score,gameover);
     integer k;
     initial
     begin
        reset=1;clk=0;clk_pulse_1Hz=0;
        #1 reset=0;
        for(k=0;k<5000;k=k+1)
        begin
            #1 clk=~clk;
            clk_pulse_1Hz=(k%10==0);
        end
     end
endmodule
