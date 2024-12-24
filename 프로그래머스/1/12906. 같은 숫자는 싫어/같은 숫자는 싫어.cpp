#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int prev =arr[0];
    answer.push_back(arr[0]);
    
    for(const auto& e : arr)
    {
        if(prev != e)
        {
            prev = e;
            answer.push_back(e);
        }
    }

    return answer;
}