#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

bool sortgen(pair<string,int>& p1, pair<string,int>& p2)
{
    return p1.second > p2.second;
}

bool sortplay(pair<int,int>& p1,pair<int,int>& p2)
{
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    //장르,총재생수
    unordered_map<string,int> umgenres;
    //장르, 고유번호,재생수
    unordered_map<string,vector<pair<int,int>>> uminfo;
    
    for(size_t i = 0 ; i < genres.size();++i)
    {
        umgenres[genres[i]] += plays[i];
        
        uminfo[genres[i]].push_back({i,plays[i]});
    }
    
    vector<pair<string,int>> vecgenres;
    for(auto& e: umgenres)
    {
        vecgenres.push_back({e.first,e.second});
    }
    
    sort(vecgenres.begin(),vecgenres.end(),sortgen);
    
    for(auto& e: uminfo)
    {
        sort(e.second.begin(),e.second.end(),sortplay);
    }
    
    
    for(auto& e : vecgenres)
    {
        
        answer.push_back( uminfo[e.first][0].first);
        
        if(1<uminfo[e.first].size())
            answer.push_back( uminfo[e.first][1].first);
            
    }
    
    return answer;
}