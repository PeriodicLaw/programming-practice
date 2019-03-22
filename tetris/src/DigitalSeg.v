`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/11 23:02:55
// Design Name: 
// Module Name: DigitalSeg
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

module FrequencyDivider(
    input clk_40MHz,
    input reset,
    output reg [1:0]status
    );
    reg [25:0]count;
    always @(posedge clk_40MHz or posedge reset)
        if(reset)
            begin
                count<=0;
                status<=2'd0;
            end
        else if(count==26'd99999)
            begin
                count<=0;
                status<=status+2'd1;
            end
        else
            count<=count+1;
endmodule

module BintoSeg(
    input [3:0]num,
    output reg [6:0]seg
    );
    always @(num)
        case(num)
            4'd0:seg=7'b0000001;
            4'd1:seg=7'b1001111;
            4'd2:seg=7'b0010010;
            4'd3:seg=7'b0000110;
            4'd4:seg=7'b1001100;
            4'd5:seg=7'b0100100;
            4'd6:seg=7'b0100000;
            4'd7:seg=7'b0001111;
            4'd8:seg=7'b0000000;
            4'd9:seg=7'b0000100;
            default:seg=7'b1111111;
        endcase
endmodule

module DigitalSeg(
    input clk,
    input reset,
    input [13:0] num,
    output reg [6:0] seg,
    output [7:0] an
    );
    wire [1:0]status;
    FrequencyDivider FD(clk,reset,status);
    
    wire [3:0]num3,num2,num1,num0;
    assign num3=num/1000;
    assign num2=(num/100)%10;
    assign num1=(num/10)%10;
    assign num0=num%10;
    assign an=reset?8'b11111111:{4'b1111,status!=2'd3,status!=2'd2,status!=2'd1,status!=2'd0}; 
    
    wire [6:0]seg3,seg2,seg1,seg0;
    BintoSeg Seg1(num0,seg0);
    BintoSeg Seg2(num1,seg1);
    BintoSeg Seg3(num2,seg2);
    BintoSeg Seg4(num3,seg3);
    always @(*)
        case(status)
            2'd0:seg=seg0;
            2'd1:seg=seg1;
            2'd2:seg=seg2;
            2'd3:seg=seg3;
            default:seg=7'b1111111;
        endcase
endmodule
