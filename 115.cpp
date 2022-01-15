class Solution {
public:
    int numDistinct(string s, string t) {
        int lens=s.size();
        int lent=t.size();
        int dp[lent+1][lens+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<lens;i++){
            if(s[i]==t[0]){
                dp[1][i]=dp[1][i-1]+1;
            }
            else {
                dp[1][i]=dp[1][i-1];
            }
        }
        for(int i=1;i<lent;i++){
            for(int k=0;k<lens;k++){
                if(t[i]==s[k]){
                    dp[i+1][k+1]=dp[i][k]+1;
                }
                else dp[i+1][k+1]=dp[i][k];
            }
        }      
        int tmp=1;
        int ans=0;
        for(int i=1;i<lens;i++){
            ans*=10;
            ans+=dp[tmp][i];
        }
        return ans;
    }
};
// char c;
// while(1){
//     c=getchar();
//     if(c==''){
//         break;
//     }
// }