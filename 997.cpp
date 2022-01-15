class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int len=trust.size();
        int in_mark[n+1];
        int out_mark[n+1];
        memset(in_mark,0,sizeof(in_mark));
        memset(out_mark,0,sizeof(out_mark));
        for(int i=0;i<len;i++){
            in_mark[trust[i][1]]++;
            out_mark[trust[i][0]]++;
        }
        int flag=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(in_mark[i]==n-1&&out_mark[i]==0){
                flag++;
                ans=i;
            }
        }
        if(flag==1)return ans;
        else return -1;
    }
};