class Solution {
    int a[20];
    string one[10]= {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string ten[10]= {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string tens[10]= {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string mark[4]= {"", "Thousand", "Million", "Billion"};
public:
    string translate(int a){
        int i,k,b,c;
        string tmp;
        if(a==0)return "";
        if(a/100){
            tmp+=one[a/100];
            tmp+=" Hundred";
            if(a%100!=0)tmp+=" ";
            a%=100;
        }
        if(a>=10&&a<20){
            tmp+=tens[a%10];
        }
        else{
            if(a>=20){
                tmp+=ten[a/10];
                if(a%10!=0)tmp+=" ";
                a%=10;
                tmp+=one[a];
            }
            else {
                tmp+=one[a];
            }
        }
        return tmp;
    }

    string numberToWords(int num) {
        int i,k,b,c,len;
        if(num==0)return "Zero";
        string ans;
        for(i=0;;i++){
            a[i]=num%1000;
            num/=1000;
            if(num==0)break;
        }
        len=i;
        int times;
        times=len%3;
        for(i=len;i>0;times--,i--){
            if(times==0)times=3;
            //if(a[i]==0)continue;
            ans+=translate(a[i]);
            if(a[i]!=0){ans+=" ";
            ans+=mark[times];}
            if(a[i-1]!=0)ans+=" ";
        }
        ans+=translate(a[i]);
        return ans;
    }
};