class Solution {
public:
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
};