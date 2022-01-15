class Solution {
        string line1="qwertyuiopQWERTYUIOP";
        string line2="asdfghjklASDFGHJKL";
        string line3="zxcvbnmZXCVBNM";
public:
    bool judge(string s){

    }
    vector<string> findWords(vector<string>& words) {
        // sort(line1.begin(),line1.end());
        // sort(line2.begin(),line2.end());
        // sort(line3.begin(),line3.end());
        unordered_map<char,int>mark;
        for(auto c:line1){
            mark[c]=1;
        }
        for(auto c:line2){
            mark[c]=2;
        }
        for(auto c:line2){
            mark[c]=2;
        }
        vector<string>ans;
        int flag=1;
        for(auto s:words){
            flag=1;
            int tmp=mark[s[0]];
            for(auto c:s){
                if(tmp==mark[c])continue;
                else {
                    flag=0;
                    break;
                }
            }
            if(flag){
                ans.push_back(s);
            }
        }
        return ans;
    }
};