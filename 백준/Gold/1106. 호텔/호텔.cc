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







int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c, n;


	cin >> c >> n;

	//cost 는 cost
	//value 는 client
	vector<int> cost;
	vector<int> value;
	vector<int> dp(100100,0);

	cost.push_back(0);
	value.push_back(0);

	for (int i = 0; i < n; ++i)
	{
		int co,val;
		cin >> co >> val;
		cost.push_back(co);
		value.push_back(val);
	}


	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j < dp.size(); ++j)
		{
			if (j >= cost[i])
				dp[j] = max(dp[j - cost[i]] + value[i], dp[j]);
		}
	}

	for (int i = 1 ;  i<dp.size();++i)
	{
		if (c <= dp[i])
		{
			cout << i;
			break;
		}
	}


	return 0;
}