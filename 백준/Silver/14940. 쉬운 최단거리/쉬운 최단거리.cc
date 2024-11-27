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
vector<vector<int>> visited;

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

	if (0 == map[row][col])
	{
		return false;
	}

	if (1 == visited[row][col])
	{
		return false;
	}
	return true;
}

struct node
{
	int row;
	int col;
	int depth;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	map.resize(n, vector<int>(m));
	visited.resize(n, vector<int>(m));

	int sr = -1;
	int sc = -1;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			cin >> map[row][col];

			if (2 == map[row][col])
			{
				sr = row;
				sc = col;
			}
		}
	}

	queue<node> q;
	q.push({ sr,sc,0 });
	visited[sr][sc] = 1;

	while (false == q.empty())
	{
		auto cur = q.front();
		q.pop();

		map[cur.row][cur.col] = cur.depth;

		for (int i = 0; i < 4; ++i)
		{
			int nrow = cur.row + drow[i];
			int ncol = cur.col + dcol[i];

			if (true == IsValid(nrow, ncol))
			{
				visited[nrow][ncol] = 1;
				q.push({ nrow, ncol, cur.depth + 1 });
			}
		}
	}

	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			if (0 == visited[row][col] && 1 == map[row][col])
			{
				cout << -1 << " ";
			}
			else
			{
				cout << map[row][col] << " ";
			}
		}
		cout << '\n';
	}

	return 0;
}