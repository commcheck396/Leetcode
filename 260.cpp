// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int tmp=nums[0];
//         int flag=1;
//         vector<int>ans;
//         for(int i=1;i<nums.size();i++){
//             if(nums[i]!=tmp&&flag==1)ans.push_back(nums[i]);
//             else if(nums[i]!=tmp&&flag!=1){
//                 flag=1;
//                 tmp=nums[i];
//             }
//             else {
//                 flag=0;
//                 continue;
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mark;
        for(int i=0;i<nums.size();i++){
            mark[nums[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(mark[nums[i]]==1)ans.push_back(nums[i]);
        }
        return ans;
    }
};