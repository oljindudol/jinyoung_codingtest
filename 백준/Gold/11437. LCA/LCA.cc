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
vector<int> parents;
vector<int> depth;
vector<vector<int>> edges;


void dfs(int from, int parent)
{
	parents[from] = parent;
	depth[from] = depth[parent] + 1;
	for (const auto& to : edges[from])
	{
		if (parent == to)
		{
			continue;
		}
		dfs(to, from);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	parents = vector<int>(n + 1);
	depth = vector<int>(n + 1);
	edges = vector<vector<int>>(n + 1);

	int f, t;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> f >> t;

		edges[f].push_back(t);
		edges[t].push_back(f);
	}

	dfs(1, 0);

	int tcnt;
	cin >> tcnt;
	for (int i = 0; i < tcnt; ++i)
	{
		cin >> f >> t;
		int d1 = depth[f];
		int d2 = depth[t];

		if (d1 > d2)
		{
			while (d1 != d2)
			{
				f = parents[f];
				--d1;
			}
		}
		if (d1 < d2)
		{
			while (d1 != d2)
			{
				t = parents[t];
				--d2;
			}
		}

		while (t != f)
		{
			f = parents[f];
			t = parents[t];
		}
		cout << t << endl;
	}

	return 0;
}