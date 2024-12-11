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

struct edge
{
	int t;
	int w;
};
vector<vector<edge>> edges;

struct node
{
	int t;
	int w;
	vector<int> path;
};

struct cmp
{
	bool operator()(const node& a, const node& b)
	{
		return a.w > b.w;
	}
};

vector<int> ret;

void daiku(int from, int to)
{
	vector<int> dp(n + 1, INF);
	dp[from] = 0;
	priority_queue<node, vector<node>, cmp> pq;
	vector<int> initpath;
	initpath.push_back(from);
	pq.push({ from,0,initpath });

	while (false == pq.empty())
	{
		auto cur = pq.top();
		pq.pop();

		if (dp[cur.t] < cur.w)
		{
			continue;
		}

		if (to == cur.t)
		{
			ret = cur.path;
		}

		for (const auto& to : edges[cur.t])
		{
			int neww = cur.w + to.w;
			auto newvec = cur.path;
			if (dp[to.t] > neww)
			{
				dp[to.t] = neww;
				newvec.push_back(to.t);
				pq.push({ to.t,neww,newvec });
			}
		}
	}
	cout << dp[to] << ' ';
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
	int s, e;
	cin >> s >> e;

	daiku(s, e);
	cout << ret.size() << ' ';
	PrintVec(ret);
	return 0;
}
