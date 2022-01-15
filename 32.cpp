class Solution {
public:
    int longestValidParentheses(string s) {
        int len=s.size();
        vector<int>dp(len+1,0);
        int max_=0;
        for(int i=1;i<len;i++){
            if(s[i]=='(')continue;
            else {
                if(s[i-1]=='(')dp[i]=i-2>0?dp[i-2]+1:1,max_=max(max_,dp[i]);
                if(s[i-1]==')'){
                    if(i-1-dp[i-1]*2>=0){
                        if(s[i-1-dp[i-1]*2]=='(')dp[i]=dp[i-1]+1+dp[i-1-dp[i-1]*2-1>=0?i-1-dp[i-1]*2-1:0];
                        else dp[i]=0;
                    }
                    max_=max(max_,dp[i]);
                }
            }
        }
        return max_*2;
    }
};