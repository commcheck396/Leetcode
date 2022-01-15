// // class Solution {
// // public:
// //     int kInversePairs(int n, int K) {
// //         if(K==0)return 1;
// //         if(n==1)return 0;
// //         if(K>(n*(n-1))/2)return 0;
// //         int mod=1e9+7;
// //         int dp[n+1][K+1];
// //         memset(dp,0,sizeof(dp));
// //         for(int i=0;i<=n;i++){
// //             dp[i][0]=1;
// //         }
// //         dp[2][1]=1;
// //         int last=1;
// //         for(int i=3;i<=n;i++){
// //             int pre=0;int tmp=last;
// //             for(int k=min(K,(i*(i-1))/2);k>0;k--){
// //                 // if(k>(i*(i-1))/2)continue;
// //                 if(tmp>=0)pre+=dp[i-1][tmp--];
// //                 if(k<last){
// //                     pre-=dp[i-1][last--];
// //                 }
// //                 dp[i][k]=pre%mod;
// //             }
// //             last=min(K,(i*(i-1))/2);
            
// //         }
// //         return dp[n][K]%mod;
// //     }
// // };

// class Solution {
// public:
//     int kInversePairs(int n, int K) {
//         if(K==0)return 1;
//         if(n==1)return 0;
//         if(K>(n*(n-1))/2)return 0;
//         if(K==1)return n-1;
//         int mod=1e9+7;
//         // int dp[n+1][(n*(n-1))/2+1];
//         // memset(dp,0,sizeof(dp));
//         // for(int i=0;i<=n;i++){
//         //     dp[i][0]=1;
//         // }
//         // dp[2][1]=1;
//         vector<long>dp(K+1,0);
//         dp[0]=1;
//         dp[1]=1;
//         int last=1;
//         for(int i=3;i<=n;i++){
//             // vector<long>dpt((i*(i-1))/2+1,0);
//             // dpt[0]=1;
//             int pre=0;int tmp=last;
//             for(int k=K;k>0;k--){
//                 if(tmp>=0)pre+=dp[tmp--];
//                 if(k<last){
//                     pre-=dp[last--];
//                 }
//                 dp[k]=pre%mod;
//             }
//             last=K;
//             // dp=dpt;
//         }
//         return dp[K]%mod;
//     }
// };

class Solution {
public:
    int kInversePairs(int N, int K) {
        int dp[K+1];
        int pre[K+1];
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        int mod=1e9+7;
        {
            dp[0]=1;
            pre[0]=1;
        }
        for(int i=1;i<=N;i++){
            
            for(int k=1;k<=K;k++){
                pre[k]=(pre[k-1]+dp[k])%mod;
            }
            for(int k=1;k<=K;k++){
                if(i>=k+1){
                    dp[k]=pre[k];
                }
                else{
                    dp[k]=(pre[k]-pre[k-i])%mod;
                }
            }
        }
        return (dp[K]+mod)%mod;
    }
};