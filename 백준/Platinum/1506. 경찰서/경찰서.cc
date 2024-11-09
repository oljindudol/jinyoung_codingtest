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
struct sscc
{
	long long idx;
	long long w;
};

bool cmp(const sscc& a, const sscc& b)
{
	return a.w < b.w;
}

constexpr long long INF = 1e9 + 1;
long long n;
vector<vector<long long>> edges;
vector<long long> costs;
vector<vector<sscc>> sccs;
stack<long long> s;
vector <long long> finished;
vector<long long> GetScc;
vector<long long> ids;
long long id = 0;
long long sccid = 1;

long long dfs(int from)
{
	ids[from] = ++id;
	s.push(from);

	long long parentid = ids[from];
	for (const auto& to : edges[from])
	{
		//방문하지 않았을경우
		if (0 == ids[to])
		{
			parentid = min(parentid, dfs(to));
			continue;
		}
		if (0 == finished[to])
		{
			parentid = min(parentid, ids[to]);
		}
	}

	if (parentid == ids[from])
	{
		vector<sscc> scc;
		while (false == s.empty())
		{
			long long to = s.top();
			s.pop();
			scc.push_back({ to ,costs[to] });
			finished[to] = sccid;
			if (to == from)
			{
				break;
			}
		}
		sort(scc.begin(), scc.end(), cmp);
		++sccid;
		sccs.push_back(scc);
	}
	return parentid;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	long long c;

	costs.resize(n);
	edges.resize(n);
	for (long long i = 0; i < n; ++i)
	{
		cin >> c;
		costs[i] = c;
	}

	char c1;
	for (long long row = 0; row < n; ++row)
	{
		for (long long col = 0; col < n; ++col)
		{
			cin >> c1;
			if ('1' == c1)
			{
				edges[row].push_back(col);
			}
		}
	}
	finished.resize(n);
	GetScc.resize(n);
	ids.resize(n);

	for (int i = 0; i < n; ++i)
	{
		if (0 == finished[i])
		{
			dfs(i);
		}
	}
	long long ret = 0;
	for (const auto& e : sccs)
	{
		ret += e[0].w;
	}
	cout << ret;

	return 0;
}

