#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    if(2 > arr.size())
    {
        cout << arr.size() << endl;
        return arr;
    }
    
    answer.push_back(arr[0]);
    int prev= arr[0];
    
    for(size_t i = 1; i < arr.size(); ++i)
    {
        if(prev != arr[i])
        {
            answer.push_back(arr[i]);
        }
        prev = arr[i];
    }
    


    return answer;
}