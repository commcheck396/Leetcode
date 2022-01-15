class Solution {
public:
    int balancedStringSplit(string s) {
        int i,k,b,c,len,ans=0;
        len=s.size();
        for(i=0;i<len;i++){
            b=0;
            c=0;
            for(;i<len;i++){
                if(s[i]=='L')b++;
                else c++;
                if(b==c){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};