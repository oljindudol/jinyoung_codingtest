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

	int n, k;
	cin >> n >> k;


	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		q.push(i + 1);
	}

	cout << "<";
	bool f = false;
	int cnt = k;
	while (false == q.empty())
	{
		--cnt;
		auto node = q.front();
		q.pop();

		if (0 == cnt)
		{
			if (true == f)
			{
				cout << ", ";
			}
			cout << node;
			cnt = k;
			f = true;
		}
		else
		{
			q.push(node);
		}
	}
	cout << ">";



	return 0;
}
