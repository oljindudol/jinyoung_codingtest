#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct node
{
    char c;
    int pos;
};

// struct cmp()
// {
//     bool operator()(const node& a,const node& b)
//     {
//         if(a.c == b.c)
//         {
//             return a.pos>b.pos;
//         }
//         return a.c <b.c;
//     }
// }

string solution(string number, int k) {
    string answer = "";
    int sz= number.size();
    vector<bool> IsErased(sz);
    
    while(number.size()>0 && '0' == number[0])
    {
        number.erase(0);
        --k;
    }
    
    for(int left = 0;left<sz-1;++left)
    {
        if(number[left] < number[left+1])
        {
            int pos = left;
            char origin = number[left+1];
            while(k>0 && pos>=0 && number[pos] <origin )
            {
                // cout<<pos<<' ';
                if(false == IsErased[pos])
                {
                    IsErased[pos]= true;
                    --pos;
                    --k;
                }
                else
                {
                    --pos;
                }

            }
            if(0==k)
            {
                break;
            }
        }
    }
    
    for(int i =0 ; i <sz;++i)
    {
        if(false == IsErased[i])
        {
            answer += number[i];
        }
    }
    
    while(k>0)
    {
        answer.pop_back();
        --k;
    }
    
    if(0==answer.size())
    {
        answer= "0";
    }
    
    
    return answer;
}