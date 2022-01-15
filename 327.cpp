class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int i,k,b,c,len;
        long long tmp;
        len=nums.size();
        long long a;
        // a[0]=nums[0];
        multiset<long long> sub;
        int ans=0;
        a=0;
        for(i=1;i<=len;i++){
            a=a+nums[i-1];
            // ans+=(sub.upper_bound(a[i]-lower)-sub.lower_bound(a[i]-upper));
            ans+=distance(S.lower_bound(a-upper),S.upper_bound(a-lower));
            sub.insert(a);
        }
        return ans;
    }
};