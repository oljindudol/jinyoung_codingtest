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
int n, m;
struct node
{
	int val;
	int cnt;
};
vector<node> nums;

bool cmp(const node& a, const node& b)
{
	return a.val < b.val;
}

void dfs(vector<int>& picked)
{
	if (m == picked.size())
	{
		PrintVec(picked);
		return;
	}
	if (m < picked.size())
	{
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (0 < nums[i].cnt)
		{
			--nums[i].cnt;
			picked.push_back(nums[i].val);
			dfs(picked);
			picked.pop_back();
			++nums[i].cnt;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	unordered_map<int, int> um;

	int t;
	while (n--)
	{
		cin >> t;
		++um[t];
	}

	for (const auto& e : um)
	{
		nums.push_back({ e.first, e.second });
	}

	sort(nums.begin(), nums.end(), cmp);

	n = nums.size();
	vector<int> picked;
	dfs(picked);

	return 0;
}
