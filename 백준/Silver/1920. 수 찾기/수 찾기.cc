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
struct pos
{
	int x;
	int y;
};

bool cmp(const pos& a, const pos& b)
{
	if (a.y == b.y)
	{
		return a.x < b.x;
	}
	return a.y < b.y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	unordered_set<int> us;

	cin >> n;
	int t;
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		us.insert(t);
	}

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> t;
		if (us.end() != us.find(t))
		{
			cout << 1 << " ";
		}
		else
		{
			cout << 0 << " ";
		}
	}

	return 0;
}
