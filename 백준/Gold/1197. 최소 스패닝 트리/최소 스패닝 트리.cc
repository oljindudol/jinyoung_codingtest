#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <ostream>

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
struct edge
{
	int to;
	long long w;
	//int visited;
};

#define INF 2147483647
vector<vector<edge>> edges;
int ret = INF;
vector<int> visited;
int v, e;

struct cmp
{
	bool operator()(const edge& a, const edge& b)
	{
		return a.w > b.w;
	}
};


int main()
{

	cin >> v >> e;
	++v;

	visited = vector<int>(v, 0);
	edges = vector<vector<edge>>(v);

	int f, t;
	long long w;
	for (int i = 0; i < e; ++i)
	{
		cin >> f >> t >> w;
		edges[f].push_back({ t,w });
		edges[t].push_back({ f,w });

	}

	visited[0] = 1;
	priority_queue<edge, vector<edge>, cmp> pq;
	long long ret = 0;
	for (const auto& e : edges[1])
	{
		pq.push(e);
	}
	visited[1] = 1;

	while (false == pq.empty())
	{
		auto top = pq.top();
		pq.pop();

		if (1 == visited[top.to])
		{
			continue;
		}
		ret += top.w;
		visited[top.to] = 1;
		for (const auto& e : edges[top.to])
		{
			pq.push(e);
		}
	}

	cout << ret;

	return 0;
}