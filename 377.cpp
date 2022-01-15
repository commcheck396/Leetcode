class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int dp[target+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<target;i++){
            for(auto num:nums){
                if(num<i){
                    if(dp[i-num]!=0)dp[i]+=dp[i-num];
                }
            }
        }
        int ans=0;
        for(int i=0;i<target;i++){
            ans+=dp[i];
        }
        return ans;
    }
};