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
constexpr int INF = 50001;

struct node
{
	int val;
	int depth;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;

	cin >> n;
	vector<int> dp(n + 1, INF);
	dp[0] = 0;

	for (int i = 1; i < n + 1; ++i)
	{
		int sq = sqrt(i);
		if (i == pow(sq, 2))
		{
			dp[i] = 1;
			continue;
		}

		for (int j = 1; j < sq + 1; ++j)
		{
			dp[i] = min(dp[i], dp[i - pow(j, 2)] + 1);
		}
	}

	cout << dp[n];
	//queue<node> q;
	//q.push({ n,0 });

	//while (true)
	//{
	//	sqrt()


	//}


	return 0;
}


