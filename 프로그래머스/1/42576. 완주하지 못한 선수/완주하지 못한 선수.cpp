#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> um;
    
    for(const auto& e: completion)
    {
        ++um[e];
    }
    
    for(const auto& e: participant)
    {
        if(0 ==um[e])
        {
            answer = e;
            break;
        }
        else
        {
            --um[e];
        }
    }
    
    
    return answer;
}