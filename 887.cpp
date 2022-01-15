class Solution {
public:
    unordered_map<int,int>memo;
    int dp(int k,int n){
        if(memo.find(n*100+k)!=memo.end())return memo[100*n+k];
        int high,low,mid;
        int b,c;
        if(n==0){
            memo[100*n+k]=0;
            return 0;
        }
        if(k==1){
            memo[100*n+k]=n;
            return n;
        }
        high=n;
        low=1;
        while(low+1<high){
            mid=(low+high)/2;
            b=dp(k-1,mid-1);
            c=dp(k,n-mid);
            if(b<c){
                low=mid;
            }
            else if(b>c){
                high=mid;
            }
            else{
                low=mid;
                high=mid;
            }
        }
        if(high!=low)memo[100*n+k]=1+min(max(dp(k-1,low-1),dp(k,n-low)),max(dp(k-1,high-1),dp(k,n-high)));
        else memo[100*n+k]=1+max(dp(k-1,low-1),dp(k,n-low));
        return memo[100*n+k];
    }

    int superEggDrop(int k, int n) {
        // int i,j,b,c;
        // int dp[101][10001];
        // // for(i=0;i<n;i++){
        // //     for(j=0;j<k;j++){
        // //       dp[i][j]=INT_MAX;  
        // //     }
        // // }
        // for(i=0;i<=n;i++){
        //     dp[1][i]=i;
        //     dp[0][i]=0;
        // }
        // for(i=0;i<=k;i++){
        //     dp[i][0]=0;
        // }
        // for(j=2;j<=k;j++){
        //     // for(i=1;i<=n;i++){
        //     //     int ans=INT_MAX;
        //     //     for(b=1;b<=i;b++){
        //     //         ans=min(ans,(max(dp[j-1][b-1],dp[j][i-b])+1));
        //     //     }
        //     //     dp[j][i]=ans;
        //     // }

        // }
        return dp(k, n);
    }
};