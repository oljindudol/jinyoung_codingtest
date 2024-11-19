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
struct node
{
	int val;
	int depth;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	queue<node> q;
	q.push({ n,0 });
	while (false == q.empty())
	{
		auto cur = q.front();
		if (1 == cur.val)
		{
			cout << cur.depth;
			break;
		}
		q.pop();
		if (0 == cur.val % 3)
		{
			q.push({ cur.val / 3,cur.depth + 1 });
		}
		if (0 == cur.val % 2)
		{
			q.push({ cur.val / 2,cur.depth + 1 });
		}
		q.push({ cur.val - 1,cur.depth + 1 });
	}


	return 0;
}
