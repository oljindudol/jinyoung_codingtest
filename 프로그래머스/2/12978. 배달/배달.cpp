#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
    int to;
    int w;    
};

struct cmp
{
    bool operator()(const edge& a,const edge& b)
    {
        return a.w>b.w;
    }
};

const int INF = 1e9;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    vector<int> dp(N+1,INF);
    priority_queue<edge,vector<edge>,cmp> pq;
    
    vector<vector<edge>> edges(N+1);
    
    for(const auto& e: road)
    {
        edges[e[0]].push_back({e[1],e[2]});
        edges[e[1]].push_back({e[0],e[2]});
    }
    
    dp[1] = 0;
    pq.push({1,0});
    while(false == pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        auto curto = cur.to;
        auto curw = cur.w;
        
        for(const auto& e: edges[curto])
        {
            int t = e.to;
            int w = e.w;
            int neww = curw+w;
            if(dp[t]> neww)
            {
                dp[t] = neww;
                pq.push({t,neww});
            }
        }
    }
    
    for(int i = 1;i<N+1;++i)
    {
        if(K >= dp[i])
        {
            ++answer;
        }
    }
    

    return answer;
}