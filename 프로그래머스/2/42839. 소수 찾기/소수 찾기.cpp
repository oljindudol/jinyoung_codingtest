#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

unordered_set<int> primes;
unordered_set<int> notprimes;
int sz;

void UpdatePrimes(int depth,string& chars)
{
    string str = chars.substr(0,depth);
    int num = stoi(str);
    if(primes.end() != primes.find(num))
    {
        return;
    }
    if(notprimes.end() !=  notprimes.find(num))
    {
        return;
    }
    
    int sq = sqrt(num);
    for(int i=2;i<=sq;++i)
    {
        if(0== num%i )
        {
            notprimes.insert(num);
            return;
        }
    }
    primes.insert(num);
}

void swap(char& a,char& b)
{
    char t = a;
    a = b;
    b = t;
}

void dfs(int depth,string& chars)
{
    if(0 != depth)
    {
        UpdatePrimes(depth,chars);
    }
    if(sz == depth)
    {
        return;
    }
    
    for(int i =depth;i<sz;++i)
    {
        swap(chars[depth],chars[i]);
        dfs(depth+1,chars);
        swap(chars[depth],chars[i]);
    }
}


int solution(string numbers) {
    int answer = 0;
    notprimes.insert(0);
    notprimes.insert(1);
    sz = numbers.size();
    
    dfs(0,numbers);
    
    answer = primes.size();
    return answer;
}