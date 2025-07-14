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
#include <cstring>

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
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> a = { 1,2,3,3,4,10 };
	vector<int> b = { 1,2,2,2,3,5,10 };

	int tcnt;
	cin >> tcnt;

	int num = 1;
	while (tcnt--)
	{
		int t;
		int ia = 0;
		int ib = 0;

		for (int i = 0; i < 6; ++i)
		{
			cin >> t;
			ia += (t * a[i]);
		}

		for (int i = 0; i < 7; ++i)
		{
			cin >> t;
			ib += (t * b[i]);
		}

		cout << "Battle " << (num++) << ": ";
		if (ia < ib)
		{
			cout << "Evil eradicates all trace of Good\n";
		}
		else if (ia > ib)
		{
			cout << "Good triumphs over Evil\n";
		}
		else
		{
			cout << "No victor on this battle field\n";
		}
	}

	return 0;
}
