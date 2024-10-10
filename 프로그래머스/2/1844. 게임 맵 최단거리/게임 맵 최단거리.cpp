#include<vector>
#include <queue>
#include <iostream>

using namespace std;

int maxrow;
int maxcol;

bool IsValid(int row,int col,const vector<vector<int> >& maps)
{
    if(0> row || maxrow<= row)
    {
        return false;
    }
    
    if(0>col || maxcol <= col)
    {
        return false;
    }
    
    if(0 == maps[row][col])
    {
        return false;
    }
    
    return true;
}

struct node
{
    int depth;
    int row;
    int col;
};

int drow[4]= {0,0,1,-1};
int dcol[4]={1,-1,0,0};



int solution(vector<vector<int> > maps)
{
    int answer = -1;
    maxrow = maps.size();
    maxcol = maps[0].size();
    queue<node> q;
    
    // for(int row =0; row<maxrow;++row)
    // {
    //     for(int col=0;col<maxcol;++col)
    //     {
    
    q.push({1,0,0});
    
    while(false == q.empty())
    {
        auto curnode = q.front();
        q.pop();
        int currow = curnode.row;
        int curcol = curnode.col;
        
        if(false == IsValid(currow,curcol,maps))
        {
            continue;
        }
        maps[currow][curcol]=0;
        
        
        if(currow ==maxrow-1 && curcol == maxcol-1)
        {
            answer = curnode.depth;
            break;
        }
        
        for(int i = 0;i<4;++i)
        {
            int newrow = currow+ drow[i];
            int newcol = curcol + dcol[i];
            q.push({curnode.depth+1,newrow,newcol});
        }
    }

            
            
            
    //     }
    // }
    
    return answer;
}