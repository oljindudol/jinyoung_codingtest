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

	cin >> n;
	int  t;
	vector<int> origin(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		origin[i] = t;
	}
	sort(origin.begin(), origin.end());


	int ret = 0;
	cin >> m;
	//vector<int> dic(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> t;
		//dic[i] = t;
		auto lb = lower_bound(origin.begin(), origin.end(), t);
		auto ub = upper_bound(origin.begin(), origin.end(), t);

		cout << ub - lb << " ";
	}

	return 0;
}
