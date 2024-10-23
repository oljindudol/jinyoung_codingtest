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

bool IsVaild(int row, int col, const vector<vector<int>>& visited)
{
	if (0 > row || n <= row)
	{
		return false;
	}
	if (0 > col || n <= col)
	{
		return false;
	}
	if (1 == visited[row][col])
	{
		return false;
	}
	return true;
}


void dfs(int row, int col, vector<vector<char>>& map, vector<vector<int>>& visited)
{

	for (int i = 0; i < 4; ++i)
	{
		int newrow = row + drow[i];
		int newcol = col + dcol[i];

		if (true == IsVaild(newrow, newcol, visited) && map[row][col] == map[newrow][newcol])
		{
			visited[newrow][newcol] = 1;
			dfs(newrow, newcol, map, visited);
			//if ('R' == map[newrow][newcol])
			//{
			//	map[newrow][newcol] = 'G';
			//}
		}
	}

}

int main()
{
	cin >> n;

	vector<vector<char>> map(n, vector<char>(n));
	vector<vector<int>> visited(n, vector<int>(n, 0));

	char tmp;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			cin >> tmp;
			map[row][col] = tmp;
		}
	}

	int ret = 0;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			if (true == IsVaild(row, col, visited))
			{
				dfs(row, col, map, visited);
				++ret;
			}
		}
	}
	cout << ret << " ";

	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			if ('R' == map[row][col])
			{
				map[row][col] = 'G';
			}
		}
	}

	ret = 0;
	visited = vector<vector<int>>(n, vector<int>(n, 0));
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			if (true == IsVaild(row, col, visited))
			{
				dfs(row, col, map, visited);
				++ret;
			}
		}
	}
	cout << ret << endl;


	return 0;
}