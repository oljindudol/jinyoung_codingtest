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
	cout << 'n';
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
		cout << 'n';
	}
	cout << 'n';
}

/////////////////////////////////////////////
vector<int> parents;
vector<int> childcnt;
int n;

void Init()
{
	parents.resize(n + 1);
	childcnt.resize(n + 1, 1);

	for (int i = 1; i < n + 1; ++i)
	{
		parents[i] = i;
	}

}

//int Find(int a)
//{
//
//}

void addChild(int p, int c)
{
	parents[c] = p;

	while (p != parents[p])
	{
		++childcnt[p];
		p = parents[p];
	}
	++childcnt[p];
}

//void dfs(int curidx, const vector<vector<int>>& edges, vector<int>& visited)
//{
//	visited[curidx] = 1;
//	for (const auto& to : edges[curidx])
//	{
//		if (1 == visited[to])
//		{
//			continue;
//		}
//		addChild(curidx, to);
//		dfs(to, edges, visited);
//	}
//}


int dfs(int curidx, const vector<vector<int>>& edges, vector<int>& visited)
{
	visited[curidx] = 1;
	for (const auto& to : edges[curidx])
	{
		if (1 == visited[to])
		{
			continue;
		}
		childcnt[curidx] += dfs(to, edges, visited);
	}
	return childcnt[curidx];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, q;
	cin >> n >> r >> q;

	Init();

	vector<vector<int>> edges(n + 1);
	vector<int> visited(n + 1);
	int f, t;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> f >> t;
		edges[f].push_back(t);
		edges[t].push_back(f);
	}

	dfs(r, edges, visited);

	for (int i = 0; i < q; ++i)
	{
		cin >> t;

		printf("%d\n", childcnt[t]);
		//cout << childcnt[t] + 1 << '\n';
	}

	return 0;
}


