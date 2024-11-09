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

using namespace std;

template <typename T>
void PrintVec(const vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
	}
	cout << endl;
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
		cout << endl;
	}
	cout << endl;
}

/////////////////////////////////////////////
vector<vector<int>> dp;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;

	int sz1 = s1.size();
	int sz2 = s2.size();

	dp.resize(sz2 + 1, vector<int>(sz1 + 1));
	for (int row = 1; row < sz2 + 1; ++row)
	{
		for (int col = 1; col < sz1 + 1; ++col)
		{
			if (s2[row - 1] == s1[col - 1])
			{
				dp[row][col] = dp[row - 1][col - 1] + 1;
			}
			else
			{
				dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
			}
		}
	}

	int row = sz2;
	int col = sz1;

	string ret = "";

	while (false == (0 == row || 0 == col))
	{
		if (s2[row - 1] == s1[col - 1])
		{
			ret += s2[row - 1];
			--row;
			--col;
			continue;
		}
		else
		{
			if (dp[row - 1][col] > dp[row][col - 1])
			{
				--row;
				continue;
			}
			else
			{
				--col;
				continue;
			}
		}
	}
	reverse(ret.begin(), ret.end());
	cout << ret.size() << " " << ret;

	return 0;
}

