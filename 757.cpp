// class Solution {
// public:
//     int intersectionSizeTwo(vector<vector<int>>& intervals) {
//         int i,k,b,c,len;
//         len=intervals.size();
//         int mark[100005];
//         memset(mark,0,sizeof(mark));
//         for(i=0;i<len;i++){
//             for(k=0;k<intervals[i].size;k++){
//                 mark[intervals[i][k]]++;
//             }
//         }
//         int min,max;
//         for(i=0;i<10005;i++){
//             if(mark[i]==len){
//                 min=i;
//                 break;
//             }
//         }
//         for(;i<10005;i++){
//             if(mark[i]==len)max=i;
//         }
//         return max-min+1;
//     }
// };

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int i,k,b,c,len;
        len=intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] != b[0] ? a[0] < b[0] : b[1] < a[1];
        });
        vector<int>mark(len,2);
        int ans=0;
        for(i=len-1;i>=0;i--){
            int start=intervals[i][0];
            for(k=start;k<start+mark[k];k++){
                for(b=0;b<len;b++){
                    if(mark[b]&&intervals[b][1]>=k){
                        mark[b]--;
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};