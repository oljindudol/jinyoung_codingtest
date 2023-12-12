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


ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int sz = lists.size();

    for (int i = 0; i < sz; ++i)
    {
        ListNode* cur = lists[i];
        while (nullptr != cur)
        {
            pq.push(cur->val);
            cur = cur->next;
        }
    }

    ListNode* ret = new ListNode;
    ret->val = pq.top();
    pq.pop();
    ListNode* cur = ret;

    while (0 != pq.size())
    {
        ListNode* tmp = new ListNode;
        tmp->val = pq.top();
        pq.pop();
        cur->next = tmp;
        cur = cur->next;
    }
    return ret;
}


int main()
{
    vector<ListNode*> input;

    ListNode* listNode = new ListNode(1);
    listNode->next = new ListNode(4);
    listNode->next->next = new ListNode(5);
    input.push_back(listNode);

    ListNode* listNode2 = new ListNode(1);
    listNode2->next = new ListNode(3);
    listNode2->next->next = new ListNode(4);
    input.push_back(listNode2);

    ListNode* listNode3 = new ListNode(2);
    listNode3->next = new ListNode(6);
    input.push_back(listNode3);



    mergeKLists(input);

    return 0;

}