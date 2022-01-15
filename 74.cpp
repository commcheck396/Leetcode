class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(),col=matrix[0].size();
        int up;
        for(int i=0;i<row;i++){
            if(matrix[i][0]<target)continue;
            else if(matrix[i][0]==target)return true;
            else up=i,break;
        }
        for(int i=0;i<col;i++){
            if(matrix[up][i]==target)return true;
        }
        return false;
    }
};