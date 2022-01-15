class Solution {
public:
    unordered_map<char,int>a={{'A',0},{'C',1},{'T',2},{'G',3}};
    vector<string> findRepeatedDnaSequences(string s) {
        int i,k,b,c,len;
        c=(1<<20)-1;
        len=s.size();
        unordered_map<int,int>mark;
        b=0;
        for(i=0;i<9;i++){
            b=b<<2;
            b=b|a[s[i]];
        }
        vector<string>ans;
        for(i=10;i<len;i++){
            b=b<<2;
            b=b|a[s[i]];
            b=b&c;
            mark[b]++;
            if(mark[b]==2)ans.push_back(s.substr(i-9,10));
        }
        return ans;
        // char tmp[10];
        // vector<string>ans;
        // for(i=0;i<len-10;i++){
        //     tmp=s.substr(i,10);
        //     mark[tmp]++;
        //     if(mark[tmp]==2)ans.push_back(tmp);
        // }
        // return ans;
    }
};