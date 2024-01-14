#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;



struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

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

    if (0 == pq.size())
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


int main()
{
    vector<ListNode*> input;

    ListNode* listNode = new ListNode(-1);
    listNode->next = new ListNode(-1);
    listNode->next->next = new ListNode(-1);
    input.push_back(listNode);

    ListNode* listNode2 = new ListNode(-2);
    listNode2->next = new ListNode(-2);
    listNode2->next->next = new ListNode(-1);
    input.push_back(listNode2);

    //ListNode* listNode3 = new ListNode(2);
    //listNode3->next = new ListNode(6);
    //input.push_back(listNode3);



    mergeKLists(input);

    return 0;

}