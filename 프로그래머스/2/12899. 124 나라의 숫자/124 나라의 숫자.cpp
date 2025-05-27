#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

vector<char> map;

string solution(int n) {
    string answer = "";
    
    map.resize(3);
    map[0]='1';
    map[1]='2';
    map[2]='4';
    
    while(n>0)
    {
        --n;
        int mok = n/3;
        int mod = n%3;
        
        answer = map[mod]+answer;
        n=mok;
    }
    
    return answer;
}