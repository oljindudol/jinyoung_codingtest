#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int p1=0;
    int p2=0;
    int sz1= cards1.size();
    int sz2=cards2.size();
    
    for(size_t i = 0; i<goal.size();++i)
    {
        auto& rw = goal[i];
        if(p1<sz1 && rw  == cards1[p1])
        {
            ++p1;
            continue;
        }
        if(p2<sz2 && rw  == cards2[p2])
        {
            ++p2;
            continue;
        }
        answer ="No";
        break;
    }
    return answer;
}