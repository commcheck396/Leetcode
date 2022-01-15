class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        vector<int>pre(stones.size()+1,0);
        pre[1]=stones[0];
        for(int i=1;i<stones.size();i++){
            pre[i+1]=pre[i]+stones[i];
        }
        int dp[stones.size()+1][stones.size()+1];
        for(int i=0;i<stones.size();i++){
            for(int k=0;k<stones.size();k++){
                dp[i][k]=0;
            }
        }
        for(int i=1;i<stones.size();i++){
            for(int k=i-1;k>=0;k--){
                dp[k][i]=max((pre[i]-pre[k]-dp[k][i-1]),(pre[i+1]-pre[k+1]-dp[k+1][i]));
            }
        }
        return dp[0][stones.size()-1];
    }
};