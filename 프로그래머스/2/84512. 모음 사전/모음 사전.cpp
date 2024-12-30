#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt = 0;
string str = " AEIOU";
string target;

void dfs(int depth,string& cur,bool end)
{
    if(target == cur)
    {
        cout<<"found" <<cnt<<':'<<cur<<'\n';
        throw exception();
    }
    else
    {
        // cout<<cnt<<':'<<cur<<'\n';
    }
    ++cnt;
    if(true == end || 5==depth)
    {
        return;
    }
    
    for(int i = 1;i<str.size();++i)
    {
        cur.push_back(str[i]);
        dfs(depth+1,cur,end);
        cur.pop_back();
    }
}


int solution(string word) {
    int answer = 0;
    target = word;
    string cur;
    
    try
    {
        dfs(0,cur,false);
    }
    catch(const exception& e)
    {
        
    }
    
    return cnt;
    // return answer;
}