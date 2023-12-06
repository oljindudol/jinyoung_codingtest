class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (nullptr == head)
            return nullptr;
        if (nullptr == head->next)
            return head;

        vector<ListNode*> inputodd;
        vector<ListNode*> inputeven;
        bool odd = true;
        auto cur = head;
        while (nullptr != cur)
        {
            if (odd)
            {
                inputodd.push_back(cur);
            }
            else
            {
                inputeven.push_back(cur);
            }
            cur = cur->next;
            odd = !odd;
        }
        cur = head;
        int oddsz = inputodd.size();
        int evensz = inputeven.size();

        for (int i = 0; i < oddsz; ++i)
        {
            if (oddsz > i + 1)
                inputodd[i]->next = inputodd[i + 1];
            else
                inputodd[i]->next = inputeven[0];
        }

        for (int i = 0; i < evensz; ++i)
        {
            if (evensz > i + 1)
                inputeven[i]->next = inputeven[i + 1];
            else
                inputeven[i]->next = nullptr;
        }
        return inputodd[0];
    }
};