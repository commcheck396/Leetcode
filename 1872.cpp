class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int len=stones.size();
        if(len==2)return stones[0]+stones[1];
        vector<int>pre(len+1,0);
        for(int i=0;i<len;i++){
            pre[i+1]=pre[i]+stones[i];
        }
        int dp[len+1];
        memset(dp,-10000,sizeof(dp));
        dp[len]=0;
        int mark[len+1];
        dp[len-1]=pre[len];
        // mark[len-1]=len-1;
        for(int i=len-2;i>=0;i--){
            // int tmp=0;
            // for(int k=i;k<len;k++){
            //     tmp+=stones[k];
            //     dp[i]=max(dp[i],pre[i]+tmp-dp[k+1]);
            // }
            dp[i]=max(dp[i+1],pre[i]+tmp-dp[k+1]);
        }
        return dp[0];
    }
};