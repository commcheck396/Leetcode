class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int i,k,b,c,len,MAX;
        len=nums.size();
        MAX=*max_element(nums.begin(),nums.end())-*min_element(nums.begin(),nums.end());
        //MAX=*max_element(nums.begin(),nums.end());
        int dp[len][MAX*2+1];
        // memset(dp,1,sizeof(dp));
        for(i=0;i<len;i++){
            for(k=0;k<=MAX*2;k++){
                dp[i][k]=1;
            }
        }
        //vector<vector<int>> dp(len, vector<int>(MAX * 2 + 1, 1));
        int ans=0;
        for(i=1;i<len;i++){
            for(k=0;k<i;k++){
                b=nums[i]-nums[k]+MAX;
                dp[i][b]=max(dp[i][b],dp[k][b]+1);
                ans=max(ans,dp[i][b]);
            }
        }
        return ans;
    }
};