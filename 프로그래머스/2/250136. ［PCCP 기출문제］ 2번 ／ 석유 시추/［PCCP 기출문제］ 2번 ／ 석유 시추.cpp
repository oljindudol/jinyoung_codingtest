#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

int drow[4] = {1,-1,0,0};
int dcol[4] = {0,0,1,-1};

int maxrow;
int maxcol;

bool IsValid(const vector<vector<int>>& land ,int row,int col)
{
    if(0>row ||maxrow<= row)
    {
        return false;
    }
    if(0>col ||maxcol <= col)
    {
        return false;
    }
    if(0== land[row][col])
    {
        return false;
    }
    return true;
}

struct pos
{
    int row;
    int col;
};

int solution(vector<vector<int>> land) {
    int answer = 0;
    maxrow = land.size();
    maxcol = land[0].size();
    vector<int> ress(maxcol);
    
    for(int row = 0 ; row<maxrow;++row)
    {
        for(int col = 0 ; col <maxcol;++col)
        {
            if(0 == land[row][col])
            {
                continue;
            }
            
            queue<pos> q;
            q.push({row,col});
            int cnt = 0;
            set<int> s;
            land[row][col] = 0;
            
            while(false == q.empty())
            {
                auto cur = q.front();
                q.pop();
                s.insert({cur.col});
                ++cnt;
                
                for(int i = 0 ;i<4;++i)
                {
                    int nrow = cur.row+drow[i];
                    int ncol = cur.col +dcol[i];
                    if(true == IsValid(land,nrow,ncol))
                    {
                        land[nrow][ncol]=0;
                        q.push({nrow,ncol});
                    }
                }
            }
            
            for(const auto& e: s)
            {
                ress[e]+=cnt;
            }
        }
    }
    
    for(const auto& e:ress)
    {
        answer = max(answer, e);
    }
    
    // answer = *max_element(ress.begin(),ress.end());
    
    return answer;
}