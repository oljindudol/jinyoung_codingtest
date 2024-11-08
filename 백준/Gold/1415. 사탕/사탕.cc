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

#define INF 500001

struct candy
{
	int cost;
	int cnt;
};

long long ret = 0;
vector<candy> candies;
vector<bool> IsPrime;


void initPrime(int n)
{
	IsPrime.resize(n, true);

	IsPrime[0] = IsPrime[1] = false;

	for (int i = 2; i < n; ++i)
	{
		if (true == IsPrime[i])
		{
			int j = i * 2;
			while (IsPrime.size() > j)
			{
				IsPrime[j] = false;
				j = j + i;
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initPrime(INF);
	unordered_map<int, int> um;

	int cnt;
	cin >> cnt;

	int t;
	for (int i = 0; i < cnt; ++i)
	{
		cin >> t;
		++um[t];
	}

	for (const auto& e : um)
	{
		candies.push_back({ e.first, e.second });
	}

	vector<long long> dp(INF, 0);
	dp[0] = 1;

	for (const auto& e : candies)
	{
		auto pdp = dp;
		int curcnt = e.cnt;
		int curcost = e.cost;
		for (int i = curcost; i < INF; ++i)
		{
			for (int j = 1; j <= curcnt; ++j)
			{
				int newcost = i - curcost * j;
				if (newcost < 0)
				{
					break;
				}
				dp[i] = dp[i] + pdp[newcost];
			}
		}
	}

	for (int i = 0; i < INF; ++i)
	{
		if (true == IsPrime[i])
		{
			ret += dp[i];
		}
	}
	cout << ret;

	return 0;
}