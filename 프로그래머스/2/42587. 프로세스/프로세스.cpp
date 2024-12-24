#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

struct node
{
    int pri;
    int cnt;
};

struct node2
{
    int pri;
    bool target=false;
};

bool cmp(const node& a,const node& b)
{
    return a.pri >b.pri;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    unordered_map<int,int> um;
    int sz = priorities.size();
    queue<node2> q;
    int i =0 ;
    for(const auto& e: priorities)
    {
        ++um[e];
        node2 n = {};
        n.pri = e;
        if(i == location)
        {
            n.target = true;
        }
        q.push(n);
        ++i;
    }
    
    vector<node> pcnts;
    for(const auto& e:um)
    {
        pcnts.push_back({e.first,e.second});
    }
    sort(pcnts.begin(),pcnts.end(),cmp);
    
    int points = 0;
    
    while(false ==q.empty())
    {
        auto cur = q.front();
        q.pop();
        
        if(pcnts.size() == points || pcnts[points].pri <= cur.pri)
        {
            ++answer;
            if(true == cur.target)
            {
                break;
            }
            if(pcnts.size() != points)
            {
                --pcnts[points].cnt;
                if(0 == pcnts[points].cnt)
                {
                    ++points;
                }
            }
        }
        else
        {
            q.push(cur);
        }
    }
    
    return answer;
}