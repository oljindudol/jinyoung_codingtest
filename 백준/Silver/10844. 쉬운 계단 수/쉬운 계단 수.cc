#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

#define MOD 1000000000

int main()
{
	int n;
	cin >> n;

	vector < vector<long long>> dp(n + 1, vector<long long>(10, 0));

	for (int i = 0; i < 10; ++i)
	{
		dp[1][i] = 1;
	}
	dp[1][0] = 0;

	for (int i = 2; i < n + 1; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (0 == j)
			{
				dp[i][j] += (dp[i - 1][1] % MOD);
			}
			else if (9 == j)
			{
				dp[i][j] += (dp[i - 1][8] % MOD);
			}
			else
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
				dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
			}
		}
	}


	long long ret = 0;
	for (int i = 0; i < 10; ++i)
	{
		ret = (ret + dp[n][i]) % MOD;
	}

	cout << ret;

	return 0;
}