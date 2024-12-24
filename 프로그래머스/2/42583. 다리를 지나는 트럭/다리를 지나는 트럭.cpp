#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct node
{
    int w;
    int age;
};

int r = 0;
int totalw = 0;
int totall = 0;
queue<node> q;
int maxage;
int sz;

void aging()
{
    queue<node> q2;
    
    while(false == q.empty())
    {
        auto cur = q.front();
        q.pop();
        ++cur.age;
        // cout<<cur.w<<' ';
        if(maxage >= cur.age)
        {
            q2.push(cur);
        }
        else
        {
            totalw-= cur.w;
            --totall;
        }
    }
    q = q2;
    // cout<<'\n';
}

void pushtruck(const vector<int>& tw,int weight)
{
    if(sz != r && weight>=totalw+tw[r] && maxage>totall )
    {
        q.push({tw[r],1});
        totalw += tw[r];
        ++r;
        ++totall;
    }
}


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    sz = truck_weights.size();
    maxage = bridge_length;
    
    while(!(sz == r && true == q.empty()))
    {
        // cout<<answer<<':';
        aging();
        pushtruck(truck_weights,weight);
        ++answer;
    }
    
    return answer;
}