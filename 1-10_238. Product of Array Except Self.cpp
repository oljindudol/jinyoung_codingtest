#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int i = 0;
    int ret = 0;
    while (i < nums.size())
    {
        ret += nums[i];
        i += 2;
    }
    return ret;
}

int main()
{
    vector<int> tc = { 1,4,3,2 };
    arrayPairSum(tc);
    return 0;
}