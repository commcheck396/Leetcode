class Solution {
public:
    bool cmp(string &a,string &b){
        int i,k,b,c,lena,lenb;
        lena=a.size();
        lenb=b.size();
        if(lena!=lenb){
            return lena>lenb;
        }
        else {
            for(i=0;i<lena;i++){
                if(a[i]!=b[i]){
                    return a[i]<b[i];
                }
                else continue;
            }
        }
        return 1;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        int i,k,b,c,lens,len;
        len=s.size;
        lens=dictionar.size();
        std::sort(dictionary.begin(),dictionary.end(),cmp);
        for(i=0;i<lens;i++){
            int lenc=dictionary[i].size();
            b=0;
            c=0;
            for(;b<len;){
                if(s[b]==dictionary[i][c]){
                    b++;
                    c++;
                }
                else {
                    b++;
                }
                if(c==lenc){
                    return dictionary[i];
                }
            }
        }
        return "";
    }
};