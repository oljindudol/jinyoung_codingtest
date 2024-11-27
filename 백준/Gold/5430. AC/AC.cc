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
#define ERR "error"

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tcnt;
	cin >> tcnt;
	deque<int> dq;
	string cmd;
	int t;
	string ret;
	string input;
	while (tcnt--)
	{
		ret = "[";
		dq.resize(0);
		cin >> cmd;
		cin >> t;
		cin >> input;
		input = input.substr(1, input.size() - 2);
		stringstream ss(input);
		string s;

		while (getline(ss, s, ','))
		{
			dq.push_back(stoi(s));
		}

		int sz = dq.size();
		int left = 0;
		int right = sz - 1;
		bool brev = false;

		for (const auto e : cmd)
		{
			if ('R' == e)
			{
				brev = !brev;
			}
			else
			{
				if (left > right)
				{
					ret = ERR;
					break;
				}
				else
				{
					brev ? --right : ++left;
				}
			}
		}

		if (ERR != ret)
		{
			if (true == brev)
			{
				for (int i = right; i >= left; --i)
				{
					ret += to_string(dq[i]);
					ret += ',';
				}
			}
			else
			{
				for (int i = left; i <= right; ++i)
				{
					ret += to_string(dq[i]);
					ret += ',';
				}
			}

			if (1 != ret.size())
			{
				ret.pop_back();
			}
			ret += ']';
		}
		cout << ret;
		cout << ' ';
	}


	return 0;
}