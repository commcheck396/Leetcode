class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,0);
        dp[0]=nums[0];
        for(int i=1;i<len;i++){
            dp[i]=max(dp[i-1]-1,nums[i]);
            if(dp[i]==0)return false;
        }
        return true;
    }
};