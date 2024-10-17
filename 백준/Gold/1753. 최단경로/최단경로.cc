#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INT_MAX 200001

//int FindMinWieghtIdx(const vector<int>& w, const vector<bool>& v)
//{
//	int minidx = -1;
//	int minw = INT_MAX;
//	int sz = w.size();
//	for (int i = 0; i < sz; ++i)
//	{
//		if (false == v[i])
//		{
//			if (minw > w[i])
//			{
//				minidx = i;
//				minw = w[i];
//			}
//		}
//	}
//
//	return minidx;
//}

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
	int vcnt, edgecnt, start;

	cin >> vcnt >> edgecnt >> start;

	++vcnt;

	vector<vector<edge>> edges(vcnt);
	vector<bool> visited(vcnt, false);
	vector<int> dp = vector<int>(vcnt, INT_MAX);

	priority_queue<edge, vector<edge>, cmp > test;
	for (int i = 0; i < edgecnt; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;

		edges[u].push_back({ v,w });
		test.push({ v,w });
	}


	priority_queue<edge, vector<edge>, cmp > pq;

	visited[0] = true;
	visited[start] = true;
	dp[start] = 0;

	pq.push({ start,0 });

	while (false == pq.empty())
	{
		edge cur = pq.top();
		int routidx = cur.to;
		int routw = cur.w;

		//for (int i = 0; i < edges[routidx].size(); ++i)
		for (auto& e : edges[routidx])
		{
			int newtoidx = e.to;
			int newcost = dp[routidx] + e.w;
			if (dp[newtoidx] > newcost)
			{
				dp[newtoidx] = newcost;
				pq.push({ newtoidx, newcost });
			}
		}
		pq.pop();
	}


	for (int i = 1; i < vcnt; ++i)
	{
		if (INT_MAX == dp[i])
		{
			cout << "INF" << endl;
		}
		else
		{
			cout << dp[i] << endl;
		}
	}

	return 0;
}