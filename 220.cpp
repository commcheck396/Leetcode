class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int i,j,b,c,len;
        len=nums.size();
        set<long>mark;
        for(i=0;i<n;i++){
            auto low=mark.lower_bound(nums[i]-k);
            auto high=mark.upper_bound(nums[i]+k);
            if(low!=mark.end()||high!=mark.begin())return true;
            mark.insert(nums[i]);
            if(i>=k)mark.erase(nums[i-k]);
        }
        return false;
    }
};