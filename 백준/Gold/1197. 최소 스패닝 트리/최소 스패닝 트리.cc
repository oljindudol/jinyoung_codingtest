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

	priority_queue<edge, vector<edge>, cmp> pq;

	int v, e;

	cin >> v >> e;
	vector<vector<edge>> edges(v + 1);
	vector<int> visited(v + 1);

	int f, t, c;


	for (int i = 0; i < e; ++i)
	{
		cin >> f >> t >> c;
		edges[f].push_back({ t,c });
		edges[t].push_back({ f,c });
	}
	long long ret = 0;

	pq.push({ 1,0 });

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
		ret = ret + curw;

		for (const auto& e : edges[curidx])
		{
			if (true == visited[e.to])
			{
				continue;
			}
			pq.push(e);
		}
	}

	cout << ret;

	return 0;
}