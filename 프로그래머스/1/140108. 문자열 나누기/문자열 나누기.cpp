#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int firstcnt =0;
    char firstchar =' ';
    int othercnt =0;
    
    for(auto& e: s)
    {
        if(' ' == firstchar)
        {
            firstchar = e;
            firstcnt = 1;
            ++answer;
            continue;
        }
        
        if(firstchar == e)
        {
            ++firstcnt;
        }
        else
        {
            ++othercnt;
        }
        
        if(firstcnt == othercnt)
        {
            firstchar = ' ';
            firstcnt = 0;
            othercnt = 0;
        }
    }
    
    
    return answer;
}