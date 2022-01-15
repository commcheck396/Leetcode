class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char,int>tmp;
        for(auto i:s)tmp[i]++;
        priority_queue<pair<int,char>>mark;
        for(auto [val,times]:tmp){
            mark.push({times,val});
        }
        for(;!mark.empty();){
            for(int i=0;i<mark.top().first;i++){
                ans.push_back(mark.top().second);
            }
            mark.pop();
        }
        return ans;
    }
};