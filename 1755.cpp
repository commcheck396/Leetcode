class Solution {
public:
        vector<int> make(vector<int> nums){
        vector<int> ans(1 << nums.size());
        int n=nums.size();
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < (1 << i); ++j){
                ans[j + (1 << i)] = ans[j] + nums[i];
            }
        }
        return ans;
    }
    bool cmp(int a,int b){
            return a>b;
        }

    int minAbsDifference(vector<int>& nums, int goal) {
        int i,k,b,c,len,ans=INT_MAX;
        len=nums.size();
        vector<int> left = make({nums.begin(), nums.begin() + len / 2});
        vector<int> right = make({nums.begin() + len / 2, nums.end()});
        sort(left.begin(), left.end());
        sort(right.begin(), right.end(),greater<int>());
        int lenl=left.size();
        int lenr=right.size();
        for(;i<lenl&&k<lenr;){
            b=left[i]+right[k];
            ans=min(ans,abs(b-goal));
            if(b<goal)i++;
            else if(b>goal)k++;
            else if(b==goal)return 0;
        }
        return  ans;
    }
};