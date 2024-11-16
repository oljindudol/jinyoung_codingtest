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
vector<bool> dp;
vector<long long> primes;
long long m, n;

void init()
{
	dp.resize(n + 1, true);

	dp[0] = false;
	dp[1] = false;
	for (long long i = 2; i < n + 1; ++i)
	{
		if (true == dp[i])
		{
			if (m <= i)
			{
				primes.push_back(i);
			}
			for (long long j = i * i; j < n + 1; j += i)
			{
				dp[j] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;


	init();

	for (const auto& e : primes)
	{
		cout << e << '\n';
	}

	return 0;
}
