class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle_, vector<int>& location) {
        double pi=3.1415926535;
        double angle=angle_/180.0*pi;
        vector<double>mark;
        int X=location[0];
        int Y=location[1];
        int sum=0;
        for(int i=0;i<points.size();i++){
            int x,y;
            x=points[i][0]-X;
            y=points[i][1]-Y;
            if(x==y&&x==0){
                sum++;
                continue;
            }
            double arc=atan2(y,x);
            mark.push_back(arc);
        }
        sort(mark.begin(),mark.end());
        int len=mark.size();
        for(int i=0;i<len;i++){
            mark.push_back(mark[i]+pi*2);
        }
        int ans=0;
        int slow;
        int fast;
        for(slow=0,fast=0;fast<mark.size()&&slow<mark.size();){
            // if(!(fast<mark.size()&&slow<mark.size()))break;
            while(mark[fast]-mark[slow]<=angle&&fast<mark.size())fast++;
            fast--;
            ans=max(ans,(fast-slow+1));
            slow++;
            if(fast==mark.size()-1)break;
        }
        return ans+sum;
    }
};