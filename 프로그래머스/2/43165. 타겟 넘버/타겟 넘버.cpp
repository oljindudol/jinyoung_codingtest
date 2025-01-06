#include <string>
#include <vector>

using namespace std;
int ret = 0;
int sz;
int t ;
void dfs(int depth,int val,const vector<int>& numbers)
{
    if(sz == depth )
    {
        if(t == val)
        {
            ++ret;
        }
        return;
    }
    
    dfs(depth+1, val + numbers[depth],numbers);
    dfs(depth+1, val - numbers[depth],numbers);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    sz = numbers.size();
    t= target;
    
    dfs(0,0,numbers);
    
    return ret;
}