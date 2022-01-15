    class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            // set<char>mark;
            // for(auto c:magazine){
            //     mark.insert(c);
            // }
            // for(auto c:ransomNote){
            //     if(mark.find(c)!=mark.end())continue;
            //     else {
            //         return false;
            //     }
            // }
            // return true;
            unordered_map(char,int)mark;
            for(auto c:magazine){
                mark[c]++;

            }
        for(auto c:ransomNote){
            if(mark[c]==0)return false;
            else{
                mark[c]--;
                continue;
            }
        }
        return true;
        }
    };