class Solution {
public:
    vector<int> constructRectangle(int area) {
        int len=sqrt(area);
        vector<int>ans;
        for(;len>0;len--){
            if(area%len==0){
                ans.push_back(area/len);
                ans.push_back(len);
                break;
            }
        }
        return ans;
    }
};