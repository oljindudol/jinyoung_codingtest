#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_set>
#include <set>

using namespace std;

int numIslands(vector<vector<char>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<set<pair<int, int>>> vset;

    if (1 == row && 1 == col)
    {
        return grid[0][0] - '0';
    }

    //1.물이면 스킵
    //2.이어져있는지 확인
    //2-1.이어져있으면 해당 set에 넣기
    //2-2.이어져있지않으면 새로운 set생성후 push

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            //물인지 확인
            if ('0' == grid[i][j])
            {
                continue;
            }
            bool connected = false;

            if (0 != i)
            {
                //이어져있는지 확인1
                for (auto& s : vset)
                {
                    auto iter = s.find({ i - 1,j });
                    if (s.end() != iter)
                    {
                        s.insert({ i,j });
                        connected = true;
                    }
                    else
                    {
                        continue;
                    }
                }
                //1 이어져있었다면 continue;
                if (true == connected)
                {
                    continue;
                }
            }


            if (0 != j)
            {
                //이어져있는지 확인2
                for (auto& s : vset)
                {
                    auto iter = s.find({ i,j - 1 });
                    if (s.end() != iter)
                    {
                        s.insert({ i,j });
                        connected = true;
                    }
                    else
                    {
                        continue;
                    }
                }
                //2 이어져있었다면 continue;
                if (true == connected)
                {
                    continue;
                }
            }

            //이어지지 않았다면, 새 set을 만들고 push
            set<pair<int, int>> newset;
            newset.insert({ i,j });
            vset.push_back(newset);
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

    vector<char> vc1{ '1', '1', '1' };
    vector<char> vc2{ '0', '1', '0' };
    vector<char> vc3{ '1', '1', '1' };
    input.push_back(vc1);
    input.push_back(vc2);
    input.push_back(vc3);
    //input.push_back(vc4);

    numIslands(input);

    return 0;

}