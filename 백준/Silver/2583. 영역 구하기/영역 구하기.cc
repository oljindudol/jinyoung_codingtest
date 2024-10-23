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
vector<vector<int>> map;
vector<vector<int>> visited;
vector<int> areas;
int tmparea;

int drow[4] = { 1,-1,0,0 };
int dcol[4] = { 0,0,-1,1 };

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
	if (1 == visited[row][col])
	{
		return false;
	}
	return true;
}

void dfs(int row, int col)
{
	for (int i = 0; i < 4; ++i)
	{
		int newrow = row + drow[i];
		int newcol = col + dcol[i];
		if (true == IsValid(newrow, newcol))
		{
			++tmparea;
			visited[newrow][newcol] = 1;
			dfs(newrow, newcol);
		}
	}

}


int main()
{
	cin >> n >> m >> k;

	map = vector<vector<int>>(n, vector<int>(m, 0));
	visited = vector<vector<int>>(n, vector<int>(m, 0));

	int rowmin, colmin, rowmax, colmax;
	for (int i = 0; i < k; ++i)
	{
		cin >> colmin >> rowmin >> colmax >> rowmax;
		for (int row = rowmin; row < rowmax; ++row)
		{
			for (int col = colmin; col < colmax; ++col)
			{
				map[row][col] = 1;
			}
		}
	}

	int ret = 0;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			if (true == IsValid(row, col))
			{
				++ret;
				tmparea = 1;
				visited[row][col] = 1;
				dfs(row, col);
				areas.push_back(tmparea);
			}
		}
	}

	sort(areas.begin(), areas.end());


	cout << ret << endl;
	for (auto& e : areas)
	{
		cout << e << " ";
	}

	return 0;
}