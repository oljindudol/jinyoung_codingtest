#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(auto& st:skill_trees)
    {
        int point=0;
        
        bool able = true;
        
        for(auto& e:st)
        {
            bool isexist = false;
            //skill에 있는지검사
            for(auto& t:skill)
            {
                if(e==t)
                {
                    isexist = true;
                    break;
                }
            }
            
            if(true == isexist)
            {
                //있다면 point까지 왔는지 검사
                if( point<skill.size() && e == skill[point])
                {
                    ++point;
                }
                else
                {
                    able=false;
                    break;
                }
            }
        }
        if(true == able)
        {
            ++answer;
        }
    }

    return answer;
}