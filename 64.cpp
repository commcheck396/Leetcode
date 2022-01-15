class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int col=grid.size();
        int row=grid[0].size();
        int dp[col+1][row+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=grid[0][0];
        for(int i=1;i<col;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1;i<row;i++){
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int i=1;i<col;i++){
            for(int k=1;k<row;k++){
                dp[i][k]=min(dp[i-1][k],dp[i][k-1])+grid[i][k];
            }
        }
        return dp[col-1][col-1];
    }
};