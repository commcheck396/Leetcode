class Solution {
public:
    string getSmallestString(int n, int k) {
        int i,j,b,c;
        string a(n,'a');
        k-=(n);
        for(i=n-1;i>=0;i--){
            if(k/25){
                a[i]+=25;
                k-=25;
            }
            else {
                a[i]+=k;
                break;
            }
        }
        return a;
    }
};