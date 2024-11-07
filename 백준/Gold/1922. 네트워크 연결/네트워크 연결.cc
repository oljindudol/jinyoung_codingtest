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
	int to;
	int w;
};

struct cmp
{
	bool operator()(const edge& a, const edge& b)
	{
		return a.w > b.w;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<edge>> edges(n + 1);
	vector<int> visited(n + 1);
	priority_queue<edge, vector<edge>, cmp> pq;


	int f, t, w;
	for (int i = 0; i < m; ++i)
	{
		cin >> f >> t >> w;
		edges[f].push_back({ t,w });
		edges[t].push_back({ f,w });
	}

	pq.push({ 1,0 });
	long long ret = 0;
	while (false == pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		int curidx = cur.to;
		int curw = cur.w;
		if (1 == visited[curidx])
		{
			continue;
		}
		visited[curidx] = 1;

		ret += curw;
		for (const auto& e : edges[curidx])
		{
			if (1 == visited[e.to])
			{
				continue;
			}
			pq.push(e);
		}
	}

	cout << ret;


	return 0;
}