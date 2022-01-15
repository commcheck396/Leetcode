class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int tmp,times;
        tmp=a[i];
        times=0;
        vector<int>ans;
        for(auto i:nums){
            if(i==tmp)times++;
            else{
                if(times>nums.size()/3)ans.push_back(i);
                tmp=i;
                times=1;
            }
        }
        return ans;
    }
};