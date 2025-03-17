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
#include <mutex>
#include <assert.h>

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
int n, tcnt;
vector<string> names;
unordered_map<string, int> um;

bool IsName(const string& val)
{
	for (const auto& e : val)
	{
		if ('0' <= e && '9' >= e)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> tcnt;

	names.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> names[i];
		um[names[i]] = i + 1;
	}


	string input;
	while (tcnt--)
	{
		cin >> input;

		if (true == IsName(input))
		{
			cout << um[input] << '\n';
		}
		else
		{
			cout << names[stoi(input) - 1] << '\n';
		}
	}

	return 0;
}