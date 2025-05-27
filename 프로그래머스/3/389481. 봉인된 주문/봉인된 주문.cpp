#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<long long> nums;
//aa : 26 + 1
//ab : 26 + 2
//az : 26  + 26
//ba : 2*26 + 1
//aaa:  1*26*26 +1*26 + 1

long long getnum(const string& str)
{
    int sz = str.size();
    
    long long ret = 0 ;
    for(int i = sz-1; i>=0;--i)
    {
        ret = ret + nums[i]* ( str[sz-i-1] - 'a' +1);
    }
    return ret;
}

string getstr(long long num)
{
    string ret = "";
    int div = 11;
    while(num>0)
    {
        --num;
        char c= 'a' + (num%26);
        ret +=c;
        num /=26;
        // long long mok = num / nums[div];
        // if(0 != mok)
        // {
        //     char ad ;
        //     int mod = num%nums[div];
        //     num = mod;
        //     ad = 'a' + (mok-1);
        //     ret.push_back(ad);
        // }
        // --div;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    
    nums.resize(12);
    nums[0] = 1;
    for(int i = 1 ; i< 12;++i)
    {
        nums[i] = nums[i-1]*26;
    }
    
    vector<long long> bannums;
    
    for(const auto& e: bans)
    {
        bannums.push_back(getnum(e));
    }
    
    sort(bannums.begin(),bannums.end());
    
    // cout<<getnum("az");
    // cout<<getstr(getnum("aazaazaa"));
    for(const auto& e: bannums)
    {
        if(e<=n)
        {
            // cout<<"e:"<<e<<',';
            ++n;
        }
        else
        {
            break;
        }
        // cout<<n<<'\n';
    }
    
    answer = getstr(n);
    return answer;
}