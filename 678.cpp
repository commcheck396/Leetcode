class Solution {
public:
    bool checkValidString(string s) {
        int i,k,b,c,len,sum1,sum2,sum3;
        len=s.size();
        for(i=0,sum1=0,sum2=0,sum3=0;i<len;i++){
            if(s[i]=='(')sum1++;
            else if(s[i]=='*')sum3++;
            else {
                sum1--;
                if(sum1<0){
                    sum1++;
                    sum3--;
                    if(sum3<0)return false;
                }
            }
        }
        if(sum1>sum3)return false;
        
        for(i=len-1,sum1=0,sum2=0,sum3=0;i>=0;i--){
            if(s[i]==')')sum1++;
            else if(s[i]=='*')sum3++;
            else {
                sum1--;
                if(sum1<0){
                    sum1++;
                    sum3--;
                    if(sum3<0)return false;
                }
            }
        }
        if(sum1>sum3)return false;
        else return true;
    }
};