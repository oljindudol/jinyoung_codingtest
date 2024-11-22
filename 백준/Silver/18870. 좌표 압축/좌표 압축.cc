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
	int n;
	cin >> n;
	vector<int> origin(n);
	vector<int> cpy;
	set<int> s;

	for (int i = 0; i < n; ++i)
	{
		cin >> origin[i];
		s.insert(origin[i]);
	}

	for (const auto& e : s)
	{
		cpy.push_back(e);
	}

	sort(cpy.begin(), cpy.end());

	auto bgn = cpy.begin();
	for (auto& t : origin)
	{
		auto lb = lower_bound(cpy.begin(), cpy.end(), t);
		t = lb - bgn;
	}

	PrintVec(origin);
	return 0;
}