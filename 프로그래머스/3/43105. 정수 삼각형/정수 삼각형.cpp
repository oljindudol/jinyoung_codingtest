#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int sz = triangle.size();
    
    for(int row = 1 ;row<sz;++row)
    {
        for(int col = 0;col<=row;++col)
        {
            if(0==col)
            {
                triangle[row][col] += triangle[row-1][col];
            }
            else if(row==col)
            {
                triangle[row][col] += triangle[row-1][col-1];
            }
            else
            {
                triangle[row][col] += max(triangle[row-1][col-1],triangle[row-1][col]);
            }
            // cout<< triangle[row][col]<<' ';
        }
        // cout<<'\n';
    }
    
    answer = *max_element(triangle[sz-1].begin(),triangle[sz-1].end());
    
    return answer;
}