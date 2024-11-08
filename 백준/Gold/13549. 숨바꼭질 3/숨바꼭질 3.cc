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

#define INF 200001

struct node
{
	int to;
	int w;
};

struct cmp
{
	bool operator() (const node& a, const node& b)
	{
		return a.w > b.w;
	}
};


vector<long long> dp;
bool IsVaild(int pos)
{
	if (0 > pos || INF < pos)
	{
		return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s, d;

	cin >> s >> d;
	dp.resize(INF + 1, INF);
	priority_queue<node, vector<node>, cmp> pq;

	pq.push({ s,0 });
	dp[s] = 0;

	while (false == pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		int curidx = cur.to;
		int curw = cur.w;

		if (INF == curw)
		{
			continue;
		}

		if (d == curidx)
		{
			break;
		}

		node newnode[3];
		newnode[0].to = curidx + 1;
		newnode[0].w = curw + 1;

		newnode[1].to = curidx - 1;
		newnode[1].w = curw + 1;

		newnode[2].to = curidx * 2;
		newnode[2].w = curw;

		for (int i = 0; i < 3; ++i)
		{
			if (false == IsVaild(newnode[i].to))
			{
				continue;
			}
			if (dp[newnode[i].to] > newnode[i].w)
			{
				dp[newnode[i].to] = newnode[i].w;
				pq.push(newnode[i]);
			}
		}
	}

	cout << dp[d];
	return 0;
}