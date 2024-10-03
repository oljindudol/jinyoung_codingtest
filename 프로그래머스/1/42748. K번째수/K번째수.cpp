#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    
    for(auto& e: commands)
    {
        vector<int> vec;
        for(int i= e[0]-1 ; i<e[1];++i)
        {
            vec.push_back(array[i]);
        }
        sort(vec.begin(),vec.end());
        
        answer.push_back(vec[e[2]-1]);
    }
    
    return answer;
}