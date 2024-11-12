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
int n, m, k;
//struct edge
//{
//	int to;
//	int v;
//};

vector<int> visited;
vector<int> candies;
//vector<vector<edge>> edges;
vector<vector<int>> edges;

struct group
{
	int candycnt;
	int childcnt;
};


int accChild;
int accCandy;

void dfs(int curidx)
{
	accCandy += candies[curidx];
	++accChild;

	for (const auto& to : edges[curidx])
	{
		if (1 == visited[to])
		{
			continue;
		}
		visited[to] = 1;
		dfs(to);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	visited.resize(n + 1);
	candies.resize(n + 1);
	edges.resize(n + 1);

	int f, t;
	for (int i = 1; i < n + 1; ++i)
	{
		cin >> t;
		candies[i] = t;
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> f >> t;

		edges[f].push_back(t);
		edges[t].push_back(f);
	}

	vector<group> groups;
	for (int i = 1; i < n + 1; ++i)
	{
		if (1 == visited[i])
		{
			continue;
		}
		visited[i] = 1;
		accCandy = 0;
		accChild = 0;

		dfs(i);

		groups.push_back({ accCandy ,accChild });
	}

	vector<int> dp(k);

	for (const auto& g : groups)
	{
		auto pdp = dp;

		for (int i = g.childcnt; i < k; ++i)
		{
			int newcnt = i - g.childcnt;
			dp[i] = max(pdp[i], pdp[newcnt] + g.candycnt);
		}
	}

	auto me = max_element(dp.begin(), dp.end());

	cout << *me;

	return 0;
}


