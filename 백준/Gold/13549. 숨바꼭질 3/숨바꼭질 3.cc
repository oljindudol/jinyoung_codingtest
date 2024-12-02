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
struct node
{
	int pos;
	int depth;
};

struct cmp
{
	bool operator()(const node& a, const node& b)
	{
		return a.depth > b.depth;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	vector<int> visited(1e5 + 1);
	priority_queue<node, vector<node>, cmp> pq;
	visited[n] = 1;
	pq.push({ n,0 });

	while (false == pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		//cout << cur.depth << ' ' << cur.pos << '\n';

		visited[cur.pos] = 1;

		if (m == cur.pos)
		{
			cout << cur.depth;
			break;
		}

		int npos[3] = { cur.pos - 1,cur.pos + 1 , cur.pos * 2 };

		for (int i = 0; i < 3; ++i)
		{
			if (npos[i] <= 100000 && npos[i] >= 0 && 1 != visited[npos[i]])
			{
				int newdepth = (2 == i) ? cur.depth : cur.depth + 1;
				pq.push({ npos[i],newdepth });
			}
		}
	}
	return 0;
}