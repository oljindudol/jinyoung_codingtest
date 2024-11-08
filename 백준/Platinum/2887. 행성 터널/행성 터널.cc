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

#define INF 200001

struct info
{
	int pos;
	int idx;
};

struct edge
{
	int from;
	int to;
	int w;
};


bool icmp(const info& a, const info& b)
{
	return a.pos < b.pos;
}

bool ecmp(const edge& a, const edge& b)
{
	return a.w < b.w;
}

vector<int> parents;
vector<int> depth;

void Init()
{
	for (int i = 0; i < parents.size(); ++i)
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

bool UNION(int a, int b)
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

	int cnt;
	cin >> cnt;
	vector<info> xinfo(cnt);
	vector<info> yinfo(cnt);
	vector<info> zinfo(cnt);

	vector<edge> edges(cnt * 3 - 3);
	parents.resize(cnt);
	depth.resize(cnt);

	int x, y, z;
	for (int i = 0; i < cnt; ++i)
	{
		cin >> x >> y >> z;
		xinfo[i] = { x,i };
		yinfo[i] = { y,i };
		zinfo[i] = { z,i };
	}

	sort(xinfo.begin(), xinfo.end(), icmp);
	sort(yinfo.begin(), yinfo.end(), icmp);
	sort(zinfo.begin(), zinfo.end(), icmp);

	int ret = 0;

	for (int i = 0; i < cnt - 1; ++i)
	{
		edges[3 * i + 0] = { xinfo[i + 1].idx,xinfo[i].idx ,xinfo[i + 1].pos - xinfo[i].pos };
		edges[3 * i + 1] = { yinfo[i + 1].idx,yinfo[i].idx ,yinfo[i + 1].pos - yinfo[i].pos };
		edges[3 * i + 2] = { zinfo[i + 1].idx,zinfo[i].idx ,zinfo[i + 1].pos - zinfo[i].pos };
	}

	sort(edges.begin(), edges.end(), ecmp);


	Init();

	for (const auto& e : edges)
	{
		if (true == UNION(e.from, e.to))
		{
			ret += e.w;
		}
	}
	cout << ret;

	return 0;
}