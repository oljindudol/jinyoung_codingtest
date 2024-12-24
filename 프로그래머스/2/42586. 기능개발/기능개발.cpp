#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int time = 0;
    
    for(int i =0 ; i < progresses.size();)
    {
        int cur = i;
        
        time = ceil(float(100-progresses[i]) /float(speeds[i]));
        
        while(i < progresses.size() && 100<= (progresses[i] + speeds[i]*time))
        {
            ++i;
        }
        
        answer.push_back(i-cur);
    }
    
    
    return answer;
}