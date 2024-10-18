#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;



#define INF 120001

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
	int edgecnt, len;
	cin >> edgecnt >> len;
	++len;

	set<int> s;
	vector<vector<edge>> edges(len);

	for (int i = 0; i < edgecnt; ++i)
	{
		int f, t, w;
		cin >> f >> t >> w;
		if (len - 1 < f || len - 1 < t)
		{
			continue;
		}
		s.insert(f);
		s.insert(t);
		edges[f].push_back({ t,w });
	}

	s.insert(0);
	s.insert(len - 1);
	vector<int> vertexes;
	for (const auto& e : s)
	{
		vertexes.push_back(e);
	}
	sort(vertexes.begin(), vertexes.end());

	for (int i = 0; i < vertexes.size() - 1; ++i)
	{
		for (int j = i + 1; j < vertexes.size(); ++j)
		{
			edges[vertexes[i]].push_back({ vertexes[j], vertexes[j] - vertexes[i] });
		}
	}

	priority_queue < edge, vector<edge>, cmp> pq;
	vector<int> dp(10000);
	for (int i = 0; i < len; ++i)
	{
		dp[i] = i;
	}

	for (auto& e : vertexes)
	{
		pq.push({ e,e });
	}
	//pq.push({ 0,0 });

	while (false == pq.empty())
	{
		edge cur = pq.top();
		pq.pop();
		int routidx = cur.to;
		int routw = cur.w;

		for (const auto& e : edges[routidx])
		{
			int newdist = dp[routidx] + e.w;
			if (dp[e.to] > newdist)
			{
				dp[e.to] = newdist;
				pq.push({ e.to,newdist });
			}
		}
	}

	cout << dp[len - 1];

	return 0;
}