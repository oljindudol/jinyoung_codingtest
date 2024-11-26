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
struct cmp
{
	bool operator()(const int& a, const int& b)
	{
		if (abs(a) == abs(b))
		{
			return a > b;
		}
		return abs(a) > abs(b);
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, cmp> pq;

	int n;

	cin >> n;


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
			}
			else
			{
				ret += to_string(pq.top());
				ret += " ";
				pq.pop();
			}
		}
		else
		{
			pq.push(t);
		}
	}

	cout << ret;


	return 0;
}