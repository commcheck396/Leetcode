class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lens=s.size();
        int lenp=p.size();
        vector<int>mark1(26,0);
        vector<int>mark2(26,0);
        for(int i=0;i<lenp;i++){
            mark2[p[i]-'a']++;
        }
        for(int i=0;i<lenp;i++){
            mark1[s[i]-'a']++;
        }
        vector<int>ans;
        int flag=1;
        for(int k=0;k<26;k++){
            if(mark1[k]!=mark2[k]){
                flag=0;
                break;
            }
            else continue;
        }
        if(flag)ans.push_back(0);
        for(int i=lenp;i<lens;i++){
            mark1[s[i-lenp]-'a']--;
            mark1[s[i]-'a']++;
            flag=1;
            for(int k=0;k<26;k++){
                if(mark1[k]!=mark2[k]){
                    flag=0;
                    break;
                }
                else continue;
            }
            if(flag)ans.push_back(i-lenp+1);
        }
        return ans;
    }
};