#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;


int main()
{
	int tcnt;
	cin >> tcnt;

	vector<int> tc;
	int mxnum = 0;
	for (int i = 0; i < tcnt; ++i)
	{
		int t;
		cin >> t;

		mxnum = max(mxnum, t);
		tc.push_back(t);
	}

	vector<int> dp(mxnum + 1);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;

	//11
	//2

	//111
	//12
	//21
	//3

	for (int i = 4; i < mxnum + 1; ++i)
	{
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}


	for (auto& e : tc)
	{
		cout << dp[e] << endl;
	}

	return 0;
}