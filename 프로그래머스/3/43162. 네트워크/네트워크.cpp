#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    int sz = computers.size();
    
    // vector<vector<int>> visited(vector<int>(false,m),n);
    vector<bool> visited(sz,false);
    
    queue<int> q;

    for(int i=0;i<sz;++i)
    {
        if(true == visited[i])
            continue;
        
        visited[i]=true;
        ++answer;
        cout<<i<<endl;
        q.push(i);
        while(false == q.empty())
        {
            int newidx = q.front();
            q.pop();
            for(int j=0;j<sz;++j)
            {
                if(false == visited[j] && 1 == computers[newidx][j])
                {
                    visited[j]=true;
                    q.push(j);
                }
            }
        }
    }
    
    return answer;
}