class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.size();
        int len2=s2.size();
        int len3=s3.size();
        if(len1==0||len2==0||len3==0)return true;
        if(len1+len2!=len3)return false;
        int dp[len1+1][len2+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<len1;i++){
            if(s1[i]==s3[i]){
                dp[i+1][0]=1;
            }
            else break;
        }
        for(int i=0;i<len2;i++){
            if(s2[i]==s3[i]){
                dp[0][i+1]=1;
            }
            else break;
        }
        for(int i=1;i<=len1;i++){
            for(int k=1;k<=len2;k++){
                if(s1[i-1]==s3[i+k-1]){
                    dp[i][k]=dp[i-1][k];
                }
                if(s2[k-1]==s3[i+k-1]){
                    if(dp[i][k]==0)dp[i][k]=dp[i][k-1];
                }
            }
        }
        return dp[len1][len2];
    }
};