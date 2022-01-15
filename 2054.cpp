bool cmp(vector<int>a,vector<int>b){
    return a[1]<b[1];
}


class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int len=events.size();
        vector<vector<int>>copy(len,vector<int>(events[1].size(),0));
        // int copy[len+1];
        for(int i=0;i<len;i++){
            for(int k=0;k<events[1].size();k++){
                copy[i][k]=events[i][k];
            }
            // copy[i]=events[i][1];
        }
        sort(events.begin(),events.end());
        sort(copy.begin(),copy.end(),cmp);
        int maxval[len+1];
        maxval[len-1]=events[len-1][2];
        for(int i=len-2;i>=0;i++){
            maxval[i]=max(maxval[i+1],events[i][2]);
        }
        int position=0;
        int ans=0;
        for(int i=0;i<len;i++){
            while(copy[i][1]>event[position][0])position++;
            ans=max(ans,copy[i][2]+maxval[position]);
        }
        return ans;
    }
};