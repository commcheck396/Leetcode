// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int len=prices.size();
//         int dp[3][len+2];
//         for(int i=0;i<=len+1;i++){
//             dp[1][i]=INT_MIN;
//         }
//         for(int i=1;i<=len;i++){
//             dp[1][i]=max(dp[1][i-1],dp[2][i]-prices[i-1]);
//             if(dp[2][i-1]<dp[i][i]+prices[i-1]-fee){
//                 // dp[1][i]=INT_MIN;
//                 dp[2][i]=dp[i][i]+prices[i-1]-fee;
//             }
//         }
//         return dp[2][len];
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices,int fee) {
        int len=prices.size();
        int dp[2][len+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=0;
        dp[1][0]=-prices[0]-fee;
        for(int i=1;i<len;i++){
            dp[0][i]=max(dp[1][i-1]+prices[i],dp[0][i-1]);
            dp[1][i]=max(dp[1][i-1],dp[0][i-1]-prices[i]-fee);
        }
        return dp[0][len-1];
    }
};