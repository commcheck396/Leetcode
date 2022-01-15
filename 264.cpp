// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         unordered_map<int,int>mark;
//         // mark[1]=0;
//         mark[1]=1;
//         int sum=1;
//         for(int i=0;sum<n;i++){
//             if(i%2==0){
//                 if(mark[i/2]){mark[i]=1;
//                 sum++;
//                 if(sum==n)return i;
//                 continue;}
//             }
//             if(i%3==0){
//                 if(mark[i/3]){mark[i]=1;
//                 sum++;
//                 if(sum==n)return i;
//                 continue;}
//             }
//             if(i%5==0){
//                 if(mark[i/5]){mark[i]=1;
//                 sum++;
//                 if(sum==n)return i;
//                 continue;}
//             }
//             if(sum==n)return i;
//         }
//         return 1;
//     }
// };

class Solution {
public:
    int nthUglyNumber(int n) {
        set<int>mark;
        mark.insert(1);
        int time=1;
        for(auto i=mark.begin();i!=mark.end()&&time<n;i++){
            mark.insert(*i*2);
            mark.insert(*i*3);
            mark.insert(*i*5);
            time++;
            mark.erase(mark.begin());
            // if(mark.size()>=n)break;
        }
        // int position=0;
        // for(auto i=mark.begin();i!=mark.end();i++){
        //     position++;
        //     if(position==n)return *i;
        // }
        return *mark.begin();
    }
};