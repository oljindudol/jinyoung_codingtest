#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct edge
{
    int t;
    int w;
};

bool cmp(const edge& a,const edge& b)
{
    return a.w<b.w;
}

struct cmp2
{
    bool operator()(const edge& a,const edge& b)
    {
        return a.w>b.w;
    }
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<vector<edge>> edges(n);
    vector<int> visited(n);
    for(const auto& e: costs)
    {
        edges[e[0]].push_back({e[1],e[2]});
        edges[e[1]].push_back({e[0],e[2]});
    }
    
    priority_queue<edge,vector<edge>,cmp2> pq;
    pq.push({0,0});
    // visited[0]=1;
    while(false == pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if(1== visited[cur.t])
        {
            continue;
        }
        visited[cur.t] = 1;
        // cout<<cur.t<<' ';
        answer += cur.w;
        
        for(const auto& to: edges[cur.t])
        {
            pq.push({to.t,to.w});
        }
    }
    
    return answer;
}