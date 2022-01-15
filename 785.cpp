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
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(100,0);
        for(int i=0;i<graph.size();i++){
            if(color[i]==0){
                color[i]=1;
                if(dfs(i,graph,color)==false)return false;
            }
        }
        return true;
    }
};