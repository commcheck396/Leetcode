class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i,k,b,c,len;
        len=nums.size();
        if(len==1)return 0;
        for(i=1;i<len-1;i++){
            if(nums[i]>nums[i+1]&&nums[i-1]<nums[i])return i;
        }
        if(nums[0]>nums[1])return 0;
        if(nums[len-1]>nums[len-2])return len-1;
        return len-1;
    }
};