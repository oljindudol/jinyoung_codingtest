#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    int sz = cards.size();
    
    vector<bool> visited(sz,false);
    vector<int> groupcnt;
    
    for(int i = 0 ; i < sz;++i)
    {
        int target = i;
        int cnt =0;
        while(false == visited[target])
        {
            visited[target]=true;
            target=cards[target]-1;
            ++cnt;
        }
        // if(0!= cnt)
        // {
            groupcnt.push_back(cnt);
        // }
    }
    
    sort(groupcnt.begin(),groupcnt.end(),greater<int>());
    
    // for(auto& e:groupcnt)
    // {
    //     cout<<e<<endl;
    // }
    
    answer = groupcnt[0]*groupcnt[1];
    
    
    
    return answer;
}