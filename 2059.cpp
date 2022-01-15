// class Solution {
//     struct node {
//         int x, step;                //x是数据值, step代表操作次数
//     };
// public:
//     int minimumOperations(vector<int>& nums, int start, int goal) {
//         bool visited[1005] = {0};                     //标记数组,标记nums走过
//         queue<node> q;
//         q.push(node{start, 0});
//         visited[start] = 1;
//         if (start == goal) return 0;
//         while (!q.empty()) {
//             node cur = q.front();
//             q.pop();
//             for (int i = 0; i < nums.size(); ++i) {
//                 int x1 = cur.x + nums[i], x2 = cur.x - nums[i], x3 = cur.x ^ nums[i];
//                 if (!(x1 < 0 || x1 > 1000 || visited[x1])) {
//                     visited[x1] = 1;
//                     q.push(node{x1, cur.step + 1});
//                 }
//                 if (!(x2 < 0 || x2 > 1000 || visited[x2])) {
//                     visited[x2] = 1;
//                     q.push(node{x2, cur.step + 1});
//                 }
//                 if (!(x3 < 0 || x3 > 1000 || visited[x3])) {
//                     visited[x3] = 1;
//                     q.push(node{x3, cur.step + 1});
//                 }
//                 if (x1 == goal || x2 == goal || x3 == goal) return cur.step + 1;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<pair<int,int>>mark;
        int vis[1005]={0};
        mark.push({start,0});
        vis[start]=1;
        for(;!mark.empty();){
            auto tmp=mark.front();
            mark.pop();
            for(auto c:nums){
                int x1=tmp.first+c,x2=tmp.first-c,x3=tmp.first^c;
                if(x1>=0&&x1<=1000&&vis[x1]==0){
                    mark.push({x1,tmp.second+1});
                    vis[x1]=1;
                    if(x1==goal)return tmp.second+1;
                }
                if(x2>=0&&x2<=1000&&vis[x2]==0){
                    mark.push({x2,tmp.second+1});
                    vis[x2]=1;
                    if(x2==goal)return tmp.second+1;
                }
                if(x3>=0&&x3<=1000&&vis[x3]==0){
                    mark.push({x3,tmp.second+1});
                    vis[x3]=1;
                    if(x3==goal)return tmp.second+1;
                }
            }
        } 
        return -1;     
    }
};