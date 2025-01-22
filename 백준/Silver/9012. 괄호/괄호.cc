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
bool IsValid(const string& s)
{
	int cnt = 0;
	for (const auto& e : s)
	{
		if ('(' == e)
		{
			++cnt;
		}
		else
		{
			if (0 == cnt)
			{
				return false;
			}
			else
			{
				--cnt;
			}
		}
	}

	return (0 == cnt);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	string s;

	while (n--)
	{
		cin >> s;

		if (true == IsValid(s))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}



	return 0;
}