#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_set>
#include<queue>
#include<stdio.h>
#include<list>

using namespace std;




#define num 1234567;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tn;
	vector<int> tc;
	int nmax = 0;

	cin >> tn;

	for (int i = 0; i < tn; ++i)
	{
		int t;
		cin >> t;
		tc.push_back(t);

		nmax = max(nmax, t);
	}

	vector<vector<int>> dp(nmax+1,vector<int>(10));

	for (int i = 0; i < 10; ++i)
	{
		dp[1][i] = 1;
	}


	for (int i = 2; i < dp.size(); ++i)
	{
		dp[i][0] = (dp[i - 1][7]) % 1234567;
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][4]) % 1234567;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5]) % 1234567;
		dp[i][3] = (dp[i - 1][2] + dp[i - 1][6]) % 1234567;
		dp[i][4] = (dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7]) % 1234567;
		dp[i][5] = (dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8]) % 1234567;
		dp[i][6] = (dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9]) % 1234567;
		dp[i][7] = (dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0]) % 1234567;
		dp[i][8] = (dp[i - 1][7] + dp[i - 1][5] + dp[i - 1][9]) % 1234567;
		dp[i][9] = (dp[i - 1][6] + dp[i - 1][8]) % 1234567;
	}

	for (auto& e: tc)
	{
		int sum = 0;
		for (int i = 0; i < 10; ++i)
		{
			sum += dp[e][i];
		}

		auto rem = sum % num;
		cout << rem << endl;
	}


	return 0;
}