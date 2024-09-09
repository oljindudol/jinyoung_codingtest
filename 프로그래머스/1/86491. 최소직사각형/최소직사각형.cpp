#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int h=0;
    int w=0;
    
    for(auto& e: sizes)
    {
        h = max(h,max(e[0],e[1]));
        w = max(w,min(e[0],e[1]));
    }
    return h*w;
}