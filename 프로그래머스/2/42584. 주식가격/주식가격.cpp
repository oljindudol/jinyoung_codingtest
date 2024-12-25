#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    int sz = prices.size();
    vector<int> answer(sz);
    
    for(int i = 0; i<sz; ++i)
    {
        int j = 1;
        // cout<< i <<' '<<(i+j+1)<<' '<< prices[i]<< prices[i+j+1]<<  '\n';
        while((i+j+1) < sz&& prices[i+j] >= prices[i])
        {
            ++j;
        }
        answer[i] = j;
    }
    answer[sz-1] = 0;
    
    return answer;
}