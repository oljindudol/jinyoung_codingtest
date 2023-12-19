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
    int ret = 0;
    //pair first 연속된 값
    //pair second 연속된 횟수
    
    pair<int,int> dfs(TreeNode* node)
    {
        if(nullptr == node)
        {
            return {1001,0};
        }
        
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        bool lefteq = false;
        bool righteq = false;
        
        //left랑 같은지 검사
        if(node->val == left.first)
        {
            lefteq =true;
        }
        
        //right랑 같은지 검사
        if(node->val == right.first)
        {
            righteq =true;
        }
        
        if( true == lefteq && false == righteq)
        {
            int suc = left.second +1;
            ret = ret > suc ? ret: suc;
            return {left.first , suc};
        }
        else if (false ==lefteq && true == righteq)
        {
            int suc = right.second +1;
            ret = ret > suc ? ret: suc;
            return {right.first , suc};
        }
        else if (true == lefteq && true == righteq)
        {
            int suc = left.second + right.second +2;
            int max = left.second > right.second ? left.second+1 :right.second+1;
            ret = ret > suc ? ret: suc;
            return {right.first , max};
        }
        else
        {
            return {node->val , 0};
        }
        

        
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if(nullptr ==  root)
        {
            return 0;
        }
        
        dfs(root);
        
        return ret;
            
    }
};