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

	int tc;
	cin >> tc;
	int h, w, n;
	for (int i = 0; i < tc; ++i)
	{
		cin >> h >> w >> n;

		int f = n % h;
		int ho;
		if (f == 0)
		{
			cout << h;
			ho = (n / h);
		}
		else
		{
			cout << f;
			ho = (n / h + 1);

		}

		//int ho = (n / h + 1);
		if (ho < 10)
		{
			cout << "0" << ho << endl;
		}
		else
		{
			cout << ho << endl;
		}
	}

	return 0;
}


