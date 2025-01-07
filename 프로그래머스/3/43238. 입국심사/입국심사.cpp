#include <string>
#include <vector>
#include <iostream>

using namespace std;
long long maxn;

bool IsPossible(long long minuit,const vector<int>& times)
{
    long long sumcnt = 0;
    for(const auto& e: times)
    {
        sumcnt += (minuit/e);
        if(sumcnt >= maxn)
        {
            return true;
        }
    }
    return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 1e9;
    maxn = n;
    
    long long left = 0;
    long long right = 1e18;
    
    while(left<=right)
    {
        long long mid = left + (right-left)/2;
        bool res = IsPossible(mid,times);
        if(false == res)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
    
    // for(const auto& e: times)
    // {
    //    answer =  min(answer,right + (e- right%e) + e);
    // }
    
    return left;
}