class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int len=nums.size();
        // int pre[len+1];
        vector<int>pre(len+1,0);
        pre[0]=0;
        for(int i=0;i<len;i++){
            pre[i+1]=pre[i]+nums[i];
        }
        vector<vector<int>>dp1(k,vector<int>(1,0));
        // for(int i=k;i<len;i++){
        //     int cur=pre[i]-pre[i-k];
        //     if(cur+dp1[i-k][0]<=dp1[i-1][0]){
        //         dp1.push_back(dp[i-1]);
        //     }
        //     else {
        //         dp1.push_back(dp[i-k]);
        //         dp1[i][0]=cur;
        //         dp1[i].push_back(i-1);
        //     }
        // }
        for(int i=k;i<=len;i++){
            int cur=pre[i]-pre[i-k];
            if(cur<=dp1[i-1][0]){
                dp1.push_back(dp1[i-1]);
            }
            else {
                vector<int>tmp;
                tmp.push_back(cur);
                tmp.push_back(i-k);
                dp1.push_back(tmp);
                // dp1.push_back(dp[i-k]);
                // dp1[i][0]=cur;
                // dp1[i].push_back(i-1);
            }
        }
        int index=k*2;
        vector<vector<int>>dp2(index,vector<int>(1,0));
        for(int i=k*2;i<=len;i++){
            int cur=pre[i]-pre[i-k];
            if(cur+dp1[i-k][0]<=dp2[i-1][0]){
                dp2.push_back(dp2[i-1]);
            }
            else {
                dp2.push_back(dp1[i-k]);
                dp2[i][0]=cur+dp1[i-k][0];
                dp2[i].push_back(i-k);
            }
        }

        index=k*3;
        vector<vector<int>>dp3(index,vector<int>(1,0));
        for(int i=k*3;i<=len;i++){
            int cur=pre[i]-pre[i-k];
            if(cur+dp2[i-k][0]<=dp3[i-1][0]){
                dp3.push_back(dp3[i-1]);
            }
            else {
                dp3.push_back(dp2[i-k]);
                dp3[i][0]=cur+dp2[i-k][0];
                dp3[i].push_back(i-k);
            }
        }
        vector<int>ans;
        for(int i=1;i<dp[3].size();i++){
            ans.push_back(dp[3][i]);
        }
        sort(ans.begin(),ans.end());
        // ans.pop_front();
        return ans;
    }
};