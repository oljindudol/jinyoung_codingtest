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

	int n;

	cin >> n;

	int cnt = 0;
	int i = 1;
	while (true)
	{
		if (IsApo(i))
		{
			++cnt;

			if (n == cnt)
			{
				cout << i;
				break;
			}
		}
		i++;
	}

	return 0;
}
