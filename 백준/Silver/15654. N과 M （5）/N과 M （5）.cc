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
vector<int> origin;
vector<int> visited;

void dfs(int depth, vector<int>& picked)
{
	if (m == depth)
	{
		PrintVec(picked);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (1 == visited[i])
		{
			continue;
		}
		picked.push_back(origin[i]);
		visited[i] = 1;
		dfs(depth + 1, picked);
		visited[i] = 0;
		picked.pop_back();

	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	origin.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> origin[i];
	}

	sort(origin.begin(), origin.end());
	visited.resize(n);

	vector<int> picked;
	dfs(0, picked);

	return 0;
}