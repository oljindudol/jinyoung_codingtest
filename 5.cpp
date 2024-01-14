#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;




using namespace std;
struct pair_hash {
    inline std::size_t operator()(const std::pair<int, int>& v) const {
        return v.first * 31 + v.second;
    }
};


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    unordered_set< pair<int, int>, pair_hash> us;

    while (true)
    {
        for (int i = 0; i < (m - 1); ++i)
        {
            for (int j = 0; j < (n - 1); ++j)
            {
                char& c = board[i][j];
                if ('X' == c)
                {
                    continue;
                }
                else if (
                    c == board[i + 1][j] &&
                    c == board[i][j + 1] &&
                    c == board[i + 1][j + 1])
                {
                    us.insert({ i,j });
                    us.insert({ i + 1,j });
                    us.insert({ i,j + 1 });
                    us.insert({ i + 1,j + 1 });
                }
            }
        }
        int sz = us.size();
        answer += sz;

        if (0 == sz)
        {
            break;
        }

        //����� �����.
        for (auto& p : us)
        {
            board[p.first][p.second] = 'X';
        }

        //�������� ���� ����� ������.
        // 1.������ X���ƴ� ����� ����.
        vector<string> vs(n, "");

        for (int j = 0; j < n; ++j)
        {
            for (int i = 0; i < m; ++i)
            {
                if ('X' != board[i][j])
                {
                    vs[j] += board[i][j];
                }
            }
        }
        // 2. ��ϵ� �Ʒ��� �����ְ� ��ĭ��Xġ��
        for (int j = 0; j < n; ++j)
        {
            //��ϵ� �Ʒ��� �����ֱ�
            for (int i = 0; i < vs[j].size(); ++i)
            {
                board[board.size()-1 - i][j] = vs[j][i];
            }

            for (int i = vs[j].size(); i < m; ++i)
            {
                board[board.size() - 1 -i][j] = 'X';
            }
        }


        //set Ŭ����
        us.clear();
    }

    return answer;
}

int main()
{
    vector<string> vs = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
    solution(4,5,vs);

    return 0;
}