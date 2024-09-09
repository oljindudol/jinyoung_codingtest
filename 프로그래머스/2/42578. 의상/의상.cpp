#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string,int> um;
    
    for(auto & e: clothes)
    {
        ++um[e[1]];
    }
    
    for(auto & e: um)
    {
        answer *= (e.second+1);
    }
    
    //공집합의 갯수 빼주기
    --answer;
    
    return answer;
}