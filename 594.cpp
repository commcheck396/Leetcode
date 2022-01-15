class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max_=0;
        int a=1,b=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])a++;
            else if(nums[i]==nums[i-1]+1){
                b=a;
                a=1;
            }
            else {
                a=0;
                b=0;
            }
            if(b!=0)max_=max(max_,a+b);
        }
        return max_;
    }
};