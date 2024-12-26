#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct node
{
    int val;
    int id;
};

struct cmptop
{
    bool operator()(const node& a,const node& b)
    {
        return a.val<b.val;
    }
};

struct cmpbot
{
    bool operator()(const node& a,const node& b)
    {
        return a.val>b.val;
    }
};

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int sz = operations.size();
    vector<bool> IsDeleted;
    int id = 0;
    priority_queue<node,vector<node>,cmptop> pqtop;
    priority_queue<node,vector<node>,cmpbot> pqbot;
    string cop;
    int val;
    for(const auto& op : operations)
    {
        cop = op.substr(0,1);
        val = stoi(op.substr(2));
        
        if("I" == cop)
        {
            pqtop.push({ val,id});
            pqbot.push({ val,id});
            IsDeleted.push_back(false);
            ++id;
        }
        else
        {
            if(1 == val)
            {
                while(false==pqtop.empty() && true == IsDeleted[pqtop.top().id] )
                {
                    pqtop.pop();
                }
                
                if(false==pqtop.empty())
                {
                    auto cur = pqtop.top();
                    pqtop.pop();
                    IsDeleted[cur.id] = true;
                }
            }
            else
            {
                while(false==pqbot.empty() && true == IsDeleted[pqbot.top().id] )
                {
                    pqbot.pop();
                }
                
                if(false==pqbot.empty())
                {
                    auto cur = pqbot.top();
                    pqbot.pop();
                    IsDeleted[cur.id] = true;
                }
            }
        }
    }
    
    while(false==pqtop.empty() && true == IsDeleted[pqtop.top().id] )
    {
        pqtop.pop();
    }
                
    if(false==pqtop.empty())
    {
        auto cur = pqtop.top();
        pqtop.pop();
        // IsDeleted[cur.id] = true;
        answer.push_back(cur.val);
    }
    
    while(false==pqbot.empty() && true == IsDeleted[pqbot.top().id] )
    {
        pqbot.pop();
    }
    
    if(false==pqbot.empty())
    {
        auto cur = pqbot.top();
        pqbot.pop();
        IsDeleted[cur.id] = true;
        answer.push_back(cur.val);
    }
    
    while(2>answer.size())
    {
        answer.push_back(0);
    }
    
    
    return answer;
}