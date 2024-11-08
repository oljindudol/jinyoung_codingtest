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
struct node
{
	int from;
	int acctime;
};

struct cmp
{
	bool operator() (const node& a, const node& b)
	{
		return a.acctime > b.acctime;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tcnt;
	cin >> tcnt;

	int	bcnt, ecnt;
	int t1, t2, w;
	for (int i = 0; i < tcnt; ++i)
	{
		cin >> bcnt >> ecnt;
		vector<int> buildtime(bcnt + 1);
		vector<vector<int>> edges(bcnt + 1);
		vector<int> ins(bcnt + 1);

		for (int j = 1; j < bcnt + 1; ++j)
		{
			cin >> t1;
			buildtime[j] = t1;
		}
		for (int j = 1; j < ecnt + 1; ++j)
		{
			cin >> t1 >> t2;
			edges[t1].push_back(t2);
			++ins[t2];
		}
		cin >> w;

		int ret = 0;
		priority_queue<node, vector<node>, cmp> pq;
		for (int i = 1; i < ins.size(); ++i)
		{
			if (0 == ins[i])
			{
				pq.push({ i,buildtime[i] });
			}
		}

		while (false == pq.empty())
		{
			auto cur = pq.top();
			pq.pop();
			int curidx = cur.from;
			int curtime = cur.acctime;

			if (w == curidx)
			{
				cout << curtime << '\n';
				break;

			}

			//bool bDirty = false;
			for (const auto& to : edges[curidx])
			{
				--ins[to];

				if (0 == ins[to])
				{
					int newbtime = curtime + buildtime[to];
					//if (w == to)
					//{
					//	cout << newbtime << '\n';
					//	bDirty = true;
					//	break;
					//}
					pq.push({ to, newbtime });
				}
			}
			//if (true == bDirty)
			//{
			//	break;
			//}
		}
	}

	return 0;
}