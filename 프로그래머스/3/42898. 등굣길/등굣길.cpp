#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> map(m,vector<int>(n,0));
    
    for(const auto e:puddles)
    {
        map[e[0]-1][e[1]-1] = -1;
    }
    
    map[0][0]=1;
    
    for(int row=0;row<m;++row)
    {
        for(int col = 0 ;col<n;++col)
        {
            if(-1 == map[row][col])
            {
                continue;
            }
            if(0 != row && -1 != map[row-1][col])
            {
                map[row][col] = map[row-1][col];
            }
            if(0 != col && -1 != map[row][col-1])
            {
                if(-1 == map[row][col])
                {
                    map[row][col] = map[row][col-1];
                }
                else
                {
                    map[row][col] += map[row][col-1];
                    map[row][col] = map[row][col]%1000000007;
                }
            }
        }
    }
    
    // for(const auto& r:map)
    // {
    //     for(const auto& c:r)
    //     {
    //         cout<< c<< ' ';
    //     }
    //     cout<<'\n';
    // }
    
    
    return map[m-1][n-1];
}