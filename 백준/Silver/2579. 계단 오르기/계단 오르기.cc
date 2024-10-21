#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define prevfalse 0
#define prevtrue 1

int main()
{
	int n;
	cin >> n;
	vector<int> stairs;

	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		stairs.push_back(tmp);
	}

	vector<vector<int>> dp(n, vector<int>(2, -1));

	dp[0][prevfalse] = dp[0][prevtrue] = stairs[0];

	if (1 == n)
	{
		cout << stairs[0];
		return 0;
	}

	dp[1][prevfalse] = stairs[1];
	dp[1][prevtrue] = stairs[0] + stairs[1];

	for (int i = 2; i < n; ++i)
	{
		//두 칸 올라가는 것 중 최댓값
		dp[i][prevfalse] = max(dp[i - 2][prevfalse], dp[i - 2][prevtrue]) + stairs[i];

		//이전 칸에서 올라오는것
		dp[i][prevtrue] = dp[i - 1][prevfalse] + stairs[i];
	}


	int ret = max(dp[n - 1][0], dp[n - 1][1]);
	cout << ret;

	return 0;
}