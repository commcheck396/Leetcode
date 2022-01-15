class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minc=10000;
        int minr=10000;
        for(int i=0;i<ops.size();i++){
            minc=min(minc,ops[i][0]);
            minr=min(minr,ops[i][1]);
        }
        return minc*minr;
    }
};