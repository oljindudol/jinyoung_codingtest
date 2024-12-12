#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool IsPossible(long long level,const vector<int>& diffs,const vector<int>& times,const long long& limit )
{
    long long sum =0;
    long long prevtime =0;
    
    for(int i =0; i < times.size();++i)
    {
        sum += times[i];
        
        long long leveldiff = (long long)diffs[i] - level;
        if(leveldiff > 0)
        {
            sum += ((prevtime + times[i])*leveldiff);
        }
        
        if(limit <sum )
        {
            return false;
        }
        
        prevtime = times[i];
    }
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    long long left = 1;
    long long right = 100001;
    
    while(left<=right)
    {
        long long mid = left+(right-left)/2;
        auto res = IsPossible(mid , diffs,times,limit);
        if(true == res)
        {
            right =mid-1;
        }
        else
        {
            left =mid+1;
        }
    }
    
    return left;
}