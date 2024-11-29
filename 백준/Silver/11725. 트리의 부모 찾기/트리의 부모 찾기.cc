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
vector<int> parents;
vector<vector<int>> edges;
void dfs(int from)
{
	for (const auto& to : edges[from])
	{
		if (0 != parents[to])
		{
			continue;
		}
		parents[to] = from;
		dfs(to);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	parents.resize(n + 1);
	edges.resize(n + 1);

	int t1, t2;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> t1 >> t2;
		edges[t1].push_back(t2);
		edges[t2].push_back(t1);
	}

	parents[1] = 1;
	dfs(1);

	for (int i = 2; i < n + 1; ++i)
	{
		cout << parents[i] << " ";
	}
	return 0;
}