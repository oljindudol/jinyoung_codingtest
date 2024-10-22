#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
using namespace std;

struct item
{
	int w;
	int v;
};



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<item> items;
	for (int i = 0; i < n; ++i)
	{
		int w, v;
		cin >> w >> v;
		items.push_back({ w,v });
	}

	vector<int> dp(k + 1, 0);

	for (int i = 0; i < n; ++i)
	{
		auto pdp = dp;

		for (int j = 1; j < k + 1; ++j)
		{
			//공간이 남아있으면
			if (j >= items[i].w)
			{
				int newweight = j - items[i].w;
				dp[j] = max(pdp[j], pdp[newweight] + items[i].v);
			}
		}
	}

	cout << dp[k];

	return 0;
}