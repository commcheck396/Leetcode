// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         int i,k,b,c,len;
//         len=nums.size();
//         vector<int>mark(len,0);
//         multiset<int> a;
//         int ans=0;
//         for(i=len-1;i>=0;i--){
//             mark[i]=distance(a.begin(),a.lower_bound(nums[i]));
//             a.insert(nums[i]);
//         }
//         return mark;
//     }
// };

struct BSTNode{

    
    int val;
    int count;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int x)
    : val(x)
    , left(NULL)
    , right(NULL)
    , count(0)
    {}
};

void BST_insert(BSTNode *node,BSTNode *insert_node,int &count_small)
{
    if(node->val >= insert_node->val)
    {
        node->count++;
        if(node->left)
        {
            BST_insert(node->left,insert_node,count_small);
        }
        else
        {
            node->left = insert_node;
        }
    }
    else{
        count_small += node->count + 1;
        if(node->right)
        {
            BST_insert(node->right,insert_node,count_small);
        }
        else
        {
            node->right = insert_node;
        }
    }
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int i,k,b,c,len;
        len=nums.size();
        vector<int>mark(len,0);
        mark[len-1]=0;
        if(len==0)return {};
        BSTNode *a=new BSTNode(nums[len-1]);
        for(i=len-2;i>=0;i--){
            c=0;
            BST_insert(a,new BSTNode(nums[i]),c);
            mark[i]=c;
        }
        return mark;
    }
};