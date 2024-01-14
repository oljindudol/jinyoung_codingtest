#include <string>
#include <math.h>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> nums;
    vector<char> alp;
    vector<char> simb;
    nums.resize(3);
    alp.resize(3);
    simb.resize(3);

    string dr = dartResult;
    int sz = dr.size();
    int idx = 0;
    int cycle = 1;
    unordered_map<char, int> um;
    um['S'] = 1;
    um['D'] = 2;
    um['T'] = 3;


    for (int i = 0; i < 3; ++i)
    {

        if ('0' <= dr[idx + 1] && '9' >= dr[idx + 1])
        {
            string tp = "";
            tp += dr[idx];
            tp += dr[idx + 1];
            nums[i] = stoi(tp);
            idx += 2;
        }
        else
        {
            string tp = "";
            tp += dr[idx];
            nums[i] = stoi(tp);
            ++idx;
        }
        alp[i] = dr[idx];

        ++idx;
        if (sz == idx)
        {

        }
        else if ('0' <= dr[idx] && '9' >= dr[idx])
        {
        }
        else
        {
            simb[i] = dr[idx];
            idx++;
        }

        //力蚌贸府
        nums[i] = pow(nums[i], um[alp[i]]);
        //扁龋贸府
        if ('*' == simb[i])
        {
            nums[i] *= 2;
            if (-1 != i - 1)
            {
                nums[i - 1] *= 2;
            }
        }
        else if ('#' == simb[i])
        {
            nums[i] *= -1;
        }

    }

    for (int i = 0; i < 3; ++i)
    {
        answer += nums[i];
    }

    return answer;

}