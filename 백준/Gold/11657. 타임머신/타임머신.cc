#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;



#define INF 30000000000
#define NINF -INF

struct edge
{
	int from;
	int to;
	long long w;
};



int main()
{
	int vcnt, ecnt;
	cin >> vcnt >> ecnt;
	++vcnt;

	vector<edge> edges;
	for (int i = 0; i < ecnt; ++i)
	{
		int f, t, w;

		cin >> f >> t >> w;
		edges.push_back({ f,t,w });
	}

	vector<long long> dp(vcnt, INF);

	dp[1] = 0;
	//int esz = edges.size();
	for (int i = 0; i < vcnt - 2; ++i)
	{
		for (auto& e : edges)
		{
			if (INF == dp[e.from])
			{
				continue;
			}
			long long newdist = dp[e.from] + e.w;
			if (dp[e.to] > newdist)
			{
				dp[e.to] = newdist;
			}
		}
	}

	set<int> nc;
	//음수간선검색
	for (auto& e : edges)
	{
		if (INF == dp[e.from])
		{
			continue;
		}
		long long newdist = dp[e.from] + e.w;
		if (dp[e.to] > newdist)
		{
			cout << -1;
			return 0;
		}
	}


	for (int i = 2; i < vcnt; ++i)
	{
		if (INF == dp[i])
		{
			cout << -1 << endl;
		}
		else
		{
			cout << dp[i] << endl;
		}
	}


	return 0;
}