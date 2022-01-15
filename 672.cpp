class Solution {
public:
    int flipLights(int n, int presses) {
        int i,k,b,c;
                if(n ==0 || presses == 0){
            return 1;
        }
        if(n == 1){
            return 2;
        }
        else if(n == 2 && presses == 1){
            return 3;
        }
        else if((n == 2 && presses >= 2) || presses == 1){
            return 4;
        }
        else if(n >= 3 && presses == 2){
            return 7;
        }
        else {
            return 8;
        }
    }
};