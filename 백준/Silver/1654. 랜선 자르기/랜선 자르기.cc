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
bool IsPossible(long long cut, const vector<long long>& cables)
{
	int sum = 0;
	for (const auto& l : cables)
	{
		sum += l / cut;
	}

	if (sum < n)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> n;

	long long left = 1;
	long long right = 0;
	vector<long long> cables(k);
	for (int i = 0; i < k; ++i)
	{
		cin >> cables[i];
		right = max(right, cables[i]);
	}

	while (left <= right)
	{
		long long mid = left + (right - left) / 2;

		bool b = IsPossible(mid, cables);
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
