#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string,int> um;
    
    for(const auto& e :phone_book)
    {
        ++um[e];
    }
    
    for(const auto& e: phone_book)
    {
        for(int i = 0 ;i<e.size();++i)
        {
            auto str =  e.substr(0,i+1);
            // cout<<str<<' ';
            if(um.end() != um.find(str))
            {
                if(0 == um[str])
                {
                    return false;
                }
                --um[str];
            }
        }

    }
    
    return answer;
}