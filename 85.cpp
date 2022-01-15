class Solution {
public:
    int row,col;
    int largestRectangleArea(vector<int>& heights) {
        int i,k,b,c,len;
        len=heights.size();
        stack<int>a;
        int ans=0;
        a.push(0);
        for(i=1;i<len;i++){
            if(!a.empty())while(!a.empty()&&heights[i]<heights[a.top()]){
                int tmp=heights[a.top()];
                a.pop();
                if(a.empty())b=-1;
                else b=a.top();
                ans=max(ans,tmp*(i-b-1));
            }
            a.push(i);
        }
        while(!a.empty()){
                int tmp=heights[a.top()];
                a.pop();
                if(a.empty())b=-1;
                else b=a.top();
                ans=max(ans,tmp*(len-b-1));
            }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int i,k,b,c;
        row=matrix.size();
        col=matrix[0].size();
        vector<int>heights(col,0);
        int ans=0;
        for(i=0;i<row;i++){
            for(k=0;k<col;k++){
                if(matrix[i][k]=='0'){
                    heights[k]=0;
                }
                else heights[k]++;
            }
            ans=max(ans,largestRectangleArea(heights));
        }
        return ans;
    }
};