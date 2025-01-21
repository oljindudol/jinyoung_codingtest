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
#include <mutex>
#include <assert.h>

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
bool IsValid(const string& s)
{
	stack<char> st;

	for (const auto& e : s)
	{
		if ('[' == e)
		{
			st.push('[');
		}
		else if (']' == e)
		{
			if (true == st.empty() || '[' != st.top())
			{
				return false;
			}
			else
			{
				st.pop();
			}
		}
		else if ('(' == e)
		{
			st.push('(');
		}
		else if (')' == e)
		{
			if (true == st.empty() || '(' != st.top())
			{
				return false;
			}
			else
			{
				st.pop();
			}
		}
	}

	if (false == st.empty())
	{
		return false;
	}

	return true;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;


	while (true)
	{
		getline(cin, s);
		if ("." == s)
		{
			break;
		}
		if (true == IsValid(s))
		{
			cout << "yes" << '\n';
		}
		else
		{
			cout << "no" << '\n';
		}
	}

	return 0;
}