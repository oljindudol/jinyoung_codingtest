#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    int sz= score.size();
    sort(score.begin(),score.end(),greater<int>());
    int target = m-1;
    
    //0 1 2 3 // 4 5 6 7 //8
    while(target < sz)
    {
        answer+= (score[target]*m);
        target += m;
    }
    
    return answer;
}