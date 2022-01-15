class Solution {
public:
    int maxArea(vector<int>& height) {
        int len=height.size();
        int low,high;
        low=0,high=len-1;
        int ans=0;
        for(;low<high&&low<len&&high>=0;){
            ans=max(ans,(high-low)*min(height[low],height[high]));
            if(height[low]<height[high]){
                int tmp=low;
                while(low<len&&height[tmp]>=height[low])low++;
            }
            else if(height[low]>height[high]){
                int tmp=high;
                while(high>=0&&height[tmp]>=height[high])high--;
            }
            else {
                int mark_1,mark_2;
                mark_1=low;
                mark_2=high;
                while(mark_1<len-1&&height[low]>=height[mark_1])mark_1++;
                while(mark_2>=1&&height[high]>=height[mark_2])mark_2--;
                if(height[mark_1]>height[mark_2])low=mark_1;
                else high=mark_2;
            }
        }
        return ans;
    }
};