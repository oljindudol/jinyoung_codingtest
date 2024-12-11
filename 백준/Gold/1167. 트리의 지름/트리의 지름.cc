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
#include <mutex>
#include <assert.h>

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
struct edge
{
	int t;
	int w;
};
vector<vector<edge>> edges;
int ret = 0;
vector<int> visited;
int dfs(int from)
{
	vector<int> lens;

	for (const auto& e : edges[from])
	{
		if (0 == visited[e.t])
		{
			visited[e.t] = 1;
			lens.push_back(dfs(e.t) + e.w);
			//visited[e.t] = 0;
		}
	}

	sort(lens.begin(), lens.end(), greater<int>());

	if (1 < lens.size())
	{
		ret = max(ret, lens[0] + lens[1]);
	}
	if (1 == lens.size())
	{
		ret = max(ret, lens[0]);
	}

	if (0 == lens.size())
	{
		return 0;
	}

	return lens[0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	edges.resize(n + 1);
	visited.resize(n + 1);

	int f, t, w;
	for (int i = 0; i < n; ++i)
	{
		cin >> f;

		while (true)
		{
			cin >> t;
			if (-1 == t)
			{
				break;
			}
			cin >> w;
			edges[f].push_back({ t,w });
		}
	}

	//for (int i = 1; i < n + 1; ++i)
	//{
	//	visited.resize(0);
	//	visited.resize(n + 1);
	//	visited[i] = 1;
	//	dfs(i);
	//}
	visited[1] = 1;
	dfs(1);
	//visited.resize(0);
	//visited.resize(n + 1);
	//visited[1] = 2;
	//dfs(2);

	cout << ret;

	return 0;
}
