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

#define INF 100001

struct cmp
{
	bool operator()(const edge& a, const edge& b)
	{
		return a.w > b.w;
	}
};

int daikstra(int from, int to, int n, const vector<vector<edge>>& edges)
{
	vector<int> dp(n + 1, INF);

	priority_queue<edge, vector<edge>, cmp> pq;
	dp[from] = 0;
	pq.push({ from,0 });

	while (false == pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		int curidx = cur.to;
		int curw = cur.w;

		if (dp[curidx] < cur.w)
			continue;

		for (const auto& next : edges[curidx])
		{
			int newidx = next.to;
			int neww = curw + next.w;

			if (dp[newidx] > neww)
			{
				dp[newidx] = neww;
				pq.push({ newidx,neww });
			}
		}
	}

	return dp[to];

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, x;
	cin >> n >> m >> x;

	vector<vector<edge>> edges(n + 1);
	vector<int> dp(n + 1, INF);

	int f, t, w;
	for (int i = 0; i < m; ++i)
	{
		cin >> f >> t >> w;

		edges[f].push_back({ t,w });
	}

	priority_queue<edge, vector<edge>, cmp> pq;
	dp[x] = 0;
	pq.push({ x,0 });

	while (false == pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		int curidx = cur.to;
		int curw = cur.w;

		if (dp[curidx] < cur.w)
			continue;

		for (const auto& next : edges[curidx])
		{
			int newidx = next.to;
			int neww = curw + next.w;

			if (dp[newidx] > neww)
			{
				dp[newidx] = neww;
				pq.push({ newidx,neww });
			}
		}
	}

	int maxd = 0;

	for (int i = 1; i < n + 1; ++i)
	{
		maxd = max(maxd, dp[i] + daikstra(i, x, n, edges));
	}
	cout << maxd;

	return 0;
}