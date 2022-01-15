// class Solution {
// public:
//     int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
//         int len=start.size();
//         vector<vector<int>>sp(len,vector<int>(2,0));
//         vector<vector<int>>ep(len,vector<int>(2,0));
//         for(int i=0;i<len;i++){
//             sp[i][0]=start[i];
//             sp[i][1]=profit[i];
//             ep[i][0]=end[i];
//             ep[i][1]=profit[i];
//         }
//         sort(sp.begin(),sp.end());
//         sort(ep.begin(),ep.end());
//         int maxval[len+1];
//         maxval[len-1]=sp[len-1][1];
//         for(int i=len-2;i>=0;i--){
//             maxval[i]=max(maxval[i+1],sp[i][1]);
//         }
//         int ans=0;
//         vector<int>tmp(2,0);
//         tmp[0]=ep[0][0]+1;
//         int position=upper_bound(sp.begin(),sp.end(),tmp)-sp.begin();
//         if(position>=len)return maxval[0];
//         for(int i=0;i<len;i++){
//             while(ep[i]>=sp[position]){
//                 position++;
//                 if(position>=len)return max(ans,maxval[0]);
//             }
//             ans=max(ans,ep[i][1]+maxval[position]);
//         }
//         return max(ans,maxval[0]);
//     }
// };
bool cmp(vector<int>a,vector<int>b){
    return a[1]<b[1];
}

class Solution {
public:
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        int len=start.size();
        vector<vector<int>>dp;
        for(int i=0;i<len;i++){
            vector<int>tmp;
            tmp.push_back(start[i]);
            tmp.push_back(end[i]);
            tmp.push_back(profit[i]);
            dp.push_back(tmp);
        }
        sort(dp.begin(),dp.end(),cmp);
        int a[len+1];
        memset(a,0,sizeof(a));
        for(int i=1;i<=len;i++){
            int position=0;
            for(int k=i-1;k>=0;k--){
                if(dp[i-1][0]>dp[k][1]){
                    position=k+1;
                    break;
                    }
            }
            a[i]=max(a[i-1],a[position]+a[i][2]);
        }
        return a[len];
    }
};