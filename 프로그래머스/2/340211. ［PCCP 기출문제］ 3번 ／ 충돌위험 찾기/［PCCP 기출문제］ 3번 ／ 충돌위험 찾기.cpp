#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct pos
{
    int row;
    int col;
};


struct node
{
    int pptr;
    vector<pos> poss;
};

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    vector<node> nodes(routes.size());
    
    int i= 0;
    for(const auto& r:routes)
    {
        int rsz = r.size();
        
        nodes[i].poss.resize(rsz);
        for(int j = 0 ; j< rsz;++j)
        {
            nodes[i].poss[j].row= points[r[j]-1][0];        
            nodes[i].poss[j].col= points[r[j]-1][1];
        }
        ++i;
    }
    
    {
        unordered_map<string,int> um;
        
        for(auto& n:nodes)
        {
            // if(n.destrow == n.currow && n.destcol == n.curcol)
            // {
            //     continue;
            // }
            string key = to_string(n.poss[0].col) + ','+to_string(n.poss[0].row);
            ++um[key];
            if(2 == um[key])
            {
                // cout<<key<<' ';
                ++answer;
            }
        }
    }

    
    while(true)
    {
        unordered_map<string,int> um;
        bool updated =false;
        
        for(auto& n:nodes)
        {
            if(n.poss.size()-1 == n.pptr)
            {
                continue;
            }
            updated =true;
            
            int& destrow = n.poss[n.pptr+1].row ;
            int& currow = n.poss[n.pptr].row;
            int& destcol = n.poss[n.pptr+1].col;
            int& curcol = n.poss[n.pptr].col;
            
            auto rowdiff = destrow - currow;
            auto coldiff = destcol -curcol ;
            
            if(0 == rowdiff)
            {
                if(0 < coldiff)
                {
                    ++curcol;
                }
                else
                {
                    --curcol;
                }
            }
            else
            {
                if(0 < rowdiff)
                {
                    ++currow;
                }
                else
                {
                    --currow;
                }
            }
            if(destrow == currow && destcol == curcol)
            {
                ++n.pptr;
            }
            
            string key = to_string(currow) + ','+to_string(curcol);
            ++um[key];
            if(2 == um[key])
            {
                // cout<<key<<' ';
                ++answer;
            }
        }
        // cout<<'\n';
        
        if(false ==updated)
        {
            break;
        }
    }
    
    
    return answer;
}