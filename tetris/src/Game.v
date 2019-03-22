`timescale 1ns / 1ps

module Game #(parameter Width = 10,parameter Height = 20)(
    input clk,
    input clk_pulse_1Hz,
    input clk_pulse_5Hz,
    input reset,
    input down,
    input left,
    input right,
    input leftRotate,
    input rightRotate,
    input [4:0]NextActiveBlock,
    input [3:0]NextActiveBlockY,
    output [Height*Width-1:0]MixedBlocks,
    output reg [13:0]score,
    output gameover
    );
    parameter State_GameStart = 3'd0;
    parameter State_GameOver = 3'd1;
    parameter State_New = 3'd2;
    parameter State_IDLE = 3'd3;
    parameter State_Down = 3'd4;
    parameter State_Move = 3'd5;
    parameter State_Stop = 3'd6;
    parameter State_Eliminate = 3'd7;
    
    reg [4:0]ActiveBlock,ActiveBlockX;
    reg [3:0]ActiveBlockY;
    reg [2:0]state,nextstate;
    reg [(Height*Width+27):0]nextdata;
    reg [4:0]elimx,nextelimx;
    reg [Height*Width-1:0]Blocks;
    wire [Height*Width-1:0]ElimBlocks;
    always @(posedge clk or posedge reset)
        if (reset)
            begin
                state<=State_GameStart;
                {Blocks,ActiveBlock,ActiveBlockX,ActiveBlockY,score}<=0;
                elimx<=0;
            end
        else
            begin
                state<=nextstate;
                {Blocks,ActiveBlock,ActiveBlockX,ActiveBlockY,score}<=nextdata;
                elimx<=nextelimx;
            end

    wire enNext,enDown,enLeft,enRight,enLeftRotate,enRightRotate,enElim;
    wire [4:0]LeftRotateBlock,RightRotateBlock;
    BlockRotater Rotater(.ActiveBlock(ActiveBlock),.LeftRotateBlock(LeftRotateBlock),.RightRotateBlock(RightRotateBlock));
    BlockChecker Checker_Next(.Blocks(Blocks),.ActiveBlock(NextActiveBlock),.ActiveBlockX(5'b0),.ActiveBlockY(NextActiveBlockY),.enExist(enNext));
    BlockChecker Checker_Down(.Blocks(Blocks),.ActiveBlock(ActiveBlock),.ActiveBlockX(ActiveBlockX+5'd1),.ActiveBlockY(ActiveBlockY),.enExist(enDown));
    BlockChecker Checker_LeftRotate(.Blocks(Blocks),.ActiveBlock(LeftRotateBlock),.ActiveBlockX(ActiveBlockX),.ActiveBlockY(ActiveBlockY),.enExist(enLeftRotate));
    BlockChecker Checker_RightRotate(.Blocks(Blocks),.ActiveBlock(RightRotateBlock),.ActiveBlockX(ActiveBlockX),.ActiveBlockY(ActiveBlockY),.enExist(enRightRotate));
    BlockChecker Checker_Left(.Blocks(Blocks),.ActiveBlock(ActiveBlock),.ActiveBlockX(ActiveBlockX),.ActiveBlockY(ActiveBlockY-4'b1),.enExist(enLeft));
    BlockChecker Checker_Right(.Blocks(Blocks),.ActiveBlock(ActiveBlock),.ActiveBlockX(ActiveBlockX),.ActiveBlockY(ActiveBlockY+4'b1),.enExist(enRight));
    BlockEliminater Eliminater(.Blocks(Blocks),.EliminateX(elimx),.ShouldEliminate(enElim),.EliminatedBlocks(ElimBlocks));
    BlockMixer Mixer(.clk(clk),.Blocks(Blocks),.ActiveBlock(ActiveBlock),.ActiveBlockX(ActiveBlockX),.ActiveBlockY(ActiveBlockY),.MixedBlocks(MixedBlocks));

    always @(*)
        case (state)
            State_GameStart:begin
                nextstate=State_New;
                nextdata=0;
                nextelimx=0;
            end
            State_New:begin
                if(enNext)
                    begin
                        nextstate=State_IDLE;
                        nextdata={Blocks,NextActiveBlock,5'b0,NextActiveBlockY,score};
                    end
                else
                    begin
                        nextstate=State_GameOver;
                        nextdata={Blocks,14'b0,score};
                    end
                nextelimx=0;
            end
            State_IDLE:begin
                if(down?clk_pulse_5Hz:clk_pulse_1Hz)
                    if(left|right|leftRotate|rightRotate)
                        nextstate=State_Move;
                    else
                        nextstate=State_Down;
                else
                    nextstate=State_IDLE;
                nextdata={Blocks,ActiveBlock,ActiveBlockX,ActiveBlockY,score};
                nextelimx=0;
            end
            State_Down:begin
                if(enDown)
                    begin
                        nextstate=State_IDLE;
                        nextdata={Blocks,ActiveBlock,ActiveBlockX+5'd1,ActiveBlockY,score};
                    end
                else
                    begin
                        nextstate=State_Stop;
                        nextdata={Blocks,ActiveBlock,ActiveBlockX,ActiveBlockY,score};
                    end
                nextelimx=0;
            end
            State_Move:begin
                nextstate=State_Down;
                if(leftRotate&enLeftRotate)
                    nextdata={Blocks,LeftRotateBlock,ActiveBlockX,ActiveBlockY,score};
                else if(rightRotate&enRightRotate)
                    nextdata={Blocks,RightRotateBlock,ActiveBlockX,ActiveBlockY,score};
                else if(left&enLeft)
                    nextdata={Blocks,ActiveBlock,ActiveBlockX,ActiveBlockY-4'd1,score};
                else if(right&enRight)
                    nextdata={Blocks,ActiveBlock,ActiveBlockX,ActiveBlockY+4'd1,score};
                else
                    nextdata={Blocks,ActiveBlock,ActiveBlockX,ActiveBlockY,score};
                nextelimx=0;
            end
            State_Stop:begin
                nextstate=State_Eliminate;
                nextdata={MixedBlocks,14'b0,score};
                nextelimx=0;
            end
            State_Eliminate:
                if(elimx<Height)
                    begin
                        nextstate=State_Eliminate;
                        nextelimx=elimx+1;
                        if(enElim)
                            nextdata={ElimBlocks,14'b0,score+14'd1};
                        else
                            nextdata={Blocks,14'b0,score};
                    end
                else
                    begin
                        nextstate=State_New;
                        nextdata={Blocks,14'b0,score};
                        nextelimx=0;
                    end
            State_GameOver:begin
                nextstate=State_GameOver;
                nextdata={Blocks,14'b0,score};
                nextelimx=0;
            end
            default:begin
                nextstate=State_GameStart;
                nextdata=0;
                nextelimx=0;
            end
        endcase
    assign gameover=(state==State_GameOver);
endmodule