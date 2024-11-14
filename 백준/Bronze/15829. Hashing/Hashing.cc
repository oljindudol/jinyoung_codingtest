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

	long long n;
	string s;
	cin >> n >> s;

	vector<int> dp(51);
	dp[0] = 1;
	dp[1] = r;
	for (int i = 2; i < dp.size(); ++i)
	{
		dp[i] = (dp[i - 1] * r) % MOD;
	}


	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += (((long long)s[i] - 'a' + 1) * dp[i]) % MOD;
	}

	cout << sum % MOD;

	return 0;
}
