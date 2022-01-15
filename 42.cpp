class Solution {
public:
    int trap(vector<int>& heights) {
        int i,k,b,c,len;
        len=heights.size();
        stack<int>a;
        int ans=0;
        for(i=0;i<len;i++){
            if(heights[i]==0)continue;
            else break;
        }
        a.push(i);
        for(i++;i<len;i++){
            while(!a.empty()&&heights[i]>heights[a.top()]){
                int tmp=heights[a.top()];
                a.pop();
                if(a.empty())continue;
                ans+=(min(heights[i],heights[a.top()])-tmp)*(i-a.top()-1);
            }
            a.push(i);
        }
        // while(!a.empty()){
        //         int tmp=heights[a.top()];
        //         a.pop();
        //         if(a.empty())continue;
        //         ans+=(min(heights[i],heights[a.top()])-tmp)*(i-a.top()-1);
        //     }
        return ans;
    }
};