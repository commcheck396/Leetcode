// bool cmp(pair<int,int>a,pair<int,int>b){
//     float n1=((a.first*1.0)/(a.second*1.0));
//     float n2=((b.first*1.0)/(b.second*1.0));
//     if(n1>n2)return 0;
//     else return 1;
//     // if(((a.first+1.0-1.0)/(a.second+1,0-1.0))>((b.first+1.0-1.0)/(b.second+1,0-1.0)))return 1;
//     // else return 0;
// }
// class Solution {
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int K) {
//         vector<pair<int,int>>mark;
//         for(int i=0;i<arr.size();i++){
//             for(int k=i+1;k<arr.size();k++){
//                 // mark.push_back((arr[i]+1.0-1.0)/(arr[k]+1.0-1.0));
//                 mark.push_back({arr[i],arr[k]});
//             }
//         }
//         sort(mark.begin(),mark.end(),cmp);
//         vector<int>ans;
//         ans.push_back(mark[K].first);
//         ans.push_back(mark[K].second);
//         // for(int i=0;i<arr.size();i++){
//         // ans.push_back(mark[i].first);
//         // ans.push_back(mark[i].second);
//         // ans.push_back(0);
//         // }
//         // for(auto i:mark){
//         //     ans.push_back(i.first);
//         //     ans.push_back(i.second);
//         //     ans.push_back(0);
//         // }
//         return ans;
//     }
// };