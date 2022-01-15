class Solution {
public:
    int minDistance(string word1, string word2) {
        int i,k,b,c,len1,len2;
        len1=word1.size();
        len2=word2.size();
        int dp[len1+1][len2+1];
        for(i=0;i<=len1;i++){
            for(k=0;k<=len2;k++){
                dp[i][k]=0;
            }
        }
        // if(word1[0]==word2[0])dp[0][0]=1;
        // if(word1[1]==word2[0])dp[1][0]=1;
        // if(word1[0]==word2[1])dp[0][1]=1;
        for(i=0;i<len1;i++){
            for(k=0;k<len2;k++){
                if(word1[i]==word2[k]){
                    dp[i+1][k+1]=dp[i][k]+1;
                }
                else {
                    dp[i+1][k+1]=max(dp[i][k+1],dp[i+1][k]);
                }
            }
        }
        return dp[len1][len2];
    }
};