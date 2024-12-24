#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int c = 0;
    
    for(const auto& e: s)
    {
        if('(' == e)
        {
            ++c;
        }
        else
        {
            if(0==c)
            {
                return false;
            }
            --c;
        }
    }
    
    if(0<c)
    {
        return false;
    }

    return answer;
}