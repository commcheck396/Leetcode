class Solution {
public:
    vector<int> grayCode(int n) {
        int i,k,b,c;
        int len=1<<n-1;
        vector<int>ans;
        ans.push_back(0);
        if(n==1)return ans;
        ans.push_back(1);
        ans.push_back(3);
        ans.push_back(2);
        int position=3;
        i=3;
        k=3;
        int last=3;
        for(position=3;position<n;position++){
            // ans.push_back(1<<position);
            // i++;
            int tmp=1<<position;
            if(k==0){
                for(k=0;k<=last;k++){
                    ans.push_back(tmp+ans[k]);
                    i++;
                }
                last=i;
                k--;
            }
            else {
                for(k=last;k>=0;k--){
                    ans.push_back(tmp+ans[k]);
                    i++;
                }
                last=i;
                k++;
                // ans.push_back(k);
            }
        }
        return ans;
    }
};