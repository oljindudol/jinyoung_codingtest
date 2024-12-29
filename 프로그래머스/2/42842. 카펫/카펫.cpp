#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int newbrown = brown +4;
    
    for(int row=3; row<2000;++row)
    {
        for(int col =row;col<2000;++col)
        {
            if(newbrown == 2*row+2*col)
            {
                if(yellow == ((row-2)*(col-2)))
                {
                    answer.push_back(col);
                    answer.push_back(row);
                    return answer;
                }
            }
        }
    }
    
    return answer;
}