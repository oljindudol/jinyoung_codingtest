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
//bool IsPan(int left, int right, const vector<int>& v)
//{
//	int newsize = right - left + 1;
//	int mid = left + (newsize) / 2;
//
//
//	for (int i = left; i < mid; ++i)
//	{
//		int j;
//		if (0 == newsize % 2)
//		{
//			j = mid + (mid - i - 1);
//		}
//		else
//		{
//			j = mid + (mid - i);
//		}
//		if (v[i] != v[j])
//		{
//			return false;
//		}
//	}
//	return true;
//}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> origin(n);
	int t;
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		origin[i] = t;
	}

	vector<int> odp(n, 1);

	for (int i = 0; i < n; ++i)
	{
		for (int l = 1; l <= n / 2; ++l)
		{
			if (0 <= (i - l) && (i + l) < n)
			{
				if (origin[i - l] == origin[i + l])
				{
					odp[i] += 2;
				}
				else
				{
					break;
				}
			}
		}
	}

	vector<int> edp(n, 0);

	for (int i = 0; i < n; ++i)
	{
		for (int l = 1; l <= n / 2; ++l)
		{
			if (0 <= (i - l + 1) && (i + l) < n)
			{
				if (origin[i - l + 1] == origin[i + l])
				{
					edp[i] += 2;
				}
				else
				{
					break;
				}
			}
		}
	}


	int m, s, e;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> s >> e;
		--s;
		--e;
		int mid = s + (e - s) / 2;
		int len = e - s + 1;

		if (0 == len % 2)
		{
			if (edp[mid] < len)
			{
				printf("0\n");
			}
			else
			{
				printf("1\n");
			}
		}
		else
		{
			if (odp[mid] < len)
			{
				printf("0\n");
			}
			else
			{
				printf("1\n");
			}
		}
	}

	return 0;
}

