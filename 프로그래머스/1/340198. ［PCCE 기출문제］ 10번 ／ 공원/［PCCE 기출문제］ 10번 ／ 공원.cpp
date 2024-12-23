#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    int r = park.size();
    int c = park[0].size();
    sort(mats.begin(),mats.end(),greater<int>());
    int gsz = mats[0];
    int lsz = mats[mats.size()-1];
    
    vector<vector<int>> dp(r,vector<int>(c));
    
    for(int row =0 ;row<r;++row)
    {
        int acc= 0;
        for(int col = c-1; col>=0;--col)
        {
            if("-1" != park[row][col])
            {
                dp[row][col] = 0;
                acc=0;
            }
            else
            {
                ++acc;
                dp[row][col] = acc;
            }
        }
    }
    
    for(int row =0 ; row < r;++row)
    {
        for(int col=0;col<c;++col)
        {
            int mx = dp[row][col];
            
            mx = min(mx,r-row);
            mx = min(mx , gsz);
            int offset = 1;
            
            while(mx>offset)
            {
                mx = min(mx,dp[row+offset][col]);
                ++offset;
            }
            
            if(lsz>mx)
            {
                continue;
            }
            // cout<<mx;
            
            for(int i = 0 ;i<mats.size();++i)
            {
                if(mats[i] <=mx)
                {
                    answer = max(answer,mats[i]);
                    break;
                }
            }
            
        }
        // cout<< '\n';
    }
    
    
    return answer;
}