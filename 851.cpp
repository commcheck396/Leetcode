int mapp[505];
vector<vector<int>>mark;
vector<int>ans;
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int>ans_(n,-1);
        vector<vector<int>>mark_(n);
        mark=mark_;
        ans=ans_;
        vector<vector<int>>sum(n,vector<int>(2,0));
        memset(sum,0,sizeof(sum));
        for(int i=0;i<n;i++){
            sum[i][1]=i;
        }
        for(int i=0;i<n;i++){
            mapp[quiet[i]]=i;
        }
        for(auto c:richer){
            mark[c[1]].push_back(c[0]);
            sum[c[1]][0]++;
        }
        sort(sum.begin(),sum.end(),[](auto &a,auto &b){return a[0]<b[0];});
        for(int i=0;i<n;i++){
            dfs(sum[i][1],quiet);
        }
        ans.resize(n);
        return ans;
    }
// private:
//     vector<vector<int>>mark;
//     vector<int>ans;
//     int dfs(int i,vector<int>& quiet){
//         if(ans[i]==-1){
//             int quieter=i;
//             // ans[i]=i;
//             // for (const auto& neighbor : mark[i]) {
//             //     auto quietestPerson = dfs(neighbor, quiet,mark,ans);
//             //     if (quiet[quietestPerson] < quiet[ans[i]]) {
//             //         ans[i] = quietestPerson;
//             //     }
//             // }
//             int tmp;
//             for(auto c:mark[i]){
//                 tmp=dfs(c,quiet);
//                 if(quiet[tmp]<quiet[quieter]){
//                     quieter=tmp;
//                 }
//             }
//             ans[i]=quieter;
//             return ans[i];
//         }
//         else return ans[i];
//     }
// };

    int dfs(int value,vector<int>& quiet){
        int i=mapp[value];
        if(ans[i]==-1){
            int quieter=i;
            int tmp;
            for(auto c:mark[i]){
                tmp=dfs(c,quiet);
                if(quiet[tmp]<quiet[quieter]){
                    quieter=tmp;
                }
            }
            ans[i]=quieter;
            return ans[i];
        }
        else return ans[i];
    }
};