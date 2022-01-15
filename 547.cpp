class Solution {
public:
    int find(vector<int>mark,int i){
        if(mark[i]!=i){
            i=mark[i];
            return mark[i]=find(mark,i);
        }
        return i;
    }
    int col(vector<int>mark,int i,int val){
        if(mark[i]!=i){
            i=mark[i];
            return mark[i]=find(mark,i);
        }
        else
        {
            mark[i]=val;
            return val;
        }
    }
    int findCircleNum(vector<vector<int>>& isconnected) {
        int len=isconnected[0].size();
        vector<int> mark(len+1,0);
        for(int i=0;i<=len;i++){
            mark[i]=i;
        }
        for(int i=0;i<isconnected.size();i++){
            for(int k=0;k<len;k++){
                if(isconnected[i][k]==1){
                    int x=find(mark,i);
                    int y=col(mark,k,x);
                    // mark[y]=mark[x];
                }
            }
        }
        sort(mark.begin(),mark.end());
        int sum=1;
        int last=mark[0];
        for(int i=0;i<len;i++){
            if(mark[i]!=last){
                last=mark[i];
                sum++;
            }
        }
        return sum;
    }
};