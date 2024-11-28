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
const int MOD = 10000;
struct node
{
	int val;
	string path;
};
char op[4] = { 'D','S','L','R' };
enum eOP
{
	OP_D, OP_S, OP_L, OP_R, OP_END,
};
vector<int> visited(10000);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tcnt;
	cin >> tcnt;

	int o, t;
	while (tcnt--)
	{
		cin >> o >> t;

		queue<node> q;
		q.push({ o,"" });
		fill(visited.begin(), visited.end(), 0);

		while (false == q.empty())
		{
			auto cur = q.front();
			q.pop();

			if (t == cur.val)
			{
				cout << cur.path << " ";
				break;
			}

			int icurval = cur.val;
			int nval[OP_END] = { -1 , -1,-1,-1 };

			//연산자 D
			nval[OP_D] = (icurval * 2) % MOD;

			//연산자 S
			nval[OP_S] = (icurval - 1);
			if (-1 == nval[OP_S])
			{
				nval[OP_S] = 9999;
			}

			//연산자 L
			nval[OP_L] = icurval * 10;
			if (1000 <= icurval)
			{
				nval[OP_L] = nval[OP_L] % MOD;
				nval[OP_L] += icurval / 1000;
			}

			//연산자 R
			nval[OP_R] = (icurval / 10) + ((icurval % 10) * 1000);

			for (int i = 0; i < OP_END; ++i)
			{
				if (0 > visited[nval[i]] || MOD <= visited[nval[i]])
				{
					continue;
				}

				if (0 == visited[nval[i]])
				{
					visited[nval[i]] = 1;
					q.push({ nval[i], cur.path + op[i] });
				}
			}
		}
	}

	return 0;
}