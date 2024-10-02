#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string,int> dium;
    unordered_map<string,int> wtum;
    
    
    
    for(int i = 0; i<want.size();++i)
    {
        wtum[want[i]] = number[i];
    }
    
    for(int i =0; i<discount.size();++i)
    {
        ++dium[discount[i]];
        
        if(9<i)
        {
            --dium[discount[i-10]];
        }
        
        if(8<i)
        {
            bool able = true;
            for(auto& e: wtum)
            {
                if(dium[e.first] < e.second)
                {
                    able= false;
                    break;
                }
            }
            if(true == able)
            {
                ++answer;
            }
        }
        
    }
    
    return answer;
}