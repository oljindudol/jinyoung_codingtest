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
#include <thread>
#include <omp.h>
#include <mutex>

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
struct item
{
	int v;
	int w;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;

	cin >> n >> k;

	vector<int> dp(k + 1);

	vector<item> items(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> items[i].w >> items[i].v;
	}

	for (const auto i : items)
	{
		auto pdp = dp;
		for (int w = i.w; w < k + 1; ++w)
		{
			int neww = w - i.w;
			int newv = pdp[neww] + i.v;
			dp[w] = max(pdp[w], newv);
		}
	}

	cout << dp[k];
	return 0;
}