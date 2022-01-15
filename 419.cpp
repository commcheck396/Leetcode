// int m,n;
// class Solution {
// public:
//     void search(int x,int y,vector<vector<char>>& board){
//         for(int i=x+1;i<m;i++){
//             if(board[i][y]=='X')board[i][y]='.';
//             else break;
//         }
//         for(int i=x-1;i>=0;i--){
//             if(board[i][y]=='X')board[i][y]='.';
//             else break;
//         }
//         for(int i=y+1;i<n;i++){
//             if(board[x][i]=='X')board[x][i]='.';
//             else break;
//         }
//         for(int i=y-1;i>=0;i--){
//             if(board[x][i]=='X')board[x][i]='.';
//             else break;
//         }
//         board[x][y]=0;
//     }
//     int countBattleships(vector<vector<char>>& board) {
//         m=board.size();
//         n=board[0].size();
//         int ans=0;
//         for(int i=0;i<m;i++){
//             for(int k=0;k<n;k++){
//                 if(board[i][k]=='X'){
//                     ans++;
//                     search(i,k,board);
//                 }
//                 else continue;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();
        int ans=0;    
        for(int i=0;i<m;i++){
            for(int k=0;k<n;k++){
                if(board[i][k]=='X'){
                    if(i==0&&k==0){
                        ans++;
                    }
                    else if(i==0){
                        if(board[i][k-1]=='X')continue;
                        else ans++;
                    }
                    else if(k==0){
                        if(board[i-1][k]=='X')continue;
                        else ans++;
                    }
                    else {
                        if(board[i-1][k]=='X'||board[i][k-1]=='X')continue;
                        else ans++;
                    }
                }
            }
        }
        return ans;
    }
};