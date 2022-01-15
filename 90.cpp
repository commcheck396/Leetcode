class Solution {
public:
    int len;
    vector<vector<int>> ans;
    set<vector<int>>tmpans;
    int dp(vector<int>& nums,int position,vector<int>upper){
        int i,k,b,c;
        tmpans.insert(upper);
        if(position<len-1){
            dp(nums,position+1,upper);
            upper.push_back(nums[position]);
            dp(nums,position+1,upper);
        }
        else{
            tmpans.insert(upper);
            upper.push_back(nums[position]);
            tmpans.insert(upper);
        } 
        return 0;
    } 
    

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        len=nums.size();
        int i,k,b,c;
        int mark[21];
        // memset(mark,0,sizeof(mark));
        // for(i=0;i<len;i++){
        //     mark[nums[i]+10]++;
        // }
        sort(nums.begin(),nums.end());
        vector<int>tmp;
        dp(nums,0,tmp);
        // set<int>:: iterator h;
        for(set<vector<int>>::iterator h=tmpans.begin();h!=tmpans.end();h++){
            ans.push_back(*h);
        }
        return ans;
        // int times[11];
        // b=INT_MAX;
        // c=-1;
        // int position[10];
        // for(i=0;i<len;i++){
        //     if(b!=nums[i]){
        //         c++;
        //         position[c]=nums[i];
        //     }
        //     times[c]++;
        //     b=nums[i];
        // }
        // int num=c;
        // vector<int>tmp;
        // for(int a1=0;a1<times[0];a1++){
            
        //     tmp.push_back(position[0]);
        // }
    }
};