    class Solution {
    public:
        int row[10];
        int line[10];
        int dia[20];
        int sub_dia[20];
        int board[10][10];
        int ans;
        int mark(int x,int y){
            row[x]=1;
            line[y]=1;
            dia[x-y+10]=1;
            sub_dia[x+y]=1;
            return 0;
        }
        int remark(int x,int y){
            row[x]=0;
            line[y]=0;
            dia[x-y+10]=0;
            sub_dia[x+y]=0;
            return 0;
        }
        int qualified(int x,int y){
            if(row[x]||line[y]||dia[x-y+10]||sub_dia[x+y])return 0;
            return 1;
        }

        int dfs(int x,int y,int n){
            int i,k,b,c;
            for(i=x;i<n;i++){
                if(qualified(i,y)){
                    mark(i,y);
                    if(y==n-1){
                        ans++;
                    }
                    else{
                        if(y<n-1)dfs(0,y+1,n);
                    }
                    remark(i,y);
                }
            }
            return 0;
        }
        int totalNQueens(int n) {
            int i,k,b,c;
            dfs(0,0,n);
            return ans;
        }
    };