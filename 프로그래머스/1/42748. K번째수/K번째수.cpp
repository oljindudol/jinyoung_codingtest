#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(const auto& e: commands)
    {
        vector<int> nums = {array.begin()+e[0]-1,array.begin()+e[1]};
        sort(nums.begin(),nums.end());
        // for(const auto& s:nums)
        // {
        //     cout<<s<<' ';
        // }
        // cout<<endl;
        
        answer.push_back(nums[e[2]-1]);
    }
    
    return answer;
}