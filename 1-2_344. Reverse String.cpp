class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        int sz = s.size();
        for (int i = 0; i < (sz / 2); i++)
        {
            tmp = s[i];
            s[i] = s[(sz - i - 1)];
            s[(sz - i - 1)] = tmp;
        }
    }
};