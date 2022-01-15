class Solution {
public:
    
    int sudoku_begin[9][9];
    int sudoku_dig[9][9];
    int line_mark[9][10];
    int row_mark[9][10];
    int unit_mark[3][3][10];
    int SUM_SOLUTION;
    int dig_mark(int x,int y,int value){
        int i,k,b,c;
        line_mark[x][value]=0;
        row_mark[y][value]=0;
        unit_mark[x/3][y/3][value]=0;
        return 0;
    }
    int re_dig_mark(int x,int y,int value){
        int i,k,b,c;
        line_mark[x][value]=1;
        row_mark[y][value]=1;
        unit_mark[x/3][y/3][value]=1;
        return 0;
    }
    int ass(int x,int y,int value,int index){
        int i,k,b,c;
        if(index==1){
            sudoku_dig[x][y]=value;
            return 0;
        }
        else sudoku_dig[x][y]=0;
        return 0;
    }
    void dfs(int x,int y) {
        if(SUM_SOLUTION>1)return;
        if(x>8||y>8)return;
        if(sudoku_dig[x][y]) {
            if(x<=8&&y<=8) {
                dfs(x+(y+1)/9,(y+1)%9);
                return;
                }
            else{
                //show();
                // printf("\n");
                return;
                }
        }
        for(int i=1;i<=9;i++) {
            if(SUM_SOLUTION>1)return;
            if(line_mark[x][i]||row_mark[y][i]||unit_mark[x/3][y/3][i]) continue;
            ass(x,y,i,1);
            re_dig_mark(x,y,i);
            if(x==8&&y==8) {
                //SUM_SOLUTION++;
                //show();
                // printf("\n");
                //ass(x,y,i,-1);
                dig_mark(x,y,i);
                //break;
                return;
                }
            else dfs(x+(y+1)/9,(y+1)%9);
            //ass(x,y,i,-1);
        }
        dig_mark(x,y,
        )
    }
    void solveSudoku(vector<vector<char>>& board) {
        int i,k,b,c;
        for(i=0;i<9;i++){
            for(k=0;k<9;k++){
                if(board[i][k]!='.'){
                    sudoku_dig[i][k]=board[i][k]-'0';
                }
                else sudoku_dig[i][k]=0;
            }
        }

        for(i=0;i<9;i++){
                for(k=0;k<=9;k++){
                    line_mark[i][k]=0;
                    row_mark[i][k]=0;
                }
            }
            for(i=0;i<3;i++){
                for(k=0;k<3;k++){
                    for(b=0;b<10;b++){
                        unit_mark[i][k][b]=0;
                    }
                }
            }
        
        for(i=0;i<9;i++){
            for(b=0;b<9;b++){
                if(sudoku_dig[i][k]!=0)re_dig_mark(i,k,sudoku_dig[i][k]);
            }
        }

        dfs(0,0);

        for(i=0;i<9;i++){
            for(k=0;k<9;k++){
                board[i][k]=sudoku_dig[i][k]+'0';
            }
        }
    }
    
};