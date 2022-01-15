class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max_=max_element(nums.begin(),nums.end())-nums.begin();
        int tmp=nums[max_];
        nums[max_]=-1;
        int second_=max_element(num.begin(),nums.end());
        if(tmp>=nums[second_]*2)return max_;
        else return -1;
        return 0;
    }
};