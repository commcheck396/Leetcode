class Solution {
public:
    int findComplement(int num) {
        int i,k,b,c;
        for(i=0;i<32;i++){
            if(pow(2,i)>num)break;
            else continue;
        }
        int mod=(INT_MAX<<1)|1;
        // int mod=INT_MIN+1;
        b=1;
        for(k=0;k<i;k++){
            mod-=b;
            b=b<<1;
        }
        return ~(num|mod);
    }
};