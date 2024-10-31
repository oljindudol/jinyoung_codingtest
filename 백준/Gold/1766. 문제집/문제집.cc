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



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> ins(n + 1, 0);
	vector<vector<int>> edges(n + 1);
	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		edges[a].push_back(b);
		++ins[b];
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i < n + 1; ++i)
	{
		if (0 == ins[i])
		{
			pq.push(i);
		}
	}

	while (false == pq.empty())
	{
		int curidx = pq.top();
		pq.pop();
		cout << curidx << " ";

		for (auto& e : edges[curidx])
		{
			--ins[e];

			if (0 == ins[e])
			{
				pq.push(e);
			}
		}
	}


	return 0;
}