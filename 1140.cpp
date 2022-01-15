class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int dp[len+1][len+1];
        int sum=0;
        for(int i=len-1;len>=0;len--){
            sum+=piles[i];
            for(int l=1;l<len;l++){
                if(i+2*l>=len)dp[i][l]=sum;
                else {
                    for(int k=1;k<2*M;k++){
                        dp[i][l]=max(dp[i][l],sum-dp[i+l][max(l,k)]);   
                    }
                }
            }
        }
        return dp[0][1];
    }
};