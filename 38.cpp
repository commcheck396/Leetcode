class Solution {
public:
    string cal(string s){
        int i,k,b,c;
        int len=s.size();
        char tmp;
        tmp=s[0];
        k=1;
        string haha;
        char c;
        for(i=1;i<len;i++){
            if(s[i]==tmp){
                k++;
            }
            else {
                c=k+'0';
                haha.push_back(c);
                haha.push_back(tmp);
                tmp=s[i];
                k=1;
            }
        }
        {
            c=k+'0';
            haha.push_back(c);
            haha.push_back(tmp);
        }
        return haha;
    }
    string countAndSay(int n) {
        int i,k,b,c;
        string s="1",p;
        for(i=1;i<n;i++){
            p=cal(s);
            s=p;
        }
        return s;
    }
};