class Solution {
public:
    int rand10() {
        int i,k,b,c;
        for(;;){
            b=rand7();
            c=rand7();
            k=(b-1)*7+c-1;
            if(0<k<=10)return k;
            else continue;
        }        
    }
};