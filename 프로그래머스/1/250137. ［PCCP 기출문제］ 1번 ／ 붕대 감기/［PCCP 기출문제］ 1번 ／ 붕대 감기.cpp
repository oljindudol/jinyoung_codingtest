#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    
    int dur = bandage[0];
    int hps = bandage[1];
    int addh = bandage[2];
    
    
    int prevatt = 0;
    for(const auto& att : attacks)
    {
        int sec = att[0];
        int power = att[1];
        
        int inter = sec-prevatt-1;
        int scnt = inter/dur;
        // cout<< answer<<' ';
        answer = min(health,answer+inter*hps + scnt* addh );
        // cout<< answer<<' ';
        answer -= power;
        // cout<< answer<<'\n';
        if(0>= answer)
        {
            return -1;
        }
        
        prevatt = sec;
    }
    
    
    return answer;
}