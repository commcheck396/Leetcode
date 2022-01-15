class Solution {
public:
    set<pair<string,int>>mark;
    int ans;
    void del(string &board){
        int i,k;
        for(i=0;i<board.size();){
            for(k=i+1;k<=board.size();k++){
                if(k==board.size())break;
                else if(board[k]==board[i])continue;
                else break;
            }
            if(k-i>=3){
                board.erase(i,k-i);
                k=0;
            }
            i=k;
        }
    }
    void bfs(string &board,string &hand,int cur){
        if(cur>=ans)return ;
        if(board.empty()){
            ans=min(ans,cur);
        }
        if(hand.empty())return;
        if(mark.count({board,cur}))return;
        else mark.insert({board,cur});
        for(int i=0;i<board.size();i++){
            for(int k=0;k<hand.size();k++){
                string new_board=board;
                string new_hand=hand;
                char tmp=hand[k];
                new_hand.erase(k,1);
                new_board.insert(new_board.begin()+i,tmp);
                del(new_board);
                bfs(new_board,new_hand,cur+1);
            }
        }
    }
    int findMinStep(string board, string hand) {
        ans=0x3f3f3f;
        bfs(board,hand,0);
        if(ans==0x3f3f3f)return -1;
        else return ans;
    }
};