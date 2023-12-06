class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto cur = head;
        vector<ListNode*> input;

        while (nullptr != cur)
        {
            input.push_back(cur);
            cur = cur->next;
        }

        int cnt;

        cnt = (right - left + 1) / 2;

        for (int i = 0; i < cnt; ++i)
        {
            auto tmp = input[left + i - 1];
            input[left + i - 1] = input[right - i - 1];
            input[right - i - 1] = tmp;
        }

        int sz = input.size();
        for (int i = 0; i < sz; ++i)
        {
            if (sz > i + 1)
                input[i]->next = input[i + 1];
            else
                input[i]->next = nullptr;
        }
        return input[0];
    }
};