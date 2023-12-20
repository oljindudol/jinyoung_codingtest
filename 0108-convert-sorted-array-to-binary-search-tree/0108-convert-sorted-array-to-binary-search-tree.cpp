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
    
    vector<int> input;
    int sz;
    
    TreeNode* DFS(int s , int e)
    {
        if( s > e)
        {
            return nullptr;
        }
        int mid = (s+e)/2;
        
        auto n = new TreeNode;
        n->left = DFS(s, mid-1);
        n->right = DFS(mid+1, e);
        n->val = input[mid];

        return n;
    }
    

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        input = nums;
        sz = nums.size();
        
        return DFS(0, sz-1);
    }
};