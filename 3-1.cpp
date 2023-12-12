class Solution {
public:
    bool isValid(string s) {

        stack<char> closure;
        for (int i = 0; i < s.length(); ++i)
        {
            if ('(' == s[i]
                || '{' == s[i]
                || '[' == s[i])
            {
                closure.push(s[i]);
            }
            else if (')' == s[i])
            {
                if (0 == closure.size())
                {
                    return false;
                }
                if ('(' != closure.top())
                {
                    return false;
                }
                else
                {
                    closure.pop();
                }
            }

            else if ('}' == s[i])
            {
                if (0 == closure.size())
                {
                    return false;
                }
                if ('{' != closure.top())
                {
                    return false;
                }
                else
                {
                    closure.pop();
                }
            }

            else if (']' == s[i])
            {
                if (0 == closure.size())
                {
                    return false;
                }
                if ('[' != closure.top())
                {
                    return false;
                }
                else
                {
                    closure.pop();
                }
            }
        }
        if (0 != closure.size())
            return false;
        else
            return true;

    }
};