class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int len;
        int div=10;
        vector<string>mark;
        string tmp;
        for(i=0;i<30;i++){
            tmp=to_string(pow(2,i));
            sort(tmp.begin(),tmp.end());
            mark.push_back(tmp);
        }
        string num=to_string(n);
        sort(num.begin(),num.end());
        for(int i=0;i<30;i++){
            if(mark[i]==num)return true;
        }
        return false;
    }
};