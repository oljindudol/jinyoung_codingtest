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

	string ret = "";

	unordered_map<string, int> um;

	int m, n;
	cin >> m >> n;
	string s;
	while (n--)
	{
		cin >> s;
		um[s] = 1;
	}

	vector<string> sret;
	while (m--)
	{
		cin >> s;
		if (1 == um[s])
		{
			sret.push_back(s);
		}
	}

	ret += to_string(sret.size());

	sort(sret.begin(), sret.end());

	for (int i = 0; i < sret.size(); ++i)
	{
		ret += " ";
		ret += sret[i];
	}
	cout << ret;

	return 0;
}
