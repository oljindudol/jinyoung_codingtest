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

void dfs(int len)
{
	if (1 == len)
	{
		printf("-");
		return;
	}

	int newlen = len / 3;

	dfs(newlen);
	for (int i = 0; i < newlen; ++i)
	{
		printf(" ");
	}
	dfs(newlen);
}

int main()
{

	int a, b;
	cin >> a >> b;
	int oa, ob;
	oa = a;
	ob = b;

	int r = a;
	while (0 != r)
	{
		r = a % b;
		a = b;
		b = r;
	}
	cout << a << " " << oa * ob / a;

	return 0;
}