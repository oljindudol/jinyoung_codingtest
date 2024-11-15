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
bool cmp(const string& a, const string& b)
{
	if (a.length() == b.length())
	{
		return a < b;
	}
	return a.length() < b.length();
}

bool IsApo(int i)
{
	int succe = 0;
	string s = to_string(i);
	for (const auto& e : s)
	{
		if ('6' == e)
		{
			++succe;
			if (3 == succe)
			{
				return true;
			}
		}
		else
		{
			succe = 0;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n;

	cin >> n;

	if (0 == n)
	{
		cout << 0;
		return 0;
	}

	int cnt2 = 0;
	int cnt5 = 0;
	while (n)
	{
		int n2 = n;
		int n5 = n;

		while (0 == n2 % 2)
		{
			++cnt2;
			n2 = n2 / 2;
		}

		while (0 == n5 % 5)
		{
			++cnt5;
			n5 = n5 / 5;
		}
		--n;
	}



	cout << min(cnt2, cnt5);

	return 0;
}
