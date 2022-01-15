class Solution {
public:
    int countSegments(string s) {
        int i,k,b,c;
        int len=s.size();
        if(len==0)return 0;
        char tmp=s[0];
        b=0;
        if(s[0]!=' ')b++;
        for(i=1;i<len;i++){
            if(s[i]!=' '&&tmp==' ')b++;
            tmp=s[i];
        }
        return b;
    }
};