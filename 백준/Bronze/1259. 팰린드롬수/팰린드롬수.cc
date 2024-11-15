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
constexpr long long r = 31;
constexpr long long MOD = 1234567891;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	while (true)
	{
		cin >> s;
		if ("0" == s)
		{
			break;
		}

		int hsz = s.size() / 2;
		bool b = true;
		for (int i = 0; i < hsz; ++i)
		{
			if (s[i] != s[s.size() - 1 - i])
			{
				b = false;
				break;
			}
		}

		if (true == b)
		{
			cout << "yes" << " ";
		}
		else
		{
			cout << "no" << " ";
		}
	}

	return 0;
}
