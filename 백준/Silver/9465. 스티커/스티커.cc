#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_set>
#include<queue>
#include<stdio.h>

using namespace std;


enum
{
	pick_none,
	pick_first,
	pick_second,
};



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cnttc;
	cin >> cnttc;
	vector<int> out;


	for (int i = 0; i < cnttc; ++i)
	{
		int cnt;
		cin >> cnt;
		vector<vector<int>> value;
		vector<vector<int>> dp;
		value.resize(2, vector<int>(cnt));
		dp.resize(3, vector<int>(cnt));

		for (int j = 0; j < cnt; ++j)
		{
			int input;
			cin >> input;
			value[0][j] = input;
		}
		for (int j = 0; j < cnt; ++j)
		{
			int input;
			cin >> input;
			value[1][j] = input;
		}

		dp[pick_none][0] = 0;
		dp[pick_first][0] = value[0][0];
		dp[pick_second][0] = value[1][0];

		for (int j = 1; j < cnt; ++j)
		{
			dp[pick_none][j] = max(dp[pick_first][j - 1], dp[pick_second][j - 1]);
			dp[pick_first][j] = max(dp[pick_none][j - 1], dp[pick_second][j - 1])+value[0][j];
			dp[pick_second][j] = max(dp[pick_none][j - 1], dp[pick_first][j - 1])+value[1][j];
		}

		int mx = max(dp[pick_none][cnt - 1]
			,max(dp[pick_first][cnt - 1]
			, dp[pick_second][cnt - 1]));




		out.push_back(mx);
	}


	for (auto& o : out)
	{
		cout << o<<endl;
	}

	return 0;
}