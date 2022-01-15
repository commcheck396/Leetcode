class Solution {
public:
    int getSum(int a, int b) {
        int i,k,b,c,len,ans=0,up=0;
        for(i=0;i<32;i++){
            b=(a>>i)&1;
            c=(b>>i)&1;
            if(b==1&&c==1){
                ans=ans|(up<<i);
                up=1;
            }
            else if(b==1||c==1){
                if(up==1){
                    ans=ans|(0<<i);
                }
                else {
                    ans=ans|(up<<i);
                }
            }
            else {
                ans=ans|(up<<i);
                up=0;
            }
        }
        return ans;
    }
};