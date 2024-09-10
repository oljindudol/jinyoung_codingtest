#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<int> dp;
    dp.push_back(triangle[0][0]);
    
    for(int i =1 ;i<triangle.size();++i)
    {
        int sz = triangle[i].size();
        vector<int> pdp = dp;
        
        for(int j = 0; j<sz;++j)
        {
            if(0==j)
            {
                dp[j] = pdp[j] +triangle[i][j];
                continue;
            }
            if(sz-1 == j)
            {
                dp.push_back(pdp[j-1]+ triangle[i][j]);
            }
            else
            {
                dp[j] = triangle[i][j]  + max(pdp[j],pdp[j-1]);
            }
        }
        
    }
    
    
    for(auto& e: dp)
    {
        answer = max(answer ,e);
    }
    
    return answer;
}