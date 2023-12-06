#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (nullptr == list1)
        return list2;
    if (nullptr == list2)
        return list1;

    ListNode* ret = new ListNode;
    ListNode* curret = ret;
    ListNode* cur1 = list1;
    ListNode* cur2 = list2;

    while (nullptr != cur1 && nullptr != cur2)
    {
        if (cur1->val < cur2->val)
        {
            curret->val = cur1->val;
            cur1 = cur1->next;
        }
        else
        {
            curret->val = cur2->val;
            cur2 = cur2->next;
        }
        ListNode* retnext = new ListNode;
        curret->next = retnext;
        curret = retnext;
    }

    if (nullptr == cur1)
    {
        curret->val = cur2->val;
        cur2 = cur2->next;

        while (nullptr != cur2)
        {
            ListNode* retnext = new ListNode;
            curret->next = retnext;
            curret = retnext;

            curret->val = cur2->val;
            cur2 = cur2->next;
        }
    }
    else
    {
        curret->val = cur1->val;
        cur1 = cur1->next;

        while (nullptr != cur1)
        {
            ListNode* retnext = new ListNode;
            curret->next = retnext;
            curret = retnext;

            curret->val = cur1->val;
            cur1 = cur1->next;
        }
    }

    return ret;
}

int main()
{
    
    ListNode* listNode = new ListNode(1);
    listNode->next = new ListNode(2);
    listNode->next->next = new ListNode(4);


    ListNode* listNode2 = new ListNode(1);
    listNode2->next = new ListNode(3);
    listNode2->next->next = new ListNode(4);


    mergeTwoLists(listNode, listNode2);

    return 0;

}