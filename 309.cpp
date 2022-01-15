class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        int dp[2][len+2];
        memset(dp,0,sizeof(dp));
        int mark[len+2];
        memset(mark,0,sizeof(mark));
        dp[0][1]=0;
        dp[1][1]=-prices[0];
        for(int i=1;i<len;i++){
            // dp[0][i+1]=max(dp[0][i],dp[1][i]+prices[i]);
            // dp[1][i+1]=max(dp[])
            if(dp[0][i]>dp[1][i]+prices[i]){
                dp[0][i+1]=dp[0][i];
            }
            else {
                dp[0][i+1]=dp[1][i]+prices[i];
                mark[i+1]=1;
            }


            if(dp[1][i]>dp[0][i]-prices[i]){
                // if(mark[i])
                dp[1][i+1]=dp[1][i];
            }
            else {
                if(mark[i]==1){
                    if(dp[1][i]>dp[0][i-1]-prices[i]){
                        dp[1][i+1]=dp[1][i];
                    }
                    else {
                        dp[1][i+1]=dp[0][i-1]-prices[i];
                    }
                }
                else {
                    dp[1][i+1]=dp[0][i]-prices[i];
                }
            }

        }
        return dp[0][len];
    }
};