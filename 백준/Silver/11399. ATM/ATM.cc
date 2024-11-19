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
constexpr int INF = 1e9 + 1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum = 0;

	int n;

	cin >> n;
	vector<int> times(n);
	int t;
	for (int i = 0; i < times.size(); ++i)
	{
		cin >> t;
		times[i] = t;
	}
	sort(times.begin(), times.end());

	int ret = 0;
	for (const auto e : times)
	{
		ret += sum + e;
		sum += e;
	}

	cout << ret;

	return 0;
}
