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
//#include "semaphore.h"
#include <semaphore>

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
#define INF 1e5
struct dpnode
{
	int depth = INF + 2;
	int cnt;
};


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

	int o, t;
	cin >> o >> t;
	vector<dpnode> visited(INF + 1);

	visited[o].cnt = 1;
	visited[o].depth = 0;

	queue<node> q;
	bool bFound = false;
	q.push({ o,0 });

	if (o == t)
	{
		cout << "0 1";
		return 0;
	}

	while (false == q.empty())
	{
		auto cur = q.front();
		q.pop();

		if (true == bFound && visited[t].depth < cur.depth)
		{
			continue;
		}

		if (t == cur.pos)
		{
			bFound = true;
			//if ()
			//{
			//	retdepth = cur.depth;
			//	++retcnt;
			//}
			//else if (retdepth == cur.depth)
			//{
			//	++retcnt;
			//}
			//else
			//{

			//}
			//continue;
		}

		int newpos = cur.pos + 1;
		if (INF >= newpos && cur.depth <= visited[newpos].depth)
		{
			visited[newpos].depth = cur.depth;
			++visited[newpos].cnt;
			q.push({ newpos,cur.depth + 1 });
		}

		newpos = cur.pos - 1;
		if (0 <= newpos && cur.depth <= visited[newpos].depth)
		{
			visited[newpos].depth = cur.depth;
			++visited[newpos].cnt;
			q.push({ newpos,cur.depth + 1 });
		}

		newpos = cur.pos * 2;
		if (INF >= newpos && cur.depth <= visited[newpos].depth)
		{
			visited[newpos].depth = cur.depth;
			++visited[newpos].cnt;
			q.push({ newpos,cur.depth + 1 });
		}
	}

	cout << visited[t].depth + 1 << ' ' << visited[t].cnt;

	return 0;
}