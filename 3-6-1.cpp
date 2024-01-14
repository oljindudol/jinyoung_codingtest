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

    //1.���̸� ��ŵ
    //2.�̾����ִ��� Ȯ��
    //2-1.�̾��������� �ش� set�� �ֱ�
    //2-2.�̾������������� ���ο� set������ push

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            //������ Ȯ��
            if ('0' == grid[i][j])
            {
                continue;
            }
            bool connected = false;

            if (0 != i)
            {
                //�̾����ִ��� Ȯ��1
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
                //1 �̾����־��ٸ� continue;
                if (true == connected)
                {
                    continue;
                }
            }


            if (0 != j)
            {
                //�̾����ִ��� Ȯ��2
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
                //2 �̾����־��ٸ� continue;
                if (true == connected)
                {
                    continue;
                }
            }

            //�̾����� �ʾҴٸ�, �� set�� ����� push
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