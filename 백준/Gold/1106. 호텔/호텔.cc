#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
#include <string>

using namespace std;



struct city
{
	int w;
	int v;
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c, n;

	cin >> c >> n;

	vector < city > cities(n);

	for (int i = 0; i < n; ++i)
	{
		int w, v;

		cin >> w >> v;
		cities[i] = { w,v };
	}

	vector<long long> dp(100001, 0);

	for (int i = 0; i < n; ++i)
	{
		for (int j = cities[i].w; j < dp.size(); ++j)
		{
			int newweight = j - cities[i].w;

			dp[j] = max(dp[j], dp[newweight] + cities[i].v);
		}
	}

	for (int i = 0; i < dp.size(); ++i)
	{
		if (dp[i] >= c)
		{
			cout << i;
			break;
		}
	}





	return 0;
}