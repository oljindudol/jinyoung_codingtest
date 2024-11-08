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
struct pipe
{
	long long l;
	long long c;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long d, p;
	cin >> d >> p;

	long long l, c;
	vector<pipe> pipes(p);
	for (int i = 0; i < p; ++i)
	{
		cin >> l >> c;
		pipes[i] = { l,c };
	}

	vector<long long> dp(d + 1);
	dp[0] = pow(2, 23);

	for (const auto& e : pipes)
	{
		auto pdp = dp;
		for (int i = e.l; i < dp.size(); ++i)
		{
			long long neww = i - e.l;
			//long long prev = (0 == pdp[neww]) ? 0 : min(pdp[neww], e.c);
			dp[i] = max(pdp[i], min(pdp[neww], e.c));
		}
	}

	cout << dp[d];

	return 0;
}