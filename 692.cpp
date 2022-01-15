class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int j) {
        unordered_map<string,int>tmp;
        for(auto i:words){
            tmp[i]++;
        }
        vector<vector<string>>mark(words.size()+1);
        for(auto[val,times]:tmp){
            mark[times].push_back(val);
        }
        vector<string>ans;
        int sum=0;
        for(int i=words.size();i>=0;i--){
            if(ans.size()==j)return ans;
            if(mark[i].size()>1)sort(mark[i].begin(),mark[i].end());
            for(int k=0;k<mark[i].size();k++){
                if(ans.size()==j)return ans;
                ans.push_back(mark[i][k]);
                if(ans.size()==j)return ans;
            }
        }
        return ans;
    }
};