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
//#include "semaphore.h"
#include <semaphore>

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
int n;

int dcol[3] = { -1,0,1 };

bool IsValid(int col)
{
	if (0 > col || 3 <= col)
	{
		return false;
	}
	return true;
}

struct node
{
	int mx;
	int mn;
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<node> dp(3);
	int t;
	for (int i = 0; i < 3; ++i)
	{
		cin >> t;
		dp[i].mx = t;
		dp[i].mn = t;
	}

	for (int i = 0; i < n - 1; ++i)
	{
		auto pdp = dp;
		for (int j = 0; j < 3; ++j)
		{
			cin >> t;
			int mx = 0;
			int mn = 1e9;
			for (int k = 0; k < 3; ++k)
			{
				int ncol = j + dcol[k];
				int nmx = (true == IsValid(ncol)) ? pdp[ncol].mx : 0;
				int nmn = (true == IsValid(ncol)) ? pdp[ncol].mn : 1e9;

				mx = max(nmx, mx);
				mn = min(nmn, mn);
			}
			dp[j].mx = t + mx;
			dp[j].mn = t + mn;
		}
		//for (const auto& e : dp)
		//{
		//	cout << e.mx << ',' << e.mn << ' ';
		//}
		//cout << endl;
	}

	int retmax = 0;
	int retmin = 1e9;

	for (const auto& e : dp)
	{
		retmax = max(retmax, e.mx);
		retmin = min(retmin, e.mn);
	}

	cout << retmax << ' ' << retmin;

	return 0;
}