#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int sz= people.size();
    int l = 0;
    int r = sz-1;
    
    while(l<=r)
    {
        if(limit <people[l] + people[r])
        {
            ++answer;
            --r;
        }
        else
        {
            ++answer;
            --r;
            ++l;
        }
    }
        
    return answer;
}