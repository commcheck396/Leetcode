class Solution {
public:
    vector<vector<int>>ans;
    int len;
    void dfs(vector<int>a,vector<int>num,int cur,int position,int last){
            vector<int>tmp(a);
            if(position>=len)return;
            int i=position;
            if(cur>num[i]){
                dfs(tmp,num,cur,position+1,num[i]);
                tmp.push_back(num[i]);
                if(last!=num[i])dfs(tmp,num,cur-num[i],position+1,-1);
            }
            else if(cur==num[i]){
                tmp.push_back(num[i]);
                ans.push_back(tmp);
            }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // vector<int>count(candidates.size()+1,0);
        sort(candidates.begin(),candidates.end());
        len=candidates.size();
        vector<int>tmp;
        dfs(tmp,candidates,target,0,-1);
        // for(int i=0;i<len;i++){
        //     vector<int>tmp;
        //     if(target>candidates[i]){
        //         tmp.push_back(candidates[i]);
        //         dfs(tmp,candidates,target-candidates[i],i);
        //     }
        //     else if(target==candidates[i]){
        //         tmp.push_back(candidates[i]);
        //         ans.push_back(tmp);
        //     }
        //     else break;
        // }
        return ans;
    }
};