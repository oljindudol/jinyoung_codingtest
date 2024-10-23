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




int r, c;
int maxrow, maxcol;
unordered_map<char, int> umVisited;
vector<int> visited;
vector<vector<char>> map;

int sol = 0;


int drow[4] = { 1,-1,0,0 };
int dcol[4] = { 0,0,-1,1 };

bool IsValid(int row, int col, const vector<int>& visited)//unordered_map<char, int>& umVisited)
{
	if (0 > row || maxrow <= row)
	{
		return false;
	}
	if (0 > col || maxcol <= col)
	{
		return false;
	}

	//if (1 == umVisited[map[row][col]])
	//{
	//	return false;
	//}
	if (1 == visited[map[row][col] - 'A'])
	{
		return false;
	}

	return true;
}

void dfs(int depth, int row, int col)
{
	//int ret = 0;
	bool dirty = false;
	for (int i = 0; i < 4; ++i)
	{
		int newrow = row + drow[i];
		int newcol = col + dcol[i];
		if (true == IsValid(newrow, newcol, visited))
		{
			visited[map[newrow][newcol] - 'A'] = 1;
			//umVisited[map[newrow][newcol]] = 1;
			//ret = max(ret, dfs(depth + 1, newrow, newcol) + 1);
			dfs(depth + 1, newrow, newcol);
			dirty = true;
			//umVisited[map[newrow][newcol]] = 0;
			visited[map[newrow][newcol] - 'A'] = 0;
		}
	}

	if (false == dirty)
	{
		sol = max(sol, depth);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	map = vector<vector<char>>(r, vector<char>(c));
	maxrow = r;
	maxcol = c;
	visited = vector<int>(26, 0);

	char tmp;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> tmp;
			map[i][j] = tmp;
		}
	}

	//umVisited[map[0][0]] = 1;
	visited[map[0][0] - 'A'] = 1;
	dfs(0, 0, 0);
	//cout << dfs(0, 0, 0) + 1;
	cout << sol + 1;

	return 0;
}