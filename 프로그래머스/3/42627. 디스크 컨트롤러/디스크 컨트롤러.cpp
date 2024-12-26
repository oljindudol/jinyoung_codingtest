#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int curtime=0;

struct node
{
    int idx;
    int rqtime;
    int duration;
};

bool cmp2(const vector<int>& a,const vector<int>& b)
{
    return a[0]<b[0];
}

struct cmp
{
    bool operator()(const node& a,const node& b)
    {
        if(a.duration == b.duration)
        {
            if(a.rqtime == b.rqtime)
            {
                return a.idx>b.idx;
            }
            return a.rqtime > b.rqtime;
        }
        return a.duration> b.duration;
    }

};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int sz = jobs.size();
    
    sort(jobs.begin(),jobs.end(),cmp2);
    
    priority_queue<node,vector<node>,cmp> pq;
    int i = 0 ;

    
    int curtime = 0;
    int sum = 0;
    while(false == pq.empty() || i<sz)
    {
        for(; i < sz;)
        {
            if(jobs[i][0] <= curtime)
            {
                pq.push({i, jobs[i][0],jobs[i][1]});
                ++i;
            }
            else if(true == pq.empty())
            {
                pq.push({i, jobs[i][0],jobs[i][1]});
                curtime = jobs[i][0];
                ++i;
            }
            else
            {
                break;
            }
        }
        
        auto cur = pq.top();
        pq.pop();
        
        curtime = max(cur.rqtime,curtime);
        curtime += cur.duration;
        sum += curtime - cur.rqtime;
    }
    
    answer = sum/sz;
    return answer;
}