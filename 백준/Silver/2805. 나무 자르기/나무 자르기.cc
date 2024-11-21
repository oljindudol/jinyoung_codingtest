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
long long n, k;
vector<long long> trees;


bool IsPossible(long long len)
{
	long long sum = 0;

	for (const auto& e : trees)
	{
		long long newlen = e - len;
		if (0 > newlen)
		{
			continue;
		}
		sum += (newlen);
		if (sum >= k)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	trees.resize(n);
	long long mx = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> trees[i];
		mx = max(mx, trees[i]);
	}

	long long left = 0, right = mx - 1;

	while (left <= right)
	{
		long long mid = left + (right - left) / 2;

		bool b = IsPossible(mid);
		if (true == b)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << right;

	return 0;
}