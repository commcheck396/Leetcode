class Solution {
public:
    bool detectCapitalUse(string word) {
        int len=word.size();
        if(len==1)return true;
        bool flag=true;
        for(int i=1;i<len-1;i++){
            if(!((word[i]>='a')^(word[i+1]>='a')))return false;
        }
        if(word[1]>='A'&&word[1]<='Z')flag=false;
        if(word[0]>='a'&&word[0]<='z'&&flag==false)return false;
        return true;
    }
};