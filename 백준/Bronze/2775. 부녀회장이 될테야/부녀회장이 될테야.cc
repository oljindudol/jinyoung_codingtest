#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define NINF -10000001

struct tc
{
	int k;
	int n;
};

int main()
{
	int tcnt;
	cin >> tcnt;
	vector<tc> vectc;
	vector<vector<int>> dp(15, vector<int>(15, 0));

	for (int i = 0; i < 15; ++i)
	{
		dp[0][i] = i;
	}

	for (int i = 0; i < tcnt; ++i)
	{
		int k, n;
		cin >> k >> n;
		vectc.push_back({ k,n });
	}

	for (int f = 1; f < 15; ++f)
	{
		for (int ho = 1; ho < 15; ++ho)
		{
			for (int prevho = 1; prevho <= ho; ++prevho)
			{
				dp[f][ho] += dp[f - 1][prevho];
			}
		}
	}

	for (auto& e : vectc)
	{
		cout << dp[e.k][e.n] << endl;
	}

	return 0;
}