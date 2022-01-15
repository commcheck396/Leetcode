class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int mod1=0,mod2=0,mod3=0;
        for(auto i:stones){
            if(i%3==1)mod1++;
            else if(i%3==2)mod2++;
            else mod3++;
        }
        int cur=0;
        int dif=mod2-mod1;
        if(mod1==0&&mod2==0){
            return false;
        }
        // else if((dif>1||dif<-1)&&(mod1!=0&&mod2!=0)){
        //     return true;
        // }
        // else if((dif>1||dif<-1)&&(mod1==0||mod2==0)){
        //     if(mod3%2==1)return false;
        //     else return true;
        // }
        else if(mod1==1&&mod2>=3){
            return true;
        }
        else if(mod2==1&&mod1>=3){
            return true;
        }
        else if(mod1==1&&mod2!=0){
            if(mod3%2==1)return false;
            else return true;
        }
        else if(mod2==1&&mod1!=0){
            if(mod3%2==1)return false;
            else return true;
        }
        else if(abs(dif)<2&&dif!=0&&(!mod1==0||mod2==0)){
            return false;
        }
        else if(mod1==0||mod2==0){
            if(stones.size()==1)return false;
            if(mod3%2==1)return false;
            else return true;
        }
        else if(abs(dif)>2){
            if(mod1==1||mod2==1){
                if(mod3%2==1)return true;
                else return false;
            }
            return true;
        }
        else if(abs(dif)==2){
            if(mod3==0)return true;
            return false;
        }
        else if(abs(dif)<2&&dif!=0&&(!mod1==0||mod2==0)){
            return false;
        }
        else if(dif==0){
            if(mod3==0)return true;
            if(mod3%2==0)return true;
            else return false;
        }
        else if(dif==-1||dif==1){
            return false;
        }
        return false; 
    }
};