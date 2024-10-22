#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
#include <string>

using namespace std;

#define MOD 1000000007

int CoinCombination(const vector<int>& coins, int maxmoney)
{
	int ret = 0;
	int coinsz = coins.size();
	vector<int> dp(maxmoney + 1, 0);

	//for (const auto& e : coins)
	//{
	//	if (maxmoney >= e)
	//	{
	//		dp[e] = 1;
	//	}
	//}

	//if (maxmoney >= coins[0])
	//{
	//	dp[coins[0]] = 1;
	//}
	dp[0] = 1;

	for (int coin = 0; coin < coinsz; ++coin) {
		for (int money = 1; money < maxmoney + 1; ++money)
		{
			int newmoney = money - coins[coin];
			if (newmoney >= 0)
			{
				dp[money] += dp[newmoney];
			}
		}
	}

	ret = dp[maxmoney];
	return ret;
}

struct TestCase
{
	vector<int> coins;
	int money;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tcnt;
	cin >> tcnt;

	vector<TestCase> vecTC;

	for (int i = 0; i < tcnt; ++i)
	{
		TestCase TC = {};
		int coincnt, coinvalue;
		cin >> coincnt;

		for (int j = 0; j < coincnt; ++j)
		{
			cin >> coinvalue;
			TC.coins.push_back(coinvalue);
		}
		cin >> TC.money;

		vecTC.push_back(TC);
	}

	for (const auto& e : vecTC)
	{
		cout << CoinCombination(e.coins, e.money) << endl;
	}



	return 0;
}