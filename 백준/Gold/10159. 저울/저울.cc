#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
#include <string>
#include <stdio.h>
#include <unordered_map>

using namespace std;

int n, m;

struct node
{
	vector<int> upper;
	vector<int> lower;
};

vector<node> map;


void dfs(int cur, node& origin, vector<int>& visited, bool upper)
{
	if (true == upper)
	{
		//for (auto iter = map[cur].upper.begin(); iter < map[cur].upper.end(); ++iter)
		//for (int i = 0; i < map[cur].upper.size(); ++i)
		for (auto u : map[cur].upper)
		{
			//auto u = map[cur].upper[i];
			if (0 == visited[u])
			{
				visited[u] = 1;
				//origin.upper.push_back(u);
				dfs(u, origin, visited, upper);
			}
		}
	}
	else
	{
		//for (auto iter = map[cur].lower.begin(); iter < map[cur].lower.end(); ++iter)
		//for (int i = 0; i < map[cur].lower.size(); ++i)
		for (auto l : map[cur].lower)
		{
			//auto l = map[cur].lower[i];
			if (0 == visited[l])
			{
				visited[l] = 1;
				dfs(l, origin, visited, upper);
				//origin.lower.push_back(l);
			}
		}
	}
}


int main()
{
	cin >> n >> m;
	map = vector<node>(n + 1);

	int h, l;
	for (int i = 0; i < m; ++i)
	{
		cin >> h >> l;
		map[h].lower.push_back(l);
		map[l].upper.push_back(h);
	}

	vector<int> ret(n + 1, 0);
	for (int i = 1; i < n + 1; ++i)
	{
		vector<int> visited(n + 1, 0);
		visited[0] = visited[i] = 1;

		dfs(i, map[i], visited, true);
		dfs(i, map[i], visited, false);
		//int uppersz = map[i].upper.size();
		//int lowersz = map[i].lower.size();

		for (const auto& e : visited)
		{
			if (0 == e)
			{
				++ret[i];
			}
		}

		//ret[i] = n - 1 - (uppersz + lowersz);
	}

	for (int i = 1; i < n + 1; ++i)
	{
		printf("%d\n", ret[i]);
	}

	return 0;
}