class Solution {
public:
    int stoneGameV(vector<int>& stone) {
        int len=stone.size();
        int dp[len+1][len+1];
        memset(dp,0,sizeof(dp));
        int pre[len+1];
        memset(pre,0,sizeof(pre));
        // vector<int>pre(stone.size()+1,0);
        // vector<vector<int>>dp(stone.size(),vector<int>(stone.size()+1,0));
        pre[0]=0;
        for(int i=0;i<len;i++){
            pre[i+1]=pre[i]+stone[i];
            dp[i+1][i+1]=0;
        }
        // vector<int>mark(stone.size()+1,stone.size());
        int mark[len+1];
        for(int i=0;i<=len;i++){
            mark[i]=len;
        }
        // reverse(stone.begin(),stone.end());
        int left,right;
        for(int i=len-1;i>0;i--){
            for(int k=i+1;k<=len;k++){
                for(int p=i;p<k;p++){
                    right=pre[k]-pre[p];
                    left=pre[p]-pre[i-1];
                    if(left==right){
                        dp[i][k]=max(dp[i][k],(max(dp[i][p],dp[p+1][k])+right));
                    }
                    else if(left>right){
                        dp[i][k]=max(dp[i][k],right+dp[p+1][k]);
                    }
                    else{
                        dp[i][k]=max(dp[i][k],left+dp[i][p]);
                    }
                }
            }
        }
        return dp[1][len];
    }
};

// class Solution {
// public:
//     int stoneGameV(vector<int>& stoneValue) {
//         int cnt=stoneValue.size();
//         //vector<vector<int>>dp(cnt,vector<int>(cnt,0));
//         int dp[cnt][cnt];
//         memset(dp,0,sizeof(dp));
//         //vector<long long>presum(cnt,0);
//         int presum[cnt];
//         memset(presum,0,sizeof(presum));
//         presum[0]=stoneValue[0];
//         for(int i=1;i<stoneValue.size();i++){
//             presum[i]=presum[i-1]+stoneValue[i];
//         }
//         for(int i=cnt-1;i>=0;i--){
//             for(int j=i+1;j<cnt;j++){
//                 for(int k=i;k<j;k++){
//                     int left=presum[k]-(i>0?presum[i-1]:0);
//                     int right=presum[j]-presum[k];
//                     if(left==right){
//                         dp[i][j]=max(dp[i][j],max(right+dp[k+1][j],left+dp[i][k]));
//                         continue;
//                     }
//                     dp[i][j]=max(dp[i][j],(left>right?right+dp[k+1][j]:left+dp[i][k]));
//                 }
//             }
//         }
//         return dp[0][cnt-1];
//     }
// };