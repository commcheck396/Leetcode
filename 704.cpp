
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i,k,b,c;
        int low,high,mid;
        low=0;
        high=nums.size()-1;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else return mid;
        }
        return -1;
    }
};