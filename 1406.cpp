class Solution {
public:
    string stoneGameIII(vector<int>& stone) {
        int len=stone.size();
        // if(len==1)return "Alice";
        reverse(stone.begin(),stone.end());
        vector<int>dp(stone.size()+1,INT_MIN);
        int sum=stone[0];
        dp[0]=0;
        dp[1]=stone[0];
        for(int i=2;i<=3&&i<=len;i++){
            sum+=stone[i-1];
            int tmp=0;
            for(int k=1;k<=i;k++){
                tmp+=stone[i-k];
                dp[i]=max(dp[i],sum-dp[i-k]);
            }
        }
        // dp[1]=stone[0];
        // dp[2]=stone[0]+stone[1];
        // dp[3]=stone[0]+stone[1]+stone[2];
        // sum=stone[0]+stone[1]+stone[2];
        for(int i=4;i<=len;i++){
            sum+=stone[i-1];
            int tmp=0;
            for(int k=1;k<=3;k++){
                tmp+=stone[i-k];
                dp[i]=max(dp[i],sum-dp[i-k]);
            }
        }
        if(sum-dp[len]>dp[len])return "Bob";
        else if(sum-dp[len]==dp[len])return "Tie";
        else return "Alice";
    }
};