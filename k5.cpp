#include <string>
#include <unordered_map>
#include <cctype>
#include <iostream>


using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string, int> um1, um2;
    int cnta = 0;
    int cntb = 0;
    int cntcommon = 0;

    for (int i = 0; i < (str1.size() - 1); ++i)
    {
        auto a1 = tolower(str1[i]);
        auto a2 = tolower(str1[i + 1]);
        if (0 == isalpha(a1) || 0 == isalpha(a2))
        {
            continue;
        }
        string tmp;
        tmp += a1;
        tmp += a2;

        ++um1[tmp];
        ++cnta;
    }

    for (int i = 0; i < str2.size(); ++i)
    {
        auto a1 = tolower(str2[i]);
        auto a2 = tolower(str2[i + 1]);
        if (0 == isalpha(a1) || 0 == isalpha(a2))
        {
            continue;
        }
        string tmp;
        tmp += a1;
        tmp += a2;

        ++um2[tmp];
        ++cntb;
    }

    for (auto& e : um1)
    {
        auto f = e.first;
        auto s = e.second;

        if (0 == um2[f])
        {
            cout << f;
            cout << um2[f] << endl;

            continue;
        }
        else
        {
            cntcommon += min(s, um2[f]);
        }
    }
    if (0 == cnta && 0 == cntb)
    {
        return 65536;
    }
    float tm = ((float)cntcommon / (float)(cnta + cntb - cntcommon));

    cout << cnta << endl;
    cout << cntb << endl;
    cout << cntcommon << endl;
    cout << tm << endl;
    answer = 65536 * tm;

    return answer;
}