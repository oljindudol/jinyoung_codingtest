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


struct mmpair
{
	int min;
	int max;

};


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
	int visited;
};

struct student
{
	int in = 0;
	int out = 0;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<student> students(n + 1);
	vector<vector<edge>> edges(n + 1);
	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;

		++students[a].out;
		++students[b].in;
		edges[a].push_back({ b ,0 });
	}

	queue<int> q;
	vector<int> izn;
	for (int i = 1; i < n + 1; ++i)
	{
		if (0 == students[i].in)
		{
			q.push(i);
		}
	}

	while (false == q.empty())
	{
		int curidx = q.front();
		q.pop();
		printf("%d ", curidx);

		//for (int i = 0; i < edges[curidx].size(); ++i)
		for (auto& e : edges[curidx])

		{
			//if (0 == edges[curidx][i].visited)
			if (1 == e.visited)
			{
				continue;
			}
			//edges[curidx][i].visited = 1;
			e.visited = 1;
			--students[curidx].out;
			--students[e.to].in;

			if (0 == students[e.to].in)
			{
				q.push(e.to);
			}
		}
	}

	return 0;
}