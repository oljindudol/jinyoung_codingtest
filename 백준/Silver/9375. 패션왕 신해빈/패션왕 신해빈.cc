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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int tcnt;
	int n;
	string s1, s2;
	cin >> tcnt;
	for (int i = 0; i < tcnt; ++i)
	{
		int ret = 1;
		unordered_map<string, int> um;
		cin >> n;
		for (int j = 0; j < n; ++j)
		{
			cin >> s1 >> s2;
			++um[s2];
		}

		for (const auto& e : um)
		{
			ret *= (e.second + 1);
		}

		cout << ret - 1 << " ";
	}

	return 0;
}
