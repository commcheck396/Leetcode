class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[n+2][n+2];
        memset(dp,0,sizeof(dp));
        for(int len=2;i<=n;i++){
            for(int i=1;i+len-1<=n;i++){
                // int k=i+len-1;
                int tmp=0x3f3f3f;
                for(int k=i;k<=i+len-1;k++){
                    tmp=min(max(dp[i][k-1],dp[k+1][i+len-1])+k,tmp);
                }
                dp[i][i+len-1]=tmp;
            }
        }
        return dp[1][n];
    }
};