class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        int row=height.size();
        int col=height[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mark;
        int vis[row+1][col+1];
        memset(vis,0,sizeof(vis));
        int i;
            i=0;
            for(int k=0;k<col;k++){
                if(vis[i][k]==0){
                    vis[i][k]=1;
                    mark.push({height[i][k],i*205+k});
                }
            }
        
            i=row-1;
            for(int k=0;k<col;k++){
                if(vis[i][k]==0){
                    vis[i][k]=1;
                    mark.push({height[i][k],i*205+k});
                }
            }
            i=0;
            for(int k=0;k<row;k++){
                if(vis[k][i]==0){
                    vis[k][i]=1;
                    mark.push({height[k][i],k*205+i});
                }
            }
            i=col-1;
            for(int k=0;k<row;k++){
                if(vis[k][i]==0){
                    vis[k][i]=1;
                    mark.push({height[k][i],k*205+i});
                }
            }
        
        // for(int i = 0; i < row; ++i)
        // {
        //     for(int j = 0; j < col; ++j)
        //     {
        //         if(i == 0 || j == 0 || i == row-1 || j == col-1)
        //         {
        //             mark.push({height[i][j], i*205 + j});
        //             vis[i][j] = 1;
        //         }
        //     }
        // }

        // pair<int,int> dir[4]{{0,1},{0,-1},{-1,0},{1,0}};
        int dirx[4]{0,0,1,-1};
        int diry[4]{1,-1,0,0};
        int maxh=0;
        int ans=0;
        for(;!mark.empty();){
            auto cur=mark.top();
            mark.pop();
            maxh=max(maxh,cur.first);
            int x0=cur.second/205,y0=cur.second%205;
            if(x0!=0&&y0!=0&&x0!=row-1&&y0!=col-1){
                ans+=maxh-cur.first;
            }
            for(int i=0;i<4;i++){
                int x=cur.second/205+dirx[i],y=cur.second%205+diry[i];
                // if(x+dir[i].first>0&&x+dir[i].first<row-1&&y+dir[i].second>0&&y+dir[i].second<col-1&&vis[x+dir[i].second][y+dir[i].second]){
                //     vis[(x+dir[i].first)][y+dir[i].second]=1;
                //     mark.push({height[(x+dir[i].first)][y+dir[i].second],(x+dir[i].first)*205+y+dir[i].second});
                // }
                if(x>=0&&x<row&&y>=0&&y<col&&vis[x][y]==0){
                    vis[x][y]=1;
                    mark.push({height[x][y],x*205+y});
                }
            }
            // mark.pop();
        }
        return ans;
    }
};