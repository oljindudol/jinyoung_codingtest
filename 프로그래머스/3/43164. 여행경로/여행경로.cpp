#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
int sz;

struct node
{
    string to;
    bool visited;
};

bool cmp(const node& a,const node& b)
{
    return a.to<b.to;
}
vector<string> retpath;
unordered_map<string,vector<node>> um;

void dfs(int depth,vector<string>& path)
{
    if(sz == depth)
    {
        retpath = path;
        throw exception();
    }
    for(auto & e: um[path.back()])
    {
        if(false == e.visited)
        {
            e.visited = true;
            path.push_back(e.to);
            dfs(depth+1,path);
            path.pop_back();
            e.visited = false;
        }
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sz = tickets.size();
    
    for(const auto& e: tickets)
    {
        um[e[0]].push_back({e[1],false});
    }
    
    for(auto& e: um)
    {
        sort(e.second.begin(),e.second.end(),cmp);
        // for(const auto& d: e.second)
        // {
        //     cout<< e.first<<' '<<d.to<<' ';
        // }
        // cout<<'\n';
    }
    vector<string> path;
    path.push_back("ICN");
    try
    {
        dfs(0,path);
    }
    catch(exception& e)
    {
    }
    
    return retpath;
}