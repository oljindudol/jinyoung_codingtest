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



struct edge
{
	int to;
	int w;
};

#define INF 1000000001


void fw(vector<vector<int>>& dp, int n)
{
	for (int k = 1; k < n + 1; ++k)
	{
		for (int i = 1; i < n + 1; ++i)
		{
			for (int j = 1; j < n + 1; ++j)
			{
				int neww = dp[i][k] + dp[k][j];
				if (dp[i][j] > neww)
				{
					dp[i][j] = neww;
				}
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));

	int f, t, w;

	for (int i = 0; i < m; ++i)
	{
		cin >> f >> t >> w;

		//dp[f][t] = w;
		dp[f][t] = min(dp[f][t], w);
	}

	for (int i = 0; i < n + 1; ++i)
	{
		dp[i][i] = 0;
	}

	fw(dp, n);

	for (int row = 1; row < n + 1; ++row)
	{
		for (int col = 1; col < n + 1; ++col)
		{
			if (INF == dp[row][col])
			{
				printf("0 ");
			}
			else
			{
				printf("%d ", dp[row][col]);
			}
		}
		printf("\n");
	}

	return 0;
}