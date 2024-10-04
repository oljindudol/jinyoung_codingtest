#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int maxrow;
int maxcol;

struct node
{
    int row;
    int col;
    int depth;
};

const int drow[4] = {0,0,1,-1};
const int dcol[4] = {1,-1,0,0};

bool IsValid(const vector<string>& maps , int row,int col)
{
    if(0 > row || maxrow <= row)
    {
        return false;
    }
    if(0 > col || maxcol <= col )
    {
        return false;
    }
    if('X' == maps[row][col])
    {
        return false;
    }
    
    return true;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    queue<node> q;
    
    int szrow = maps.size();
    int szcol = maps[0].size();
    maxrow = szrow;
    maxcol = szcol;
    
    vector<vector<bool>> visited(szrow,vector<bool>(szcol,false));
    
    int midrow=-1;
    int midcol=-1;
    
    int srow;
    int scol;
    
    bool fin = false;
    for(int row = 0 ; row < szrow;++row)
    {
        if(true ==fin)
        {
            break;
        }
        
        for(int col = 0 ; col< szcol;++col)
        {
            if('S'  == maps[row][col])
            {
                srow = row;
                scol = col;
                break;
            }
        }
    }
    
    // node n;
    // n.row = srow;
    // n.col = scol;
    // n.depth = 0;
    
    // q.push(n);
    q.push({srow,scol,0});
    
    while(false == q.empty())
    {
        auto cur = q.front();
        q.pop();
        
        if(false == IsValid(maps,cur.row,cur.col) || true == visited[cur.row][cur.col])
        {
           continue; 
        }
        
        visited[cur.row][cur.col] = true;
        if('L' == maps[cur.row][cur.col])
        {
            midrow = cur.row;
            midcol = cur.col;
            answer = cur.depth;
            break;
        }
        
        for(int i = 0 ; i<4;++i)
        {
            q.push({cur.row + drow[i] , cur.col+dcol[i] ,cur.depth+1});
        }
    }
    
    if(-1 == midrow)
    {
        return -1;
    }
    
    
    q = queue<node>();
    vector<vector<bool>> visited2(szrow,vector<bool>(szcol,false));
    
    int endrow = -1;
    int endcol = -1;
    
    q.push({midrow,midcol,answer});
    
    while(false == q.empty())
    {
        auto cur = q.front();
        q.pop();
        if(false == IsValid(maps,cur.row,cur.col) || true == visited2[cur.row][cur.col])
        {
           continue; 
        }
        cout<<cur.row<<","<<cur.col<<","<<endl;
        visited2[cur.row][cur.col] = true;
        if('E' == maps[cur.row][cur.col])
        {
            endrow = cur.row;
            endcol = cur.col;
            answer = cur.depth;
            break;
        }
        
        for(int i = 0 ; i<4;++i)
        {
            q.push({cur.row + drow[i] , cur.col+dcol[i] ,cur.depth+1});
        }
    }
    
    if(-1 == endrow)
    {
        cout<<"e2"<<endl;
        return -1;
    }
    
    
    return answer;
}