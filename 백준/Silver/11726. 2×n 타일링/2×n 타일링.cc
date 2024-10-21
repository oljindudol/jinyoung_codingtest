#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define NINF -10000001

int main()
{
	int n;
	cin >> n;

	vector<long long> dp(n + 1);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i < n + 1; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n];

	return 0;
}