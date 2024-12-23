#include <string>
#include <vector>

using namespace std;

int drow[4] = {1,-1,0,0};
int dcol[4] = {0,0,1,-1};

int r;
int c;

bool IsValid(int row,int col)
{
    if(0>row||r<=row)
    {
        return false;
    }
    if(0>col||c<=col)
    {
        return false;
    }
    return true;
    
}

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    r = board.size();
    c = board[0].size();
    
    for(int i =0 ; i<4;++i)
    {
        int nrow = h + drow[i];
        int ncol = w+dcol[i];
        
        if(true == IsValid(nrow,ncol) && board[h][w] == board[nrow][ncol])
        {
            ++answer;
        }
    }
    
    
    return answer;
}