class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int>mark;
        mark.push_back(triangle[0][0]);
        for(int i=1;i<triangle.size();i++){
            vector<int>tmp;
            tmp.push_back(mark[0]+triangle[i][0]);
            for(int k=1;k<triangle[i].size()-1;k++){
                tmp.push_back(min(mark[k-1],mark[k])+triangle[i][k]);
            }
            tmp.push_back(mark[mark.size()-1]+triangle[i][triangle[i].size()-1]);
            mark=tmp;
        }
        int min_=INT_MAX;
        for(auto i:mark){
            min_=min(min_,i);
        }
        return min_;
    }
};