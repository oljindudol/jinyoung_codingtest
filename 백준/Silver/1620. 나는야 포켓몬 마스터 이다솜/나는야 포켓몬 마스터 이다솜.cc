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


	int n, m;
	cin >> n >> m;

	unordered_map<string, int> um1;
	unordered_map<int, string> um2;

	string s;

	for (int i = 1; i < n + 1; ++i)
	{
		cin >> s;
		um1[s] = i;
		um2[i] = s;
	}

	const int i0 = '0';
	const int i9 = '9';
	while (m--)
	{
		cin >> s;

		//if (true == isalpha(s[0]))
		//if (false == (i0 <= s[0] && i9 >= s[0]))
		//{
		//	cout << um1[s] << " ";
		//}
		//else
		//{
		//	cout << um2[stoi(s)] << " ";
		//}
		if (i9 >= s[0])
		{
			cout << um2[stoi(s)] << " ";
		}
		else
		{
			cout << um1[s] << " ";
		}

	}





	return 0;
}
