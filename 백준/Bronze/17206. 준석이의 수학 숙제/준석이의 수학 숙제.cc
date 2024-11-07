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

using namespace std;

template <typename T>
void PrintVec(const vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
	}
	cout << endl;
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
		cout << endl;
	}
	cout << endl;
}

/////////////////////////////////////////////



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;

	int t;

	int s3, s7, s21, ret;
	for (int i = 0; i < cnt; ++i)
	{
		cin >> t;
		ret = 0;
		s3 = t / 3;
		ret = ret + s3 * (s3 * 3 + 3) / 2;
		s7 = t / 7;
		ret = ret + s7 * (s7 * 7 + 7) / 2;
		s21 = t / 21;
		ret = ret - s21 * (s21 * 21 + 21) / 2;

		cout << ret << " ";
	}



	return 0;
}