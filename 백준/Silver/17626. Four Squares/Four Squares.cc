#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <ostream>
#include <stack>
#include <unordered_set>
#include <sstream>
#include <list>

using namespace std;

template <typename T>
void PrintVec(const vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
	}
	cout << '\n';
}


template <typename T>
void PrintVec(const vector<vector<T>>& vec)
{
	for (const auto& e1 : vec)
	{
		for (const auto& e2 : e1)
		{
			cout << e2 << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

/////////////////////////////////////////////

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> dp(n + 1, n);

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < n + 1; ++i)
	{
		int sq = sqrt(i);
		int pw = pow(sq, 2);
		if (i == pw)
		{
			dp[i] = 1;
		}
		else
		{
			for (int j = 1; j <= sq; ++j)
			{
				int newval = i - pow(j, 2);
				dp[i] = min(dp[i], dp[newval] + 1);
			}
		}
	}

	cout << dp[n];
	return 0;
}
