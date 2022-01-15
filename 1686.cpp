bool cmp(pair(int,int) a,pair(int,int) b){
    return a->first>b->first;
}
class Solution {
public:
    int stoneGameVI(vector<int>& valuea, vector<int>& valueb) {
        int len=valuea.size();
        vector<pair(int,int)>mark;
        for(int i=0;i<len;i++){
            mark.push_back({valuea[i]+valueb[i],i})
        }
        sort(mark.begin(),mark.end(),cmp);
        int alice=0,bob=0;
        for(auto i=mark.rbegin();;){
            if(i!=mark.rend()){
                alice+=valuea[i->second];
                i++;
            }
            if(i!=mark.rend()){
                bob+=valueb[i->second];
                i++;
            }
            if(i==mark.rend()){
                break;
            }
        }
        if(alice>bob)return 1;
        else if(alice==bob)return 0;
        else return -1;
    }
};