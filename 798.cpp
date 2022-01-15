class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int i,k,b,c,len;
        len=nums.size();
        int diff[len+1];
        //memset(diff,1,sizeof(diff));
        for(i=0;i<len+1;i++){
            diff[i]=1;
        }
        for(i=0;i<len;i++){
            diff[(i+1+len-nums[i])%len]--;
        }
        int max_=-100000;
        c=0;
        for(i=0,b=0;i<len;i++){

            b+=diff[i];
            if(max_<b)c=i;
            max_=max(max_,b);

        }
        return c;
    }
};