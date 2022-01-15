class Solution {
public:
    vector<string>all;
    set<string>jud;
    int calculate(string s) {
        long long i,k,b,c,len;
        len=s.size();
        char tmp;
        // queue<int> a;
        stack<long long> a;
            b=0,i=0;
           while((s[i]>='0'&&s[i]<='9')||s[i]==' '){
                if(s[i]!=' ')b=b*10+s[i]-'0';
                    i++;
                }
                a.push(b);
            tmp=s[i++];
        for(;i<len;i++){
            b=0;
            while((s[i]>='0'&&s[i]<='9')||s[i]==' '){
                    if(s[i]!=' ')b=b*10+s[i]-'0';
                    i++;
                    if(i>=len)break;
                }
                //stack.push(b);
            if(i<=len){
                if(tmp=='+'){
                    a.push(b);
                }
                else if(tmp=='-'){
                    a.push(-b);
                }
                else if(tmp=='*'){
                    c=a.top();
                    a.pop();
                    b=b*c;
                    a.push(b);
                }
                else if(tmp=='/'){
                    c=a.top();
                    a.pop();
                    b=c/b;
                    a.push(b);
                }
                if(i<len)tmp=s[i];
            }
        }
        for(c=0;!empty(a);){    
            c+=a.top();
            a.pop(); 
        }
        return (int)c;
    }

    string translate(string s,int position){
        int i,k,b,c;
        int len=s.size();
        if(position>=len)return "";
        else{
            if(s[position]=='0'&&position!=len-1){
                //if(!(s[position-1]=='0'&&(s[position-2]=='+'||s[position-2]=='-'||s[position-2]=='*')))all.push_back(s);
                string tmp=s;
                s.insert(position,"+");
                translate(s,position+2);
                s=tmp;
                s.insert(position,"-");
                translate(s,position+2);
                s=tmp;
                s.insert(position,"*");
                translate(s,position+2);
                s=tmp;
                //all.push_back(s);
                if(s[position-1]!='0')translate(s,position+1);
            }
            else {
                //if(s[position-1]!='0')all.push_back(s);
                string tmp=s;
                s.insert(position,"+");
                all.push_back(s);
                translate(s,position+2);
                s=tmp;
                s.insert(position,"-");
                all.push_back(s);
                translate(s,position+2);
                s=tmp;
                s.insert(position,"*");
                all.push_back(s);
                translate(s,position+2);
                s=tmp;
                if(s[position]!='0'){if(position>=2){if(!((s[position-2]=='+'||s[position-2]=='-'||s[position-2]=='*')&&s[position-1]=='0')){
                    all.push_back(s);
                    translate(s,position+1);}}
                else {
                    all.push_back(s);
                    translate(s,position+1);}
                }
                
            }
        }
        return "";
    }

    vector<string> addOperators(string num, int target) {
        int i,k,b,c;
        int len;

        len=num.size();
        translate(num,1);
        int sum=all.size();
        vector<string>ans;
        if(target==0&&num=="00"){
            ans.push_back("0*0");
            ans.push_back("0+0");
            ans.push_back("0-0");
            return ans;
        }
        //return all;
        for(i=0;i<sum;i++){
            if(calculate(all[i])==target)ans.push_back(all[i]);
        }
        for(i=0;i<ans.size();i++){
            jud.insert(ans[i]);
        }
        ans.clear();
        for(set<string>::iterator h=jud.begin();h!=jud.end();h++){
            ans.push_back(*h);
        }
        return ans;
    }
};