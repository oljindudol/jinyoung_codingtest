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

using namespace std;

template <typename T>
void PrintVec(const vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
	}
	cout << 'n';
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
		cout << 'n';
	}
	cout << 'n';
}

/////////////////////////////////////////////
constexpr long long INF = 4e10 + 1;

vector<int> ins;
vector<vector<int>> edges;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	ins.resize(n + 1);
	edges.resize(n + 1);

	int prev, cur, scnt;
	for (int i = 0; i < m; ++i)
	{
		cin >> scnt;
		cin >> prev;
		for (int j = 1; j < scnt; ++j)
		{
			cin >> cur;
			edges[prev].push_back(cur);
			++ins[cur];
			prev = cur;
		}
	}
	vector<int> ret;
	queue<int> q;
	for (int i = 1; i < n + 1; ++i)
	{
		if (0 == ins[i])
		{
			q.push(i);
		}
	}

	while (false == q.empty())
	{
		auto cur = q.front();
		q.pop();

		ret.push_back(cur);

		for (const auto to : edges[cur])
		{
			--ins[to];

			if (0 == ins[to])
			{
				q.push(to);
			}
		}
	}

	for (int i = 1; i < n + 1; ++i)
	{
		if (0 != ins[i])
		{
			cout << 0;
			return 0;
		}
	}

	for (const auto& e : ret)
	{
		cout << e << '\n';
	}

	return 0;
}


