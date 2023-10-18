#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    int sz = nums.size();
    for (int i = 0; i < (sz - 2); i++)
    {
        for (int j = (i+1); i < (sz - 1); j++) 
        {
            for (int k = (j + 1); k < sz; k++)
            {
                if (0 == (nums[i] + nums[j] + nums[k]))
                {
                    ret.push_back({ nums[i],nums[j],nums[k] });
                }
            }
        }
    }
    return ret;
}

int main()
{
    vector<int> tc = { -1,0,1,2,-1,-4 };
    threeSum(tc);
    return 0;
}