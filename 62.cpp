class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        memset(dp[0],1,sizeof(dp[0]));
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<m;i++){
            for(int k=1;k<n;k++){
                dp[i][k]=dp[i-1][k]+dp[i][k-1];
            }
        }
        return dp[m-1][n-1];
    }
};