class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        stack<int>tmp;
        unordered_map<int,int>mark;
        for(auto i:nums2){
            while(!tmp.empty()&&i>tmp.top()){
                mark[tmp.top()]=i;
                tmp.pop();
            }
            tmp.push(i);
        }
        for(int i;i<nums1.size();i++){
            if(mark[nums1[i]])ans.push_back(mark[nums1[i]]);
            else ans.push_back(-1);
        }
        return ans;
    }
};