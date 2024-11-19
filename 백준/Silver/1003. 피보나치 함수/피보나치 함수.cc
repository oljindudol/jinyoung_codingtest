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
struct node
{
	long long val;
	long long pcnt;
};

constexpr long long	INF = 1e9;
vector<node> dp;
node pb(int n)
{
	if (INF != dp[n].val)
	{
		return dp[n];
	}

	auto left = pb(n - 1);
	auto right = pb(n - 2);
	node cur = { left.val + right.val , left.pcnt + right.pcnt };
	dp[n] = cur;
	return cur;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	dp.resize(41, { INF,INF });
	dp[0] = { 0, 1 };
	dp[1] = { 1,0 };
	cin >> n;
	string ret = "";
	int t;
	while (n--)
	{
		cin >> t;
		auto cur = pb(t);
		ret += to_string(cur.pcnt);
		ret += " ";
		ret += to_string(cur.val);
		ret += " ";

	}
	cout << ret;


	return 0;
}
