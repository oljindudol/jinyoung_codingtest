#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int sz = computers.size();
    vector<int> visited(sz);
    
    for(int i = 0 ; i < sz;++i)
    {
        if(1 == visited[i])
        {
            continue;
        }
        ++answer;
        visited[i] = 1;
        queue<int> q;
        q.push(i);
        
        while(false == q.empty())
        {
            int cur = q.front();
            q.pop();
            
            for(int to = 0 ;to<sz;++to)
            {
                if(1 == computers[cur][to] && 0== visited[to])
                {
                    visited[to] =1;
                    q.push(to);
                }
            }
        }
        
    }
    
    return answer;
}