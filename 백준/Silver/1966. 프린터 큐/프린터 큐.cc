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
	int val;
	int idx;
};


struct cmp
{
	bool operator()(const node& a, const node& b)
	{
		return a.val < b.val;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;

	int n, m;
	int t;
	for (int i = 0; i < cnt; ++i)
	{
		cin >> n >> m;
		priority_queue<int, vector<int>> pq;
		queue<node> q;
		for (int j = 0; j < n; ++j)
		{
			cin >> t;
			pq.push(t);
			q.push({ t,j });
		}

		int ret = 1;
		while (false == q.empty())
		{
			int mx = pq.top();

			auto cur = q.front();
			q.pop();

			if (mx > cur.val)
			{
				q.push(cur);
			}
			else
			{
				if (m == cur.idx)
				{
					cout << ret << " ";
					break;
				}
				pq.pop();
				++ret;
			}
		}
	}

	return 0;
}
