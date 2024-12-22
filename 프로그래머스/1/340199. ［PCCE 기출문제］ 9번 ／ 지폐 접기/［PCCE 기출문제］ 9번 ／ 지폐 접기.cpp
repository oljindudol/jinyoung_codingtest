#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int wl = max(wallet[0],wallet[1]);
    int ws = min(wallet[0],wallet[1]);
    
    int l = max(bill[0],bill[1]);
    int s = min(bill[0],bill[1]);
    
    
    while(l>wl || s>ws)
    {
        l/=2;
        
        int newl = max(l,s);
        int news = min(l,s);
        l=newl;
        s=news;
        ++answer;
    }
    
    
    return answer;
}