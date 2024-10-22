#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
using namespace std;

#define INF 100001
int main()
{
	int n;
	cin >> n;

	vector<int> dp(n + 1, INF);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 2; i < n + 1; ++i)
	{
		int sq = sqrt(i);

		for (int j = 1; j <= sq; ++j)
		{
			dp[i] = min(dp[i], dp[i - pow(j, 2)] + 1);
		}
	}

	cout << dp[n];

	return 0;
}