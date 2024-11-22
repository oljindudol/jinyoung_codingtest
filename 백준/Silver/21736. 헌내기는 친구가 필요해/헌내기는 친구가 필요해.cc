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
int maxrow, maxcol;
vector<vector<char>> map;
int drow[4] = { 1,-1,0,0 };
int dcol[4] = { 0,0,1,-1 };
int ret = 0;

bool IsVaild(int row, int col)
{
	if (0 > row || maxrow <= row)
	{
		return false;
	}

	if (0 > col || maxcol <= col)
	{
		return false;
	}

	if ('X' == map[row][col])
	{
		return false;
	}

	return true;
}

void dfs(int row, int col)
{
	if ('P' == map[row][col])
	{
		++ret;
	}
	map[row][col] = 'X';

	for (int i = 0; i < 4; ++i)
	{
		int newrow = row + drow[i];
		int newcol = col + dcol[i];
		if (true == IsVaild(newrow, newcol))
		{
			dfs(newrow, newcol);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> maxrow >> maxcol;
	int dorow;
	int docol;

	map.resize(maxrow, vector<char>(maxcol));

	for (int row = 0; row < maxrow; ++row)
	{
		for (int col = 0; col < maxcol; ++col)
		{
			cin >> map[row][col];
			if ('I' == map[row][col])
			{
				dorow = row;
				docol = col;
				map[row][col] = 'X';
			}
		}
	}

	dfs(dorow, docol);

	if (0 == ret)
	{
		cout << "TT";
	}
	else
	{
		cout << ret;
	}


	return 0;
}