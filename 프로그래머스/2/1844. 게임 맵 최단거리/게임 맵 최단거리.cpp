#include<vector>
#include<queue>

using namespace std;

int sx[] = {1,-1,0,0};
int sy[] = {0,0,1,-1};
int maxx;
int maxy;
int minroot;
vector<vector<bool>> visited;

//유효성검사
bool valid(int x,int y)
{
    return false == (x>= maxx || x<0 || y>=maxy||y<0);
}

void updateMinRoot(int _in)
{
    if( -1 == minroot)
    {
        minroot = _in;
        return;
    }
    if( -1 != _in)
    {
        minroot = min(minroot,_in);
    }
    else
    {
        return;
    }
}


// int dfs(vector<vector<int>>& maps, int x,int y,int depth)
// {
//     //벽과만났을때
//     if(0 == maps[x][y])
//     {
//         return -1;
//     }
//     //visited에 만났을때
//     if(true == visited[x][y])
//         return -1;
//     if(x== (maxx-1) &&y== (maxy-1))
//         return depth;
    
    
//     for(int i = 0 ; i<4;++i)
//     {
//         int x = sx[i];
//         int y = sy[i];
//         if(valid(x,y))
//         {
//             visited[x][y]=true;
//                  updateMinRoot(dfs(maps,x,y,depth+1));
//             visited[x][y]=false;
            
//         }
//     }
// }

struct node
{
    int x;
    int y;
    int depth;
};

int solution(vector<vector<int> > maps)
{
    int answer = 10001;
    
    maxx = maps.size();
    maxy = maps[0].size();
    
    for(int i = 0 ; i<maxx; ++i)
    {
        visited.push_back(vector<bool>(maxy,false));
    }
    
    queue<node> q;
    int tarx = maxx-1;
    int tary = maxy-1; 
    
    q.push({0,0,1});
    
    while(false == q.empty())
    {
        node curnode = q.front();
        q.pop();
        
        if(tarx == curnode.x && tary == curnode.y)
        {
            answer = min(answer,curnode.depth);
            continue;
        }
        for(int i =0; i<4;++i)
        {
            int newx = curnode.x+ sx[i];
            int newy = curnode.y+sy[i];
            
            if( true == valid(newx,newy) && 1== maps[newx][newy] && false == visited[newx][newy])
            {
                visited[newx][newy]=true;
                q.push({newx,newy,curnode.depth +1 });
            }
        }
    }
    
    if(10001 == answer)
        return -1;
    
    return answer;
}