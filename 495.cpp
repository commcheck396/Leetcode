class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0;
        for(int i=0;i<timeSeries-1;i++){
            ans+=min(duration,timeSeries[i+1]-timeSeries[i]);
        }
        ans+=duration;
        return ans;
    }
};