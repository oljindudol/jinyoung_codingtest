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

vector<vector<int>> edges;
vector<int> aPerson;
vector<int> visited;

bool dfs(int from)
{
	for (const auto& t : edges[from])
	{
		int to = t;
		if (true == visited[to]) continue;
		visited[to] = true;

		//비어 있거나 점유 노드에 더 들어갈 공간이 있는 경우.
		if (0 == aPerson[to] || dfs(aPerson[to]))
		{
			aPerson[t] = from;
			return true;
		}
	}
	return false;
}


int main()
{
	int pcnt, wcnt;

	cin >> pcnt >> wcnt;

	edges.resize(pcnt + 1);
	aPerson.resize(wcnt + 1, 0);
	visited.resize(wcnt + 1, 0);

	int cnt, tmp;

	for (int i = 1; i < pcnt + 1; ++i)
	{
		cin >> cnt;
		edges[i].resize(cnt);
		for (int j = 0; j < cnt; ++j)
		{
			cin >> tmp;
			edges[i][j] = tmp;
		}
	}

	int count = 0;
	for (int i = 1; i < pcnt + 1; ++i)
	{
		visited.clear();
		visited.resize(pcnt + 1, 0);
		if (true == dfs(i))
		{
			++count;
		}
	}

	cout << count;
	return 0;
}