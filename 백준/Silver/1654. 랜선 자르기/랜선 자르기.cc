#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
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
long long k, n;
vector<long long> cables;

bool IsPossible(long long mid)
{
	long long psum = 0;

	for (const auto& e : cables)
	{
		psum += (e / mid);
		if (psum >= n)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> k >> n;

	cables.resize(k);

	long long lenmax = 0;
	long long tlen;
	for (int i = 0; i < k; ++i)
	{
		cin >> tlen;
		cables[i] = tlen;
		lenmax = max(lenmax, tlen);
	}

	long long left = 1;
	long long right = lenmax;

	while (left <= right)
	{
		long long mid = left + (right - left) / 2;
		if (true == IsPossible(mid))
		{
			left = mid + 1;
			continue;
		}
		else
		{
			right = mid - 1;
			continue;
		}
	}

	cout << right;

	return 0;
}