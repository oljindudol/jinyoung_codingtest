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

//struct edge
//{
//	int to;
//	int w;
//};

struct building
{
	int InCnt = 0;
	int w;
	int buildtime = 0;
};

struct node
{
	int idx;
	int acctime;
};

struct cmp
{
	bool operator()(const node& a, const node& b)
	{
		return a.acctime > b.acctime;
	}
};



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;
	vector<building> buildings(cnt + 1);
	vector<vector<int>> edges(cnt + 1);

	int t;
	for (int i = 1; i < buildings.size(); ++i)
	{
		vector<int > vecinput;
		while (true)
		{
			cin >> t;
			if (-1 == t)
			{
				break;
			}
			else
			{
				vecinput.push_back(t);
			}
		}
		reverse(vecinput.begin(), vecinput.end());

		buildings[i].w = vecinput.back();
		buildings[i].InCnt = vecinput.size() - 1;
		for (int j = 0; j < vecinput.size() - 1; ++j)
		{
			edges[vecinput[j]].push_back(i);
			//++buildings[vecinput[j]].InCnt;
		}
	}

	priority_queue<node, vector<node>, cmp> pq;

	for (int i = 1; i < buildings.size(); ++i)
	{
		if (0 == buildings[i].InCnt)
		{
			pq.push({ i,buildings[i].w });
		}
	}

	int ret = 0;

	while (false == pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		auto curidx = cur.idx;
		auto curtime = cur.acctime;

		buildings[curidx].buildtime = curtime;

		for (const auto& to : edges[curidx])
		{
			--buildings[to].InCnt;
			if (0 == buildings[to].InCnt)
			{
				auto newtime = curtime + buildings[to].w;
				pq.push({ to,newtime });
			}
		}
	}

	for (int i = 1; i < buildings.size(); ++i)
	{
		cout << buildings[i].buildtime << " ";
	}

	return 0;
}