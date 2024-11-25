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
struct node
{
	int start;
	int end;
};

bool cmp(const node& a, const node& b)
{
	if (a.start == b.start)
	{
		return a.end < b.end;
	}
	return a.start < b.start;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<node> nodes(n);

	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> nodes[i].start >> nodes[i].end;
	}
	sort(nodes.begin(), nodes.end(), cmp);

	int left = 0;
	int right = 0;

	for (const auto& e : nodes)
	{
		if (right <= e.start)
		{
			++ret;
			left = e.start;
			right = e.end;
		}
		else
		{
			right = min(right, e.end);
		}
	}

	cout << ret;
	return 0;
}