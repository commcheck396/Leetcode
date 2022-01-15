class Solution {
public:
    // int cal(long &x,int d){
    //     int i,k,b,c;
    //     for(i=1;;i++){
    //         if(x>(int)pow(d,i))continue;
    //         else break;
    //     }
    //     if(x>(int)pow(d,i-1))x-=(int)pow(d,i-1);
    //     // i=(int)pow(x,d);
    //     if(i>=2)return (int)pow(d,i-2);
    //     else return 0;
    // }
    long cal(long &x,long d){
        int i,k,b,c;
        if(x==d){
            x=0;
            return 1;
        }
        for(i=1;;i++){
            if(x>(long)pow(d,i))continue;
            else break;
        }
        if(x>(long)pow(d,i-1))x-=(long)pow(d,i-1);
        // i=(int)pow(x,d);
        if(i>=2)return (long)pow(d,i-2);
        else return 0;
    }

    int divide(int dividend, int divisor) {
        int i,k,b,c;
        int flag=1;
        long mark=pow(2,31)-1;
        long d1,d2;
        d1=dividend;
        d2=divisor;
        if(d2<0&&d1>0){
            flag=-1;
            d2=-d2;
        }
        else if(d2>0&&d1<0){
            flag=-1;
            d1=-d1;
        }
        else if(d2<0&&d1<0){
            d1=-d1;
            d2=-d2;
        }
        //if(abs(d2)==1)if(d1>pow(2,31)-1)return d1*d2;
        // else return d1*flag;
        long ans=0;
        if(abs(d1)==abs(d2)){
            if(d1>mark||-d1>mark){
                if(flag==-1)return -mark;
                else return mark;
            }
            else {
                if(flag==-1)return -1;
                else return 1;
            }
        }
        if(abs(d2)==1){
            if(d1>mark||-d1>mark){
                if(d1==2147483648){
                    if(flag==-1)return -2147483648;
                    else return mark;
                }
                if(flag==-1)return -mark;
                else return mark;
            }
            else {
                if(flag==-1)return -abs(d1);
                else return abs(d1);
            }
        }
        for(;;){
            b=cal(d1,d2);
            if(b==0)break;
            ans+=b;
            if(ans>mark){
                if(flag==-1)return -mark;
                else return mark;
            }
        }
        if(flag==-1)return -ans;
        else return ans;
        // int times=(int)pow(d1,d2);
        // for(i=0;i<len;i++)
    }
};