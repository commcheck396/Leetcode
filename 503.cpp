class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len=nums.size();
        vector<int>ans(len,-1);
        stack<pair<int,int>>mark;
        for(int i=0;i<len;i++){
            while(!mark.empty()&&nums[i]>mark.top().first){
                ans[mark.top().second]=nums[i];
                mark.pop();
            }
            mark.push({nums[i],i});
        }
        for(int i=0;i<len;i++){
            while(!mark.empty()&&nums[i]>mark.top().first){
                ans[mark.top().second]=nums[i];
                mark.pop();
            }
            //mark.push({nums[i],i});
        }
        return ans;
    }
};