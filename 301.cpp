class Solution {
public:
    int dell,delr,numl,numr,num,len;
    set<string>mark;
    vector<string>ans;
    int dfs(string cur,int l,int r,string s,int position,int dl,int dr){
        // for(int i=position;i<len;i++){

        // }
        // if(position==len-1&&dl==dell&&dr==delr)mark.insert(cur);
        if(position==len-1&&dl==dell&&dr==delr)ans.push_back(cur);
        string tmp=cur;
        if(s[position]=='('){
            if(l<numl){tmp.push_back('(');dfs(tmp,l+1,r,s,position+1,dl,dr);}
            tmp=cur;
            if(dl<dell)dfs(tmp,l,r,s,position+1,dl+1,dr);
        }

        else if(s[position]==')'){
            if(r<numr&&r<l){tmp.push_back(')');dfs(tmp,l,r+1,s,position+1,dl,dr);}
            tmp=cur;
            if(dl<dell)dfs(tmp,l,r,s,position+1,dl,dr+1);
        }
        
        else {tmp=cur;tmp.push_back(s[position]);dfs(tmp,l,r,s,position+1,dl,dr);}

        return 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        numl=0,numr=0;
        len=s.size();
        numl-=dell;
        numr-=delr;
        for(auto c:s){
            if(c=='('){
                dell++;
                numl++;
                }
            else if(c==')'){
                numr++;
                if(dell)dell--;
                else delr++;
            }
        }
        num=max(numl,numr);
        dfs("",0,0,s,0,0,0);
        for(auto c:mark){
            ans.push_back(c);
        }
        return ans;
    }
};