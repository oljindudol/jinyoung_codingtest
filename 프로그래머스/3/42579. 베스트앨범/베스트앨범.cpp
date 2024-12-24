#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
struct music
{
    int idx;
    string genre;
    int plays;
    int sp;
};

bool cmp(const music& a,const music& b)
{
    if(a.sp == b.sp)
    {
        if(a.plays == b.plays)
        {
            return a.idx<b.idx;
        }
        return a.plays>b.plays;
    }
    return a.sp>b.sp;
}

// struct g
// {
//     int genre;
//     int plays;
// }

// bool gcmp(const g& a,const g& b)
// {
//     return 
// }


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string,int> um;
    int sz = genres.size();
    vector<music> vm(sz);
    
    for(int i =0 ; i < sz;++i)
    {
        vm[i].idx = i;
        vm[i].genre = genres[i];
        vm[i].plays = plays[i];
        
        um[genres[i]]+= plays[i];
    }
    
    for(auto& e: vm)
    {
       e.sp = um[e.genre];
    }
    
    string prev = "";
    int cnt = 0;
    
    sort(vm.begin(),vm.end(),cmp);
    for(const auto& e: vm)
    {
        if(2 == cnt)
        {
            if(prev != e.genre)
            {
                prev = e.genre;
                cnt = 1;
                answer.push_back(e.idx);
            }
            continue;
        }
        
        if(prev == e.genre)
        {
            ++cnt;
            answer.push_back(e.idx);
            prev = e.genre;
        }
        else
        {
            cnt = 1;
            answer.push_back(e.idx);
            prev = e.genre;
        }
    }
    
    
    return answer;
}