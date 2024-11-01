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
#define TRUTH -1
vector<int> parents;

void init(int n)
{
	parents.resize(n + 1);

	for (int i = 0; i < n + 1; ++i)
	{
		parents[i] = i;
	}
}

int Find(int n)
{
	if (TRUTH == parents[n])
	{
		return TRUTH;
	}

	while (n != parents[n])
	{
		n = parents[n];
		if (TRUTH == n)
			return TRUTH;
	}
	return n;
}

void Union(int a, int b)
{
	int ra = Find(a);
	int rb = Find(b);

	if (ra == rb)
		return;

	if (-1 == ra)
	{
		parents[rb] = ra;
	}
	else
	{
		parents[ra] = rb;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	init(n);

	int incnt, tmp;
	cin >> incnt;
	for (int i = 0; i < incnt; ++i)
	{
		cin >> tmp;
		parents[tmp] = TRUTH;
	}

	vector<vector<int>> parties;
	for (int i = 0; i < m; ++i)
	{
		cin >> incnt;
		cin >> tmp;
		vector<int> party(incnt);
		int f = tmp;
		party[0] = f;
		for (int j = 1; j < incnt; ++j)
		{
			cin >> tmp;
			party[j] = tmp;
			Union(f, tmp);
		}
		parties.push_back(party);
	}

	int ret = 0;
	for (const auto& e : parties)
	{
		if (TRUTH != Find(e[0]))
		{
			++ret;
		}
	}

	cout << ret;

	return 0;
}