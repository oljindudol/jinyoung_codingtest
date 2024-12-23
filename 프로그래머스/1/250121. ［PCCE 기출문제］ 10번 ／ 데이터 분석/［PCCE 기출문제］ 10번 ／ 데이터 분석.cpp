#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// template <T>
// bool cmp(const vector<int>& a,const vector<int>& b)
// {
//     return a[T] < b[T];
// }

bool cmp0(const vector<int>& a,const vector<int>& b)
{
    return a[0] < b[0];
}

bool cmp1(const vector<int>& a,const vector<int>& b)
{
    return a[1] < b[1];
}

bool cmp2(const vector<int>& a,const vector<int>& b)
{
    return a[2] < b[2];
}

bool cmp3(const vector<int>& a,const vector<int>& b)
{
    return a[3] < b[3];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    vector<string> cols = {"code","date","maximum","remain"};
    int extidx, sortidx;
    for(int i =0 ; i <cols.size(); ++i)
    {
        if(ext ==cols[i])
        {
            extidx = i;
        }
        if(sort_by ==cols[i])
        {
            sortidx = i;
        }
    }
    
    for(const auto& e:data)
    {
        if(e[extidx] < val_ext)
        {
            answer.push_back(e);
        }
    }
    
    if(0 == sortidx)
    {
        sort(answer.begin(),answer.end() ,cmp0);
    }
    else if(1 == sortidx)
    {
        sort(answer.begin(),answer.end() ,cmp1);
    }
    else if(2 == sortidx)
    {
        sort(answer.begin(),answer.end() ,cmp2);
    }
    else
    {
        sort(answer.begin(),answer.end() ,cmp3);
    }
    
    
    return answer;
}