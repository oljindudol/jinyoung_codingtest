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

	vector<string> vs;
	string s;
	char c;
	stringstream ss;


	while (true)
	{
		//cin >> s;
		getline(cin, s);
		if ("." == s)
		{
			break;
		}

		stack<char> stack;
		bool ip = true;
		for (const auto& e : s)
		{
			if ('(' == e)
			{
				stack.push(e);
			}
			else if (')' == e)
			{
				if (true == stack.empty())
				{
					ip = false;
					break;
				}
				auto o = stack.top();
				stack.pop();
				if ('(' != o)
				{
					ip = false;
					break;
				}
			}
			else if ('[' == e)
			{
				stack.push(e);
			}
			else if (']' == e)
			{
				if (true == stack.empty())
				{
					ip = false;
					break;
				}
				auto o = stack.top();
				stack.pop();
				if ('[' != o)
				{
					ip = false;
					break;
				}
			}
		}
		if (false == ip || false == stack.empty())
		{
			cout << "no ";
		}
		else
		{
			cout << "yes ";
		}

	}

	return 0;
}
