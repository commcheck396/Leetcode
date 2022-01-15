 class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int remaining=0;
        int ans=0;
        int cur=numBottles;
        for(;cur>0;){
            ans+=cur;
            remaining+=cur;
            cur=remaining/numExchange;
            remaining=(remaining)%numExchange;
            // cur=cur/numExchange+cur%numExchange;
        }
        // ans+=cur;
        return ans;
    }
};