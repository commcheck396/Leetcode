int answer;
class Solution {
public:
    vector<int> translate(int n,int k){
        int up;
        vector<int> ans;
        int tmp;
        for(;n;){
            // up=n%10-k>0?n%10-k:0;
            tmp=n%k;
            ans.push_back(tmp);
            n/=k;
        }
        return ans;
    }
    bool judge(vector<int>cur){
        int len=cur.size();
        int fast=len-1;
        int slow=0;
        for(;fast>slow;){
            if(cur[fast]==cur[slow]){
                fast--;
                slow++;
            }
            else return false;
        }
        return true;
    }
    vector<int>to_vector(int n){
        vector<int>ans;
        for(;n;){
            ans.push_back(n%10);
            n/=10;
        }
    }
    int to_int(vector<int>n){
        int len=n.size();
        int ans;
        for(int i=0;i<len;i++){
            ans+=n[i]*pow(10,i);
        }
        return ans;
    }
    int dfs(int cur,int times,int n,int k){
        if(times==n)return 0;
        vector<int>tmp=to_vector(n);
        int low=0;
        int high=tmp.size();
        int mid;
        int fast,slow;
        if(tmp.size()%2){
            int mid=(high-1)/2;
            while()
        }
        for(;;){

        }

    }
    long long kMirror(int k, int n) {
        int times=0;
        int ans=0;
        int cur=1;
        int len=1;
        vector<int>tmp;
        for(;times<n;){
            if(judge(translate(cur,k))){
                times++;
                ans+=cur;
            }
            int high=len-1;
            int low=0;
            for(int i=10;;i*=10){
                if()
            }
        }
        return ans;
    }
};