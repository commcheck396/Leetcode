class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int>max_row;
        for(int i=0;i<grid.size();i++){
            int tmp;
            tmp=max_element(grid[i].begin(),grid[i].end())-grid[i].begin();
            max_row.push_back(grid[i][tmp]);
        }
        vector<int>max_col;
        for(int i=0;i<grid[0].size();i++){
            int tmp=0;
            for(int k=1;k<grid.size();k++){
                if(grid[k][i]<grid[tmp][i]){
                    continue;
                }
                else {
                    tmp=k;
                }
            }
            max_col.push_back(grid[tmp][i]);
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int k=0;k<grid[0].size();k++){
                ans+=min(max_row[i],max_col[k])-grid[i][k];
            }
        }
        return ans;
    }
};