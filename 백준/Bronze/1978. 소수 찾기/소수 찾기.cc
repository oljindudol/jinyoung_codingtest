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
constexpr int INF = 1e3 + 1;
vector<bool> IsPrime;

void init()
{
	IsPrime.resize(INF, true);

	IsPrime[0] = false;
	IsPrime[1] = false;

	for (int i = 2; i < INF; ++i)
	{
		if (false == IsPrime[i])
		{
			continue;
		}

		for (int j = i * i; j < INF; j += i)
		{
			IsPrime[j] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	int cnt;
	cin >> cnt;
	int t;
	int ret = 0;
	while (cnt--)
	{
		cin >> t;

		if (true == IsPrime[t])
		{
			++ret;
		}
	}

	cout << ret;


	return 0;
}

