#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int sz = wallpaper.size();
    int strsz = wallpaper[0].size();
    
    int left = 50;
    int right = 0;
    int top = 50;
    int bottom = 0;
    
    for(int i = 0 ; i < sz ; ++i)
    {
        for(int j = 0 ; j<strsz ; ++j)
        {
            if('#' == wallpaper[i][j])
            {
                left = min(left,j);
                right = max(right,j);
                top = min(top,i);
                bottom = max (bottom,i);
            }
        }
    }
    
    ++right;
    ++bottom;
    
    answer.push_back(top);
    answer.push_back(left);
    answer.push_back(bottom);
    answer.push_back(right);
    
    return answer;
}