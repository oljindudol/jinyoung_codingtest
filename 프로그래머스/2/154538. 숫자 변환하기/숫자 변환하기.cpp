#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define maxint 1000000

int target;
int mindepth = maxint;
int addnum ;


void dfs(int _val, int _depth)
{
    if(target == _val)
    {
        mindepth = min(mindepth , _depth);
        return;
    }
    if(target < _val)
    {
        return;
    }
    
    dfs(_val+addnum ,_depth+1 );
    dfs(_val*2,_depth+1);
    dfs(_val*3,_depth+1);
    
    
}


struct node
{
    int val;
    int depth;
};


int solution(int x, int y, int n) {
    int answer = 0;
    target = y;
    addnum = n;
    
    set<int> visited;
    queue<node> q;
    
    q.push({x,0});
    bool bFound =false; 
    
    while(false == q.empty())
    {
        if(true == bFound )
        {
            break;
        }
        
        auto cur = q.front();
        q.pop();
        if(visited.end() != visited.find( cur.val) )
        {
            continue;
        }
        else
        {
            visited.insert(cur.val);
        }
        
        if(y == cur.val)
        {
            mindepth = min(cur.depth , mindepth);
            continue;
        }
        if(y < cur.val)
        {
            continue;
        }
        
        q.push({cur.val + n,cur.depth+1});
        q.push({cur.val *2,cur.depth+1});
        q.push({cur.val*3,cur.depth+1});
    }
    
    
    
    // dfs(x,0);
    
    
    if(maxint == mindepth)
    {
        answer = -1;
    }
    else
    {
        answer = mindepth;
    }
    
    return answer;
}