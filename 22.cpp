class Solution {
public:
    vector<set<string>>mark;
    vector<string>ans;
    set<string>tmp;
    vector<string> generateParenthesis(int n) {
        tmp.insert("()");
        mark.push_back(tmp);
        for(int i=2;i<=n;i++){
            tmp.clear();
            for(int k=1;k<i;k++){
                for(auto a:mark[k]){
                    for(auto b:mark[i-k]){
                        tmp.insert(a+b);
                    }
                }
            }
        }
        for(auto a:mark[n]){
            ans.push_back(a);
        }
        return ans;
    }
};  