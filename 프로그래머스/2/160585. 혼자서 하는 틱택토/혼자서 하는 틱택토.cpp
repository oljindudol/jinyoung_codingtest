#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool IsWin(vector<string>& _b , const char& _c)
{
    //가로판단
    for(int i=0; i<3;++i)
    {
        if(_c == _b[i][0] && _c == _b[i][1] &&_c == _b[i][2])
        {
            // cout<<i<<"가로"<<endl;
            return true;
        }
    }
    //세로판단
    for(int i=0; i<3;++i)
    {
        if(_c == _b[0][i] && _c == _b[1][i] &&_c == _b[2][i])
        {
            // cout<<"세로"<<i<<endl;
            return true;
        }
    }
    //사선1
    if(_c == _b[0][0] && _c == _b[1][1] && _c == _b[2][2])
        {
            // cout<<"사선1"<<endl;
            return true;
        }
    //사선2
    if(_c == _b[0][2] && _c == _b[1][1] && _c == _b[2][0])
        {
            // cout<<"사선2"<<endl;
            return true;
        }
    
    return false; 
}

int solution(vector<string> board) {
    int answer = 1;
    
    //나올 수 없는 경우
    //1. cnt(O) = cnt(x) 이거나 cnt(o)-1 = cnt(x)
    int cntO = 0;
    int cntX = 0;
    for(auto& s : board)
    {
        for(auto& e: s)
        {
            if('O'==e)
            {
                ++cntO;
            }
            if('X'==e)
            {
                ++cntX;
            }
        }
    }
    int diffcnt = cntO-cntX;
    
    if(false  ==(diffcnt == 1 ||diffcnt==0))
    {
        // cout<< "a"<<endl;
        return 0;
    }
    
    
    //2. 둘 다 승리한경우
    bool IsWinO = IsWin(board,'O');
    bool IsWinX = IsWin(board,'X');
    
    if(IsWinO && IsWinX)
    {
        // cout<< "b"<<endl;
        return 0;
    }
    
    //3. O가 승리했는데 cnt가 같은경우
    if(IsWinO && 0 == diffcnt)
        return 0;
    //4. X가 승리했는데 cnt가 1개차이인경우
    if(IsWinX && 1 == diffcnt)
        return 0;
    
    return answer;
}