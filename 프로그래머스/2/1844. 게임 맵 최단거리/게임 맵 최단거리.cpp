#include<vector>
#include <queue>

using namespace std;
int drow[4] = {1,-1,0,0};
int dcol[4] = {0,0,1,-1};
int r,c;

bool IsValid(int row,int col,const vector<vector<int>>& map)
{
    if(0>row || r<=row)
    {
        return false;
    }
    if(0>col || c<=col)
    {
        return false;
    }
    if(0==map[row][col])
    {
        return false;
    }
    return true;
}

struct node
{
    int row;
    int col;
    int depth;
};
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    r= maps.size();
    c= maps[0].size();
    
    queue<node> q;
    q.push({0,0,1});
    
    while(false == q.empty())
    {
        auto cur = q.front();
        q.pop();
        if(r-1 == cur.row && c-1==cur.col)
        {
            return cur.depth;
        }
        
        for(int i = 0 ; i < 4;++i)
        {
            int nrow = cur.row+drow[i];
            int ncol = cur.col+dcol[i];
            
            if(true == IsValid(nrow,ncol,maps))
            {
                maps[nrow][ncol] = 0;
                q.push({nrow,ncol,cur.depth+1});
            }
        }
    }
    
    
    return -1;
}