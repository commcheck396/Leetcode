// // class Solution {
// public:
//     int n,k;
//     vector<vector<int>>ans;
//     void dfs(vector<int>a,vector<int>mark){
//         if(a.size()<k){
//             for(int i=1;i<=n;i++){
//                 if(mark[i]==0){
//                     vector<int>tmp(mark);
//                     tmp[i]=1;
//                     vector<int>b(a);
//                     b.push_back(i);
//                     dfs(b,tmp);
//                 }
//                 else continue;
//             }
//         }
//         else if(a.size()==k){
//             ans.push_back(a);
//         }
//     }
//     vector<vector<int>> combine(int N, int K) {
//         n=N;
//         k=K;
//         vector<int>mark(n+1,0);
//         vector<int>a;
//         dfs(a,mark);
//         return ans;
//     }
// };

class Solution {
public:
    int n,k;
    vector<vector<int>>ans;
    void dfs(vector<int>a,int position){
        if(position>n){
            if(a.size()==k)ans.push_back(a);
            return;
        }
        if(a.size()<k){
            for(int i=position;i<=n;i++){
                // dfs(a,i+1);
                // vector<int>tmp(a);
                // a.insert(a.begin(),i);
                if(n-position+1+a.size()<k)return;
                a.push_back(i);
                // tmp.push_back(i);
                dfs(a,i+1);
                a.pop_back();
            }
        }
        else if(a.size()==k){
            ans.push_back(a);
        }
    }
    vector<vector<int>> combine(int N, int K) {
        n=N;
        k=K;
        // vector<int>mark(n+1,0);
        vector<int>a;
        dfs(a,1);
        // vector<vector<int>>ans_;
        return ans;
        // for(auto i:ans){
        //     ans_.push_back(i);
        // }
        // return ans_;
    }
};