#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <ostream>
#include <stack>
#include <unordered_set>
#include <sstream>
#include <list>
#include <thread>
#include <omp.h>
#include <mutex>

using namespace std;

template <typename T>
void PrintVec(const vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
	}
	cout << '\n';
}


template <typename T>
void PrintVec(const vector<vector<T>>& vec)
{
	for (const auto& e1 : vec)
	{
		for (const auto& e2 : e1)
		{
			cout << e2 << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

/////////////////////////////////////////////
int n, m;
vector<vector<int>> map;

int drow[4] = { 1,-1,0,0 };
int dcol[4] = { 0,0,1,-1 };

bool IsValid(int row, int col)
{
	if (0 > row || n <= row)
	{
		return false;
	}
	if (0 > col || m <= col)
	{
		return false;
	}
	if (1 == map[row][col])
	{
		return false;
	}
	return true;
}

bool IsValid2(int row, int col)
{
	if (0 > row || n <= row)
	{
		return false;
	}
	if (0 > col || m <= col)
	{
		return false;
	}
	if (3 != map[row][col])
	{
		return false;
	}
	return true;
}

struct pos
{
	int row;
	int col;
};

void polution()
{
	//외부공기
	queue<pos> q;
	vector<vector<int>> visited(n, vector<int>(m));
	q.push({ 0,0 });
	q.push({ n - 1,0 });
	q.push({ 0,m - 1 });
	q.push({ n - 1,m - 1 });
	visited[0][0] = 1;
	visited[n - 1][0] = 1;
	visited[0][m - 1] = 1;
	visited[n - 1][m - 1] = 1;
	while (false == q.empty())
	{
		auto cur = q.front();
		q.pop();
		map[cur.row][cur.col] = 3;

		for (int i = 0; i < 4; ++i)
		{
			int nrow = cur.row + drow[i];
			int ncol = cur.col + dcol[i];

			if (true == IsValid(nrow, ncol) && 0 == visited[nrow][ncol])
			{
				visited[nrow][ncol] = 1;
				q.push({ nrow,ncol });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	map.resize(n, vector<int>(m));
	int ccnt = 0;

	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			cin >> map[row][col];
			if (1 == map[row][col])
			{
				++ccnt;
			}
		}
	}

	polution();
	int ret = 0;
	while (0 < ccnt)
	{
		for (int row = 0; row < n; ++row)
		{
			for (int col = 0; col < m; ++col)
			{
				if (1 == map[row][col])
				{
					int cnt = 0;

					for (int i = 0; i < 4; ++i)
					{
						int nrow = row + drow[i];
						int ncol = col + dcol[i];
						if (true == IsValid2(nrow, ncol))
						{
							++cnt;
						}
					}
					if (1 < cnt)
					{
						map[row][col] = 0;
						--ccnt;
					}
				}
			}
		}
		polution();
		//PrintVec(map);
		ret++;
	}

	cout << ret;
	return 0;
}
