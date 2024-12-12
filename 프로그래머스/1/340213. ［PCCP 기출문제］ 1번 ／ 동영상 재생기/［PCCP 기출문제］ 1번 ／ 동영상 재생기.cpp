#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int ilen = stoi(video_len.substr(3,5)) +stoi(video_len)*60;
    int ipos = stoi(pos.substr(3,5)) +stoi(pos)*60;
    int iop_start = stoi(op_start.substr(3,5)) +stoi(op_start)*60;
    int iop_end = stoi(op_end.substr(3,5)) +stoi(op_end)*60;
    
            if(iop_start <=ipos && iop_end >= ipos)
        {
            ipos = iop_end;
        }
    for(const auto& cmd : commands)
    {
        if("prev" == cmd)
        {
            ipos = max(ipos-10,0);
        }
        if("next" == cmd)
        {
            ipos = min(ipos+10,ilen);
        }
        
        if(iop_start <=ipos && iop_end >= ipos)
        {
            ipos = iop_end;
        }
    }
    
    string h = to_string(ipos/60);
    while(2 !=h.size())
    {
        h = '0'+h;
    }
    
    string m = to_string(ipos%60);
    while(2 !=m.size())
    {
        m = '0'+m;
    }
    
    answer = h;
    answer += ':';
    answer += m;
    
    
    return answer;
}