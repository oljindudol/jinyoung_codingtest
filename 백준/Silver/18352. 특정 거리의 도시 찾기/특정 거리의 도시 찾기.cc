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
#define INF 300002

struct node
{
	int idx;
	int dist;
};

struct cmp
{
	bool operator () (const node& a, const node& b)
	{
		return a.dist > b.dist;
	}
};

int main()
{
	//k:거리 x:출발
	int v, e, k, x;
	cin >> v >> e >> k >> x;
	vector<vector<int>> edges(v + 1);
	vector<int> dp(v + 1, INF);

	int f, t;
	for (int i = 0; i < e; ++i)
	{
		cin >> f >> t;
		edges[f].push_back(t);
	}
	priority_queue<node, vector<node>, cmp> pq;
	//다익이
	pq.push({ x,0 });
	dp[x] = 0;

	while (false == pq.empty())
	{
		node cur = pq.top();
		pq.pop();
		int curidx = cur.idx;
		int curdist = cur.dist;

		for (const auto& e : edges[curidx])
		{
			int newidx = e;
			int newdist = curdist + 1;

			if (dp[newidx] > newdist)
			{
				dp[newidx] = newdist;
				pq.push({ newidx,newdist });
			}
		}
	}



	//출력
	bool exist = false;
	for (int i = 0; i < v + 1; ++i)
	{
		if (k == dp[i])
		{
			cout << i << endl;
			exist = true;
		}
	}

	if (false == exist)
	{
		cout << -1;
	}

	return 0;
}