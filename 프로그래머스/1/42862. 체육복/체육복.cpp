#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int lostcnt = lost.size();
    vector<int> spare(n+1);
    vector<int> losts(n+1);
    
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    
    
    for(const auto& e: reserve)
    {
        spare[e] = 1;
    }
    for(const auto& e: lost)
    {
        losts[e] = 1;
    }
    // for(const auto& e: lost)
    // {
    //     if(1 == spare[e])
    //     {
    //         --lostcnt;
    //         spare[e]=0;
    //     }
    // }
    
    for(const auto& e: lost)
    {
        if(1==spare[e])
        {
            --lostcnt;
            spare[e] = 0;
            continue;
        }
        if(1==spare[e-1] && 0 == losts[e-1])
        {
            --lostcnt;
            spare[e-1] = 0;
            continue;
        }
        if(1==spare[e+1]&& 0 == losts[e+1])
        {
            --lostcnt;
            spare[e+1] = 0;
        }
        // if(1== spare[e-1])
        // {
        //     --lostcnt;
        //     spare[e-1] = 0;
        //     continue;
        // }
        // if(1== spare[e+1])
        // {
        //     --lostcnt;
        //     spare[e+1] = 0;
        // }
    }
    
    answer = n-lostcnt;
    return answer;
}