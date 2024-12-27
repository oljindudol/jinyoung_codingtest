#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int l=0;
    int s=0;
    
    for(const auto& e: sizes)
    {
        l = max(l,max(e[0],e[1]));
        s = max(s,min(e[0],e[1]));
    }
    
    answer = l*s;
    
    return answer;
}