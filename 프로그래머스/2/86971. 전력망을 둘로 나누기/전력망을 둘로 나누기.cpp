#include <string>
#include <vector>

using namespace std;

vector<vector<int>> edges;
vector<int> visited;
int f;
int t;
int cnt;

void dfs(int from)
{
    visited[from] = 1;
    ++cnt;
    for(const auto& to: edges[from])
    {
        if(0== visited[to] && false == (f==min(to,from) && t==max(to,from) )) 
        {
            dfs(to);
        }
    }
}

int ret = 101;

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    int nsz = n+1;
    
    edges.resize(nsz);
    
    for(const auto& e: wires)
    {
        edges[e[0]].push_back(e[1]);
        edges[e[1]].push_back(e[0]);
    }
    
    for(const auto& e: wires)
    {
        visited.resize(0);
        visited.resize(nsz);
        f = e[0];
        t = e[1];
        
        cnt = 0;
        dfs(1);
        int c1 = cnt;
        cnt = 0 ;
        
        for(int i =2; i<nsz;++i)
        {
            if(0 == visited[i])
            {
                dfs(i);
                break;
            }
        }
        
        ret = min(ret,abs(c1-cnt));
        
    }
    
    return ret;
}