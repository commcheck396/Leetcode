class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int i,b,c,len;
        unordered_map<int,int>tmp;
        for(auto t:nums)tmp[*t]++;
        multimap<int,int>sub;
        for(auto &[val,times]:tmp)sub.emplace(times,val);
        vector<int>ans;
        for(auto t=sub.rbegin();t!=sub.rend()&&i<k;t++){
            ans.push_back(t->second);
        }
        return ans;
    }
};