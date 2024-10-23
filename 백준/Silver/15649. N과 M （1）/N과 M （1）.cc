#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
#include <string>
#include <stdio.h>

using namespace std;

int maxdepth;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

vector<string> vecstr;

void dfs(int depth, vector<int>& nums)
{
	if (depth == maxdepth)
	{
		string str = "";
		for (int i = 0; i < maxdepth; ++i)
		{
			str = str + to_string(nums[i]) + " ";
		}
		vecstr.push_back(str);
	}

	for (int i = depth; i < nums.size(); ++i)
	{
		swap(nums[depth], nums[i]);
		dfs(depth + 1, nums);
		swap(nums[depth], nums[i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n >> maxdepth;

	vector<int> nums;
	for (int i = 1; i < n + 1; ++i)
	{
		nums.push_back(i);
	}

	dfs(0, nums);

	sort(vecstr.begin(), vecstr.end());

	for (const auto& e : vecstr)
	{
		printf("%s\n", e.c_str());
	}

	return 0;
}