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
    int ret=0;
    int maxdepth(TreeNode* _tn)
    {
        if(nullptr == _tn)
            return 0;
        
        int left = maxdepth(_tn->left);
        int right = maxdepth(_tn->right);
        
        ret = ret>left+right ? ret : left+right ;
        return left>right ? left+1 :right+1;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        maxdepth(root);
        
        return ret;
    }
};