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

	string origin;
	cin >> origin;
	vector<int> nums;
	vector<char> ops;

	int left = 0;
	for (int right = 1; right < origin.size(); ++right)
	{
		if ('+' == origin[right] || '-' == origin[right])
		{
			string num = { origin.begin() + left,origin.begin() + right };
			nums.push_back(stoi(num));
			ops.push_back(origin[right]);
			left = right + 1;
			right = left;
		}
	}

	string num = { origin.begin() + left,origin.end() };
	nums.push_back(stoi(num));


	int ret = nums[0];
	bool b = false;
	for (int i = 0; i < nums.size() - 1; ++i)
	{
		if ('-' == ops[i] || b == true)
		{
			ret -= nums[i + 1];
			b = true;
		}
		else
		{
			ret += nums[i + 1];
		}
	}

	cout << ret;
	return 0;
}
