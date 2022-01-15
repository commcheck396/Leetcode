class Solution {
public:
    string shortestCompletingWord(string li, vector<string>& words) {
        int mark[26];
        int tmp_mark[26];
        vector<pair<int,int>>satisfied;
        memset(mark,0,sizeof(mark));
        for(auto c:li){
            if(c>='A'&&c<='Z')mark[c-'A']++;
            else if(c>='a'&&c<='z')mark[c-'a']++;
            else continue;
        }
        for(int k=0;k<words.size();k++){
            memset(tmp_mark,0,sizeof(tmp_mark));
            for(auto c:words[k]){
                if(c>='A'&&c<='Z')tmp_mark[c-'A']++;
                else if(c>='a'&&c<='z')tmp_mark[c-'a']++;
                else continue;
            }
            int flag=1;
            for(int i=0;i<26;i++){
                if(mark[i]<=tmp_mark[i])continue;
                else {
                    flag=0;
                    break;
                }
            }
            if(flag)satisfied.push_back({words[k].size(),k});
        }
        sort(satisfied.begin(),satisfied.end());
        return words[satisfied[0].second];
    }
};