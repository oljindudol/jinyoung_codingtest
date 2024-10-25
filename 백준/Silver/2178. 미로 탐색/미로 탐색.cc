#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <ostream>

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

/////////////////////////////////////////////

int drow[4] = { 1,-1,0,0 };
int dcol[4] = { 0,0,-1,1 };

bool IsValid(int row, int col, const vector<vector<int>>& map, const vector<vector<int>>& visited)
{
	int rsize = visited.size();
	int csize = visited[0].size();

	if (0 > row || rsize <= row)
	{
		return false;
	}
	if (0 > col || csize <= col)
	{
		return false;
	}
	if (1 == visited[row][col])
	{
		return false;
	}
	if (0 == map[row][col])
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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(m, 0));
	vector<vector<int>> visited(n, vector<int>(m, 0));

	char c;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			cin >> c;
			map[row][col] = c - '0';
		}
	}

	//for (int row = 0; row < n; ++row)
	//{
	//	for (int col = 0; col < m; ++col)
	//	{
	//		if (false == IsValid(row, col, visited))
	//		{
	//			continue;
	//		}


	//	}
	//}

	queue<node> q;
	visited[0][0] = 1;
	q.push({ 0,0,1 });
	while (false == q.empty())
	{
		node front = q.front();
		q.pop();
		int row = front.row;
		int col = front.col;
		int depth = front.depth;

		if (n - 1 == row && m - 1 == col)
		{
			cout << depth;
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int newrow = row + drow[i];
			int newcol = col + dcol[i];
			if (true == IsValid(newrow, newcol, map, visited))
			{
				visited[newrow][newcol] = 1;
				q.push({ newrow,newcol,depth + 1 });
			}
		}
	}

	return 0;
}