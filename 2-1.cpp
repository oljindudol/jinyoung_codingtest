class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if (nullptr == head)
        {
            return true;
        }

        vector<int> vlist;
        vlist.push_back(head->val);
        ListNode* curnode = head->next;

        while (nullptr != curnode)
        {
            vlist.push_back(curnode->val);
            curnode = curnode->next;
        }

        int size = vlist.size();
        for (int i = 0; i < (size / 2); ++i)
        {
            if (vlist[i] != vlist[size - i - 1])
                return false;
        }
        return true;
    }
};