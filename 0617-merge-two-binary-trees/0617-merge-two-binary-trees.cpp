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
    TreeNode* dfs(TreeNode* ltn,TreeNode* rtn)
    {
        if( nullptr == ltn && nullptr == rtn)
        {
            return nullptr;
        }
        TreeNode* ltnleft=nullptr;
        TreeNode* rtnleft=nullptr;
        TreeNode* ltnright=nullptr;
        TreeNode* rtnright=nullptr;
        int lval=0;
        int rval=0;
        
        if(nullptr != ltn)
        {
            ltnleft = ltn->left;
            ltnright = ltn->right;
            lval = ltn->val;
        }
        if(nullptr != rtn)
        {
            rtnleft = rtn->left;
            rtnright = rtn->right;
            rval = rtn->val;
        }
        
        TreeNode* left = dfs(ltnleft,rtnleft);
        TreeNode* right = dfs(ltnright,rtnright);
        
        auto ret = new TreeNode;
        ret->val = lval+rval;
        
        ret->left = left;
        ret->right = right;
        
        return ret;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(nullptr == root1)
        {
            return root2;
        }
        if(nullptr == root2)
        {
            return root1;
        }
        
        TreeNode* newroot = dfs(root1,root2);
        
        return newroot;
    }
};