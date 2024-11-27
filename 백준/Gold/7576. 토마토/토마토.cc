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
int row, col;
int drow[4] = { 1,-1 ,0,0 };
int dcol[4] = { 0,0,1,-1 };
int maxrow, maxcol, maxheight;
vector<vector<int>> map;

bool IsValid(int row, int col)
{
	if (0 > row || maxrow <= row)
	{
		return false;
	}

	if (0 > col || maxcol <= col)
	{
		return false;
	}

	if (0 != map[row][col])
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

	cin >> maxcol >> maxrow;
	map.resize(maxrow, vector<int>(maxcol));

	queue<node> q;
	for (int row = 0; row < maxrow; ++row)
	{
		for (int col = 0; col < maxcol; ++col)
		{
			cin >> map[row][col];
			if (1 == map[row][col])
			{
				q.push({ row,col,1 });
			}
		}
	}

	int ret = 1;

	while (false == q.empty())
	{
		auto cur = q.front();
		q.pop();
		ret = max(ret, cur.depth);

		for (int i = 0; i < 4; ++i)
		{
			int nrow = cur.row + drow[i];
			int ncol = cur.col + dcol[i];

			if (true == IsValid(nrow, ncol))
			{
				map[nrow][ncol] = cur.depth + 1;
				q.push({ nrow,ncol,cur.depth + 1 });
			}
		}
	}


	for (const auto& row : map)
	{
		for (const auto& col : row)
		{
			if (0 == col)
			{
				cout << -1;
				return 0;
			}
		}
	}


	cout << ret - 1;
	return 0;
}