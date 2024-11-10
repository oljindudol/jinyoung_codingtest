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
constexpr long long INF = 3e9 + 1;
constexpr long long NINF = -3e9 - 1;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long  c;
	cin >> c;
	long long t;
	vector<long long> l(c);
	for (long long i = 0; i < c; ++i)
	{
		cin >> t;
		l[i] = t;
	}

	sort(l.begin(), l.end());

	long long soldiff = abs(l[0] + l[1] + l[2]);
	long long ret1 = l[0];
	long long ret2 = l[1];
	long long ret3 = l[2];
	for (int mid = 1; mid < l.size(); ++mid)
	{
		int left = mid - 1;
		int right = mid + 1;
		while (left >= 0 && right < l.size())
		{
			long long cursol = l[left] + l[mid] + l[right];
			long long cursoldiff = abs(cursol);
			if (soldiff > cursoldiff)
			{
				soldiff = cursoldiff;
				ret1 = l[left];
				ret2 = l[mid];
				ret3 = l[right];
			}

			if (cursol > 0)
			{
				--left;
			}
			else if (cursol < 0)
			{
				++right;
				continue;
			}
			else
			{
				cout << l[left] << " " << l[mid] << " " << l[right];
				return 0;
			}
		}
	}

	cout << ret1 << " " << ret2 << " " << ret3;
	return 0;
}

