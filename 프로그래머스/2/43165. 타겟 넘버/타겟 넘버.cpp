#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
    int idx;
    int cursum;
    int leftsum;
};

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    sort(numbers.begin(),numbers.end(),greater<int>());
    int sum =0;
    int sz = numbers.size();
    
    for(auto& e: numbers)
    {
        sum += e;
    }
    
    queue<node> q;
    
    q.push({1,numbers[0],sum-numbers[0]});
    q.push({1,-numbers[0],sum-numbers[0]});
    
    while(false == q.empty())
    {
        auto curnode = q.front();
        q.pop();
        
        // 종료조건
        // targetnum인지 판단한다.
        if(sz == curnode.idx)
        {
            if(target == curnode.cursum)
            {
                ++answer;
            }
            continue;
        }
        // 가지치기
        // 현재 node기준으로 cursum이 target보다작으면 남은건다더해서 target보다 커질 수 있는지본다
        // 현재 node 기준으로 target보다 크면 남은걸 다 빼서 target보다 작아질 수 있는지 본다.
        if( curnode.cursum < target)
        {
            int tempsum = (curnode.cursum + curnode.leftsum);
            if( target < tempsum)
            {
                //아무것도 하지않는다
            }
            else if(target == tempsum)
            {
                //같아지면 남은걸다 더한경우밖에 답이없어서 그게정답
                ++answer;
                continue;
            }
            else
            {
                // 위 두조건에 해당안되면 가지치기
                continue;
            }
        }
        else
        {
            int tempsum = (curnode.cursum - curnode.leftsum);
            if( target > tempsum)
            {
                //아무것도 하지않는다
            }
            else if(target == tempsum)
            {
                //같아지면 남은걸다 더한경우밖에 답이없어서 그게정답
                ++answer;
                continue;
            }
            else
            {
                // 위 두조건에 해당안되면 가지치기
                continue;
            }
        }
        
        // q에넣기 현재노드기준으로 +-해준다
        q.push({curnode.idx+1,curnode.cursum + numbers[curnode.idx],curnode.leftsum-numbers[curnode.idx]});
        q.push({curnode.idx+1,curnode.cursum -numbers[curnode.idx],curnode.leftsum-numbers[curnode.idx]});
        
    }
    
    return answer;
}