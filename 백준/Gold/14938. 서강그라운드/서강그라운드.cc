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
int n, m;

vector<int> values;
vector<int> visited;
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
	int v;
};

struct cmp
{
	bool operator()(const node& a, const node& b)
	{
		return a.w > b.w;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r;
	cin >> n >> m >> r;

	values.resize(n + 1);
	edges.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 1; i < n + 1; ++i)
	{
		cin >> values[i];
	}

	int f, t, w;
	while (r--)
	{
		cin >> f >> t >> w;
		edges[f].push_back({ t,w });
		edges[t].push_back({ f,w });
	}

	int ret = 0;
	for (int i = 1; i < n + 1; ++i)
	{
		visited.resize(0);
		visited.resize(n + 1);
		priority_queue<node, vector<node>, cmp> pq;
		pq.push({ i,0,values[i] });

		int res = 0;
		while (false == pq.empty())
		{
			auto cur = pq.top();
			pq.pop();

			if (0 == visited[cur.t])
			{
				visited[cur.t] = 1;
			}
			else
			{
				continue;
			}
			res += values[cur.t];
			ret = max(ret, res);

			for (const auto& to : edges[cur.t])
			{
				if (0 == visited[to.t])
				{
					//visited[to.t] = 1;
					int neww = cur.w + to.w;
					int newv = cur.v + values[cur.t];
					if (m >= neww)
					{
						pq.push({ to.t,neww,newv });
					}
				}
			}
		}
	}

	cout << ret;
	return 0;
}
