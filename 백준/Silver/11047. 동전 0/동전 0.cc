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
struct con
{
	int s;
	int e;
};

bool cmp(const con& a, const con& b)
{
	if (a.s == b.s)
	{
		return a.e < b.e;
	}
	return a.s < b.s;
}

int main()
{
	int n, k;
	cin >> n >> k;

	int min = 1000000001;
	int ret = 0;
	int tmp;
	vector<int> values(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		values[n - 1 - i] = tmp;
	}

	for (int i = 0; i < n; ++i)
	{
		ret += k / values[i];
		k = k % values[i];
	}

	cout << ret;

	return 0;
}