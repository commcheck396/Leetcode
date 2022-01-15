int m,n;
int now;
class Solution {
public:
    int search(int x,int y,vector<vector<int>> &grid){
        // if(x==0||y==0||x=m-1||y==n-1)grid[x][y]=0;
        if(x<0||y<0||x>=m||y>=n)return 0;
        else if(grid[x][y]!=now)return 0;
        else {
            grid[x][y]=0;
            if(x==0||y==0||x==m-1||y==n-1){
                grid[x][y]=-1;
                search(x-1,y,grid);
                search(x+1,y,grid);
                search(x,y+1,grid);
                search(x,y-1,grid);
            }
            else {
                if((grid[x-1][y]==now||grid[x-1][y]==0||grid[x-1][y]==-1)&&(grid[x+1][y]==now||grid[x+1][y]==0||grid[x+1][y]==-1)&&(grid[x][y+1]==now||grid[x][y+1]==0||grid[x][y+1]==-1)&&(grid[x][y-1]==now||grid[x][y-1]==0||grid[x][y-1]==-1)){
                    grid[x][y]=0;
                }
                else grid[x][y]=-1;
                search(x-1,y,grid);
                search(x+1,y,grid);
                search(x,y+1,grid);
                search(x,y-1,grid);
            }
        }
        return 0;
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m=grid.size();
        n=grid[0].size();
        now=grid[row][col];
        search(row,col,grid);
        for(int i=0;i<m;i++){
            for(int k=0;k<n;k++){
                if(grid[i][k]==0)grid[i][k]=now;
                else if(grid[i][k]==-1)grid[i][k]=color;
                else continue;
            }
        }
        return grid;
    }
};