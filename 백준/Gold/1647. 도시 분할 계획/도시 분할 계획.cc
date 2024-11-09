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
struct edge
{
	int from;
	int to;
	int w;
};

bool cmp(const edge& a, const edge& b)
{
	return a.w < b.w;
}

int v;
int ret = 0;
int lastw = 0;
vector<edge> edges;
vector<int> parents;
vector<int> depth;

void Init()
{
	parents.resize(v + 1);
	depth.resize(v + 1);
	for (int i = 0; i < v + 1; ++i)
	{
		parents[i] = i;
	}
}

int Find(int a)
{
	if (a == parents[a])
	{
		return a;
	}
	return Find(parents[a]);
}

bool Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb)
	{
		return false;
	}

	if (depth[pa] == depth[pb])
	{
		parents[pa] = pb;
		++depth[pb];
		return true;
	}
	if (depth[pa] > depth[pb])
	{
		parents[pb] = pa;
		return true;
	}
	if (depth[pa] < depth[pb])
	{
		parents[pa] = pb;
		return true;
	}
}


void kruscal()
{
	Init();

	sort(edges.begin(), edges.end(), cmp);

	for (const auto& e : edges)
	{
		if (true == Union(e.from, e.to))
		{
			ret += e.w;
			lastw = e.w;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int  e;
	cin >> v >> e;

	edges.resize(e);
	int f, t, w;
	for (int i = 0; i < e; ++i)
	{
		cin >> f >> t >> w;

		edges[i] = { f,t,w };
	}
	kruscal();

	cout << (ret - lastw);

	return 0;
}