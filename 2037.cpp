class Solution {
public:
    int fib(int n) {
        int i,k,b,c,mod=1e9+7;
        vector<int>fibo;
        fibo.push_back(0);
        fibo.push_back(1);
        if(n==1&&n==0){
            return fibo[n];
        }
        b=fibo[1];
        else {
            for(i=2;i<=n;i++){
                // b=fibo[i-1];
                c=fibo[i-1];
                fibo.push_back(b+c);
                b=c;
            }
        }
        return fibo[n];
    }
};