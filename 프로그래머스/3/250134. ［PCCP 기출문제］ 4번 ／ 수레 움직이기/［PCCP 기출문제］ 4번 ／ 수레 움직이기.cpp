#include <string>
#include <vector>

using namespace std;

int inf;
int ret;
int r,c;

struct pos
{
    int row;
    int col;
};

int drow[4] = {1,-1,0,0};
int dcol[4] = {0,0,1,-1};

pos rpos;
pos bpos;
pos rtpos;
pos btpos;
pos dummy = {-1,-1};

vector<vector<int>> rvisited;
vector<vector<int>> bvisited;

bool IsValid(int row,int col,const vector<vector<int>>& map, const vector<vector<int>>& visited,const pos& OtherPrevPos,const pos& OtherCurPos)
{
    if(0>row||r<=row)
    {
        return false;
    }
    if(0>col ||c<=col)
    {
        return false;
    }
    //visited 확인
    if(1==visited[row][col])
    {
        return false;
    }
    //벽확인
    if(5==map[row][col])
    {
        return false;
    }
    //이전위치 확인
    if(row==OtherPrevPos.row && col==OtherPrevPos.col)
    {
        return false;
    }
    // //현재위치확인
    // if(row==OtherCurPos.row && col==OtherCurPos.col)
    // {
    //     return false;
    // }
    return true;
}

bool rFinished()
{
    if(rtpos.row == rpos.row
       &&rtpos.col == rpos.col)
    {
        return true;
    }
    return false;
}

bool bFinished()
{
    if(btpos.row == bpos.row
       &&btpos.col == bpos.col
      )
    {
        return true;
    }
    return false;
}

bool IsEnd()
{
    if(rFinished()&&bFinished())
    {
        return true;
    }
    return false;
}

void dfs(int depth,const vector<vector<int>>& map)
{
    if(true == IsEnd())
    {
        ret = min(ret,depth);
    }
    
    if(false == rFinished())
    {
        for(int i=0; i < 4;++i)
        {
            int rnrow = rpos.row +drow[i];
            int rncol = rpos.col + dcol[i];
            
            if(false == IsValid(rnrow,rncol,map,rvisited,dummy,dummy) )
            {
                continue;
            }
            
            if(true == bFinished() 
               && bpos.row == rnrow
              && bpos.col == rncol)
            {
                continue;
            }
            
            pos prevrpos = rpos;
            rpos.row = rnrow;
            rpos.col = rncol;
            rvisited[rnrow][rncol] =1;
            if(true ==bFinished())
            {
                dfs(depth+1,map);
            }
            else
            {
                
                for(int j=0;j<4;++j)
                {
                    int bnrow = bpos.row+drow[j];
                    int bncol = bpos.col+dcol[j];
                    if(false == IsValid(bnrow,bncol,map,bvisited,rpos,rpos))
                    {
                        continue;
                    }
                    if(prevrpos.row == bnrow && prevrpos.col == bncol
                       && rpos.row == bpos.row && rpos.col == bpos.col)
                    {
                        continue;
                    }
                    if(rpos.row == bnrow && rpos.col == bncol)
                    {
                        continue;
                    }
                    
                    
                    pos prevbpos = bpos;
                    bpos.row = bnrow;
                    bpos.col = bncol;
                    bvisited[bnrow][bncol]= 1;
                    
                    dfs(depth+1,map);
                    
                    bvisited[bnrow][bncol]=0;
                    bpos = prevbpos;
                }
                
            }
            rvisited[rnrow][rncol] =0;
            rpos = prevrpos;
        }
    }
    else
    {
        for(int j=0;j<4;++j)
        {
            int bnrow = bpos.row+drow[j];
            int bncol = bpos.col+dcol[j];
            if(false == IsValid(bnrow,bncol,map,bvisited,rpos,rpos))
            {
                continue;
            }
            pos prevbpos = bpos;
            bpos.row = bnrow;
            bpos.col = bncol;
            bvisited[bnrow][bncol]= 1;
            
            dfs(depth+1,map);
            
            bvisited[bnrow][bncol]=0;
            bpos = prevbpos;
        }
    }
}


int solution(vector<vector<int>> maze) {
    
    r = maze.size();
    c = maze[0].size();
    rvisited.resize(r,vector<int>(c));
    bvisited.resize(r,vector<int>(c));
    
    for(int row = 0; row<r;++row)
    {
        for(int col = 0 ; col<c;++col)
        {
            int ival = maze[row][col];
            if(0== ival ||5==ival)
            {
                continue;
            }
            
            if(1 == ival)
            {
                rpos.row = row;
                rpos.col = col;
                rvisited[row][col] = 1;
            }
            else if(2 == ival)
            {
                bpos.row = row;
                bpos.col = col;
                bvisited[row][col] =1;
            }
            else if(3 == ival)
            {
                rtpos.row = row;
                rtpos.col = col;
            }
            else if(4 == ival)
            {
                btpos.row= row;
                btpos.col = col;
            }
        }
    }
    
    // bFinished();
    
    inf = r*c+1;
    ret = inf;
    
    dfs(0,maze);
    
    if(inf ==ret)
    {
        return 0;
    }
    
    return ret;
}