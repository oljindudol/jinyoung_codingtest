/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    
    if (lists.size() == 0) return nullptr;

    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
    int sz = lists.size();

    for (int i = 0; i < sz; ++i)
    {
        ListNode* cur = lists[i];
        while (nullptr != cur)
        {
            pq.push(cur);
            cur = cur->next;
        }
    }

    if(0 == pq.size())
    {
        return nullptr;
    }

    ListNode* ret = pq.top();
    pq.pop();
    ListNode* cur = ret;

    while (0 != pq.size())
    {
        cur->next = pq.top();
        pq.pop();
        cur = cur->next;
    }
    
    cur->next = nullptr;
    return ret;
}
};