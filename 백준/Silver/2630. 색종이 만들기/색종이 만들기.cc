#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
#include <string>
#include <stdio.h>
#include <unordered_map>

using namespace std;

template <typename T>
void PrintVec(const vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
	}
	cout << endl;
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
		cout << endl;
	}
	cout << endl;
}

int n;

#define WHITE 0
#define BLUE 1
#define ENDDFS 2
vector<int> colorcnt(ENDDFS, 0);
int dfs(int minrow, int maxrow, int mincol, int maxcol, const vector<vector<int>>& map)
{
	if (minrow + 1 == maxrow && mincol + 1 == maxcol)
	{
		return map[minrow][mincol];
	}

	int midrow = (minrow + maxrow) / 2;
	int midcol = (mincol + maxcol) / 2;

	int r[4];

	r[0] = dfs(minrow, midrow, mincol, midcol, map);
	r[1] = dfs(midrow, maxrow, mincol, midcol, map);
	r[2] = dfs(minrow, midrow, midcol, maxcol, map);
	r[3] = dfs(midrow, maxrow, midcol, maxcol, map);

	if ((WHITE == r[0]) && (r[0] == r[1]) && (r[1] == r[2]) && (r[2] == r[3]))
	{
		return WHITE;
	}
	if ((BLUE == r[0]) && (r[0] == r[1]) && (r[1] == r[2]) && (r[2] == r[3]))
	{
		return BLUE;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (ENDDFS == r[i])
		{
			continue;
		}
		++colorcnt[r[i]];
	}
	return ENDDFS;
}
int main()
{
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));

	int tmp;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			cin >> tmp;
			map[row][col] = tmp;

		}
	}
	auto r = dfs(0, n, 0, n, map);
	if (ENDDFS != r)
	{
		++colorcnt[r];
	}

	cout << colorcnt[WHITE] << endl;
	cout << colorcnt[BLUE] << endl;

	return 0;
}