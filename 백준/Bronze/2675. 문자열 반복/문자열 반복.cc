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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int r;
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> r;
		cin >> s;

		for (const auto& e : s)
		{
			for (int j = 0; j < r; ++j)
			{
				cout << e;
			}
		}
		cout << endl;
		//printf("\n");
	}

	return 0;
}

