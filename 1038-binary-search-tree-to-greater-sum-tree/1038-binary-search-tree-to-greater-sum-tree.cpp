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
    int costacc;
    void DFS(TreeNode* node)
    {
        if(nullptr == node)
        {
            return;
        }
        
        DFS(node->right);
        costacc += node->val;
        node->val = costacc;
        DFS(node->left);
        
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        costacc= 0;
        
        DFS(root);
        
        return root;
    }
};