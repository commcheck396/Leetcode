class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int num_x=0,num_o=0;
        for(int i=0;i<3;i++){
            for(int k=0;k<3;k++){
                if(board[i][k]=='X')num_x++;
                else if(board[i][k]=='O')num_o++;
                else continue;
            }
        }
        if(num_o>num_x)return false;
        if(num_x>num_o+1)return false;
        int flag=0;
        if(num_x==num_o)flag=1;
        else flag=0;
        int stage=0;
        for(int i=0;i<3;i++){
            if(board[i][0]=='O'&&board[i][1]=='O'&&board[i][2]=='O'){
                if(stage==2||!flag)return false;
                else {
                    stage=1;
                }
            }
            if(board[0][i]=='O'&&board[1][i]=='O'&&board[2][i]=='O'){
                if(stage==2||!flag)return false;
                else {
                    stage=1;
                }
            }
            if(board[i][0]=='X'&&board[i][1]=='X'&&board[i][2]=='X'){
                if(stage==1||flag)return false;
                else {
                    stage=2;
                }
            }
            if(board[0][i]=='X'&&board[1][i]=='X'&&board[2][i]=='X'){
                if(stage==1||flag)return false;
                else {
                    stage=2;
                }
            }
        }
        if(board[0][0]=='X'&&board[1][1]=='X'&&board[2][2]=='X'){
                if(stage==1||flag)return false;
                else {
                    stage=2;
                }
            }
        if(board[0][0]=='O'&&board[1][1]=='O'&&board[2][2]=='O'){
                if(stage==2||!flag)return false;
                else {
                    stage=1;
                }
            }
        if(board[0][2]=='X'&&board[1][1]=='X'&&board[0][2]=='X'){
                if(stage==1||flag)return false;
                else {
                    stage=2;
                }
            }
        if(board[0][2]=='O'&&board[1][1]=='O'&&board[0][2]=='O'){
                if(stage==2||!flag)return false;
                else {
                    stage=1;
                }
            }
        return true;
    }
};