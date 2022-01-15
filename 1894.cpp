class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long i,j,b,c,len;
        len=chalk.size();
        if(len==1)return 0;
        for(i=0,b=0;i<len;i++){
            b+=chalk[i];
        }
        k=k%b;
        for(;;){
            for(i=0;i<len;i++){
                k-=chalk[i];
                if(k<0)return (int)i;
            }
        }
    }
};