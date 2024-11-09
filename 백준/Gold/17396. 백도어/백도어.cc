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
	long long to;
	long long w;
};

struct cmp
{
	bool operator()(const edge& a, const edge& b)
	{
		return a.w > b.w;
	}
};

#define INF 10000000000001
long long n;
vector<long long> visible;
vector<vector<edge>> edges;
vector<long long> dp;
void daikustraa(long long from)
{
	dp.resize(n, INF);
	dp[from] = 0;

	priority_queue <edge, vector<edge>, cmp> pq;
	pq.push({ from,0 });

	//vector<int> visited(n, 0);

	while (false == pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		auto curidx = cur.to;
		auto curw = cur.w;

		if (dp[curidx] < curw)
		{
			continue;
		}

		for (const auto& to : edges[curidx])
		{
			if (n - 1 != to.to && 1 == visible[to.to])
			{
				continue;
			}
			long long neww = curw + to.w;
			if (dp[to.to] > neww)
			{
				dp[to.to] = neww;
				pq.push({ to.to,neww });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long m;
	cin >> n >> m;
	visible.resize(n, -1);
	edges.resize(n);

	long long v;
	for (int i = 0; i < n; ++i)
	{
		cin >> v;
		visible[i] = v;
	}

	long long f, t, w;
	for (int i = 0; i < m; ++i)
	{
		cin >> f >> t >> w;

		if (n - 1 != t && 1 == visible[t])
		{
			continue;
		}
		if (n - 1 != f && 1 == visible[f])
		{
			continue;
		}
		edges[f].push_back({ t,w });
		edges[t].push_back({ f,w });
	}

	daikustraa(0);
	if (INF == dp[n - 1])
	{
		cout << -1;
	}
	else
	{
		cout << dp[n - 1];
	}

	return 0;
}