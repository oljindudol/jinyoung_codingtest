#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ret;
    //sort(nums.begin(), nums.end());
    for(int i=0;i<nums.size()-1;i++)
    {
        for (int j = (i+1); nums.size(); j++)
        {
            //if (target <= nums[j]) break;
            if (target == (nums[i] + nums[j]))
            {
                ret.push_back(i);
                ret.push_back(j);
            }
            if (0 != ret.size())
            {
                break;
            }
        }
    }

    return ret;
}


int main()
{
    //vector<string> tc = { "eat","tea","tan","ate","nat","bat" };
    vector<int> tc= { 3,2,4 };
    twoSum(tc,5);
    return 0;
}