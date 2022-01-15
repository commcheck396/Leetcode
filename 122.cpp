// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int len=prices.size();
//         if(len<2)return 0;
//         int in_store;
//         if(prices[0]<prices[1]){
//             in_store=prices[0];
//         }
//         else in_store=0;
//         int ans=0;
//         for(int i=1;i<len;i++){
//             if(in_store!=0){
//                 if(prices[i]>=prices[i-1])continue;
//                 else {
//                     ans+=prices[i-1]-in_store;
//                     in_store=prices[i];
//                 }
                
//             }  
//             else {
//                 if(price[i-1]<=prices[i]){
//                     in_store=price[i-1];
//                 }
//             }
//         }
//         if(in_store<=prices[len-1]){
//             ans+=prices[len-1]-in_store;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        int dp[2][len+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=0;
        dp[1][0]=-prices[0];
        for(int i=1;i<len;i++){
            dp[0][i]=max(dp[1][i-1]+prices[i],dp[0][i-1]);
            dp[1][i]=max(dp[1][i-1],dp[0][i-1]-prices[i]);
        }
        return dp[0][len-1];
    }
};