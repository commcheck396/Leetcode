class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        int buy=INT_MIN;
        int sold=0;
        int bought=INT_MIN;
        int sell=0;
        // memset(buy,0,sizeof(buy));
        // for(int i=0;i<=len;i++){
        //     buy[1][i]=INT_MIN;
        //     buy[2][i]=INT_MIN;
        // }
        // memset(sold,0,sizeof(sold));
        for(int i=0;i<len;i++){
            // buy[1][i+1]=max(buy[1][i],-prices[i]);
            // sold[1][i+1]=max(sold[1][i],prices[i]+buy[1][i]);
            // buy[2][i+1]=max(sold[1][i]-prices[i],buy[2][i]);
            // sold[2][i+1]=max(prices[i]+buy[2][i],sold[2][i]);
            bought=max(bought,-prices[i]);
            sold=max(sold,bought-prices[i]);
            buy=max(sold-prices[i],buy);
            sell=max(sell,buy+prices[i]);
        }
        return sell;
    }
};