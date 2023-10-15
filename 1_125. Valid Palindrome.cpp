class Solution {
public:
    bool isPalindrome(string s) {
        string tmpstr;
        int slen = s.length();
        bool res = true;

        for (int i = 0; i < slen; i++) {
            if (65 <= s[i] && s[i] <= 90)
            {
                s[i] += 32;
                tmpstr += s[i];
            }
            else if (97 <= s[i] && s[i] <= 122)
            {
                tmpstr += s[i];
            }
            else if (48 <= s[i] && s[i] <= 57)
            {
                tmpstr += s[i];
            }
        }

        int tlen = tmpstr.length();
        if (0 == tlen)
            return res;

        cout << tmpstr;
        for (int i = 0; i < (tlen / 2); i++) {
            if (tmpstr[i] != tmpstr[tlen - 1 - i])
            {
                cout << i << endl;
                cout << tmpstr[i] << endl;
                cout << tmpstr[tlen - i] << endl;
                res = false;
                return res;
            }
        }
        return res;

    }
};