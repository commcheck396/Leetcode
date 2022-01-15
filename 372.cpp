int num;
class Solution {
public:
    int helper(vector<int>cur){
        if(cur.size()>1){
            int times=cur[cur.size()-1];
            cur.pop_back();
            int mod=helper(cur);
            int ans=1;
            for(int i=0;i<10;i++){
                ans=(ans*mod)%1337;
            }
            mod=ans;
            ans=1;
            for(int i=0;i<times;i++){
                ans=(ans*num)%1337;
            }
            return (ans*mod)%1337;
        }
        else {
            int ans=1;
            for(int i=0;i<cur[0];i++){
                ans=(ans*num)%1337;
            }
            return ans;
        }
        return 0;
    }
    int superPow(int a, vector<int>& b) {
        int len=b.size();
        // long long tmp;
        num=a%1337;
        int ans=helper(b);
        return ans;
    }
};