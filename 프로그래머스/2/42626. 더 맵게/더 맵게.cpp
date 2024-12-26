#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i =0 ; i< scoville.size();++i)
    {
        pq.push(scoville[i]);
    }
    
    while(K>pq.top())
    {
        if(1==pq.size())
        {
            return -1;
        }
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        int c= a+b*2;
        pq.push(c);
        
        ++answer;
    }
    
    return answer;
}