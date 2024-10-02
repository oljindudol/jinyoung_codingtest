#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    list<char> l;
    
    while(0 != n)
    {
        int tmp = n%3;
        if(1 == tmp)
        {
            l.push_front('1');
        }
        else if(2 == tmp)
        {
            l.push_front('2');
        }
        else
        {
            l.push_front('4');
        }
        
        n/=3;
        if(0 == tmp)
        {
            n-=1;
        }
    }
    
    for(auto& e:l)
    {
        answer+=e;
        // answer.push_back(e);
    }
    
    return answer;
}