class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int neg_sum=0;
        for(auto i:nums){
            if(i<0)neg_sum++;
        }
        int i;
        for(i=0;nums[i]<0&&k>0&&i<nums.size();i++,k--){
            nums[i]=-nums[i];
        }
        if(k%2==0);
        else {
            if(i>=nums.size())nums[i-1]=-nums[i-1];
            else if(i==0)nums[0]=-nums[0];
            else {
                if(nums[i]<nums[i-1])nums[i]=-nums[i];
                else{
                    nums[i-1]=-nums[i-1];
                }
            }
        }
        int ans=0;
        for(auto c:nums){
            ans+=c;
        }
        return ans;
    }
};