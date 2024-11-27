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
int n;
vector<vector<int>> map;

void dfs(const int from, int to, vector<int>& visited)// , bool first)
{
	for (int i = 0; i < n; ++i)
	{
		if (1 == map[to][i] && 0 == visited[i])
		{
			visited[i] = 1;
			map[from][i] = 1;
			dfs(from, i, visited);
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	map.resize(n, vector<int>(n));

	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			cin >> map[row][col];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		vector<int> visited(n);
		dfs(i, i, visited);
	}

	PrintVec(map);

	return 0;
}