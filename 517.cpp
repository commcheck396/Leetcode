class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int i,k,b,c,num,sum;
        num=machines.size();
        for(i=0,sum=0;i<num;i++){
            sum+=machines[i];
        }
        int per;
        if(sum%num){
            return -1;
        }
        pre_=sum/num;
        int ans=0;
        for(i=0,b=0;i<num;i++){
            b+=machines[i];
            if(machines[i]-pre_<=0){
                ans=max(ans,abs(b-(i+1)*pre_));
            }
            else ans=max(ans,max(machines[i]-pre_,abs(b-(i+1)*pre_)));
        }
        return ans;
    }
};