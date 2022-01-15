class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int len=arr.size();
        // vector<int>dp(len,0);
        unordered_map<int,int>dp;
        for(int i=0;i<len;i++){
            dp[i]=dp[i-difference]+1;
        }
        int max_=0;
        for(auto i:dp){
            max_=max(i,max_);
        }
        return max_;
    }
};