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

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (nullptr == head)
            return nullptr;

        ListNode* cur = head;
        vector<ListNode*> input;
        while (nullptr != cur)
        {
            input.push_back(cur);
            cur = cur->next;
        }

        int sz = input.size();
        bool even = 0 == sz % 2 ? true : false;
        int end = even ? sz : sz - 2;

        for (int i = 0; i < end; (i = i + 2))
        {
            auto tmp = input[i];
            input[i] = input[i + 1];
            input[i + 1] = tmp;
        }


        for (int i = 0; i < sz; ++i)
        {
            ListNode* tmp = new ListNode;
            if (sz > i + 1)
                input[i]->next = input[i + 1];
            else
                input[i]->next = nullptr;
        }
        return input[0];
    }
};
