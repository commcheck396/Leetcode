    class Solution {
        vector<int>vis;
        public:
        int dfs(vector<vector<int>>&ans,int position,vector<int>&nums,vector<int>&tmp){
            int i,k,b,c;
            if(position==nums.size()){
                ans.push_back(tmp);
                return 0;
            }
            for(i=0;i<nums.size();i++){
                if(vis[i]||(i>0&&nums[i]==nums[i-1]&&vis[i-1]==0)){
                    continue;
                }
                tmp.push_back(nums[i]);
                vis[i]=1;
                dfs(ans,position+1,nums,tmp);
                tmp.pop_back();
                vis[i]=0;
            }
            return 0;
        }

        vector<vector<int>> permuteUnique(vector<int>& nums) {
            int i,k,b,c;
            vector<
            int len=nums.size();

            sort(nums.begin(),nums.end());
            vector<vector<int>>ans;
            vis.resize(nums.size());
            for(i=0;i<len;i++){
                vis[i]=0;
            }
            vector<int>tmp;
            dfs(ans,0,nums,tmp);
            return ans;
        }
    };

    class Solution {
        vector<int>vis;
    public:
        int dfs(vector<string>&ans,int position,string &S,string &tmp){
            int i,k,b,c;
            if(position==S.size()){
                ans.push_back(tmp);
                return 0;
            }
            for(i=0;i<S.size();i++){
                if(vis[i]||(i>0&&S[i]==S[i-1]&&vis[i-1]==0)){
                    continue;
                }
                tmp.push_back(S[i]);
                vis[i]=1;
                dfs(ans,position+1,S,tmp);
                tmp.pop_back();
                vis[i]=0;
            }
            return 0;
        }
        vector<string> permutation(string S) {
            int i,k,b,c,len=S.size();
            sort(S.begin(),S.end());
            string tmp;
            vector<string>ans;
            dfs(ans,posiiton+1,S,tmp);
            return ans;
        }
    };