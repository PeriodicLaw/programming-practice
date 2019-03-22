`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/08 21:00:30
// Design Name: 
// Module Name: Top
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


module Top(
    input clk_100MHz,
    input reset,
    input down1,
    input down2,
    input left,
    input right,
    input leftRotate,
    input rightRotate,
    input cheat,
    input [7:0]seed,
    output gameover,
    output [6:0]seg,
    output [7:0]an,
    output VGA_VS,
    output VGA_HS,
    output [3:0] VGA_R,
    output [3:0] VGA_G,
    output [3:0] VGA_B
    );
    defparam PulseMaker1.countMax=99999999;
    defparam PulseMaker2.countMax=19999999;
    wire [199:0]MixedBlocks;
    wire clk_pulse_1Hz,clk_40MHz,clk_pulse_5Hz;
    wire [4:0]NextActiveBlock;
    wire [3:0]NextActiveBlockY;
    wire [13:0]score;
    PulseMaker PulseMaker1(clk_100MHz,clk_pulse_1Hz);
    PulseMaker PulseMaker2(clk_100MHz,clk_pulse_5Hz);
    Game Game(clk_100MHz,clk_pulse_1Hz,clk_pulse_5Hz,reset,down1|down2,left,right,leftRotate,rightRotate,cheat?seed[4:0]:NextActiveBlock,cheat?4'd5:NextActiveBlockY,MixedBlocks,score,gameover);
    DigitalSeg Seg(clk_40MHz,reset,score,seg,an);
    VGA VGA(MixedBlocks,clk_40MHz,reset,VGA_VS,VGA_HS,VGA_R,VGA_G,VGA_B);
    clk_wiz_0 clk0(.clk_in1(clk_100MHz),.reset(1'b0),.clk_out1(clk_40MHz));
    RandomGen1 Rand1(clk_40MHz,reset,seed,NextActiveBlock);
    RandomGen2 Rand2(clk_40MHz,reset,seed,NextActiveBlockY);
endmodule
