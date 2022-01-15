class Solution {
public:
    int minSteps(string s, string t) {
        int i,k,b,c,len;
        len=s.length();
        int mark1[27];
        int mark2[27];
        int diff[27];
        memset(mark1,0,sizeof(mark1));
        memset(mark2,0,sizeof(mark2));
        for(i=0;i<len;i++){
            mark1[s[i]-'a']++;
        }
        for(i=0;i<len;i++){
            mark2[t[i]-'a']++;
        }
        for(i=0;i<27;i++){
            ans+=(mark1[i]-mark2[i])>0?(mark1[i]-mark2[i]):0;
        }

    return ans;
    }
};