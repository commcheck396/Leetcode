class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i,k,b,c;
        int len=s.size();
        int mark[27];
        memset(mark,0,sizeof(mark));
        int low,up,max_=0;
        for(low=0,up=0;up<len;){
            for(;;){
                if(mark[s[up]-'a'+1]==0){
                    mark[s[up]-'a'+1]++;
                    max_=max(max_,up-low+1);
                    up++;
                    break;
                }
                else {
                    mark[s[low]-'a'+1]--;
                    low++;
                }
            }
        }
        return max_;
    }
};