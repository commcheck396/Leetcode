class Solution {
    int mark[200005];
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i,k,b,c,len=nums.size();
        for(i=0;i<len;i++){
            if(mark[nums[i]+100000]){
                if(i+1-mark[nums[i]+100000]<=k)return true;
            }
            mark[nums[i]+100000]=i+1;
        }
        return false;
    }
};