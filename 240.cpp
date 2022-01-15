class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int up=0,down=row-1,left=0,right=col-1;
        int flag=1;
        for(int i=0;i<row;i++){
            if(matrix[i][col-1]<target)continue;
            else if(matrix[i][col-1]==target)return true;
            else {
                up=i;
                flag=0;
                break;
            }
        } 
        if(flag)return false;
        flag=1;
        for(int i=row-1;i>up;i--){
            if(matrix[i][0]>target)continue;
            else if(matrix[i][0]==target)return true;
            else {
                down=i;
                flag=0;
                break;
            }
        } 
        if(flag)return false;
        flag=1;
        for(int i=0;i<col;i++){
            if(matrix[i][down]<target)continue;
            else if(matrix[i][down]==target)return true;
            else {
                left=i;
                flag=0;
                break;
            }
        } 
        if(flag)return false;
        flag=1;
        for(int i=col-1;i>left;i--){
            if(matrix[i][up]>target)continue;
            else if(matrix[i][up]==target)return true;
            else {
                right=i;
                flag=0;
                break;
            }
        }   
        if(flag)return false; 
        for(int i=up;i<=down;i++){
            for(int k=left;k<=right;k++){
                if(matrix[i][k]==target)return true;
            }
        }
        return false;
    }
};