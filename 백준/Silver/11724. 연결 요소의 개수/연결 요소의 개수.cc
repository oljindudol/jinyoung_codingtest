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
void dfs(int from, vector<int>& visited, const vector<vector<int>>& edges)
{
	visited[from] = 1;

	for (const auto& to : edges[from])
	{
		if (0 == visited[to])
		{
			dfs(to, visited, edges);
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ret = 0;
	int n, m;
	cin >> n >> m;

	vector<int> visited(n + 1);
	vector<vector<int>> edges(n + 1);

	int v1, v2;
	for (int i = 0; i < m; ++i)
	{
		cin >> v1 >> v2;
		edges[v1].push_back(v2);
		edges[v2].push_back(v1);
	}

	for (int i = 1; i < n + 1; ++i)
	{
		if (0 == visited[i])
		{
			++ret;
			dfs(i, visited, edges);
		}
	}

	cout << ret;

	return 0;
}
