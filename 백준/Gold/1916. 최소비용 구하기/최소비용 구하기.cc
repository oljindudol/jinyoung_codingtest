#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1000000001

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
	int vcnt, ecnt;

	cin >> vcnt >> ecnt;
	vcnt++;
	vector<vector<edge>> edges(vcnt, vector<edge>());

	for (int i = 0; i < ecnt; ++i)
	{
		int f, t, w;
		cin >> f >> t >> w;
		edges[f].push_back({ t,w });
	}

	int start, end;
	cin >> start >> end;

	//다익스트라
	vector<int> dp(vcnt, INF);
	priority_queue<edge, vector<edge>, cmp> pq;

	dp[start] = 0;
	pq.push({ start,0 });
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

		for (auto& e : edges[routidx])
		{
			int newdist = dp[routidx] + e.w;
			if (dp[e.to] > newdist)
			{
				dp[e.to] = newdist;
				pq.push({ e.to,newdist });
			}
		}
	}

	cout << dp[end];
	return 0;
}