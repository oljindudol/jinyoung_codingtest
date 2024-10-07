#include <string>
#include <vector>
#include <unordered_map>

using namespace std;





vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string,int> um;
    int psz = players.size();
    
    for(int i = 0; i < psz; ++i)
    {
        um[players[i]] = i;
    }
    
    for(auto& e : callings )
    {
        auto curplayer = e;
        int curplayeridx = um[curplayer];
        int nextplayeridx = curplayeridx-1;
        string nextplayer = players[nextplayeridx];
        
        //스왑
        players[curplayeridx] = players[nextplayeridx];
        players[nextplayeridx] = curplayer;
        
        //um동기화
        --um[curplayer];
        ++um[nextplayer];
    }
    
    
    
    return players;
}