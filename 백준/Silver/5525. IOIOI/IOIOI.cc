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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;
	int len = n * 2 + 1;
	char c[2] = { 'I','O' };

	int ret = 0;

	for (int left = 0; left < m; )
	{
		if (c[0] != s[left])
		{
			++left;
			continue;
		}

		int right = left + 1;
		while (right < m && c[(right - left) % 2] == s[right])
		{
			++right;
		}

		int newlen = right - left;

		if (len <= newlen)
		{
			ret += ((newlen - len) / 2) + 1;
		}
		left = right;
	}

	cout << ret;

	return 0;
}