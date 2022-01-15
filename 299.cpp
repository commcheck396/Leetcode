class Solution {
public:
    bool bfs(int position,vector<vector<int>>&mark,vector<int>&color){
        int tmp=color[position];
        for(int i=0;i<mark[position].size();i++){
            if(color[mark[position][i]]==tmp)return false;
            else if(color[mark[position][i]]==0){
                // mark[position][i]=-color;
                color[mark[position][i]]=-tmp;
                if(bfs(mark[position][i],mark,color)==false)return false;
            }
            else continue;
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>mark(n);
        vector<int>color(n,0);
        for(auto i:dislikes){
            mark[i[0]-1].push_back(i[1]-1);
            mark[i[1]-1].push_back(i[0]-1);
        }
        // int position=0;
        // for(;position<n;position++){
        //     if(!mark[position].empty())break;
        // }
        // color[mark[position][0]]=1;
        for(int i=0;i<n;i++){
            if(color[i]==0){
                color[i]=1;
                if(bfs(i,mark,color)==false)return false;
            }
        }
        return true;
    }
};