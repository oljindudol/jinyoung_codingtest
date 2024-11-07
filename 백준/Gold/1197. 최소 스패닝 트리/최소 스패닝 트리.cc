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

vector<int> vertexes;
vector<edge> edges;
vector<int> parents;
vector<int> depth;
int v;

void init()
{
	for (int i = 1; i < v + 1; ++i)
	{
		parents[i] = i;
	}
}

int find(int from)
{
	if (from == parents[from])
	{
		return from;
	}

	return find(parents[from]);
}

bool Union(int a, int b)
{
	int pa = find(a);
	int pb = find(b);

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
	if (depth[pa] < depth[pb])
	{
		parents[pa] = pb;
		return true;
	}
	if (depth[pa] > depth[pb])
	{
		parents[pb] = pa;
		return true;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int  e;
	cin >> v >> e;

	vertexes.resize(v + 1);
	edges.resize(v + 1);
	parents.resize(v + 1);
	depth.resize(v + 1);

	int f, t, w;
	for (int i = 0; i < e; ++i)
	{
		cin >> f >> t >> w;
		edges.push_back({ f, t,w });
	}

	init();

	sort(edges.begin(), edges.end(), cmp);

	long long ret = 0;
	for (const auto& e : edges)
	{
		if (false == Union(e.from, e.to))
		{
			continue;
		}
		ret += e.w;
	}

	cout << ret;

	return 0;
}