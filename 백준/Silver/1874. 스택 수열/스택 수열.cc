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
long long n, k;
bool IsPossible(long long cut, const vector<long long>& cables)
{
	int sum = 0;
	for (const auto& l : cables)
	{
		sum += l / cut;
	}

	if (sum < n)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	string s = "";
	bool bRealFound = true;
	stack<int> st;
	int num = 1;
	for (int i = 0; i < n; ++i)
	{
		while (num <= nums[i])
		{
			st.push(num);
			s += "+ ";
			++num;
		}

		bool bFound = false;
		while (false == st.empty())
		{
			auto top = st.top();
			s += "- ";
			st.pop();

			if (nums[i] == top)
			{
				bFound = true;
				break;
			}
		}

		if (false == bFound)
		{
			bRealFound = false;
			break;
		}
	}

	if (true == bRealFound)
	{
		cout << s;
	}
	else
	{
		cout << "NO";
	}

	return 0;
}
