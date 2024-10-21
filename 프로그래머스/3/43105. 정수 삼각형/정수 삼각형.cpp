#include <string>
#include <vector>
#include <iostream>

using namespace std;

int maxel=-1;
vector<int> dp;
int maxdepth;

void dfs(const vector<vector<int>>& triangle,int depth)
{
    if(maxdepth < depth)
    {
        return;
    }
    
    vector<int> pdp;
    for(int i = 0 ; i < depth;++i)
    {
        pdp.push_back(dp[i]);
    }
    
    //depth만큼돈다
    for(int i = 0 ; i < depth;++i)
    {
        if(0 == i)
        {
            dp[i] = pdp[i] + triangle[depth-1][i];
            continue;
        }
        else if(depth-1 == i)
        {
            dp[i] = pdp[i-1] +triangle[depth-1][i]; 
            continue;
        }
        else
        {
            dp[i] = max(pdp[i] + triangle[depth-1][i] ,pdp[i-1] +triangle[depth-1][i] );
            continue;
        }
    }
    
    dfs(triangle,depth+1);
    
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    maxdepth = triangle.size();
    
    
    dp = vector<int>(maxdepth,0);
    dp[0] = triangle[0][0];
    dfs(triangle,2);
    
    for(int i = 0 ; i < maxdepth; ++i)
    {
        answer = max(answer,dp[i]);
    }
    return answer;
}