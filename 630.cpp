// int dp[10005];
// int mark[10005][3];
// class Solution {
// public:
//     int search(int position){
//         if(mark[position]!=0){
//             dp[position+mark[position][0]]=max(dp[position+mark[position][0]],dp[position]+1);
//         }
//         else {
//             dp[position+mark[mark[posi]]]
//         }
//     }

//     int scheduleCourse(vector<vector<int>>& courses) {

//         memset(mark,0,sizeof(mark));
//         int i;
//         int tmp,sum=0;
//         for(i=0;i<courses.size();i++){
//             tmp=courses[i][1]-courses[i][0];
//             if(tmp<0)continue;
//             else {
//                 if(mark[tmp][0]!=0){
//                     if(mark[tmp][0]>courses[i][0]){
//                         mark[tmp][0]=courses[i][0];
//                     }
//                     else continue;
//                 }
//                 else{
//                     mark[tmp][0]=courses[i][0];
//                 }
//                 sum++;
//             }
//         }
//         int fast=0,slow=0;
//         for(;fast<10005;fast++){
//             if(mark[fast][0]!=0){
//                 while(mark[slow][0]!=0)slow++;
//                 for(;slow<fast;slow++){
//                     mark[slow][1]=fast;
//                 }
//             }
//             else continue;
//         }
//         // for(int i=0;i<10005;i++){

//         // }
//         // sort(mark.begin(),mark.begin()+)

//     }
// };

bool cmp(vector<int>a,vector<int>b){
    return a[1]<b[1];
}
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int>mark;
        sort(courses.begin(),courses.end(),cmp);
        int sum=0;
        for(auto c:courses){
            if(sum+c[0]<=c[1]){
                mark.push(c[0]);
                sum+=c[0];
            }
            else if(!mark.empty()){
                if(mark.top()>c[0]){
                    sum-=mark.top();
                    mark.push(c[0]);
                    mark.pop();
                    sum+=c[0];
                }
            }
        }
        return mark.size();
    }
};