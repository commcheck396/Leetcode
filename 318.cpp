int len;
bool cmp(string a,string b){
    return a.size()>b.size();
}
class Solution {
public:
    void translate(vector<string> words,vector<int> &mark){
        for(int i=0;i<len;i++){
            int tmp=0;
            for(auto c:words[i]){
                tmp=tmp|(1<<(c-'a'));
            }
            mark[i]=tmp;
        }
    }
    int maxProduct(vector<string>& words) {
        //sort(words.begin(),words.end(),cmp);
        len=words.size();
        vector<int> mark(len+1,0);
        translate(words,mark);
        int i,k;
        int max_=0;
        for(i=1;i<len;i++){
            for(k=0;k<i;k++){
                if((mark[i]&mark[k])==0)max_=max_>(words[i].size()*words[k].size())?max_:(words[i].size()*words[k].size());
            }
        }
        return max_;
    }
};
