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
vector<vector<int>> edges;
string ret = "";

void dfs(int from, vector<int>& visited)
{
	visited[from] = 1;
	ret += to_string(from);
	ret += " ";

	for (const auto& to : edges[from])
	{
		if (0 == visited[to])
		{
			dfs(to, visited);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, v;
	cin >> n >> m >> v;

	edges.resize(n + 1);
	int v1, v2;
	for (int i = 0; i < m; ++i)
	{
		cin >> v1 >> v2;
		edges[v1].push_back(v2);
		edges[v2].push_back(v1);
	}

	for (auto& e : edges)
	{
		sort(e.begin(), e.end());
	}

	vector<int> visited1(n + 1);
	dfs(v, visited1);

	vector<int> visited2(n + 1);
	ret += '\n';
	queue<int> q;
	visited2[v] = 1;
	q.push(v);
	while (false == q.empty())
	{
		int cur = q.front();
		q.pop();
		ret += to_string(cur);
		ret += " ";

		for (const auto& to : edges[cur])
		{
			if (0 == visited2[to])
			{
				visited2[to] = 1;
				q.push(to);
			}
		}
	}
	cout << ret;

	return 0;
}
