class Solution {
public:
    void dfs(vector<int>a,int n,int i,int sum){
        if(a.size()==2){
            if(n-a[0]-a[1]>9)return;
            else if(n-sum<=a[1])return;
            else{
                if(n-a[0]-a[1]==a[0]||n-a[0]-a[1]==a[1])return ;
                else a.push_back(n-a[0]-a[1]);
                ans.push_back(a);
            }
        }
        else if(a.size()==1){
            if(n-sum<=a[0])return;
            for(int k=i;k<9&&k<n-sum){
                if(n-sum<=a[1])return;
                vector<int>tmp(a);
                a.push_back(k);
                dfs(a,n,k+1,sum+k);
            }
        }
        else{
            for(int k=1;k<=9&&k<sum;k++){
                vector<int>tmp;
                tmp.push_back(k);
                dfs(a,n,k,k);
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>a;
        for(int i=0;i<=9;i++){
            a.push_back(i);
        }
        dfs(a,n,0,0);
        return ans;
    }
};