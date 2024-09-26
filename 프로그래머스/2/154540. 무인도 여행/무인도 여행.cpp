#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int sx[4] = {1,-1,0,0};
int sy[4] = {0,0,1,-1};
int maxX;
int maxY;

struct coord
{
    int cx;
    int cy;
};

bool IsValid(int _cx,int _cy)
{
    if(0>_cx || maxX<=_cx)
    {
        return false;
    }
    
    if(0>_cy || maxY<=_cy)
    {
        return false;
    }
    
    return true;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    maxY = maps.size();
    maxX = maps[0].size();
    
    vector<vector<bool>> visited(maxY,vector<bool>(maxX,false));
    
    queue<coord> q;
    

    
    for(int i = 0 ; i< maxY;++i)
    {
        for(int j = 0 ; j< maxX; ++j)
        {
            if('X' != maps[i][j] && false == visited[i][j] )
            {
                int sum =0;

                visited[i][j] = true;
                q.push({j,i});
                
                while(false == q.empty())
                {
                    auto& e =  q.front();
                    q.pop();
                    
                    auto& letter = maps[e.cy][e.cx];
                    int num = letter-'0';
                    sum+=num;
                    cout<<num<<endl;
                    
                    for(int c=0;c<4;++c)
                    {
                        int newx = e.cx+sx[c];
                        int newy = e.cy+sy[c];
                        
                        if(true == IsValid(newx,newy) &&false == visited[newy][newx] && 'X' != maps[newy][newx])
                        {
                            visited[newy][newx] = true;
                            q.push({newx,newy});
                        }
                    }
                }
                answer.push_back(sum);
            }
            
        }
    }
    
    
    
    if(0 == answer.size())
    {
        answer.push_back(-1);
    }
    else
    {
        sort(answer.begin(),answer.end());
    }
    return answer;
}