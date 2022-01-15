class Solution {
public:
    int findIntegers(int n) {
        int i,k,b,c,ans;
        int a[32];
        a[0]=1;
        a[1]=2;
        for(i=2;i<32;i++){
            a[i]=a[i-1]+a[i-2];
        }
        b=0;
        for(i=30,ans=0;i>=0;i--){
            if ((n & (1 << i)) != 0){
                ans+=a[i];
                if(b){
                    return ans;
                }
                b=1;
            }
            else {
                b=0;
            }
        }
        return ans+1;
    }
};