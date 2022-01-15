    class Solution {
    public:
        int row[10];
        int line[10];
        int dia[20];
        int sub_dia[20];
        int board[10][10];
        int ans;
        vector<vector<string>> a;
        int mark(int x,int y){
            row[x]=1;
            line[y]=1;
            dia[x-y+10]=1;
            sub_dia[x+y]=1;
            board[x][y]=1;
            return 0;
        }
        int remark(int x,int y){
            row[x]=0;
            line[y]=0;
            dia[x-y+10]=0;
            sub_dia[x+y]=0;
            board[x][y]=0;
            return 0;
        }
        int qualified(int x,int y){
            if(row[x]||line[y]||dia[x-y+10]||sub_dia[x+y])return 0;
            return 1;
        }
        int record(int n){
            string s(n,'0');
            vector<string>tmp(n,s);
            int i,k,b,c;
            for(i=0;i<n;i++){
                for(k=0;k<n;k++){
                    if(board[i][k])tmp[i][k]='Q';
                    else tmp[i][k]='.';
                }
            }
            a.push(tmp);
            return 0;
        }

        int dfs(int x,int y,int n){
            int i,k,b,c;
            for(i=x;i<n;i++){
                if(qualified(i,y)){
                    mark(i,y);
                    if(y==n-1){
                        record(n);
                    }
                    else{
                        if(y<n-1)dfs(0,y+1,n);
                    }
                    remark(i,y);
                }
            }
            return 0;
        }
        // int totalNQueens(int n) {
        //     int i,k,b,c;
        //     dfs(0,0,n);
        //     return ans;
        // }
    vector<vector<string>> solveNQueens(int n) {
            int i,k,b,c;
            dfs(0,0,n);
            return a;
        }
    };