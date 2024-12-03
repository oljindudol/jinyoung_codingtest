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
//#include "semaphore.h"
#include <semaphore>

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
int vcnt, ecnt;
int	a1, a2;
vector<int> dp;
int s;

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

vector<vector<edge>> edges;
#define INF 2e9 +1

void daiku(int start)
{

	dp[start] = 0;
	priority_queue<edge, vector<edge>, cmp> q;
	q.push({ start,0 });


	while (false == q.empty())
	{
		auto cur = q.top();
		q.pop();

		if (dp[cur.to] < cur.w)
		{
			continue;
		}

		for (const auto& to : edges[cur.to])
		{
			int neww = cur.w + to.w;
			if (dp[to.to] > neww)
			{
				dp[to.to] = neww;
				q.push({ to.to,neww });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> vcnt >> ecnt;
	cin >> s;
	edges.resize(vcnt + 1);

	int f, t, w;
	while (ecnt--)
	{
		cin >> f >> t >> w;

		edges[f].push_back({ t,w });
		//edges[t].push_back({ f,w });
	}

	dp.resize(vcnt + 1, INF);

	daiku(s);

	for (int i = 1; i < vcnt + 1; ++i)
	{
		if (dp[i] == INF)
		{
			cout << "INF ";

		}
		else
		{
			cout << dp[i] << ' ';
		}
	}
	return 0;
}