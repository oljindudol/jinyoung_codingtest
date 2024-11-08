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
vector<int> origin;
vector<int> nums;


int find(int left, int right, const int val)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (val == nums[mid])
		{
			return mid;
		}
		else if (val > nums[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return left;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	origin.resize(n);

	int t;
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		origin[i] = t;
	}


	for (const auto& e : origin)
	{
		int idx = find(0, nums.size() - 1, e);

		if (nums.size() == idx)
		{
			nums.push_back(e);
		}
		else
		{
			nums[idx] = e;
		}
	}
	cout << nums.size();

	return 0;
}