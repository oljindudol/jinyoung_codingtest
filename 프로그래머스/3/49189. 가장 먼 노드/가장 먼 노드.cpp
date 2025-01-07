#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
int vcnt;

vector<vector<int>> edges;

struct node
{
    int t;
    int w;
};

struct cmp
{
    bool operator()(const node& a,const node& b)
    {
        return a.w>b.w;
    }
};

constexpr int INF = 200001;
int daikustra(int from)
{
    vector<int> dp(vcnt+1,INF);
    dp[from] =0;
    
    priority_queue<node,vector<node>,cmp> pq;
    pq.push({from,0});
    
    while(false ==pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        
        if(dp[cur.t] < cur.w)
        {
            continue;
        }
        
        for(const auto& to: edges[cur.t])
        {
            int neww = cur.w + 1;
            if(dp[to] > neww)
            {
                dp[to] = neww;
                pq.push({ to,neww});
            }
        }
    }
    
    int ret = 0;
    sort(dp.begin(),dp.end(),greater<int>());
    int prev = dp[1];
    for(int i = 1 ; i< vcnt+1; ++i)
    {
        if(prev == dp[i])
        {
            ++ret;
        }
        else
        {
            break;
        }
    }
    

    return ret;
    
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vcnt = n;
    edges.resize(n+1);
    
    for(const auto& e: edge)
    {
        edges[e[0]].push_back(e[1]);
        edges[e[1]].push_back(e[0]);
    }
    
    return daikustra(1);
}