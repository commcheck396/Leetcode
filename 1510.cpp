class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool>dp(n+1,false);
        dp[1]=true;
        for(int i=2;i<=n;i++){
            int tmp;
            for(int k=1;;k++){
                tmp=k*k;
                if(tmp>i)break;
                else{
                    if(dp[i-tmp]==false){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};