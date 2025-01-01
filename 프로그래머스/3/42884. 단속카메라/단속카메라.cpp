#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct node
{
    int s;
    int e;
};

bool cmp(const node& a,const node& b)
{
    if(a.e==b.e)
    {
        return a.s<b.s;
    }
    return a.e<b.e;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int sz = routes.size();
    
    vector<node> nodes(sz);
    for(int i =0 ; i< sz;++i)
    {
        nodes[i] = {routes[i][0],routes[i][1]};
    }
    
    sort(nodes.begin(),nodes.end(),cmp);
    
    int lastend = -30001;
    
    for(const auto& e: nodes)
    {
        if(lastend < e.s)
        {
            answer++;
            lastend = e.e;
        }
    }
    
    return answer;
}