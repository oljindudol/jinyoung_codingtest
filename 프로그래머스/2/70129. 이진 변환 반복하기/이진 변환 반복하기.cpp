#include <string>
#include <vector>

using namespace std;

string tobinary(const string& _s)
{
    string ret;
}

int countchar(const string& _s,const char& _c)
{
    int ret= 0;
    for(auto& e: _s)
    {
        if(_c == e)
        {
            ++ret;
        }
    }
    return ret;
}

string convertbi(int _num)
{
    string ret = "";
    
    while(0 != _num)
    {
        ret = to_string(_num%2)+ret;
        _num /=2;
    }
    return ret;
}


vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int zeroremove = 0;
    
    while("1" != s)
    {
        ++cnt;
        
        int sz= s.size();
        int zerocnt = countchar(s,'0');
        zeroremove += zerocnt;
        int newcnt = sz-zerocnt;
        s = convertbi(newcnt);
    }
    
    answer.push_back(cnt);
    answer.push_back(zeroremove);
    
    return answer;
}