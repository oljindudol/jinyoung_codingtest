#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
#include <string>
#include <stdio.h>
#include <unordered_map>

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


#define NINF -1000000001
int main()
{
	int n, m, k;
	cin >> n >> k;

	vector<int> nums(n);

	int tmp;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		nums[i] = tmp;
	}

	int cursum = 0;
	for (int i = 0; i < k; ++i)
	{
		cursum += nums[i];
	}


	int ret = cursum;
	for (int i = k; i < n; ++i)
	{
		cursum += nums[i];
		cursum -= nums[i - k];

		ret = max(cursum, ret);
	}

	cout << ret;

	return 0;
}