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
	int val;
	int cnt;
};

bool cmp(const node& a, const node& b)
{
	if (a.cnt == b.cnt)
	{
		return a.val < b.val;
	}
	return a.cnt < b.cnt;
}

int bs(const int val, const vector<node>& vcnt)
{
	int left = 0;
	int right = vcnt.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (val < vcnt[mid].val)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return right;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;
	vector<node> vcnt(8001);
	vector<int> nums(cnt);
	int sum = 0;
	const int mid = cnt / 2;
	for (int i = 0; i < 8001; ++i)
	{
		vcnt[i] = { i - 4000,0 };
	}

	for (int i = 0; i < cnt; ++i)
	{
		cin >> nums[i];
		sum += nums[i];
		++vcnt[nums[i] + 4000].cnt;
	}

	sort(nums.begin(), nums.end());



	cout << int(round((float)sum / (float)cnt)) << '\n';
	cout << nums[mid] << '\n';

	sort(vcnt.begin(), vcnt.end(), cmp);

	int idx = 8000;
	int mxcnt = vcnt[idx].cnt;
	while (mxcnt == vcnt[idx].cnt)
	{
		--idx;
	}
	++idx;

	if (8000 != idx)
	{
		++idx;
		cout << vcnt[idx].val << '\n';
	}
	else
	{
		cout << vcnt[idx].val << '\n';
	}

	cout << nums[cnt - 1] - nums[0];
	return 0;
}
