

int drow[4] = {0,0,1,-1};
int dcol[4] = {1,-1,0,0};

int maxrow;
int maxcol;

bool IsValid(int _row,int _col,const vector<vector<char>>& _grid,const vector<vector<int>>& _visited)
{
    if(0 > _row || maxrow <= _row)
    {
        return false;
    }
    if(0 > _col || maxcol <= _col)
    {
        return false;
    }
    if('0' == _grid[_row][_col])
    {
        return false; 
    }
    if(1 == _visited[_row][_col])
    {
        return false;
    }
    
    return true;
}

struct node
{
    int row;
    int col;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret =0;
        
        maxrow = grid.size();
        maxcol = grid[0].size();
    
        queue<node> q;
        vector<vector<int>> visited(maxrow,vector<int>(maxcol,0));
        
        
        for(int row= 0; row<maxrow;++row)
        {
            for(int col =0; col<maxcol;++col)
            {
                if(false == IsValid(row,col,grid,visited))
                {
                    continue;
                }
                q.push({row,col});
                
                ++ret;
                while(false == q.empty())
                {
                    auto curnode = q.front();
                    q.pop();
                    auto currow = curnode.row;
                    auto curcol = curnode.col;
                    if(false == IsValid(currow,curcol,grid,visited))
                    {
                        continue;
                    }
                    
                    visited[currow][curcol]=1;
                    for(int i=0;i<4;++i)
                    {
                        int newrow= currow+drow[i];
                        int newcol = curcol +dcol[i];
                        
                        q.push({newrow,newcol});
                    }
                }
            }
            
        }
        return ret;
        
    }
};