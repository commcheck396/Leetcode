class Solution {
public:
    int m,n;
    int dfs(vector<vector<int>>& grid,int x,int y){
        int i,k,b,c,MAX=0;
        if(x>=0&&x<m&&y>=0&&y<n&&grid[x][y]!=0){
            b=grid[x][y];
            grid[x][y]=0;
            MAX=max(MAX,dfs(grid,x+1,y));
            MAX=max(MAX,dfs(grid,x-1,y));
            MAX=max(MAX,dfs(grid,x,y+1));
            MAX=max(MAX,dfs(grid,x,y-1));
            grid[x][y]=b;
            return b+MAX;
        }
        else return 0;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int i,k,b,c,MAX=0;
        m=grid.size();
        n=grid[0].size();
        for(i=0;i<m;i++){
            for(k=0;k<n;k++){
                MAX=max(MAX,dfs(grid,i,k));
            }
        }
        return MAX;
    }
};