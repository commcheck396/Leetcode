class Solution {
public:
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
                if(!a.empty())b=0;
                else b=a.top();
                ans=max(ans,tmp*(i-b-1));
            }
            a.push(i);
        }
        while(!a.empty()){
                int tmp=heights[a.top()];
                a.pop();
                if(!a.empty())b=0;
                else b=a.top();
                ans=max(ans,tmp*(i-b-1));
            }
        return ans;
    }
};