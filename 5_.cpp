#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

static bool compare(const char& s1, const char& s2)
{
    return s1 < s2;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> m1;
    vector<vector<string>> ret;

    for (int i=0;i<strs.size();++i)
    {
        string tmp = strs[i];

        sort(tmp.begin(), tmp.end(), compare);

        auto fi = m1.find(tmp);
        vector<string> v1;
        if (m1.end() == fi)
        {
            v1.push_back(strs[i]);
            m1.insert(pair<string, vector<string>>(tmp,v1));
        }
        else
        {
            (fi->second).push_back(strs[i]);
        }
    }

    for (auto iter = m1.begin(); m1.end() != iter; ++iter)
    {
        ret.push_back(iter->second);
    }

    return ret;

}


int main()
{
    vector<string> tc = {"eat","tea","tan","ate","nat","bat"};
    groupAnagrams(tc);
    return 0;
}