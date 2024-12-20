#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    int curtime = h1*3600 + m1*60+s1;
    int targettime = h2*3600 + m2*60+s2;
    float prevh = 61.f;
    float prevm = 61.f;
    float prevsec = 61.f;
    
    
    for(int i = curtime; i<targettime+1; ++i)
    {
        float curh = float(i %43200)/720.f;
        float curm = float(i %3600)/60.f;
        float cursec = float(i % 60);
        
        // if(targettime-curtime < 40)
        // {
        //     cout<< prevh << " "<< curh<< " ";
        //     cout<< prevm << " "<<curm<< " ";
        //     cout<< prevsec << " "<<cursec;
        // }
        
        if(cursec == curh)
        {
            ++answer;
            prevh = curh;
            prevm = curm;
            prevsec =cursec;
            continue;
        }
        else if(cursec == curm)
        {
            ++answer;
            prevh = curh;
            prevm = curm;
            prevsec =cursec;
            continue;
        }
        if(61 == prevh)
        {
            prevh = curh;
            prevm = curm;
            prevsec =cursec;
            continue;
        }
        if(prevsec < prevh && (cursec > curh|| prevsec > cursec ) )
        {
            // cout<< prevh << " "<< curh<< " ";
            // cout<< prevm << " "<<curm<< " ";
            // cout<< prevsec << " "<<cursec;
            // cout<<'\n';
            ++answer;
        }
        if(prevsec < prevm && (cursec > curm|| prevsec > cursec) )
        {
            // cout<< prevh << " "<< curh<< " ";
            // cout<< prevm << " "<<curm<< " ";
            // cout<< prevsec << " "<<cursec;
            // cout<<'\n';
            ++answer;
        }
        
        
        prevh = curh;
        prevm = curm;
        prevsec =cursec;
    }
    
    return answer;
}