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
vector<vector<int>> edges;
vector<int> visited;
struct node
{
	int pos;
	int depth;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	visited.resize(101);
	edges.resize(101);

	cin >> n >> m;

	int t1, t2;
	for (int i = 0; i < n + m; ++i)
	{
		cin >> t1 >> t2;
		edges[t1].push_back(t2);
	}

	queue<node> q;
	q.push({ 1,0 });
	visited[1] = 1;

	while (false == q.empty())
	{
		auto cur = q.front();
		q.pop();

		if (100 == cur.pos)
		{
			cout << cur.depth;
			break;
		}

		for (int i = 1; i <= 6; ++i)
		{
			int newpos = cur.pos + i;
			if (100 < newpos || 1 == visited[newpos])
			{
				continue;
			}
			visited[newpos] = 1;

			if (0 != edges[newpos].size())
			{
				int newnewpos = edges[newpos][0];
				visited[newnewpos] = 1;
				q.push({ newnewpos,cur.depth + 1 });
			}
			else
			{
				q.push({ newpos,cur.depth + 1 });
			}
		}
	}

	return 0;
}