class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int group) {
        if(hand.size()%group!=0)return false;
        // hand.sort();
        unordered_map<int,int>mark;
        set<int>a;
        for(auto i:hand){
            mark[i]++;
            a.insert(i);
        }
        for(auto i=a.begin();i!=a.end();i++){
            int num=*i;
            if(mark[num]==0)continue;
            int times=mark[num];
            for(int k=0;k<group;k++){
                if(mark[num+k]<times)return false;
                else {
                    mark[num+k]-=times;
                }
            }
        }
        return true;
    }
};