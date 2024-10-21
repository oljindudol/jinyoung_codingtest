#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

struct pos
{
    int row;
    int col;
};

int maxrow;
int maxcol;

bool IsPuddle(int row,int col,vector<vector<int>>& puddles)
{
    for(const auto& e: puddles)
    {
        if(col == e[0]-1 && row == e[1]-1)
        {
            return true;
        }
    }
    return false;
}


int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    maxrow = n;
    maxcol = m;
    
//    vector<vector<int>> pm(n,vector<int>(m,0));
    
//     for(auto& e:puddles)
//     {
//         pm[e[0]][e[1]] = 1;
//     }
    
    vector<long long> dp(m,0);
    // dp[0] = 1;
    for(int row=0;row<n; ++row)
    {
        for(int col=0;col<m;++col)
        {
            if(true == IsPuddle(row,col,puddles))
            {
                dp[col] = 0;
                continue;
            }
            
            if(0 == row && 0 == col)
            {
                dp[col] = 1;
                continue;
            }
            if(0 == row && 0 != col)
            {
                dp[col] = dp[col-1];
                continue;
            }
            if(0 != row && 0 == col)
            {
                dp[col] = dp[col];
                continue;
            }
            if(0 != row && 0 != col)
            {
                dp[col] = dp[col]+dp[col-1]%1000000007;
                continue;
            }
        }
        
        // for(auto& e: dp)
        // {
        //     cout<<e<<",";
        // }
        // cout<<endl;
    }
    
    return dp[m-1]%1000000007;
}