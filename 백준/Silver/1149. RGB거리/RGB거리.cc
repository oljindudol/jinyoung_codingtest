#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_set>

using namespace std;

int cnt;
vector<vector<int>> cost;
vector<vector<int>> dp;

enum color
{
	RED,
	GREEN,
	BLUE,
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> cnt;
	
	for (int i = 0; i < cnt; ++i)
	{
		int r, g, b;
		cin >> r >> g >> b;

		vector<int> t;
		t.push_back(r);
		t.push_back(g);
		t.push_back(b);

		cost.push_back(t);
	}

	dp.resize(cnt, vector<int>(3, 0));

	dp[0][RED] = cost[0][RED];
	dp[0][GREEN] = cost[0][GREEN];
	dp[0][BLUE] = cost[0][BLUE];


	for (int i = 1; i < cnt; ++i)
	{
		dp[i][RED] = min(dp[i - 1][GREEN], dp[i - 1][BLUE]) + cost[i][RED];
		dp[i][GREEN] = min(dp[i - 1][RED], dp[i - 1][BLUE]) + cost[i][GREEN];
		dp[i][BLUE] = min(dp[i - 1][RED], dp[i - 1][GREEN]) + cost[i][BLUE];
	}

	int dpmin = min(dp[cnt - 1][RED], dp[cnt - 1][GREEN]);
	dpmin = min(dpmin, dp[cnt - 1][BLUE]);
	cout << dpmin;
	return 0;
}