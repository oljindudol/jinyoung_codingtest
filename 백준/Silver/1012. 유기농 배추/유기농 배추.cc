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


int n, m, k;

int drow[4] = { 1,-1,0,0 };
int dcol[4] = { 0,0,-1,1 };

bool IsValid(int row, int col, const vector<vector<int>>& map)
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
	return true;
}

void dfs(int row, int col, vector<vector<int>>& map)
{

	for (int i = 0; i < 4; ++i)
	{
		int newrow = row + drow[i];
		int newcol = col + dcol[i];
		if (true == IsValid(newrow, newcol, map))
		{
			map[newrow][newcol] = 0;
			dfs(newrow, newcol, map);
		}
	}
}

int main()
{
	int tcnt;
	cin >> tcnt;

	int trow, tcol;
	for (int i = 0; i < tcnt; ++i)
	{
		cin >> n >> m >> k;
		vector<vector<int>> map(n, vector<int >(m, 0));
		int ret = 0;

		for (int j = 0; j < k; ++j)
		{
			cin >> trow >> tcol;
			map[trow][tcol] = 1;
		}

		for (int row = 0; row < n; ++row)
		{
			for (int col = 0; col < m; ++col)
			{
				if (true == IsValid(row, col, map))
				{
					++ret;
					dfs(row, col, map);
				}
			}
		}

		cout << ret << endl;
	}


	return 0;
}