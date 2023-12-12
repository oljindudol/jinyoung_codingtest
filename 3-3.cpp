#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;



vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> highest;
    int sz = temperatures.size();
    highest.resize(sz);
    int max = temperatures[sz - 1];

    for (int i = 0; i < sz; ++i)
    {
        if (max < temperatures[sz - i - 1])
        {
            max = temperatures[sz - i - 1];
        }
        highest[sz - i - 1] = max;
    }

    vector<int> ret;
    ret.resize(sz);

    for (int i = 0; i < sz - 1; ++i)
    {
        if (temperatures[i] < highest[i])
        {
            int cnt = 1;
            for (int j = i+1; j < sz; ++j)
            {
                if (temperatures[i] < temperatures[j])
                    break;
                else
                    ++cnt;
            }
            ret[i] = cnt;
        }
    }
    return ret;
}

int main()
{
    vector<int> input;
    input = { 73, 74, 75, 71, 69, 72, 76, 73 };


    dailyTemperatures(input);

    return 0;

}