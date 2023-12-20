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
    int glow,ghigh,sum;
    void DFS(TreeNode* node)
    {
        if(nullptr == node)
        {
            return;
        }
        int v = node->val;
        cout<<v;
        if( glow <= v
          && ghigh >= v)
        {
            sum +=v;
        }

        if( glow < v)
        {
            DFS(node->left);
        }
        if( ghigh > v)
        {
            DFS(node->right);
        }
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        glow = low;
        ghigh = high;
        sum =0;
        
        
        DFS(root);
        return sum;
        
    }
};