class Solution {
public:
    int maxPower(string s) {
        int ans=0;
        int tmp=0;
        char last=s[0];
        for(auto c:s){
            if(last==c)tmp++;
            else {
                ans=max(ans,tmp);
                last=c;
            }
        }
        ans=max(tmp,ans);
        return ans;
    }
};