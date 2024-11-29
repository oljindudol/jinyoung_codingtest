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
vector<int> origin;
vector<int> visited;

void dfs(int depth, vector<int>& picked, int mxidx)
{
	if (m == depth)
	{
		PrintVec(picked);
		return;
	}

	for (int i = mxidx; i < n; ++i)
	{
		picked.push_back(origin[i]);
		dfs(depth + 1, picked, i);
		picked.pop_back();
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	vector<int> nums;

	int t;
	for (int i = 0; i < n; ++i)
	{
		cin >> t;

		auto ub = lower_bound(nums.begin(), nums.end(), t);

		if (nums.end() == ub)
		{
			nums.push_back(t);
		}
		else
		{
			*ub = t;
		}
	}

	cout << nums.size();

	return 0;
}