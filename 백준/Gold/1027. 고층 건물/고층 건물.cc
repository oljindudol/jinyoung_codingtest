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

struct rect
{
	int range[4];
	int parent;
};

struct point
{
	int x;
	int y;
};


bool IsValid(float maxIncline, float curIncline)
{
	if (maxIncline < curIncline)
	{
		return true;
	}
	return false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;
	vector< int> Heights(cnt);
	int t;
	for (int i = 0; i < cnt; ++i)
	{
		cin >> t;
		Heights[i] = t;
	}

	vector<int> maxview(cnt, 0);
	for (int from = 0; from < cnt; ++from)
	{
		float maxIncle = -2000000000.f;
		for (int to = from + 1; to < cnt; ++to)
		{
			float diffx = to - from;
			float diffy = Heights[to] - Heights[from];
			float curIncle = diffy / diffx;
			if (true == IsValid(maxIncle, curIncle))
			{
				++maxview[from];
			}
			maxIncle = max(maxIncle, curIncle);
		}
		maxIncle = -2000000000.f;
		for (int to = from - 1; to >= 0; --to)
		{
			float diffx = from - to;
			float diffy = Heights[to] - Heights[from];
			float curIncle = diffy / diffx;
			if (true == IsValid(maxIncle, curIncle))
			{
				++maxview[from];
			}
			maxIncle = max(maxIncle, curIncle);
		}
	}

	auto iter = max_element(maxview.begin(), maxview.end());
	cout << *iter;

	return 0;
}