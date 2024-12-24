#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string,int> um;
    
    for(const auto& e:clothes)
    {
        ++um[e[1]];
    }
    
    for(const auto&e: um)
    {
        answer*=(e.second+1) ;
    }
    
    --answer;
    return answer;
}