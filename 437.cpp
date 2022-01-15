int pre[1005];
int P;
int ans;
class Solution {
public:
    int re_dfs(TreeNode *head,int cur,int target){
        int i,k,b,c;
        TreeNode *position;
        cur+=head->val;
        if(cur==target)ans++;
        if(head->left!=nullptr){
            re_dfs(head->left,cur,target);
        }
        if(head->right!=nullptr){
            re_dfs(head->right,cur,target);
        }
        return 0;
    }
    int dfs(TreeNode *head,int cur,int target){
        int i,k,b,c;
        TreeNode *position;
        re_dfs(head,0,target);
        if(head->left!=nullptr){
            dfs(head->left,cur,target);
        }
        if(head->right!=nullptr){
            dfs(head->right,cur,target);
        }
        return 0;
    }

    int pathSum(TreeNode* root, int targetSum) {
        int i,k,b,c;
        TreeNode *head,*position;
        head=root;
        if(head==nullptr)return 0;
        position=head;
        ans=0;
        dfs(root,0,targetSum);
        return ans;
    }
};