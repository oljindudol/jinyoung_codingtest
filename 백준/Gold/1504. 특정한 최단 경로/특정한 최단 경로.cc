#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 800001


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

int di(int from, int to, int vcnt, const vector<vector<edge>>& edges)
{
	int sz = vcnt;

	vector<int> dp(sz, INF);
	priority_queue<edge, vector<edge>, cmp> pq;
	dp[from] = 0;
	pq.push({ from,0 });

	while (false == pq.empty())
	{
		edge cur = pq.top();
		pq.pop();
		int routidx = cur.to;
		int routw = cur.w;

		if (dp[routidx] < routw)
		{
			continue;
		}

		for (const auto& e : edges[routidx])
		{
			int newdist = routw + e.w;
			if (dp[e.to] > newdist)
			{
				dp[e.to] = newdist;
				pq.push({ e.to,newdist });
			}
		}
	}

	return dp[to];
}


int main()
{
	int vcnt, ecnt;
	cin >> vcnt >> ecnt;
	++vcnt;

	vector<vector<edge>> edges(vcnt, vector<edge>());
	for (int i = 0; i < ecnt; ++i)
	{
		int f, t, w;
		cin >> f >> t >> w;
		edges[f].push_back({ t,w });
		edges[t].push_back({ f,w });
	}

	int start, end;

	cin >> start >> end;


	int r1, r2, r3, r4, r5;

	r1 = di(1, start, vcnt, edges);
	r2 = di(start, end, vcnt, edges);
	r3 = di(end, vcnt - 1, vcnt, edges);

	r4 = di(1, end, vcnt, edges);
	r5 = di(start, vcnt - 1, vcnt, edges);

	bool r1p = true;
	if (INF == r1 || INF == r2 || INF == r3)
	{
		r1p = false;
	}

	bool r2p = true;
	if (INF == r4 || INF == r2 || INF == r5)
	{
		r2p = false;
	}
	if (false == r1p && false == r2p)
	{
		cout << -1;
	}
	else
	{
		int ret = min((r1 + r2 + r3), (r4 + r2 + r5));
		cout << ret;
	}

	return 0;
}