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

using namespace std;

template <typename T>
void PrintVec(const vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
	}
	cout << endl;
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
		cout << endl;
	}
	cout << endl;
}

/////////////////////////////////////////////
#define INF 2e9+1;
vector<int> visited;
int a;
int b;
int sol = INF;

//int bs(int val)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c, t;

	cin >> c;

	vector<int> r(c);
	for (int i = 0; i < c; ++i)
	{
		cin >> t;
		r[i] = t;
	}

	sort(r.begin(), r.end());

	for (int i = 0; i < r.size(); ++i)
	{
		int target = -r[i];
		auto lb = lower_bound(r.begin(), r.end(), target) - r.begin();
		auto ub = upper_bound(r.begin(), r.end(), target) - r.begin();

		int solidx[4] = { lb - 1,lb,ub,ub + 1 };
		for (int j = 0; j < 4; ++j)
		{
			if (i == solidx[j] || solidx[j] < 0 || solidx[j] >= r.size())
			{
				continue;
			}

			int newsol = abs(r[i] + r[solidx[j]]);
			if (sol > newsol)
			{
				sol = newsol;
				a = r[i];
				b = r[solidx[j]];
			}
		}
	}
	cout << min(a, b) << " " << max(a, b);

	return 0;
}

