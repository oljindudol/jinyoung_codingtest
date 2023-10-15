#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

static bool compare(const pair<string, int>& _p1, const pair<string, int>& _p2)
{
    return _p1.second > _p2.second;
}



string mostCommonWord(string paragraph, vector<string>& banned) {
    string tmp;
    map<string, int> m1;
    vector<pair<string, int>> v1;
    string ret;

    for (int i = 0; i < paragraph.size(); i++)
    {
        if ((paragraph[i] >= 97 && paragraph[i] <= 122) || paragraph[i] == ' ')
        {
            tmp += paragraph[i];
        }
        else if (paragraph[i] >= 65 && paragraph[i] <= 90)
        {
            tmp += (paragraph[i] + 32);
        }
        else
        {
            tmp += ' ';
        }
    }

    while (-1 != tmp.find("  "))
    {
        tmp.replace(tmp.find("  "), 2, " ");
    }

    while (' ' == tmp[tmp.size() - 1])
    {
        tmp.erase(tmp.begin() + (tmp.size() - 1));
    }
    int space;
    for (int i = 0;;)
    {
        space = tmp.find(' ', i);

        if (-1 == space)
        {
            string tmpstr = tmp.substr(i, tmp.size());
            auto iter = m1.find(tmpstr);
            if (m1.end() == iter)
            {
                m1.insert(pair<string, int>(tmpstr, 1));
            }
            else
            {
                ++(iter->second);
            }
            break;
        }
        else
        {
            string tmpstr = tmp.substr(i, space - i);
            auto iter = m1.find(tmpstr);
            if (m1.end() == iter)
            {
                m1.insert(pair<string, int>(tmpstr, 1));
            }
            else
            {
                ++(iter->second);
            }
        }
        i = space + 1;
    }

    for (auto iter = m1.begin(); m1.end() != iter; iter++)
    {
        v1.push_back(*iter);
    }

    sort(v1.begin(), v1.end(), compare);

    for (auto iter = v1.begin(); v1.end() != iter; iter++)
    {
        auto iter2 = banned.begin();
        for (; banned.end() != iter2; iter2++)
        {
            if (*iter2 == iter->first)
            {
                break;
            }
        }
        if (banned.end() == iter2)
        {
            ret = iter->first;
            break;
        }

    }

    return ret;
}



int main()
{
    string tc = "a.";
    vector<string> tc2;
    mostCommonWord(tc,tc2);
    return 0;
}