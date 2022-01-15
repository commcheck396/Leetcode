// // class Solution {
// // public:
// //     bool isPossible(vector<int>& nums) {
// //         int i,k,b,c,len;
// //         len=nums.size();
// //         b=nums[0];
// //         for(i=1,c=1;i<len;i++){
// //             if(nums[i]==b)continue;
// //             else if(nums[i]==b+1){
// //                 c++;
// //                 b++;
// //                 if(c==3)return true;
// //                 continue;
// //             }
// //             else {
// //                 b=nums[i];
// //                 c=1;
// //                 continue;
// //             }
// //         }
// //         return false;
// //     }
// // };

// class Solution {
// public:
//     bool isPossible(vector<int>& nums) {
//         int i,k,b,c,len,sum;
//         len=nums.size();
//         int a[100005];
//         memset(a,0,sizeof(a));
//         for(i=0;i<len;i++){
//             a[nums[i]]++;
//         }
//         b=a[100004];
//         for(i=100004;i>=0;i--){
//             if(a[i]==0)continue;
//             else break;
//         }
//         b=a[i];
//         sum=1;
//         for(i--;i>=0;i--){
//             if(b==a[i]){
//                 sum++;
//                 continue;
//             }
//             else if(b!=a[i]){
//                 if(sum>=3){
//                     b=a[i];
//                     sum=1;
//                     continue;
//                 }
//                 else {
//                     if(b==0){
//                         b=a[i];
//                         continue;
//                     }
//                     else return false;
//                 }
//             }
//         }
//         return true;
//     }  
// };

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        int dp1 = 0, dp2 = 0, dp3 = 0;
        int i = 0;

        while (i < n) {
            int start = i;
            int x = nums[i];
            while (i < n && nums[i] == x) {
                i++;
            }
            int cnt = i - start;

            if (start > 0 && x != nums[start - 1] + 1) {
                if (dp1 + dp2 > 0) {
                    return false;
                } else {
                    dp1 = cnt;
                    dp2 = dp3 = 0;
                }
            } else {
                if (dp1 + dp2 > cnt) return false;
                int left = cnt - dp1 - dp2;
                int keep = min(dp3, left);
                dp3 = keep + dp2; 
                dp2 = dp1;
                dp1 = left - keep;
            }
        }
        return dp1 == 0 && dp2 == 0;
    }
};
