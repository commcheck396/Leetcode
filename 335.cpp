class Solution {
public:
    bool connected(vector<int>a,vector<int>b){
        if(a[0]==a[2]){
            if((b[1]-a[1])*(b[1]-a[3])<=0&&((a[0]-b[0])*(a[0]-b[2])<=0))return true;
            else return false;
        }
        else {
            if((a[1]-b[1])*(a[1]-b[3])<=0&&((b[0]-a[0])*(b[0]-a[2])<=0))return true;
            else return false;
        }
        return false;
    }
    bool connected_(vector<int>a,vector<int>b){
        if(a[1]==a[3]){
            if(((a[0]-b[0])*(a[0]-b[2])<=0)||((a[0]-b[2])*(a[2]-b[2])<=0))return true;
            else return false;
        }
        else {
            if(((a[1]-b[3])*(a[1]-b[1])<=0)||((a[3]-b[1])*(a[3]-b[3])<=0))return true;
            else return false;
        }
        return false;
    }
    bool isSelfCrossing(vector<int>& distance) {
        int x=0,y=0;
        vector<vector<int>>mark;
        vector<int>tmp;
        // if(distance[1]==0||distance[2]==0||distance[0]==0||distance[3]==0)return true;
        int len=distance.size();
        for(int i=0;i<len;i++){
            tmp.clear();
            tmp.push_back(x);
            tmp.push_back(y);
            if((i+1)/4==1){
                tmp.push_back(x);
                tmp.push_back(y+distance[i]);
                y+=distance[i];
            }
            else if((i+1)/4==2){
                tmp.push_back(x-distance[i]);
                tmp.push_back(y);
                x-=distance[2];
            }
            else if((i+1)/4==3){
                tmp.push_back(x);
                tmp.push_back(y-distance[i]);
                y-=distance[i];
            }
            else {
                tmp.push_back(x+distance[i]);
                tmp.push_back(y);
                x+=distance[i];
            }
            mark.push_back(tmp);
            if(mark.size()>10)mark.erase(mark.begin());
            if(i>=3){
                if(mark.size()>=6)if(connected(mark[mark.size()-1],mark[mark.size()-4])||connected_(mark[mark.size()-1],mark[mark.size()-5])||connected(mark[mark.size()-1],mark[mark.size()-6]))return true;
                else if(mark.size()>=5)if(connected(mark[mark.size()-1],mark[mark.size()-4])||connected_(mark[mark.size()-1],mark[mark.size()-5]))return true;
                else {
                    if(connected(mark[mark.size()-1],mark[mark.size()-4]))return true;
                }
            }
        }
        return false;
    }
};