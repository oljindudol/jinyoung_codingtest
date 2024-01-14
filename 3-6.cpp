#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_set>
#include <set>

using namespace std;

set<pair<int, int>>* eat(int row, int col, int maxrow, int maxcol, int depth,
    set<pair<int, int>>& s, vector<set<pair<int, int>>>& vset, vector<vector<char>>& grid)
{
    if (0 == depth)
    {
        s.insert({ row,col });
        set<pair<int, int>>* a = nullptr;
        set<pair<int, int>>* b = nullptr;


        if (maxrow != (row + 1))
        {
            a = eat(row + 1, col, maxrow, maxcol, depth + 1, s, vset, grid);
        }
        if (maxcol != (col + 1))
        {
            b = eat(row, col + 1, maxrow, maxcol, depth + 1, s, vset, grid);
        }
        if (nullptr != a)
        {
            for (auto& p : s)
            {
                a->insert(p);
                return nullptr;
            }
        }
        if (nullptr != b)
        {
            for (auto& p : s)
            {
                b->insert(p);
                return nullptr;
            }
        }
        //이어져 있지않으면 vset에넣기
        vset.push_back(s);
        return nullptr;
    }

    if (0 != depth)
    {
        //1.물이면 return
        //2.이어져있는지 확인
        //3.이어져있지않으면 s에 push 후 탐색
        if ('0' == grid[row][col])
            return nullptr;

        set<pair<int, int>>* c = nullptr;
        for (auto& s : vset)
        {
            auto iter = s.find({ row,col });
            if (s.end() != iter)
            {
                c = &s;
                break;
            }
        }

        //이어져있지않으면 set에 pair 저장
        if (nullptr == c)
        {
            s.insert({ row,col });
        }

        set<pair<int, int>>* a = nullptr;
        set<pair<int, int>>* b = nullptr;
        if (maxrow != (row + 1)
            && nullptr == c)
        {
            a = eat(row + 1, col, maxrow, maxcol, depth + 1, s, vset, grid);
        }
        if (maxcol != (col + 1))
        {
            b = eat(row, col + 1, maxrow, maxcol, depth + 1, s, vset, grid);
        }

        if (nullptr != a)
            return a;
        if (nullptr != b)
            return b;
        return c;

    }
    return nullptr;
}


int numIslands(vector<vector<char>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<set<pair<int, int>>> vset;

    if (1 == row && 1 == col)
    {
        return grid[0][0] - '0';
    }



    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            //물인지 확인
            if ('0' == grid[i][j])
            {
                continue;
            }
            if (i== 1 && j ==3)
                int a = 0;
            set<pair<int, int>>* c = nullptr;
            for (auto& s : vset)
            {
                auto iter = s.find({ i,j });
                if (s.end() != iter)
                {
                    c = &s;
                    break;
                }
            }

            //이어져있다면
            if (nullptr != c)
            {
                continue;
            }
            else
            {
                //이어지지 않았다면, 탐색시작
                set<pair<int, int>> newset;
                eat(i, j, row, col, 0, newset, vset, grid);
            }


        }
    }

    return vset.size();
}

int main()
{
    vector<vector<char>> input;
     //vector<char> vc1{ '1', '1', '1', '1', '0' };
     //vector<char> vc2{ '1', '1', '0', '1', '0' };
     //vector<char> vc3{ '1', '1', '0', '0', '0' };
     //vector<char> vc4{ '0', '0', '0', '0', '0' };

     vector<char> vc1{ '1', '0', '1', '1', '1' };
     vector<char> vc2{ '1', '0', '1', '0', '1' };
     vector<char> vc3{ '1', '1', '1', '0', '1' };
     input.push_back(vc1);
     input.push_back(vc2);
     input.push_back(vc3);
     //input.push_back(vc4);

    numIslands(input);

    return 0;

}