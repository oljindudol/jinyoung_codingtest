#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <ostream>

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
int tc;

struct employee
{
	int score;
	int interview;
};

bool cmp(const employee& a, const employee& b)
{
	return a.score < b.score;
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	int cnt, a, b;

	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{
		cin >> a >> b;

		int oa = a;
		int ob = b;
		while (0 != b)
		{
			int c = a % b;
			a = b;
			b = c;
		}
		cout << (oa * ob / a) << endl;
	}


	return 0;
}