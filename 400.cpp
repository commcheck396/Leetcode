class Solution {
public:
    int findNthDigit(int n) {
        long last=1;
        long times=10;
        long tmp;
        int i;
        for(i=1;;i++,times*=10){
            tmp=(times-last)*i;
            if(n<=tmp)break;
            else{
                last=times;
                n-=tmp;
                continue;
            }
        }
        int position=n%i;
        // return position;
        int la=n/i;
        times/=10;
        if(position==0)return (times+la-1)%10;
        else {
            int ans;
            // times/=pow(10,position);
            string num;
            num=to_string(times+la);
            return num[position-1]-'0';
        }
        return -1;

    }
};