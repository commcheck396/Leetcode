class Solution {
public:
    int line_mark[9][10];
    int row_mark[9][10];
    int unit_mark[3][3][10];

    int dig_mark(int x,int y,int value){
        int i,k,b,c;
        if(line_mark[x][value]==0||row_mark[y][value]==0||unit_mark[x/3][y/3][value]==0)return -1;
        line_mark[x][value]=0;
        row_mark[y][value]=0;
        unit_mark[x/3][y/3][value]=0;
        return 0;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int i,k,b,c;
        for(i=0;i<9;i++){
                for(k=0;k<=9;k++){
                    line_mark[i][k]=1;
                    row_mark[i][k]=1;
                }
            }
            for(i=0;i<3;i++){
                for(k=0;k<3;k++){
                    for(b=0;b<10;b++){
                        unit_mark[i][k][b]=1;
                    }
                }
            }
            for(i=0;i<9;i++){
                for(k=0;k<9;k++){
                    if(board[i][k]!='.')if(dig_mark(i,k,board[i][k])==-1)return false;
                }
            }
        return true;
    }
};  