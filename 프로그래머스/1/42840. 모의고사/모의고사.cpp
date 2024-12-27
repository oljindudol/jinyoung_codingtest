#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> numss(3);
    vector<int> sols(3,0);
    numss[0] = { 1,2,3,4,5};
    numss[1] = {2,1,2,3,2,4,2,5};
    numss[2] = {3,3,1,1,2,2,4,4,5,5};
    
    for(int i = 0 ; i < answers.size();++i)
    {
        for(int j =0 ; j < 3; ++j)
        {
            if(answers[i] ==numss[j][i%numss[j].size()])
            {
                ++sols[j];
            }
        }
    }
    
    int maxsol = *max_element(sols.begin(),sols.end()); 
    
    for(int i =0 ; i <3;++i)
    {
        if(maxsol == sols[i])
        {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}