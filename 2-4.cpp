class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {


        ListNode* ret = nullptr;
        ListNode* curret = nullptr;

        vector<int> vecsum;

        int c = 0;

        while (!(nullptr == l1 && nullptr == l2))
        {
            int a = 0;
            int b = 0;
            if (nullptr != l1)
            {
                a = l1->val;
                l1 = l1->next;
            }
            if (nullptr != l2)
            {
                b = l2->val;
                l2 = l2->next;
            }

            int sum = a + b + c;

            c = sum / 10;
            vecsum.push_back(sum % 10);
        }

        if (0 != c)
            vecsum.push_back(c);

        int sz = vecsum.size();

        for (int i = 0; i < sz; ++i)
        {
            auto tmp = new ListNode;
            if (nullptr == curret)
            {
                ret = tmp;
                curret = tmp;
            }
            else
            {
                curret->next = tmp;
                curret = curret->next;
            }
            curret->val = vecsum[i];
        }

        return ret;

    }
};