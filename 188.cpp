class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len=prices.size();
        if(len==0)return 0;
        int sold[k+1];
        int bought[k+1];
        for(int i=0;i<=k;i++){
            bought[i]=INT_MIN;
            sold[i]=0;
        }
        bought[0]=0;
        int max_=0;
        for(int i=0;i<len;i++){
            for(int j=1;j<=k;j++){
                bought[j]=max(bought[j],sold[j-1]-prices[i]);
                sold[j]=max(sold[j],bought[j]+prices[i]);
                max_=max(max_,sold[j]);
            }
        }
        return max_;
    }
};