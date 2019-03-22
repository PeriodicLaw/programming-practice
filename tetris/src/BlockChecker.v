`timescale 1ns / 1ps

module BlockRotater(
    input [4:0]ActiveBlock,
    output reg [4:0]LeftRotateBlock,
    output reg [4:0]RightRotateBlock
    );
    parameter NONE=5'd0;
    parameter I1 = 5'd1;
    parameter I2 = 5'd2;
    parameter J1 = 5'd3;
    parameter J2 = 5'd4;
    parameter J3 = 5'd5;
    parameter J4 = 5'd6;
    parameter L1 = 5'd7;
    parameter L2 = 5'd8;
    parameter L3 = 5'd9;
    parameter L4 = 5'd10;
    parameter O = 5'd11;
    parameter S1 = 5'd12;
    parameter S2 = 5'd13;
    parameter T1 = 5'd14;
    parameter T2 = 5'd15;
    parameter T3 = 5'd16;
    parameter T4 = 5'd17;
    parameter Z1 = 5'd18;
    parameter Z2 = 5'd19;
    always @(ActiveBlock)
        case(ActiveBlock)
            I1:begin
                LeftRotateBlock=I2;RightRotateBlock=I2;
            end
            I2:begin
                LeftRotateBlock=I1;RightRotateBlock=I1;
            end
            J1:begin
                LeftRotateBlock=J4;RightRotateBlock=J2;
            end
            J2:begin
                LeftRotateBlock=J1;RightRotateBlock=J3;
            end
            J3:begin
                LeftRotateBlock=J2;RightRotateBlock=J4;
            end
            J4:begin
                LeftRotateBlock=J3;RightRotateBlock=J1;
            end
            L1:begin
                LeftRotateBlock=L4;RightRotateBlock=L2;
            end
            L2:begin
                LeftRotateBlock=L1;RightRotateBlock=L3;
            end
            L3:begin
                LeftRotateBlock=L2;RightRotateBlock=L4;
            end
            L4:begin
                LeftRotateBlock=L3;RightRotateBlock=L1;
            end
            O:begin
                LeftRotateBlock=O;RightRotateBlock=O;
            end
            S1:begin
                LeftRotateBlock=S2;RightRotateBlock=S2;
            end
            S2:begin
                LeftRotateBlock=S1;RightRotateBlock=S1;
            end
            T1:begin
                LeftRotateBlock=T4;RightRotateBlock=T2;
            end
            T2:begin
                LeftRotateBlock=T1;RightRotateBlock=T3;
            end
            T3:begin
                LeftRotateBlock=T2;RightRotateBlock=T4;
            end
            T4:begin
                LeftRotateBlock=T3;RightRotateBlock=T1;
            end
            Z1:begin
                LeftRotateBlock=Z2;RightRotateBlock=Z2;
            end
            Z2:begin
                LeftRotateBlock=Z1;RightRotateBlock=Z1;
            end
            default:begin
                LeftRotateBlock=NONE;RightRotateBlock=NONE;
            end
        endcase
endmodule

module BlockChecker#(parameter Width = 10,parameter Height = 20)(
    input [Height*Width-1:0]Blocks,
    input [4:0]ActiveBlock,
    input [4:0]ActiveBlockX,
    input [3:0]ActiveBlockY,
    output enExist
    );
    parameter NONE=5'd0;
    parameter I1 = 5'd1;
    parameter I2 = 5'd2;
    parameter J1 = 5'd3;
    parameter J2 = 5'd4;
    parameter J3 = 5'd5;
    parameter J4 = 5'd6;
    parameter L1 = 5'd7;
    parameter L2 = 5'd8;
    parameter L3 = 5'd9;
    parameter L4 = 5'd10;
    parameter O = 5'd11;
    parameter S1 = 5'd12;
    parameter S2 = 5'd13;
    parameter T1 = 5'd14;
    parameter T2 = 5'd15;
    parameter T3 = 5'd16;
    parameter T4 = 5'd17;
    parameter Z1 = 5'd18;
    parameter Z2 = 5'd19;
    
    wire [10:0]Neibor;
    assign Neibor[0]=(ActiveBlockX>=1)&(ActiveBlockY>=1)&~Blocks[(ActiveBlockX-1)*Width+ActiveBlockY-1];
    assign Neibor[1]=(ActiveBlockX>=1)&~Blocks[(ActiveBlockX-1)*Width+ActiveBlockY];
    assign Neibor[2]=(ActiveBlockX>=1)&(ActiveBlockY<Width-1)&~Blocks[(ActiveBlockX-1)*Width+ActiveBlockY+1];
    assign Neibor[3]=(ActiveBlockY>=1)&~Blocks[ActiveBlockX*Width+ActiveBlockY-1];
    assign Neibor[4]=~Blocks[ActiveBlockX*Width+ActiveBlockY];
    assign Neibor[5]=(ActiveBlockY<Width-1)&~Blocks[ActiveBlockX*Width+ActiveBlockY+1];
    assign Neibor[6]=(ActiveBlockY<Width-2)&~Blocks[ActiveBlockX*Width+ActiveBlockY+2];
    assign Neibor[7]=(ActiveBlockX<Height-1)&(ActiveBlockY>=1)&~Blocks[(ActiveBlockX+1)*Width+ActiveBlockY-1];
    assign Neibor[8]=(ActiveBlockX<Height-1)&~Blocks[(ActiveBlockX+1)*Width+ActiveBlockY];
    assign Neibor[9]=(ActiveBlockX<Height-1)&(ActiveBlockY<Width-1)&~Blocks[(ActiveBlockX+1)*Width+ActiveBlockY+1];
    assign Neibor[10]=(ActiveBlockX<Height-2)&~Blocks[(ActiveBlockX+2)*Width+ActiveBlockY];
    
    reg enBlock;
    always@(*)
    begin
        case (ActiveBlock)
            I1:enBlock=Neibor[3]&Neibor[4]&Neibor[5]&Neibor[6];
            I2:enBlock=Neibor[1]&Neibor[4]&Neibor[8]&Neibor[10];
            J1:enBlock=Neibor[3]&Neibor[4]&Neibor[5]&Neibor[9];
            J2:enBlock=Neibor[1]&Neibor[4]&Neibor[7]&Neibor[8];
            J3:enBlock=Neibor[0]&Neibor[3]&Neibor[4]&Neibor[5];
            J4:enBlock=Neibor[1]&Neibor[2]&Neibor[4]&Neibor[8];
            L1:enBlock=Neibor[3]&Neibor[4]&Neibor[5]&Neibor[7];
            L2:enBlock=Neibor[0]&Neibor[1]&Neibor[4]&Neibor[8];
            L3:enBlock=Neibor[2]&Neibor[3]&Neibor[4]&Neibor[5];
            L4:enBlock=Neibor[1]&Neibor[4]&Neibor[8]&Neibor[9];
            O:enBlock=Neibor[4]&Neibor[5]&Neibor[8]&Neibor[9];
            S1:enBlock=Neibor[4]&Neibor[5]&Neibor[7]&Neibor[8];
            S2:enBlock=Neibor[1]&Neibor[4]&Neibor[5]&Neibor[9];
            T1:enBlock=Neibor[3]&Neibor[4]&Neibor[5]&Neibor[8];
            T2:enBlock=Neibor[1]&Neibor[3]&Neibor[4]&Neibor[8];
            T3:enBlock=Neibor[1]&Neibor[3]&Neibor[4]&Neibor[5];
            T4:enBlock=Neibor[1]&Neibor[4]&Neibor[5]&Neibor[8];
            Z1:enBlock=Neibor[3]&Neibor[4]&Neibor[8]&Neibor[9];
            Z2:enBlock=Neibor[2]&Neibor[4]&Neibor[5]&Neibor[8];
        default: enBlock=1'b0;
      endcase
    end
    assign enExist=(ActiveBlockX<Height)&(ActiveBlockY<Width)&enBlock;
endmodule

module BlockMixer #(parameter Width = 10,parameter Height = 20)(
    input clk,
    input [Height*Width-1:0]Blocks,
    input [4:0]ActiveBlock,
    input [4:0]ActiveBlockX,
    input [3:0]ActiveBlockY,
    output reg [Height*Width-1:0]MixedBlocks
    );
    parameter NONE=5'd0;
    parameter I1 = 5'd1;
    parameter I2 = 5'd2;
    parameter J1 = 5'd3;
    parameter J2 = 5'd4;
    parameter J3 = 5'd5;
    parameter J4 = 5'd6;
    parameter L1 = 5'd7;
    parameter L2 = 5'd8;
    parameter L3 = 5'd9;
    parameter L4 = 5'd10;
    parameter O = 5'd11;
    parameter S1 = 5'd12;
    parameter S2 = 5'd13;
    parameter T1 = 5'd14;
    parameter T2 = 5'd15;
    parameter T3 = 5'd16;
    parameter T4 = 5'd17;
    parameter Z1 = 5'd18;
    parameter Z2 = 5'd19;
    
    reg [Height*Width-1:0] ActiveBlock_Data;
    always @(posedge clk)
    begin
        ActiveBlock_Data=0;
        case(ActiveBlock)
            I1:begin
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY-1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY+2]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            I2:begin
                ActiveBlock_Data[(ActiveBlockX-1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[(ActiveBlockX+2)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            J1:begin
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY-1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            J2:begin
                ActiveBlock_Data[(ActiveBlockX-1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY-1]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            J3:begin
                ActiveBlock_Data[(ActiveBlockX-1)*Width+ActiveBlockY-1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY-1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            J4:begin
                ActiveBlock_Data[(ActiveBlockX-1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[(ActiveBlockX-1)*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            L1:begin
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY-1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY-1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            L2:begin
                ActiveBlock_Data[(ActiveBlockX-1)*Width+ActiveBlockY-1]=1;
                ActiveBlock_Data[(ActiveBlockX-1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            L3:begin
                ActiveBlock_Data[(ActiveBlockX-1)*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY-1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            L4:begin
                ActiveBlock_Data[(ActiveBlockX-1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            O:begin
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            S1:begin
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY-1]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            S2:begin
                ActiveBlock_Data[(ActiveBlockX-1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            T1:begin
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY-1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            T2:begin
                ActiveBlock_Data[(ActiveBlockX-1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY-1]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            T3:begin
                ActiveBlock_Data[(ActiveBlockX-1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY-1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            T4:begin
                ActiveBlock_Data[(ActiveBlockX-1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            Z1:begin
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY-1]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            Z2:begin
                ActiveBlock_Data[(ActiveBlockX-1)*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY+1]=1;
                ActiveBlock_Data[(ActiveBlockX+1)*Width+ActiveBlockY]=1;
                ActiveBlock_Data[ActiveBlockX*Width+ActiveBlockY]=1;
            end
            default:;
        endcase
    end
    integer x,y;
    always@(*)
    for(x=0;x<Height;x=x+1)
        for(y=0;y<Width;y=y+1)
            MixedBlocks[x*Width+y]=Blocks[x*Width+y]|ActiveBlock_Data[x*Width+y];
endmodule

module BlockEliminater#(parameter Width = 10,parameter Height = 20)(
    input [Height*Width-1:0]Blocks,
    input [4:0]EliminateX,
    output reg ShouldEliminate,
    output reg [Height*Width-1:0]EliminatedBlocks
    );
    always @(*)
    case(EliminateX)
        0:begin
            ShouldEliminate=&Blocks[Width-1:0];
            EliminatedBlocks={Blocks[Height*Width-1:Width],10'b0};
        end
        1:begin
            ShouldEliminate=&Blocks[2*Width-1:Width];
            EliminatedBlocks={Blocks[Height*Width-1:2*Width],Blocks[Width-1:0],10'b0};
        end
        2:begin
            ShouldEliminate=&Blocks[3*Width-1:2*Width];
            EliminatedBlocks={Blocks[Height*Width-1:3*Width],Blocks[2*Width-1:0],10'b0};
        end
        3:begin
            ShouldEliminate=&Blocks[4*Width-1:3*Width];
            EliminatedBlocks={Blocks[Height*Width-1:4*Width],Blocks[3*Width-1:0],10'b0};
        end
        4:begin
            ShouldEliminate=&Blocks[5*Width-1:4*Width];
            EliminatedBlocks={Blocks[Height*Width-1:5*Width],Blocks[4*Width-1:0],10'b0};
        end
        5:begin
            ShouldEliminate=&Blocks[6*Width-1:5*Width];
            EliminatedBlocks={Blocks[Height*Width-1:6*Width],Blocks[5*Width-1:0],10'b0};
        end
        6:begin
            ShouldEliminate=&Blocks[7*Width-1:6*Width];
            EliminatedBlocks={Blocks[Height*Width-1:7*Width],Blocks[6*Width-1:0],10'b0};
        end
        7:begin
            ShouldEliminate=&Blocks[8*Width-1:7*Width];
            EliminatedBlocks={Blocks[Height*Width-1:8*Width],Blocks[7*Width-1:0],10'b0};
        end
        8:begin
            ShouldEliminate=&Blocks[9*Width-1:8*Width];
            EliminatedBlocks={Blocks[Height*Width-1:9*Width],Blocks[8*Width-1:0],10'b0};
        end
        9:begin
            ShouldEliminate=&Blocks[10*Width-1:9*Width];
            EliminatedBlocks={Blocks[Height*Width-1:10*Width],Blocks[9*Width-1:0],10'b0};
        end
        10:begin
            ShouldEliminate=&Blocks[11*Width-1:10*Width];
            EliminatedBlocks={Blocks[Height*Width-1:11*Width],Blocks[10*Width-1:0],10'b0};
        end
        11:begin
            ShouldEliminate=&Blocks[12*Width-1:11*Width];
            EliminatedBlocks={Blocks[Height*Width-1:12*Width],Blocks[11*Width-1:0],10'b0};
        end
        12:begin
            ShouldEliminate=&Blocks[13*Width-1:12*Width];
            EliminatedBlocks={Blocks[Height*Width-1:13*Width],Blocks[12*Width-1:0],10'b0};
        end
        13:begin
            ShouldEliminate=&Blocks[14*Width-1:13*Width];
            EliminatedBlocks={Blocks[Height*Width-1:14*Width],Blocks[13*Width-1:0],10'b0};
        end
        14:begin
            ShouldEliminate=&Blocks[15*Width-1:14*Width];
            EliminatedBlocks={Blocks[Height*Width-1:15*Width],Blocks[14*Width-1:0],10'b0};
        end
        15:begin
            ShouldEliminate=&Blocks[16*Width-1:15*Width];
            EliminatedBlocks={Blocks[Height*Width-1:16*Width],Blocks[15*Width-1:0],10'b0};
        end
        16:begin
            ShouldEliminate=&Blocks[17*Width-1:16*Width];
            EliminatedBlocks={Blocks[Height*Width-1:17*Width],Blocks[16*Width-1:0],10'b0};
        end
        17:begin
            ShouldEliminate=&Blocks[18*Width-1:17*Width];
            EliminatedBlocks={Blocks[Height*Width-1:18*Width],Blocks[17*Width-1:0],10'b0};
        end
        18:begin
            ShouldEliminate=&Blocks[19*Width-1:18*Width];
            EliminatedBlocks={Blocks[Height*Width-1:19*Width],Blocks[18*Width-1:0],10'b0};
        end
        19:begin
            ShouldEliminate=&Blocks[20*Width-1:19*Width];
            EliminatedBlocks={Blocks[19*Width-1:0],10'b0};
        end
        default:begin
            ShouldEliminate=1'b0;
            EliminatedBlocks=Blocks;
        end
    endcase
endmodule