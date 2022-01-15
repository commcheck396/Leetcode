class Solution {
public:
    bool is_pri(int n){
        int t =sqrt(n);
        for(int i=2;i<=t;i++)
            if(n%i==0)    return false;
        return true;
    }
    int minSteps(int n) {
        if(n==1)  return 0; 
        if(is_pri(n))    return n;
        int t=n/2;
        for(int i=t;i>=2;i--)
            if(n%i==0)
                return minSteps(i) + minSteps(n/i);
        return 0;
    }
};