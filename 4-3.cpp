#include "check.h"
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_set>
#include <set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int maxDepth(TreeNode* root) {
    if (nullptr == root)
        return 0;

    int depth = 0;
    vector<deque<TreeNode*>> vdq;
    deque<TreeNode*> dq;

    TreeNode* p = root;
    dq.push_back(p);
    vdq.push_back(dq);

    while (0 == vdq.size())
    {
        deque<TreeNode*> cdq = vdq.back();
        vdq.pop_back();

        ++depth;
        deque<TreeNode*> tdq;
        while (0 == cdq.size())
        {
            TreeNode* cn = cdq.front();
            cdq.pop_front();

            if (nullptr != cn->left)
            {
                tdq.push_back(cn->left);
            }
            if (nullptr != cn->right)
            {
                tdq.push_back(cn->right);
            }
        }

        if (0 != tdq.size())
        {
            vdq.push_back(tdq);
        }

    }

    return depth;
}


int main()
{

    vector<vector<int>> input;

    vector<int> vc1{ 2,1,1, };
    vector<int> vc2{ 2,3,1, };
    vector<int> vc3{ 3,4,1, };

    input.push_back(vc1);
    input.push_back(vc2);
    input.push_back(vc3);

    networkDelayTime(input, 4, 2);
    return 0;
}