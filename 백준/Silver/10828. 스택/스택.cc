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
	int idx;
	int cnt;
};

bool cmp(const node& a, const node& b)
{
	return a.val < b.val;
}

bool cmp2(const node& a, const node& b)
{
	return a.idx < b.idx;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string s;
	int t;
	stack<int> st;
	while (n--)
	{
		cin >> s;

		if ("push" == s)
		{
			cin >> t;
			st.push(t);
		}
		else if ("pop" == s)
		{
			if (true == st.empty())
			{
				cout << -1 << " ";
			}
			else
			{
				cout << st.top() << " ";
				st.pop();
			}
		}
		else if ("size" == s)
		{
			cout << st.size() << " ";
		}
		else if ("empty" == s)
		{
			if (true == st.empty())
			{
				cout << 1 << " ";
			}
			else
			{
				cout << 0 << " ";
			}
		}
		else if ("top" == s)
		{
			if (true == st.empty())
			{
				cout << -1 << " ";
			}
			else
			{
				cout << st.top() << " ";
			}
		}

	}




	return 0;
}
