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
//vector<int> dp;
long long a, b, c;
int dfs(int n)
{
	if (0 == n)
	{
		return 1;
	}
	//if (0 != dp[n])
	//{
	//	return dp[n];
	//}

	if (1 == n % 2)
	{
		long long newn = (n - 1) / 2;
		long long tmp = dfs(newn);
		long long ret = ((a * tmp) % c * tmp) % c;
		return  ret;
	}
	else
	{
		long long newn = n / 2;
		long long tmp = dfs(newn);
		long long ret = (tmp * tmp) % c;
		return  ret;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;

	a = a % c;
	cout << dfs(b);

	return 0;
}
