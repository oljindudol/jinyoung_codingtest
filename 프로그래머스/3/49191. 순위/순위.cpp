#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct node
{
    set<int> ws;
    set<int> ls;
};

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> wins(n+1);
    vector<vector<int>> loses(n+1);
    
    for(const auto& e: results)
    {
        wins[e[0]].push_back(e[1]);
        loses[e[1]].push_back(e[0]);
    }
    
    vector<node> info(n+1);
    
    for(int from = 1; from<n+1;++from)
    {
        vector<int> visited(n+1);
        visited[from] =1;
        
        queue<int> q;
        q.push(from);
        while(false == q.empty())
        {
            auto cur = q.front();
            q.pop();
            
            for(const auto& to: wins[cur])
            {
                if(0 == visited[to])
                {
                    visited[to] =1;
                    info[from].ws.insert(to);
                    q.push(to);
                }
            }
        }
        
        q.push(from);
        while(false == q.empty())
        {
            auto cur = q.front();
            q.pop();
            
            for(const auto& to: loses[cur])
            {
                if(0 == visited[to])
                {
                    visited[to] =1;
                    info[from].ls.insert(to);
                    q.push(to);
                }
            }
        }
    }
    
    
    for(int i =1 ; i < n+1;++i)
    {
        int res= 0;
        res += info[i].ws.size();
        res += info[i].ls.size();
        
        if(n-1 == res)
        {
            ++answer;
        }
    }
    
    
    return answer;
}