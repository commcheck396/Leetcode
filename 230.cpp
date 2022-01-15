/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    priority_queue<int>mark;
    int kk;
    int dfs(TreeNode* head){
        if(mark.size()>=kk){if(head->val<mark.size()){
            mark.push(head->val);
            mark.pop();
        }}
        else mark.push(head->val);
        if(head->left!=nullptr)dfs(head->left);
        if(head->right!=nullptr)dfs(head->right);
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        kk=k;
        dfs(root);
        return mark.top();
    }
};