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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ccnt, gcnt, w;
	cin >> ccnt;

	vector<int> chus(ccnt);
	for (int i = 0; i < ccnt; ++i)
	{
		cin >> w;
		chus[i] = w;
	}

	cin >> gcnt;
	vector<int> gus(gcnt);

	for (int i = 0; i < gcnt; ++i)
	{
		cin >> w;
		gus[i] = w;
	}

	vector<long long> dp(40001);
	dp[0] = 1;

	for (const auto& w : chus)
	{
		auto pdp = dp;
		for (int i = 0; i < dp.size(); ++i)
		{
			long long new1 = i - w;
			if (0 <= new1)
			{
				dp[i] += pdp[new1];
			}
			//long long new2 = i + w;

			//if (dp.size() > new2)
			//{
			//	dp[i] += pdp[new2];
			//}
		}
	}

	for (const auto& w : chus)
	{
		auto pdp = dp;
		for (int i = 0; i < dp.size(); ++i)
		{
			//long long new1 = i - w;
			//if (0 <= new1)
			//{
			//	dp[i] += pdp[new1];
			//}
			long long new2 = i + w;

			if (dp.size() > new2)
			{
				dp[i] += pdp[new2];
			}
		}
	}

	for (const auto& w : gus)
	{
		if (0 == dp[w])
		{
			cout << 'N' << ' ';
		}
		else
		{
			cout << 'Y' << ' ';
		}
	}


	return 0;
}