class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
        int col=obstacle.size();
        int row=obstacle[0].size();
        int dp[col+1][row+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<col;i++){
            if(obstacle[i][0]==1)break;
            else dp[i][0]=1;
        }
        for(int i=0;i<row;i++){
            if(obstacle[0][i]==1)break;
            else dp[0][i]=1;
        }
        for(int i=1;i<col;i++){
            for(int k=1;k<row;k++){
                if(obstacle[i][k]==0)continue;
                else {
                    dp[i][k]=dp[i-1][k]+dp[i][k-1];
                }
            }
        }
        return dp[col-1][row-1];
    }
};