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
#define INF 2e9
int n, m;
int s, e;

struct edge
{
	int to;
	int w;
};

struct node
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

struct cmp2
{
	bool operator()(const node& a, const node& b)
	{
		return a.w > b.w;
	}
};

vector<vector<edge>> edges;

void daikustra(int from, int to)
{
	vector<int> dp(n + 1, INF);

	priority_queue <node, vector<node>, cmp2> pq;

	dp[from] = 0;
	pq.push({ from,0 });

	while (false == pq.empty())
	{
		auto cur = pq.top();
		pq.pop();

		if (dp[cur.to] < cur.w)
		{
			continue;
		}

		for (const auto& e : edges[cur.to])
		{
			int neww = cur.w + e.w;
			if (dp[e.to] > neww)
			{
				dp[e.to] = neww;
				pq.push({ e.to,neww });
			}
		}
	}

	cout << dp[to];
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	edges.resize(n + 1);

	int f, t, w;
	while (m--)
	{
		cin >> f >> t >> w;
		edges[f].push_back({ t,w });
	}


	cin >> s >> e;

	daikustra(s, e);

	return 0;
}