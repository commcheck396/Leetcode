class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int>satisfied;
        vector<vector<int>>mark(n,vector<int>(0));
        vector<int>ans;
        int tmp[n];
        memset(tmp,0,sizeof(tmp));
        for(auto c:prerequisites){
            mark[c[1]].push_back(c[0]);
            tmp[c[0]]++;
        }
        for(int i=0;i<n;i++){
            if(tmp[i]==0)satisfied.push(i);
        }
        for(;!satisfied.empty();){
            int c=satisfied.front();
            ans.push_back(c);
            for(int i=0;i<mark[c].size();i++){
                if(tmp[mark[c][i]]!=0){
                    tmp[mark[c][i]]--;
                    if(tmp[mark[c][i]]==0)satisfied.push(mark[c][i]);
                }
            }
            satisfied.pop();
        }
        // for(int i=0;i<n;i++){
        //     if(tmp[i]!=0)return [];
        // }
        // return ans;
        if(ans.size()==n)return ans;
        else return [];
    }
};