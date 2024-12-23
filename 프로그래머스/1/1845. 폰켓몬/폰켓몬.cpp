#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    unordered_set<int> us;
    
    int pickcnt = nums.size()/2;
    
    for(const auto& e: nums)
    {
        us.insert(e);
    }
    
    answer = min(pickcnt,(int)us.size());
    
    return answer;
}