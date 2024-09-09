#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(auto& e : scoville)
    {
        pq.push(e);
    }
    
    while( 1 < pq.size() &&  K > pq.top())
    {
        
        int prev = pq.top();
        pq.pop();
        int preprev = pq.top();
        pq.pop();
        int newsc = prev + preprev*2;
        pq.push( newsc);
        ++answer;
    }
 
    
    if(K > pq.top())
        return -1;
    
    return answer;
}