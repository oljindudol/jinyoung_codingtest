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

	priority_queue<int> pq;

	string ret = "";
	int t;
	while (n--)
	{
		cin >> t;
		if (0 == t)
		{
			if (true == pq.empty())
			{
				ret += "0 ";
				continue;
			}
			ret += to_string(pq.top());
			ret += " ";
			pq.pop();
		}
		else
		{
			pq.push(t);
		}
	}

	cout << ret;


	return 0;
}