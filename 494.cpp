class Solution {
public:
    int dis;
    int cal(int pre,int position){
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //int i,k,b,c;
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        dis=(target+sum)/2;
        if((target+sum)%2||abs(target)>sum)return 0;
        else {
            // vector<int>dp(dis+1,0);
            // for(auto i:nums){
            //     for(int k=0;k<)
            // }
            int dp[nums.size()][dis+1]={0};
            for(int i=0;i<nums.size();i++){
                for(int k=nums[i];k<=dis;k++){
                    dp[i][k]=max(dp[i-1][k],dp[i-1][k-nums[i]]+1);
                }
            }
        }
        return dp[i-1][dis];
    }
};