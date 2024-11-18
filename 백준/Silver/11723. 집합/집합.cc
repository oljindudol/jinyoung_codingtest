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

	set<int> s;

	int n;
	cin >> n;
	string str;
	int t;

	set<int> s1;
	for (int i = 1; i < 21; ++i)
	{
		s1.insert(i);
	}

	while (n--)
	{
		cin >> str;

		if ("add" == str)
		{
			cin >> t;
			s.insert(t);
		}

		else if ("remove" == str)
		{
			cin >> t;
			s.erase(t);
		}

		else if ("check" == str)
		{
			cin >> t;
			if (s.end() != s.find(t))
			{
				//cout << 1 << " ";
				printf("1 ");
			}
			else
			{
				//cout << 0 << " ";
				printf("0 ");
			}
		}

		else if ("toggle" == str)
		{
			cin >> t;
			if (s.end() != s.find(t))
			{
				s.erase(t);
			}
			else
			{
				s.insert(t);
			}
		}

		else if ("all" == str)
		{
			s = s1;
			//s.clear();
			//for (int i = 1; i < 21; ++i)
			//{
			//	s.insert(i);
			//}
		}

		else if ("empty" == str)
		{
			s.clear();
			continue;
		}

	}

	return 0;
}
