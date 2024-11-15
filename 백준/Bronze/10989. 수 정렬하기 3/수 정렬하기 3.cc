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
constexpr long long r = 31;
constexpr long long MOD = 1234567891;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt, t;
	cin >> cnt;
	vector<int> v(10001);
	for (int i = 0; i < cnt; ++i)
	{
		cin >> t;
		++v[t];
	}

	for (int i = 1; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i]; ++j)
		{
			printf("%d ", i);
		}
	}

	return 0;
}
