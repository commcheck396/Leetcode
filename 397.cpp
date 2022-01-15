    class Solution {
    public:
        int integerReplacement(int n) {
            // int dp[n+1];
            // memset(dp,0,sizeof(dp));
            
            // int ans=0;
            // if(n==1)return 0;
            // for(int i=0;;){
            //     if(n%2)n--;
            //     else {
            //         n/=2;
            //     }
            //     ans++;
            //     if(n==1)return ans;
            // }
            // return -1;
            // unordered_map<int,int>mark;
            // mark[1]=0;
            // for(int i=2;i<=n;i++){
            //     if(i%2==0){
            //         mark[i]=mark[i/2]+1;
            //         // i/=2;
            //     }
            //     else {
            //         if(mark[(i+1)/2]<mark[(i-1)/2]){
            //             mark[i]=mark[(i+1)/2]+2;
            //             // i=(i+1)/2;
            //         }
            //         else {
            //             mark[i]=mark[(i-1)/2]+2;
            //             // i=(i-1)/2;
            //         }
            //     }
            // }
            // return mark[n];
            return dfs(n);
        }
        int dfs(int n){
            if(n==1)return 0;
            if(n==INT_MAX)return 32;
            if(n%2==0){
                return dfs(n/2)+1;
            }
            else {
                return min(dfs((n+1)),dfs((n-1)))+1;
            }
            return 0;
        }
    };