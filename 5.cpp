// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int i,k,b,c,len,mark,max;
//         len=s.size();
//         if(len==0||len==1)return s;
//         vector<vector<int>> dp(len,vector<int>(len));
//         mark=0;
//         max=1;
//         for(i=0;i<len;i++){
//             dp[i][i]=1;
//             if(s[i]==s[i+1])dp[i][i+1]=1,mark=i,max=2;
//         }
//         for(i=2;i<len;i++){
//             for(k=0;k<len-i;k++){
//                 if(s[k]==s[k+i]&&dp[k+1][k+i-1]){
//                     dp[k][k+i]=1;
//                     max=i+1;
//                     mark=k;
//                 }
//             }
//         }
//         return s.substr(mark,max);
//     }
// };
//dp


class Solution {
public:
    string longestPalindrome(string s) {
        int i,k,b,c,len;
        len=s.size();
        int low,up,max_=0,mark;
        for(i=0;i<len;i++){
            for(low=i,up=i;low>=0&&up<len;low--,up++){
                if(s[low]==s[up]){
                    if(max_<up-low+1){
                        mark=low;
                        max_=up-low+1;
                    }
                }
                else break;
            }
            for(low=i-1,up=i;low>=0&&up<len;low--,up++){
                if(s[low]==s[up]){
                    if(max_<up-low+1){
                        mark=low;
                        max_=up-low+1;
                    }
                }
                else break;
            }
        }
        return s.substr(mark,max_);
    }
};