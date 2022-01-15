class Solution {
public:
    bool canCross(vector<int>& stones) {
        int len=stones.size();
        // vector<int>diff(len,0);
        // for(int i=1;i<len;i++){
        //     diff[i]=stones[i]-stones[i-1];
        // }
        // int length=1;
        // for(int i=1;i<len;i++){
        //     if(diff[i]==length||diff[i]==length+1||diff[i]==length-1){
        //         length=diff[i];
        //     }
        //     else return false;
        // }
        // return true;
        int dp[len][10005];
        if(len==1)return true;
        if(stones[1]-stones[0]!=1)return false;
        int i,k,b,c;
        for(i=0;i<len;i++){
            memset(dp[i],0,sizeof(dp[i]));
        }
        dp[1][1]=1;
        for(i=2;i<len;i++){
            for(k=1;k<i;k++){
                if(k>=stones[i]-stones[k]-1){if(dp[k][stones[i]-stones[k]]==1)dp[i][stones[i]-stones[k]]=1;
                if(dp[k][stones[i]-stones[k]+1]==1)dp[i][stones[i]-stones[k]]=1;
                if(dp[k][stones[i]-stones[k]-1]==1)dp[i][stones[i]-stones[k]]=1;}
            }
        }
        for(i=0;i<10005;i++){
            if(dp[len-1][i]==1)return true;
        }
        return false;
    }
};