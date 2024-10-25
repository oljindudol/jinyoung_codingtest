#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <ostream>

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

vector<long long> map;
vector<long long> targets;
int n, m;

//int dfs(long long left, long long right, const long long target)
//{
//	if (left > right)
//	{
//		return 0;
//	}
//	long long mid = left + (right - left) / 2;
//
//	if (target == map[mid])
//	{
//		return 1;
//	}
//
//	if (target > map[mid])
//	{
//		return dfs(mid + 1, right, target);
//	}
//
//	return dfs(left, mid, target);
//}

int bs(int target)
{
	int left = 0;
	int right = map.size();

	while (left < right)
	{

		long long mid = left + (right - left) / 2;


		if (target == map[mid])
		{
			return 1;
		}

		if (target > map[mid])
		{
			left = mid + 1;
			continue;
		}

		right = mid;
	}

	return 0;
}

int main()
{
	long long tmp;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		map.push_back(tmp);
	}
	sort(map.begin(), map.end());

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> tmp;
		targets.push_back(tmp);
	}

	for (const auto& e : targets)
	{
		tmp = bs(e);
		printf("%d\n", tmp);
	}

	return 0;
}