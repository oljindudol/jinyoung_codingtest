#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
using namespace std;

int drow[4] = { 1,-1,0,0 };
int dcol[4] = { 0,0,-1,1 };

int n;

bool IsValid(int row, int col, const vector<vector<int>>& visited)
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

vector<vector<int>> map;
vector<vector<int>> dp;
vector<vector<int>> visited;
//vector<vector<int>> map(n, vector<int>(n));
//vector<vector<int>> dp(n, vector<int>(n, 1));

int dfs(int row, int col)
{
	if (1 != dp[row][col])
	{
		return dp[row][col];
	}

	for (int i = 0; i < 4; ++i)
	{
		int newrow = row + drow[i];
		int newcol = col + dcol[i];
		if (false == IsValid(newrow, newcol, visited))
		{
			continue;
		}
		if (map[newrow][newcol] <= map[row][col])
		{
			continue;
		}

		visited[newrow][newcol] = 1;
		dp[row][col] = max(dp[row][col], dfs(newrow, newcol) + 1);
		visited[newrow][newcol] = 0;
	}

	return dp[row][col];
}

int main()
{
	cin >> n;
	map = vector < vector<int>>(n, vector<int>(n));
	dp = vector<vector<int>>(n, vector<int>(n, 1));
	visited = vector<vector<int>>(n, vector<int>(n, 0));

	for (int row = 0; row < n; ++row)
	{
		int tmp;
		for (int col = 0; col < n; ++col)
		{
			cin >> tmp;
			map[row][col] = tmp;
		}
	}

	int maxv = 0;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			maxv = max(maxv, dfs(row, col));
		}
	}
	cout << maxv;


	//int rep = n * n;
	//for (int i = 0; i < rep - 1; ++i)
	//{
	//	bool dirty = false;
	//	for (int row = 0; row < n; ++row)
	//	{
	//		for (int col = 0; col < n; ++col)
	//		{

	//			for (int i = 0; i < 4; ++i)
	//			{
	//				int newrow = row + drow[i];
	//				int newcol = col + dcol[i];
	//				if (false == IsValid(newrow, newcol))
	//				{
	//					continue;
	//				}
	//				if (map[row][col] < map[newrow][newcol])
	//				{
	//					dp[row][col] = max(dp[row][col], dp[newrow][newcol] + 1);
	//					dirty = true;
	//				}
	//			}
	//		}
	//	}
	//	if (false == dirty)
	//	{
	//		break;
	//	}
	//}

	//int ret = 0;
	//for (int row = 0; row < n; ++row)
	//{
	//	for (int col = 0; col < n; ++col)
	//	{
	//		ret = max(ret, dp[row][col]);
	//	}
	//}
	//cout << ret;

	return 0;
}