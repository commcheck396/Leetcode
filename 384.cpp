class Solution {
public:
    vector<int>initial;
    int len;
    Solution(vector<int>& nums) {
        initial=nums;
        len=nums.size();
    }
    
    vector<int> reset() {
        return initial;
    }
    
    vector<int> shuffle() {
        vector<int>tmp(len,0);
        tmp=initial;
        int mark[len+1];
        memset(mark,0,sizeof(mark));
        for(int i=0;i<len;i++){
            int position;
            position=rand()%len;
            while(mark[position]!=0){
                // break;
                position=rand()%len;
            }
            tmp[position]=initial[i];
            mark[position]++;
        }
        return tmp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */