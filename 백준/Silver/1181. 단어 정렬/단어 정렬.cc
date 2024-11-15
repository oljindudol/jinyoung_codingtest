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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;

	string s;
	set<string> ss;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		ss.insert(s);
	}

	vector<string> vs;
	for (const auto& e : ss)
	{
		vs.push_back(e);
	}

	sort(vs.begin(), vs.end(), cmp);


	for (const auto& e : vs)
	{
		cout << e << " ";
	}
	return 0;
}
