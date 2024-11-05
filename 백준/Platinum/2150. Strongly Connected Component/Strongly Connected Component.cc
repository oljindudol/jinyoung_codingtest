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

int vcnt, ecnt;
vector<vector<int>> edges;
vector<int> ids;
vector<int> finished;

stack<int> s;
vector<vector<int>> SCCs;
int id = 0;


//struct cmp
//{
//
//	bool operator()(const vector<vector<int>>& a, const vector<vector<int>>& b)
//	{
//		return a[0] < b[0];
//	}
//
//};
bool cmp(const vector<int>& a, const vector<int>& b)
{
	return a[0] < b[0];
}


int dfs(int from)
{
	ids[from] = ++id;
	s.push(from);

	int parent = ids[from];
	for (int i = 0; i < edges[from].size(); ++i)
	{
		int to = edges[from][i];
		//방문했던 노드가 아니라면
		if (0 == ids[to])
		{
			parent = min(parent, dfs(to));
		}
		// 처리중인 노드
		else if (0 == finished[to])
		{
			parent = min(parent, ids[to]);
		}
	}

	//부모가 자기자신인경우
	if (parent == ids[from])
	{
		vector<int> scc;
		while (true)
		{
			int f = s.top();
			s.pop();

			scc.push_back(f);
			finished[f] = true;
			if (f == from)
			{
				break;
			}
		}
		SCCs.push_back(scc);
	}
	return parent;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> vcnt >> ecnt;

	edges.resize(vcnt + 1);
	ids.resize(vcnt + 1, 0);
	finished.resize(vcnt + 1, 0);

	int f, t;
	for (int i = 0; i < ecnt; ++i)
	{
		cin >> f >> t;
		edges[f].push_back(t);
	}

	for (int from = 1; from < vcnt + 1; ++from)
	{
		if (ids[from] == 0)
		{
			dfs(from);
		}
	}

	printf("%d\n", (int)SCCs.size());

	for (auto& scc : SCCs)
	{
		sort(scc.begin(), scc.end());
	}

	sort(SCCs.begin(), SCCs.end(), cmp);

	for (const auto& scc : SCCs)
	{
		for (const auto& c : scc)
		{
			printf("%d ", c);
		}
		printf("-1\n");
	}

	return 0;
}