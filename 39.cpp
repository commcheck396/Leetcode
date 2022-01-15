class Solution {
public:
    vector<vector<int>>ans;
    int len;
    void dfs(vector<int>a,vector<int>num,int cur,int position){
        for(int i=position;i<len;i++){
            vector<int>tmp(a);
            if(cur>num[i]){
                dfs(tmp,num,cur,position+1);
                tmp.push_back(num[i]);
                dfs(tmp,num,cur-num[i],position);
            }
            else if(cur==num[i]){
                tmp.push_back(num[i]);
                ans.push_back(tmp);
            }
            else break;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>count(candidates.size()+1,0);
        sort(candidates.begin(),candidates.end());
        len=cnadidiates.size();
        vector<int>tmp;
        dfs(tmp,candidate,target,0);
        // for(auto num:candidates){
        //     vector<int>tmp;
        //     if(target>num){
        //         tmp.push_back(num);
        //         dfs(tmp,candidates,target-num);
        //     }
        //     else if(target==num){
        //         tmp.push_back(num);
        //         ans.push_back(tmp);
        //     }
        //     else break;
        // }
        return ans;
    }
};