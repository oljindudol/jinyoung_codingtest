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
vector<vector<long long>> map;
//struct edge
//{
//	int t;
//	int f;
//};

//vector<edge> edges;
vector<vector<int>> edges;
int ret;
int INF = 2e9 + 1;
int minc = INF;

void bf()
{
	for (int i = 0; i < m; ++i)
	{
		for (int row = 1; row < n + 1; ++row)
		{
			for (int col = 1; col < n + 1; ++col)
			{
				for (const auto& to : edges[col])
				{
					if (INF == map[row][col])
					{
						continue;
					}
					long long newval = map[row][col] + 1;
					map[row][to] = min(map[row][to], newval);
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	map.resize(n + 1, vector<long long>(n + 1, INF));
	edges.resize(n + 1);

	int t, f;
	for (int i = 0; i < m; ++i)
	{
		cin >> t >> f;
		edges[f].push_back(t);
		edges[t].push_back(f);
	}

	for (int i = 0; i < n + 1; ++i)
	{
		map[i][i] = 0;
	}

	bf();


	for (int row = 1; row < n + 1; ++row)
	{
		long long sum = 0;
		for (int col = 1; col < n + 1; ++col)
		{
			sum += map[row][col];
		}
		if (minc > sum)
		{
			minc = sum;
			ret = row;
		}
	}

	cout << ret;

	return 0;
}