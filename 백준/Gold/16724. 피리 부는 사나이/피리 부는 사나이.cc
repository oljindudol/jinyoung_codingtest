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

int n, m;
vector<vector<char>> map;

enum eDIR
{
	U,
	D,
	L,
	R,
};

char cDIR[4] = { 'U','D','L','R' };

int reversedir[4] = { 1,0,3,2 };
int drow[4] = { -1,1,0,0 };
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
	if ('X' == map[row][col])
	{
		return false;
	}
	return true;
}

void dfs(int row, int col)
{
	if ('X' == map[row][col])
	{
		return;
	}
	auto alpha = map[row][col];
	map[row][col] = 'X';

	int newrow, newcol;


	for (int i = 0; i < 4; ++i)
	{
		if (cDIR[i] == alpha)
		{
			newrow = row + drow[i];
			newcol = col + dcol[i];
			dfs(newrow, newcol);
			break;
		}
	}


	// 상향식
	for (int i = 0; i < 4; ++i)
	{
		int nrow = row + drow[i];
		int ncol = col + dcol[i];

		if (IsValid(nrow, ncol))
		{
			if (cDIR[reversedir[i]] == map[nrow][ncol])
			{
				dfs(nrow, ncol);
			}
		}
	}

}

int main()
{
	cin >> n >> m;

	map = vector<vector<char>>(n, vector<char>(m));

	char tmp;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			cin >> tmp;
			map[row][col] = tmp;
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
				dfs(row, col);
			}
		}
	}

	cout << ret;

	return 0;
}