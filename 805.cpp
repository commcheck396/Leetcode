class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int i,k,b,c,len;
        len=nums.size();
        int sum=0;
        for(i=0;i<len;i++){
            sum+=nums[i];
        }      
        float avr=(sum*1.0)/len;
        float dis_;
        int dis;
        int dp[len+1][sum/2+1];
        for(i=1;i<=len/2;i++){
            dis_=i*avr;
            if(dis_>(int)dis_)continue;
            else dis=dis_;
            int count[sum/2+1]={0};
            for(k=1;k<=dis;k++){
                if(k>=nums[i]){
                    // dp[i][k]=max(dp[i-1][k],dp[i-1][k-nums[i]]+nums[i]);
                    if(dp[i-1][k]>dp[i-1][k-nums[i]]+nums[i]){
                        dp[i][k]=dp[i-1][k];
                    }
                    else{
                        dp[i][k]=dp[i-1][k-nums[i]]+nums[i];
                        count[k]=count[k-nums[i]]+1;
                    }
                }
                else dp[i][k]=dp[i-1][k];
                if(dp[i][k]==dis&&count[k]==i) return true;
            }
            if(dp[i][dis]==dis&&count[k]==i) return true;
        }
        return false;
    }
};