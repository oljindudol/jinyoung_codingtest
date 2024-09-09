#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    
    for(auto iter1 =lost.begin(); iter1<lost.end();)
    {
        bool dirty =false;
        for(auto iter2 = reserve.begin();iter2<reserve.end();)
        {
            if(*iter1 ==*iter2)
            {
                iter1 = lost.erase(iter1);
                iter2 = reserve.erase(iter2);
            }
            else
            {
                ++iter2;
            }
        }
        if(false == dirty)
            ++iter1;
    }
    
    int answer = n-lost.size();
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    
    int pnt = 0;
    for(int i =0;i<lost.size();++i)
    {
        
        for(int j=pnt;j<reserve.size();++j)
        {
            if(lost[i]+1<reserve[j])
            {
                break;
            }
            if(2 > abs(lost[i]-reserve[j]))
            {
                pnt =j+1;
                ++answer;
                break;
            }
        }
    }
    
    
    return answer;
}