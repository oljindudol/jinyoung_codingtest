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
constexpr long long INF = 4e6 + 1;
constexpr long long MOD = 1e9 + 7;





int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> edges(n + 1);
	vector<int> visited(n + 1);

	int t1, t2;
	for (int i = 0; i < k; ++i)
	{
		cin >> t1 >> t2;
		edges[t1].push_back(t2);
		edges[t2].push_back(t1);
	}

	queue<int> q;
	q.push(1);
	visited[1] = 1;

	int ret = 0;
	while (false == q.empty())
	{
		int cur = q.front();
		q.pop();
		ret++;
		for (const auto& to : edges[cur])
		{
			if (1 == visited[to])
			{
				continue;
			}
			visited[to] = 1;
			q.push(to);
		}
	}
	cout << --ret;

	return 0;
}
