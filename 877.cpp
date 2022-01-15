class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int len=piles.size();
        int dp[len+2][len+2];
        for(int i=0;i<len+2;i++){
            memset(dp[i],0,sizeof(dp[i]));
        }
        for(int i=0;i<len;i++){
            dp[i][i]=piles[i];
        }
        for(int i=len-2;i>=0;i--){
            for(int k=len-1;k>i;k--){
                dp[i][k]=max((piles[i]-dp[i+1][k]),(piles[k]-dp[i][k-1]));
            }
        }
        return dp[0][len-1];
    }
};