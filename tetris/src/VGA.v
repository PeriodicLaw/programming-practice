`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/08 20:17:57
// Design Name: 
// Module Name: VGA
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


module VGA(
    input [199:0] Blocks,
    input clk_40MHz,
    input reset,
    output reg VGA_VS,
    output reg VGA_HS,
    output [3:0] VGA_R,
    output [3:0] VGA_G,
    output [3:0] VGA_B
    );
    
    reg [10:0]x_count;
    reg [9:0]y_count;
    always @ (posedge clk_40MHz or posedge reset)
         if(reset) x_count <= 11'd0;
         else if(x_count == 11'd1056) x_count <= 11'd0;
         else x_count <= x_count+1'b1;
    always @ (posedge clk_40MHz or posedge reset)
         if(reset) y_count <= 10'd0;
         else if(y_count == 10'd628) y_count <= 10'd0;
         else if(x_count == 11'd1056) y_count <= y_count+1'b1;
    always @ (posedge clk_40MHz or posedge reset)
         if(reset) VGA_HS <= 1'b1;
         else if(x_count == 11'd0) VGA_HS <= 1'b0;
         else if(x_count == 11'd128) VGA_HS <= 1'b1;
    always @ (posedge clk_40MHz or posedge reset)
         if(reset) VGA_VS <= 1'b1;
         else if(y_count == 10'd0) VGA_VS <= 1'b0;
         else if(y_count == 10'd4) VGA_VS <= 1'b1;
    
    wire [299:0]allBlocks;
    wire [4:0]blockx;
    wire [3:0]blocky;
    wire interior,around,display,border;
    assign allBlocks={100'b0,Blocks};
    assign blockx=(y_count-10'd277)/15;
    assign blocky=(x_count-11'd666)/15;
    assign interior=(x_count>=11'd666)&(x_count<11'd816)&(y_count>=10'd277)&(y_count<10'd577);
    assign around=(x_count>=11'd646)&(x_count<11'd836)&(y_count>=10'd257)&(y_count<10'd597);
    assign display=interior&allBlocks[blockx*10+blocky];
    assign border=around&~interior;
    
    assign VGA_R=display?4'b1111:4'b0;
    assign VGA_G=(display|border)?4'b1111:4'b0;
    assign VGA_B=display?4'b1111:4'b0;
endmodule
