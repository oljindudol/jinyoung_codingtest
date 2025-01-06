#include <string>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    string s;
    int depth;
};

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int sz = words.size();
    vector<int> visited(sz);
    
    queue<node> q;
    q.push({begin,0});
    while(false == q.empty())
    {
        auto cur = q.front();
        q.pop();
        
        if(target ==cur.s)
        {
            return cur.depth;
        }
        
        for(int i =0 ; i < sz;++i)
        {
            if(1==visited[i])
            {
                continue;
            }
            int diff = 0;
            for(int j= 0;j<words[i].size();++j)
            {
                if(cur.s[j] != words[i][j])
                {
                    ++diff;
                }
            }
            if(1== diff)
            {
                visited[i] = 1;
                q.push({words[i],cur.depth+1});
            }
        }
        
    }
    
    return 0;
}