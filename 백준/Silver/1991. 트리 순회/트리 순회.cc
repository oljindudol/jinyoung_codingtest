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
int n;
vector<int> visited;
vector<vector<int>> edges;

void dfs1(int from)
{
	cout << (char)(from + 'A');

	if (-1 != edges[from][0] && 1 != visited[edges[from][0]])
	{
		visited[edges[from][0]] = 1;
		dfs1(edges[from][0]);
	}

	if (-1 != edges[from][1] && 1 != visited[edges[from][1]])
	{
		visited[edges[from][1]] = 1;
		dfs1(edges[from][1]);
	}
}

void dfs2(int from)
{
	if (-1 != edges[from][0] && 1 != visited[edges[from][0]])
	{
		visited[edges[from][0]] = 1;
		dfs2(edges[from][0]);
	}
	cout << (char)(from + 'A');

	if (-1 != edges[from][1] && 1 != visited[edges[from][1]])
	{
		visited[edges[from][1]] = 1;
		dfs2(edges[from][1]);
	}
}

void dfs3(int from)
{

	if (-1 != edges[from][0] && 1 != visited[edges[from][0]])
	{
		visited[edges[from][0]] = 1;
		dfs3(edges[from][0]);
	}

	if (-1 != edges[from][1] && 1 != visited[edges[from][1]])
	{
		visited[edges[from][1]] = 1;
		dfs3(edges[from][1]);
	}
	cout << (char)(from + 'A');
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	edges.resize(26);

	cin >> n;
	char c1, c2;
	while (n--)
	{
		cin >> c1;

		for (int i = 0; i < 2; ++i)
		{
			cin >> c2;

			if ('.' != c2)
			{
				edges[c1 - 'A'].push_back(c2 - 'A');
			}
			else
			{
				edges[c1 - 'A'].push_back(-1);
			}
		}
	}

	visited.resize(0);
	visited.resize(26);
	visited[0] = 1;
	dfs1(0);
	cout << '\n';
	visited.resize(0);
	visited.resize(26);
	visited[0] = 1;
	dfs2(0);
	cout << '\n';
	visited.resize(0);
	visited.resize(26);
	visited[0] = 1;
	dfs3(0);

	return 0;
}
