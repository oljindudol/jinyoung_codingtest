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

	if (1 == n)
	{
		cout << 1;
		return 0;
	}

	list<int> dp;
	for (int i = 0; i < n; ++i)
	{
		dp.push_back(i + 1);
	}

	while (1 != dp.size())
	{
		//auto node = dp.front();
		dp.pop_front();

		if (1 == dp.size())
		{
			break;
		}
		auto node = dp.front();
		dp.pop_front();
		dp.push_back(node);
	}

	cout << *dp.begin();

	return 0;
}
