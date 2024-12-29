#include <string>
#include <vector>

using namespace std;
int n;
vector<int> visited;
int ret= 0;

void dfs(int curk ,int picked,const vector<vector<int>>& ds)
{
    ret = max(ret,picked);
    for(int i =0 ; i < n;++i)
    {
        if(0==visited[i] && curk>=ds[i][0])
        {
            visited[i] = 1;
            dfs(curk-ds[i][1],picked+1,ds );
            visited[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    n = dungeons.size();
    visited.resize(n);
    dfs(k,0,dungeons);
    
    return ret;
    // return answer;
}