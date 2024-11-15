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
vector<vector<int>> dp;
int n;
void init()
{
	dp.resize(n + 1);
	dp[0].push_back(1);

	for (int i = 1; i < n + 1; ++i)
	{
		dp[i].resize(i + 1);
		for (int j = 0; j <= i; ++j)
		{
			if (0 == j)
			{
				dp[i][j] = dp[i - 1][0];
				continue;
			}
			if (i == j)
			{
				dp[i][j] = dp[i - 1][j - 1];
				continue;
			}

			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num = 0;
	int idx = 0;
	string s;
	for (int i = 1; i < 4; ++i)
	{
		cin >> s;

		if ("Fizz" != s && "Buzz" != s && "FizzBuzz" != s)
		{
			idx = i;
			num = stoi(s);
			break;
		}
	}

	num = num + (4 - idx);

	if (0 == num % 3 || 0 == num % 5)
	{
		if (0 == num % 3)
		{
			cout << "Fizz";
		}
		if (0 == num % 5)
		{

			cout << "Buzz";
		}
	}
	else
	{
		cout << num;
	}


	return 0;
}
