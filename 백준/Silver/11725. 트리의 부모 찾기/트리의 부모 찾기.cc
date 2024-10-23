#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
#include <string>
#include <stdio.h>
#include <unordered_map>

using namespace std;

int n;
vector<int> dp;
vector<vector<int>> map;

void dfs(int cur)
{
	for (int i = 0; i < map[cur].size(); ++i)
	{
		if (-1 == dp[map[cur][i]])
		{
			dp[map[cur][i]] = cur;
			dfs(map[cur][i]);
		}
	}
}


int main()
{
	cin >> n;
	dp = vector<int>(n + 1, -1);
	map = vector<vector<int>>(n + 1);

	int a, b;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i < n + 1; ++i)
	{
		printf("%d\n", dp[i]);
		//cout << dp[i] << endl;
	}

	return 0;
}