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

	int n, m;
	cin >> n >> m;
	vector<long long> nums(n + 1);
	vector<long long> sums(n + 1);

	sums[0] = 0;
	for (int i = 1; i < n + 1; ++i)
	{
		cin >> nums[i];
		sums[i] = sums[i - 1] + nums[i];
	}

	int t1, t2;
	for (int i = 0; i < m; ++i)
	{
		cin >> t1 >> t2;
		cout << sums[t2] - sums[t1 - 1] << " ";
	}

	return 0;
}
